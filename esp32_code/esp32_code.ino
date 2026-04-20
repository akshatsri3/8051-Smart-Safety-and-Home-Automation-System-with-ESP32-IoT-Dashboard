#include <WiFi.h>

const char* ssid = "akshat21";
const char* password = "akshat21";

WiFiServer server(80);

String statusMsg = "SYSTEM SAFE";

void setup() {
  Serial.begin(9600);      // For Serial Monitor
  Serial2.begin(9600);     // RX2 = GPIO16 (from 8051)

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {

  // 📡 Receive data from 8051
  if (Serial2.available()) {
    char data = Serial2.read();

    Serial.print("Received: ");
    Serial.println(data);

    if (data == 'F') statusMsg = "🔥 FIRE DETECTED";
    else if (data == 'S') statusMsg = "✅ SYSTEM SAFE";
  }

  // 🌐 Web server
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();

    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<title>Safety System</title>");
    client.println("</head>");
    client.println("<body style='text-align:center;font-family:Arial;'>");

    client.println("<h1>🔥 8051 IoT Safety Panel</h1>");
    client.println("<h2>" + statusMsg + "</h2>");

    client.println("</body></html>");
  }
}