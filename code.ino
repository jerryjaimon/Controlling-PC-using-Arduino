const int trigger1 = 4; //Trigger pin of 2nd Sensor
const int echo1 = 5; //Echo pin of 2nd Senso
const int trigger2 = 7; //Trigger pin of 2nd Sensor
const int echo2 = 6; //Echo pin of 2nd Sensor
long time_taken;
int dist, distL, distR, l = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
}
//Function to calculate distance.Activates each sensor and returns distance
int calculate_distance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time_taken = pulseIn(echo, HIGH);
  dist = time_taken * 0.034 / 2;
  if (dist > 60)
    dist = 60;
  return dist;
}
void loop() {
  
  distL = calculate_distance(trigger1, echo1);
  distR = calculate_distance(trigger2, echo2);
  //Checks if distance is between 1 and 25.If not it skips to the last part where 2 is
  //printed to the serial monitor
        if (distR >= 1 && distR <= 25) {
          Serial.println("Right Locked");
          delay(500);
          calculate_distance(trigger2, echo2);
          distR = dist;
          if (distR >= 1 && distR <= 37) {
            int temp = dist;
            delay(200);
            while (distR <= 40) {
              delay(50);
              calculate_distance(trigger2, echo2);
              distR = dist;
              //Prints 4 if hand is held at a distance of less than 3 cm
              if (distR <= 3) {
                Serial.println("4");
                delay(200);
              }
              //Checks if hand is moving backward and prints 6
              else if ((temp + 6) < distR) {
                if (distR > 40) {
                  continue;
                }
                Serial.println("6");
                delay(400);
              }
              //Checks if hand is moving towards the computer
              else if ((temp - 2) > distR) {
                Serial.println("5");
                delay(400);
              }
            }
          }
          //If hand is kept stable for a second, then it prints 2
          else if (distR > 30) {
            Serial.println("2");
          }
        }
        delay(200);

        //Left Locked
        if (distL >= 1 && distL <= 25) {
          Serial.println("Left Locked");
          delay(500);
          calculate_distance(trigger2, echo2);
          distL = dist;
          if (distL >= 1 && distL <= 37) {
            int temp = dist;
            delay(200);
            while (distL <= 40) {
              delay(50);
              calculate_distance(trigger2, echo2);
              distL = dist;
              //Prints 4 if hand is held at a distance of less than 3 cm
              if (distL <= 3) {
                Serial.println("8");
                delay(200);
              }
              //Checks if hand is moving backward and prints 6
              else if ((temp + 6) < distR) {
                if (distL > 40) {
                  continue;
                }
                Serial.println("9");
                delay(400);
              }
              //Checks if hand is moving towards the computer
              else if ((temp - 2) > distR) {
                Serial.println("10");
                delay(400);
              }
            }
          }
          //If hand is kept stable for a second, then it prints 2
          else if (distL > 30) {
            Serial.println("8");
          }
        }
        delay(200);
}
