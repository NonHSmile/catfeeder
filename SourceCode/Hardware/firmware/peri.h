#define SWITCH_PRESSED(x) ((PINB& (1<<x)) == 0)

void init_peri();
void set_led(uint8_t pin, uint8_t state);
void set_led_value(uint8_t value);
uint16_t read_adc(uint8_t channel);
