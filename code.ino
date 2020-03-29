
const int trigger2 = 7; //Trigger pin of 2nd Sesnor
const int echo2 = 6;//Echo pin of 2nd Sesnor
long time_taken;
int dist,distL,distR,l=0;
 
void setup() {
    Serial.begin(9600); 
    pinMode(trigger2, OUTPUT); 
    pinMode(echo2, INPUT); 
}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    time_taken = pulseIn(echo, HIGH);
    dist= time_taken*0.034/2;
    if (dist>60)
    dist = 60;
}

void loop() { 
    calculate_distance(trigger2,echo2);
    distR =dist;

    //Lock Right - Control Mode
    if (distR>=1 && distR<=25)
    {
        delay(500); //Hand Hold Time
        calculate_distance(trigger2,echo2);
        distR =dist;
      if (distR>=1 && distR<=37)
      {
        int temp=dist;
        delay(200);
        //Serial.println("Right Locked");
        
        while(distR<=40)
        {
          delay(50);
          calculate_distance(trigger2,echo2);
          distR =dist;
          if(distR<=3)
             {
              Serial.println("4");
              delay(200);
            }  
          else if((temp+6)<distR)                // this condition becomes true if we moves our hand away from the right sensor (**but in front of it ). here " temp+6 " is for calibration.
            {
              if(distR>40)
                {
                  continue;
                }
              Serial.println("6");
              delay(400);
            }
          else if((temp-2)>distR)           // this condition becomes true if we moves our hand closer to the right sensor.
            {
              Serial.println("5");                // send "up" serially.
              delay(400);
            }
          }
      }
      
      else if( distR>30)
          {Serial.println("2");}  
    }

    delay(200);
}
