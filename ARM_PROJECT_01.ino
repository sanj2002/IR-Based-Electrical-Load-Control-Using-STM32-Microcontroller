#include <IRremote.h>

const byte IR_RECEIVE_PIN = PB12;

#define RELAY1 PB8
#define RELAY2 PB9
#define RELAY3 PB6
#define RELAY4 PB7

void setup()
{
   Serial.begin(115200);
   Serial.println("IR Receive test");
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

   pinMode(RELAY1, OUTPUT);
   pinMode(RELAY2, OUTPUT);
   pinMode(RELAY3, OUTPUT);
   pinMode(RELAY4, OUTPUT);
}

void loop()
{
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);

      if(ir_code == "16")
        digitalWrite(RELAY1, HIGH);
      else if(ir_code == "c")
        digitalWrite(RELAY1, LOW);
      if(ir_code == "16")
        digitalWrite(RELAY2, HIGH);
      else if(ir_code == "18")
        digitalWrite(RELAY2, LOW);
      if(ir_code == "16")
        digitalWrite(RELAY3, HIGH);
      else if(ir_code == "8")
        digitalWrite(RELAY3, LOW);
      if(ir_code == "16")
        digitalWrite(RELAY4, HIGH);
      else if(ir_code == "5e")
        digitalWrite(RELAY4, LOW);
      
      IrReceiver.resume();
   }
}
