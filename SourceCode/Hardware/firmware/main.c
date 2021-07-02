#include <avr/io.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */

#include "peri.h"
#include "usbdrv.h"

#define RQ_SET_LED         0  //set LED
#define RQ_SET_LED_VALUE   1  //set 3 LED in binary
#define RQ_GET_SWITCH      2  //read sw
#define RQ_GET_LIGHT       3  //read light

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */
usbMsgLen_t usbFunctionSetup(uint8_t data[8])
{
    usbRequest_t *rq = (void *)data;

    /* declared as static so they stay valid when usbFunctionSetup returns */
    static uint8_t switch_state[4];  
    static uint16_t light_value;

    if (rq->bRequest == RQ_SET_LED)
    {
        uint8_t led_val = rq->wValue.bytes[0];  //write(host->device)
        uint8_t led_no  = rq->wIndex.bytes[0];
        set_led(led_no, led_val);
        return 0;
    }

    else if (rq->bRequest == RQ_SET_LED_VALUE)
    {
        uint8_t led_value = rq->wValue.bytes[0];  //read(device->host)
        set_led_value(led_value);
        return 0;
    }

    else if (rq->bRequest == RQ_GET_SWITCH)
    {
        switch_state[0] = SWITCH_PRESSED(PB0);
        switch_state[1] = SWITCH_PRESSED(PB1);
        switch_state[2] = SWITCH_PRESSED(PB4);
        switch_state[3] = SWITCH_PRESSED(PB5);

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 4;
    }

    else if (rq->bRequest == RQ_GET_LIGHT)
    {
        light_value = read_adc(PC4);
        usbMsgPtr = (uchar*) &light_value;
        return sizeof(light_value);
    }

    /* default for not implemented requests: return no data back to host */
    return 0;
}

/* ------------------------------------------------------------------------- */
int main(void)
{
    init_peri();
    usbInit();

    /* enforce re-enumeration, do this while interrupts are disabled! */
    usbDeviceDisconnect();
    _delay_ms(300);
    usbDeviceConnect();

    /* enable global interrupts */
    sei();

    /* main event loop */
    for(;;)
    {
        usbPoll();
    }

    return 0;
}

/* ------------------------------------------------------------------------- */
