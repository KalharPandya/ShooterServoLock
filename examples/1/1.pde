#include <ShooterServoLock.h>

ServoLock shooter(26, 27);

void upFeedback(){
  Serial.println("Locked");
}
void setup(){
    Serial.begin(115200);
    shooter.attachServoUpFeedback(upFeedback);
}


void loop(){
  delay(2000);
    shooter.lock();
    delay(2000);
    shooter.unlock();
}