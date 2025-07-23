const int sensPin = 3;   
const int ledPin = 2;         
const int clapInterval = 500;   
const int debounceDelay = 200; 

unsigned long lastClap = 0;   
int clapCount = 0;              
bool ledState = false;          

void setup() {
  Serial.begin(9600);
  pinMode(sensPin, INPUT);      
  pinMode(ledPin, OUTPUT);     
  digitalWrite(ledPin, LOW);   
  Serial.println("System ready. One clap to turn LED ON, two claps to turn OFF.");
}

void loop() {
  if (digitalRead(sensPin) == HIGH) {
    unsigned long currentTime = millis();

    if (currentTime - lastClap > debounceDelay) {
      clapCount++;
      Serial.print("Clap detected: ");
      Serial.print(clapCount);
      Serial.println(" Count");

      if (clapCount == 1) {
        ledState = true;
        digitalWrite(ledPin, HIGH);
        Serial.println("LED ON");
      } else if (clapCount == 2 && currentTime - lastClap <= clapInterval) {
        ledState = false;
        digitalWrite(ledPin, LOW);
        Serial.println("LED OFF");
        clapCount = 0;
      }

      lastClap = currentTime;
    }

    while (digitalRead(sensPin) == HIGH && millis() - lastClap < debounceDelay) {
    }
  }

  if (clapCount > 0 && millis() - lastClap > clapInterval) {
    if (clapCount < 2) {
      Serial.println("Incomplete clap sequence. Resetting.");
    }
    clapCount = 0;
  }
}