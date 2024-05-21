#define channumber 6 //How many channels have your radio?
int channel[channumber]; //read Channel values
int PPMin = 4;

void setup()
{
  Serial.begin(9600); //Start serial
  pinMode(PPMin, INPUT); // Pin 4 as input
}

void readSignal(){
  if(pulseIn(PPMin , HIGH) > 4000){
    for(int i = 1; i <= channumber; i++){
      channel[i-1]=pulseIn(PPMin, HIGH);
    }
  }
}
void printSignal(){
  for(int i = 1; i <= channumber; i++){
    Serial.print("CH"); //Channel
    Serial.print(i); //Channel number
    Serial.print(": "); 
    Serial.print(channel[i-1]); //Print the value
    Serial.print("  ");
  }
  Serial.println();
}

void loop()
{
  readSignal();
  printSignal();
  delay(200);//Give time to print values.
}
