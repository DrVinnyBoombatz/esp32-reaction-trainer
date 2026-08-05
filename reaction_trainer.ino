const int BUTTON_PIN = 4;
const int LED_BUILTIN = 26;
bool LED = false;
bool trackLED = false;
bool gameover = false;
unsigned long time_on = 0;
unsigned long time_for_reaction = 0;
unsigned long time_off = 0;
unsigned long time_since_off = 0;
unsigned long interval = 0;
unsigned long times_button_is_pressed = 0;
unsigned long total_reactiontime = 0;
void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);
  pinMode(26, OUTPUT);
  interval = random(1000,5000);}
void loop() {
if (gameover == true) return;
  time_since_off = millis() - time_off;
    if (time_since_off >= interval and trackLED == false)
      {LED = true;
      trackLED = true;
      time_on = millis();};
      if (trackLED == true)
      {       
      if (LED == (true) and (trackLED == true))
            {digitalWrite(26, HIGH);}
            if (digitalRead(BUTTON_PIN) == LOW)
              {LED = (false);
              trackLED = (false);
            digitalWrite(26, LOW);
            time_off = millis();
            times_button_is_pressed += 1;
            Serial.println(times_button_is_pressed);
            interval = random(1000,7000); 
              Serial.println("Button Pressed!");
                delay(300);
                time_for_reaction = time_off - time_on;
                String mms = "mms";
                String xy = "Your reaction time:";
                Serial.println(xy+time_for_reaction+mms);
                total_reactiontime += (time_for_reaction);
                if (times_button_is_pressed == 5)
                {gameover = true;
                if (gameover == true)
                {String avgtime = "Your average reaction time is:";
                  Serial.println("Game Over");
                  Serial.println(avgtime+(total_reactiontime/times_button_is_pressed)+mms);}}
              }
      }           
    else
     {LED = false;
     trackLED = false;
      if (LED == (false))
        {digitalWrite(26, LOW);}}}
