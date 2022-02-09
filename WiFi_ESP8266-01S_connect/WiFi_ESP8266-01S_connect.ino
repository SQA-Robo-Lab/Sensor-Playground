/**
 * WiFi Connection Sketch
 * 
 * Wiring:
 * Arduino Nano   <--->   Esp8266-01s
 * 3.3V           <--->   VCC
 * 3.3V           <--->   CHPD
 * GND            <--->   GND
 * D2             <--->   TXD
 * D3             <--->   RXD
 * 
 * Based on: https://github.com/vanslooten/Arduino_examples/blob/master/first_esp8266_connect.ino
 */

#include "WiFiEsp.h"
#include "SoftwareSerial.h"

char ssid[] = "Davids Galaxy A52s";
char pass[] = "1ccwDnSs!";
int status = WL_IDLE_STATUS;

SoftwareSerial EspSerial(2,3);

void setup() {
  Serial.begin(115200);
  EspSerial.begin(9600);
  WiFi.init(&EspSerial);

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present!");
    while(true);
  }

  while(status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA with SSID: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
  }

  Serial.println("WiFi connection successful!");
}

void loop() {
  Serial.println();
  printCurrentNet();
  printWiFiData();

  delay(10000);
}

void printWiFiData() {
  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print your MAC address
  byte mac[6];
  WiFi.macAddress(mac);
  char buf[20];
  sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
  Serial.print("MAC address: ");
  Serial.println(buf);
}

void printCurrentNet() {
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to
  byte bssid[6];
  WiFi.BSSID(bssid);
  char buf[20];
  sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X", bssid[5], bssid[4], bssid[3], bssid[2], bssid[1], bssid[0]);
  Serial.print("BSSID: ");
  Serial.println(buf);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI): ");
  Serial.println(rssi);
}
