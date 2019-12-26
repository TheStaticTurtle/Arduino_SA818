#include <SA818.h>

#define SA818_PD  9
#define SA818_PTT 8
#define SA818_RX  10
#define SA818_TX  11

SA818 intercom(SA818_UHF, SA818_RX, SA818_TX, SA818_PTT, SA818_PD);

void block() { for(;;) {} }

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  Serial.println("intercom.begin()");
  intercom.begin();
  
  Serial.print("intercom.powerUp(): ");
  intercom.powerUp();
  Serial.println("done");
  
  Serial.print("intercom.handshake(): ");
  if(intercom.handshake(true)) {
    Serial.println("ok");
  } else {
    Serial.println("failed");
    block();
  }

  Serial.print("intercom.applyConfig(): ");
  intercom.setTXFrequency(433.9250);
  intercom.setRXFrequency(433.9250);
  intercom.setBandwidth(SA818_BW_25k);
  intercom.setRX_CTCSS("0000");
  intercom.setTX_CTCSS("0000");
  intercom.printConfig();
  intercom.applyConfig() ? Serial.println("ok") : Serial.println("failed");
  delay(100);
  
  intercom.setVolume(8);
  delay(100);
  intercom.setFilter(SA818_FILTER_HIGHPASS | SA818_FILTER_LOWPASS | SA818_FILTER_EMPHASIS);
  delay(100);
  intercom.setTailTone(false);
  delay(100);
  
  delay(1000);
  intercom.enableTX();
  delay(2000);
  intercom.disableTX();
  Serial.println("loop();");
}

void loop() {
  delay(10);
  Serial.println(intercom.readRSSI());
}