#include <reg52.h>

// LCD control pins
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

// Sensors
sbit GAS_Sensor   = P0^7;   // (DUMMY - not used)
sbit Flame_Sensor = P0^6;

// Output
sbit Relay  = P2^3;   // Relay (LED connected through relay)

// Function declarations
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_init();
void lcd_string(unsigned char *);
void delay(unsigned int);

// Read flame sensor (stable)
bit flame_detected()
{
    if(Flame_Sensor == 0)
    {
        delay(20);
        if(Flame_Sensor == 0)
            return 1;
    }
    return 0;
}

void main() {

    lcd_init();

    Relay = 1;   // OFF initially (active LOW)

    lcd_cmd(0x80);
    lcd_string("System Starting");

    delay(2000);
    lcd_cmd(0x01);

    while(1)
    {
        // ?? Read ONLY flame sensor
        bit flame = flame_detected();

        // ?? Relay logic: ONLY flame
        if(flame)
        {
            Relay = 0;   // ON ? LED via relay ON
            delay(300);  // stability
        }
        else
        {
            Relay = 1;   // OFF
        }

        // ?? Flame detection
        if(flame)
        {
            lcd_cmd(0x80);
            lcd_string("Flame Detected ");

            lcd_cmd(0xC0);
            lcd_string("DANGER !!!      ");

            delay(300);
        }

        // ? Safe condition
        else
        {
            lcd_cmd(0x80);
            lcd_string("All Safe       ");

            lcd_cmd(0xC0);
            lcd_string("No Hazard      ");

            delay(300);
        }
    }
}

// LCD Initialization
void lcd_init() {
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    delay(2);
}

// LCD Command
void lcd_cmd(unsigned char cmd) {
    P1 = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(1);
    EN = 0;
}

// LCD Data
void lcd_data(unsigned char dat) {
    P1 = dat;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(1);
    EN = 0;
}

// LCD String
void lcd_string(unsigned char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

// Delay
void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}