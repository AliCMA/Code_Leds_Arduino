#define ledR 9      // Hier connect ik de dgitale pin naar vak-9 op de arduino
#define ledG 6      // Hier connect ik de dgitale pin naar vak-6 op de arduino
#define ledB 3      // Hier connect ik de dgitale pin naar vak-3 op de arduino
#define buttonPin 2  //  Hier connect ik de dgitale pin van de button naar vak-2 op de arduino

//Dit zijn de begin waardes van deze variabelen, doorde -1 bij de colorstate staat de led strips in het begin voor het klikken op de knop uit. 
int previousButtonStateOn = 0;
int buttonState = 1;//
int colorState = -1; //

void setup() {
  //De eerste drie codes hieronder, zijn bedoeld voor de ledstrip kleuren. 
  pinMode(ledR , OUTPUT); 
  pinMode(ledG , OUTPUT); 
  pinMode(ledB , OUTPUT); 
  pinMode (buttonPin, INPUT_PULLUP); // sets te pin as input

  //Dit stuk code zorgt ervoor dat alles in het begin uit staat
  analogWrite(ledR , 255); 
  analogWrite(ledG , 255); 
  analogWrite(ledB , 255); 
}


void loop() {
  // Eerst hebben we een variabelen Button state en daarna een digitale read van ButtonPin, dus elk keer als de knop ingedrukt word komt er een +1 waarde erbij en de %3 is omdat, wij 3 verschillende kleuren hebben. 
  int buttonState = digitalRead(buttonPin);
  if(buttonState != previousButtonStateOn){
    previousButtonStateOn = buttonState;
    if(previousButtonStateOn == 1){
         colorState++;
         colorState%=3;
    }
  }

//Deze onderstaande swtich codes zorge ervoor, wanneer de knop word ingedrukt, de waarde naar 0, 1 of 2 gaat en dan de bijhorende kleuren te voorschijn komen op de led strip. 
switch (colorState) {
  case 0: 
    analogWrite(ledR , 0); 
    analogWrite(ledG , 255); 
    analogWrite(ledB , 255 ); 
    break;
  case 1:
    analogWrite(ledR , 255); 
    analogWrite(ledG , 0); 
    analogWrite(ledB , 255 ); 
    break;
  case 2:
    analogWrite(ledR , 255); 
    analogWrite(ledG , 255); 
    analogWrite(ledB , 0 );  
    break;
  default:
    analogWrite(ledR , 255); 
    analogWrite(ledG , 255); 
    analogWrite(ledB , 255);
    break;
}  
}
