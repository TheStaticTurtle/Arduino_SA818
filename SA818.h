/*
  SA818.h - Library for controlling the SA818 RF Moules
  Created by TuerleForGaming.
  Shared under the GNU General Public License v3.0
*/

#ifndef SA818_h
#define SA818_h

#include "Arduino.h"

#define SA818_CONTACT_TIMEOUT 5000
#define SA818_SERBPS          9600

#define SA818_FILTER_EMPHASIS B100
#define SA818_FILTER_HIGHPASS B010
#define SA818_FILTER_LOWPASS  B001

class SoftwareSerial;

class SA818
{
  public:
    SA818(int RXpin, int TXpin, int ptt, int pd);
    void powerUp();
    void powerDown();
    void enableTX();
    void disableTX();
    void begin();
    bool handshake(bool forceCheck);
    bool setVolume(int volume);
    bool setFilter(int mix);
    bool setTailTone(bool value);
    int  readRSSI();
    void rawSend(String at);
  private:
    int _pinCHPD;
    int _pinPTT;
    int _RXpin;
    int _TXpin;
    bool _isTransmitting;
    SoftwareSerial* _rfSerial;
    void emptySerial();
};

#endif 
