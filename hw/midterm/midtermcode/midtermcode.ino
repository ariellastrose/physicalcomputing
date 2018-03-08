  int ledPin = 13;
  int inputPin = 2;
  int pirState = LOW;
  int val = 0;
//color changing light
  int redPin = 11;
  int greenPin = 10;
  int bluePin = 9;
  int interval;
  boolean startTimer = false;
  int counter = 0;
  //int r = [];
  
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);

  Serial.begin(9600);

  //colorchanging LED

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  Serial.println(val);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW) {
      Serial.println("Motion detected");
     pirState = HIGH;
     if(startTimer == false){
           startTimer = true;
     }
     
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("No motion detected");
     pirState = LOW;
    }
  }

  if (startTimer == true){

    //millis timmer
     //counter++
    if (millis () - startTimer >= interval) {
      counter++;
    }
    //if counter > length of my array items startTimer = false
    if (counter > length.array) {
      startTimer = false; 
    }
    
    //outside of millis
    //setColor(r[counter],g[counter],b[counter]);

    setColor(r[counter], g[counter], b[counter]);
  }

  

//  //colorchanging LED
//  setColor(150, 66, 81);
//  delay(1000);
//  setColor(150, 66, 81);
//  delay(1000);
//  setColor(212, 183, 235);
//  delay(1000);
//  setColor(87,133, 159);
//  delay(1000);
//  setColor(132, 190, 113);
//  delay(1000);

}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
//Basic PIR sensor tester code from Adafruit
