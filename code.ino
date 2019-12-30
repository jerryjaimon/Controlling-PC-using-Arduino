const int t1 = 13;
const int e1 = 12;
int t;
float distM;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

int mode(int trigger, int echo)
{
  int dist=0;
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigger, LOW);
  t=pulseIn(echo,HIGH); 
  dist=t*0.034/2;
  if(dist>50)
    dist=50;
  return dist;
}
void loop() {
  int count=0;
  distM=mode(t1,e1);
  //Middle Ultrasonic sensor
  if (distM<20 && distM>1)
    {
    
      while(1){
      Serial.println("Change window");
      delay(500);
      distM=mode(t1,e1);
      if(distM<1 || distM>20)
        {Serial.println("Enter");
        break;}
      else  
        continue;}
    }

  else if(distM>20 && distM <30)
    {
      for(int i=0;i<4;++i)
       {
        count+=1;
        if(count>=3)
          {Serial.println("Close");
          count=0;}
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        distM=mode(t1,e1);
        if(distM<20 || distM>30)
          {Serial.println("Broke");
          digitalWrite(LED_BUILTIN,LOW);
          break;
          }
        digitalWrite(LED_BUILTIN,LOW);
       }
     }
    delay(1000);
}
