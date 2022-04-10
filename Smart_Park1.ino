// Arduino kod za Smart Parking
//
unsigned const int A = 13;
unsigned const int B = 12;
unsigned const int C = 11;
unsigned const int D = 10;
unsigned const int E = 9;
unsigned const int F = 8;
unsigned const int G = 7;
unsigned const int H = 6;

int Avi1 = 0;

int Avi2 = 0;

int Avi3 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(1, OUTPUT);
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  
   pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

//My Functions

void zero(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void one(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void two(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void three(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}



void loop()
{
  if (0.01723 * readUltrasonicDistance(46, 48) > 15) {
    digitalWrite(2, HIGH);
    Avi1 = 0;
    Serial.println("1.0");
  } else {
    if (0.01723 * readUltrasonicDistance(46, 48) < 15) {
      digitalWrite(2, LOW);
      Avi1 = 1;
      Serial.println("1.1");
    }
  }

  if (0.01723 * readUltrasonicDistance(50, 52) > 15) {
    digitalWrite(3, HIGH);
    Avi2 = 0;
    Serial.println("2.0");
  } else {
    if (0.01723 * readUltrasonicDistance(50, 52) < 15) {
      digitalWrite(3, LOW);
      Avi2 = 1;
     Serial.println("2.1");
    }
  }

  if (0.01723 * readUltrasonicDistance(A3, A3) > 15) {
    digitalWrite(5, HIGH);
    Avi3 = 0;
    Serial.println("3.0");
  } else {
    if (0.01723 * readUltrasonicDistance(A3, A3) < 15) {
      digitalWrite(5, LOW);
      Avi3 = 1;
      Serial.println("3.1");
    }
  }

  if (Avi1 == 0 && (Avi2 == 0 && Avi3 == 0)) {
    Serial.println("3");
    three();
  }
  if (Avi1 == 1 && (Avi2 == 0 && Avi3 == 0)) {
    Serial.println("2");
    two();
  }
  if (Avi1 == 0 && (Avi2 == 1 && Avi3 == 0)) {
    Serial.println("2");
    two();
  }
  if (Avi1 == 0 && (Avi2 == 0 && Avi3 == 1)) {
    Serial.println("2");
    two();
  }
  if (Avi1 == 1 && (Avi2 == 0 && Avi3 == 1)) {
    Serial.println("1");
    one();
  }
  if (Avi1 == 1 && (Avi2 == 1 && Avi3 == 0)) {
    Serial.println("1");
    one();
  }
  if (Avi1 == 0 && (Avi2 == 1 && Avi3 == 1)) {
    Serial.println("1");
    one();
  }
  if (Avi1 == 1 && (Avi2 == 1 && Avi3 == 1)) {
    Serial.println("0");
    zero();
  }
  delay(10); // Delay a little bit to improve simulation performance
}
