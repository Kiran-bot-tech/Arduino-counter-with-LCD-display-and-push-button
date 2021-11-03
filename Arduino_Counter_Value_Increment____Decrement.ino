

#include <LiquidCrystal.h>  //Library LiquidCrystal


const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int  Up_buttonPin   = 2;
const int  Down_buttonPin = 3;

int buttonPushCounter = 0;    // counter for the number of button presses
int up_buttonState = 0;       // current state of the up button
int up_lastButtonState = 0;   // previous state of the up button

int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button
bool bPress = false;


void setup()
{
  Serial.begin(9600);
  pinMode( Up_buttonPin , INPUT_PULLUP);
  pinMode( Down_buttonPin , INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Counter Value:");
  lcd.setCursor(2, 1);
  lcd.print(buttonPushCounter);
}
void loop()
{
  checkUp();
  checkDown();

  if ( bPress)
  {
    bPress = false;
    lcd.setCursor(2, 1);
    lcd.print("               ");
    lcd.setCursor(2, 1);
    lcd.print(buttonPushCounter);
  }
}
void checkUp()
{
  up_buttonState = digitalRead(Up_buttonPin);
  if (up_buttonState != up_lastButtonState)    // compare the buttonState to its previous state
  {
    if (up_buttonState == LOW)   // if the state has changed, increment the counter
    {
      bPress = true;  // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    }
    else {
      Serial.println("off"); // if the current state is LOW then the button went from on to off:
    }
    delay(50);  // Delay a little bit to avoid bouncing
  }

  up_lastButtonState = up_buttonState;   // save the current state as the last state, for next time through the loop
}

void checkDown()
{
  down_buttonState = digitalRead(Down_buttonPin);
  if (down_buttonState != down_lastButtonState)  // compare the buttonState to its previous state
  {
    if (down_buttonState == LOW)   // if the state has changed, increment the counter
    {
      bPress = true;
      buttonPushCounter--;  // if the current state is HIGH then the button went from off to on:
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");  // if the current state is LOW then the button went from on to off:
    }
    delay(50);            // Delay a little bit to avoid bouncing
  }
  down_lastButtonState = down_buttonState;  // save the current state as the last state, for next time through the loop

}
