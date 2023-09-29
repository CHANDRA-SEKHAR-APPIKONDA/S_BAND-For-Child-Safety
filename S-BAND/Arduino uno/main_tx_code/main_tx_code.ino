#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8); // CE, CSN pins 
unsigned long int previousMillis = 0; // Store the last time a heartbeat signal was sent
const unsigned long int heartbeatInterval = 1000; // Send a heartbeat signal every 1 seconds

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0E1LL); // Set the receiving address of the receiver module
  radio.setPALevel(RF24_PA_HIGH); // Set the power amplifier level
  radio.stopListening(); // Put the radio in transmit mode6
}

void loop() {
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= heartbeatInterval) {
    sendHeartbeatSignal(); // Send the heartbeat signal
    previousMillis = currentMillis;
  }


  if (currentMillis - previousMillis >= heartbeatInterval) {
    sendHeartbeatSignal(); // Send the heartbeat signal
    previousMillis = currentMillis;
  }
}
// Function to send the heartbeat signal
void sendHeartbeatSignal() {
  uint8_t signal = 0x66; // You can use any value to represent the heartbeat signal
  radio.write(&signal, sizeof(signal)); // Send the heartbeat signal
}