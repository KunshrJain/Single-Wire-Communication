class Single_Wire_Comms {
  private:

    int KJTP[39][6] = {
      {0,0,0,0,0,0}, {0,0,0,0,0,1}, {0,0,0,0,1,0}, {0,0,0,0,1,1},
      {0,0,0,1,0,0}, {0,0,0,1,0,1}, {0,0,0,1,1,0}, {0,0,0,1,1,1},
      {0,0,1,0,0,0}, {0,0,1,0,0,1}, {0,0,1,0,1,0}, {0,0,1,0,1,1},
      {0,0,1,1,0,0}, {0,0,1,1,0,1}, {0,0,1,1,1,0}, {0,0,1,1,1,1},
      {0,1,0,0,0,0}, {0,1,0,0,0,1}, {0,1,0,0,1,0}, {0,1,0,0,1,1},
      {0,1,0,1,0,0}, {0,1,0,1,0,1}, {0,1,0,1,1,0}, {0,1,0,1,1,1},
      {0,1,1,0,0,0}, {0,1,1,0,0,1}, {0,1,1,0,1,0}, {0,1,1,0,1,1},
      {0,1,1,1,0,0}, {0,1,1,1,0,1}, {0,1,1,1,1,0}, {0,1,1,1,1,1},
      {1,0,0,0,0,0}, {1,0,0,0,0,1}, {1,0,0,0,1,0}, {1,0,0,0,1,1},
      {1,0,0,1,0,0}, {1,0,0,1,0,1}
    };

    char KJIP[39] = {
      '0','1','2','3','4','5','6','7','8','9',
      'a','b','c','d','e','f','g','h','i','j',
      'k','l','m','n','o','p','q','r','s','t',
      'u','v','w','x','y','z',' ','\n'
    };

    uint8_t RTX_PIN;
    uint8_t ledpin;

    void sendChar(char c) {
      pinMode(RTX_PIN,OUTPUT);
      for (int i = 0; i < 39; i++) {
        if (KJIP[i] == c) {
          int* bits = KJTP[i];
          Serial.print(c);
          for (int j = 0; j < 6; j++) {
            digitalWrite(23, HIGH); 
            delay(10);

            digitalWrite(23, bits[j] ? HIGH : LOW); 
            delay(100);

            digitalWrite(23, LOW); 
            delay(100);
          }
          return;
        }
      }

      Serial.print("Character not supported: ");
      Serial.println(c);
    }

    void receive() {
      pinMode(RTX_PIN, INPUT);
      uint8_t msg[6];
      bool sent=1;
      bool rec=1;
      while (1) {
        for (int i = 0; i < 6; i++) {
          while (digitalRead(RTX_PIN) != HIGH){
            if (Serial.available()) {
              if (sent){
                Serial.print("Sending-> ");
                sent=0;
              }
              char c = Serial.read();
              sendChar(c);
              delay(1000);  
            }
          }

          delay(50);  

          // Read actual bit
          msg[i] = digitalRead(RTX_PIN);

          // Wait for bit to end (optional)
          delay(100);
        }

        // Decode bits into character
        bool matched = false;
        for (int j = 0; j < 39; j++) {
          bool match = true;
          for (int k = 0; k < 6; k++) {
            if (msg[k] != KJTP[j][k]) {
              match = false;
              break;
            }
          }


          if (match) {
            Serial.print(KJIP[j]);
            matched = true;
            break;
          }
        }

        if (!matched) {
          Serial.println("Unknown pattern received.");
        }


        break; 
      }
    }



  public:
    void initialize(uint8_t pin, uint8_t lp, uint32_t baud_rate) {
      RTX_PIN = pin;
      ledpin = lp;
      Serial.begin(baud_rate);
      Serial.println("Receiver Mode");
    }

    void start() {
      receive();
    }
};
