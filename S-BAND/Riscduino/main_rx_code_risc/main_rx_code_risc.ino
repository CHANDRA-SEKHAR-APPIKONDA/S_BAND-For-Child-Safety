#include <SPI.h> //Including SPI protocol library for wireless communication using NRF modules
//#include <Tone.h>  //Including buzzer library
#include <nRF24L01.h> //Including NRF module library
#include <RF24.h>
//Tone buzzer;
RF24 radio(9,10); // CE, CSN pins
unsigned long lastHeartbeatMillis = 0; // Store the time of the last received heartbeat
const unsigned long heartbeatTimeout = 5000; // Timeout for considering the device not alive (5 seconds)

const int buzzerPin = 5; // Buzzer pin
const int led = 4; //Led pin
void setup() {
  
  pinMode(led, OUTPUT); //Pinmode of led
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT); //Pinmode of buzzer
  //buzzer.begin(buzzerPin);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0E1LL); // Receiving address of the sender module
  radio.setPALevel(RF24_PA_HIGH); //Power amplifier level
  radio.startListening(); //Enable receive mode
}

void loop() {
  
  if (radio.available()) {
      unsigned long currentMillis = millis(); //present time at the time of receiving heart beat signal
      unsigned long timeSinceLastPacket = currentMillis - lastHeartbeatMillis; //checking the time duration between present and past heart beat signals

  // Estimate RSSI based on the time elapsed
      int8_t rssi = estimateRssi(timeSinceLastPacket);
      int signal = 0;
      radio.read(&signal, sizeof(signal)); // Read the received signal

    if (signal == 0x66) {
      Serial.println("your chid is safe"); // Received the heartbeat signal
      Serial.print("RSSI VALUE :");
      Serial.println(rssi); //monitoring rssi values
      if(rssi > -14)
      {Serial.println("SAFE ZONE");} //It means your child below 0-30metres
      else
      {Serial.println("ALERT ZONE");} //It means your child crossing above 30 metres
      lastHeartbeatMillis =millis(); // Update the time of the last received heartbeat
      digitalWrite(led,1);  //If your child in range then LED starts blinking with respect to data packets it received
      delay(150); //synchronised dealy with the data packet (heart beat signal)
      digitalWrite(led,0); 
      delay(1000);


    }
  }

  // Check if the device is not alive based on the timeout
  unsigned long currentMillis = millis(); 
  if (currentMillis - lastHeartbeatMillis >= heartbeatTimeout) //Here if there is time delay between present and past heart beat signal it indicates signal strenghts are decreasing means child going out of range
   {
    unsigned long timeSinceLastPacket = currentMillis - lastHeartbeatMillis;
    int8_t rssi = estimateRssi(timeSinceLastPacket);
    Serial.println("ALERT : your chid is going out of radius");
    Serial.println("DANGER ZONE"); //Alert showing in serial monitor
    Serial.println(rssi);
    digitalWrite(led,1); // Turn of the led
    // Sound the buzzer to indicate a non-responsive device
    digitalWrite(buzzerPin,1);
    delay(1000);
    digitalWrite(buzzerPin,0);
    //buzzer.play(2500, 250); // Frequency in Hz, Duration in milliseconds
    delay(1000); // Buzzer on for 1 second
  }
}
int8_t estimateRssi(unsigned long timeSinceLastPacket) {
  return -int8_t(timeSinceLastPacket / 90); // Adjust the divisor as needed considering our surroundings
}




