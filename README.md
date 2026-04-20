# 🔥 8051 Smart Safety System with ESP32 IoT Dashboard

## 📌 Overview
This project is a smart safety monitoring system using an 8051 microcontroller and ESP32. It detects fire using a flame sensor, controls a relay-based output, and displays real-time status on a web dashboard via WiFi.

---

## 🎯 Features
- Flame detection using sensor
- Relay-based device control
- LCD status display (16x2)
- ESP32 WiFi dashboard
- Real-time monitoring

---

## 🧠 System Architecture

Flame Sensor → 8051 → Relay → LED  
                             ↓  
                         ESP32 → WiFi → Web UI  

---

## 🔧 Components Used

- 8051 Microcontroller (AT89S52)
- ESP32 Module
- Flame Sensor
- 16x2 LCD Display
- Relay Module (4-channel)
- LED (as load)
- Resistors (220Ω, 1kΩ, 2kΩ)
- Breadboard & Jumper Wires

---

## 🔌 Circuit Connections

### 8051 Connections
- Flame Sensor → P0.6  
- LCD Data → Port 1  
- LCD Control → P3.0, P3.1, P3.2  
- Relay → P2.3  
- TX (Software UART) → P2.0  

### ESP32 Connections
- GPIO16 (RX2) ← 8051 P2.0 (via voltage divider)
- GND → Common GND
- VIN → 5V

---

## ⚙️ Working Principle

1. Flame sensor continuously monitors environment  
2. When flame is detected:
   - Relay turns ON  
   - LED turns ON  
   - LCD displays "Flame Detected"  
3. When no flame:
   - Relay remains OFF  
   - LCD displays "All Safe"  
4. 8051 sends status ('F' or 'S') to ESP32  
5. ESP32 hosts a web server displaying system status  

---

## 🌐 ESP32 Setup

Replace WiFi credentials in ESP32 code:

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

After uploading:
- Open Serial Monitor  
- Note the IP address  
- Open browser and enter:

http://<ESP32-IP>

---

## 🔥 Output Behavior

Condition         | Relay | LED | LCD Display
------------------|-------|-----|-------------
No Flame          | OFF   | OFF | All Safe
Flame Detected    | ON    | ON  | Flame Detected

---

## 🚀 How to Run

1. Burn 8051 code using ProgISP  
2. Upload ESP32 code using Arduino IDE  
3. Power both modules  
4. Connect ESP32 to WiFi  
5. Open browser using ESP32 IP  

---

## 🧠 Concepts Used

- Embedded C Programming  
- Sensor Interfacing  
- Relay Switching  
- Software UART  
- IoT using ESP32  
- Web Server  

---

## 🔮 Future Enhancements

- Gas sensor integration  
- Mobile notifications  
- Cloud connectivity (Firebase)  
- Mobile app UI  

---

## 🎯 Conclusion

This project demonstrates a real-time embedded safety system integrated with IoT. It combines hardware control with wireless monitoring, making it suitable for smart home and industrial applications.

---
## 👨‍💻 Team Members
- [Akshat Srivastava](https://github.com/akshatsri3)
- [Anshika Raj](https://github.com/anshikaraj016)

