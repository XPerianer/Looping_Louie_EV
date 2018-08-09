// Constants

const int buttons[] = {0, 0, 0, 0};
const int powerswitch_pin = 0;

const int motor_pwm = 9;
const int motor_enable_one = 8;
const int motor_enable_two = 7;

const int motor_base_speed = 100;

void setup() {
  pinMode(powerswitch_pin, INPUT_PULLUP);
  for(int i=0;i<4;i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }
  pinMode(motor_pwm, OUTPUT);
  pinMode(motor_enable_one, OUTPUT);
  pinMode(motor_enable_two, OUTPUT);
  motor(0);
}

void loop() {
 while(!powerswitch()){
  delay(100);
  motor(0);
 }
 while(powerswitch()){
  int speed = motor_base_speed;
  for(int i=0;i<4;i++){
    if(pin(i)){
      speed = 255;
    }
  }

  motor(speed);
 }
}


// Library like functions

void motor(int speed){ // From -255 for full backwards to 255 to full forward (clamped otherwise)
  speed = max(min(255,speed),-255);
  if(speed == 0){
    digitalWrite(motor_pwm, LOW);
    digitalWrite(motor_enable_one, LOW);
    digitalWrite(motor_enable_two, LOW);
  } else if(speed > 0){
    analogWrite(motor_pwm, speed);
    digitalWrite(motor_enable_one, HIGH);
    digitalWrite(motor_enable_two, LOW);
  } else {// speed < 0
    analogWrite(motor_pwm, -speed);
    digitalWrite(motor_enable_one, LOW);
    digitalWrite(motor_enable_two, HIGH);
  }
}

bool pin(int number){
  if(digitalRead(buttons[number]) == LOW)
    return false;
   return true;
}

bool powerswitch(){
  if(digitalRead(powerswitch_pin) == LOW)
    return false;
   return true;
}
