const int buttonPin1 = 1;  // Pin za tipko b1
const int buttonPin2 = 2  ;  // Pin za tipko b2
const int buttonPin3 = 4;  // Pin za tipko b3
const int buttonPin4 = 5;  // Pin za tipko b4

const int ledPin1 = 6;  // Pin za LED 1
const int ledPin2 = 7;  // Pin za LED 2

bool led1State = false;  // Stanje LED 1
bool led2State = false;  // Stanje LED 2

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Branje stanja tipk
  bool button1State = digitalRead(buttonPin1);
  bool button2State = digitalRead(buttonPin2);
  bool button3State = digitalRead(buttonPin3);
  bool button4State = digitalRead(buttonPin4);

  // Krmiljenje LED 1
  if (button1State == HIGH) {
    led1State = true;
    led2State = false;
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }

  // Krmiljenje LED 2
  if (button2State == LOW) {
    led1State = false;
    led2State = true;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }

  // Ugasnitev LED 1 in LED 2
  if (button3State == HIGH) {
    led1State = false;
    led2State = false;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  // Zamenjava stanja LED 1 in LED 2
  if (button4State == HIGH) {
    if (led1State && !led2State) {
      led1State = false;
      led2State = true;
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
    } else if (!led1State && led2State) {
      led1State = true;
      led2State = false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }
  }
}
