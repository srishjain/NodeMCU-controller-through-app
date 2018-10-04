
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(115200);
pinMode(16, OUTPUT);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("Jerk stay away","shalini_1215");
  Serial.println("Connecting to wifi");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    if (i == "ON") {
      digitalWrite(16,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Led is on");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "OFF") {
      digitalWrite(16,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Led is off");
      client.println("</html>");
      client.stop();
      delay(1);

    }

}
