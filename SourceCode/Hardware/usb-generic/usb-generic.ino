#include <usbdrv.h>

#define RQ_SET_LED    0
#define RQ_GET_SWITCH 1
#define RQ_GET_LIGHT  2
#define RQ_SET_SERVO  4


#include <Servo.h>
//////////////////////////////////////////////////////////////////////


Servo myservo;
int pos=0;


usbMsgLen_t usbFunctionSetup(uint8_t data[8])
{
  usbRequest_t *rq = (usbRequest_t*)data;
  static uint8_t switch_state[4];

  if (rq->bRequest == RQ_SET_LED)
  {
    uint8_t led_val = rq->wValue.bytes[0];
    uint8_t led_no  = rq->wIndex.bytes[0];

    if (led_no == 0)
      digitalWrite(PIN_PC0, led_val);
    else if (led_no == 1)
      digitalWrite(PIN_PC1, led_val);
    else if (led_no == 2)
      digitalWrite(PIN_PC2, led_val);

    return 0;  // return no data back to host
  }

  else if (rq->bRequest == RQ_GET_SWITCH)
    {
        switch_state[0] = digitalRead(PIN_PB0);
        switch_state[1] = digitalRead(PIN_PB1);
        switch_state[2] = digitalRead(PIN_PB4);
        switch_state[3] = digitalRead(PIN_PB5);

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = (char *)&switch_state;

        /* return the number of bytes of data to be returned to host */
        return 4;
    }


  else if (rq->bRequest == RQ_SET_SERVO)
  {
    uint16_t deg = rq->wValue.word;


    myservo.write(deg);
    Serial.println(deg);
    
  }

  return 0;   /* nothing to do; return no data back to host */
}




void swCheck();

//////////////////////////////////////////////////////////////////////
void setup()
{
    pinMode(PIN_PB0,INPUT_PULLUP);
    pinMode(PIN_PB1,INPUT_PULLUP);
    pinMode(PIN_PB4,INPUT_PULLUP);
    pinMode(PIN_PB5,INPUT_PULLUP);
    myservo.attach(PIN_PB2);
    //pinMode(PIN_PB2,OUTPUT);

    usbInit();

    /* enforce re-enumeration of USB devices */
    usbDeviceDisconnect();
    delay(300);
    usbDeviceConnect();
}

//////////////////////////////////////////////////////////////////////
void loop()
{
  //swCheck();
  usbPoll();
}
