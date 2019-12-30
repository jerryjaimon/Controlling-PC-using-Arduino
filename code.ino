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
distM=mode(t1,e1);
delay(500);
Serial.println(distM);
}
