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

#define SA818_VHF             1
#define SA818_UHF             2

#define SA818_FILTER_EMPHASIS B100
#define SA818_FILTER_HIGHPASS B010
#define SA818_FILTER_LOWPASS  B001
#define SA818_BW_12_5k        0
#define SA818_BW_25k          1

class SoftwareSerial;

class SA818
{
  public:
    SA818(int model,int RXpin, int TXpin, int ptt, int pd);
    void powerUp();
    void powerDown();
    void enableTX();
    void disableTX();
    void begin();
    bool handshake(bool forceCheck);
    bool setVolume(int volume);
    bool setFilter(int mix);
    bool setTailTone(bool value);

    bool setTXFrequency(float value);
    bool setRXFrequency(float value);
    bool setBandwidth(int value);
    bool setRX_CTCSS(char value[4]);
    bool setTX_CTCSS(char value[4]);

    bool applyConfig();
    void printConfig();
    
    int  readRSSI();
    void rawSend(String at);
  private:
    int   _pinCHPD;
    int   _pinPTT;
    int   _RXpin;
    int   _TXpin;
    bool  _isTransmitting;
    int   _ModuleVersion;
    float _CONF_TXfreq    = 433.9000;
    float _CONF_RXfreq    = 433.9000;
    int   _CONF_bandwidth = SA818_BW_25k;
    int   _CONF_squeltch  = 4;
    char*  _CONF_TXCTCSS  = "0000";
    char*  _CONF_RXCTCSS  = "0000";

    SoftwareSerial* _rfSerial;
    void emptySerial();
};

#endif 
