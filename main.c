#include <stdint.h>

#define RCC_BASE       0x40021000
#define RCC_APB2ENR    (*(volatile uint32_t *)(RCC_BASE + 0x18))

#define GPIOC_BASE    0x40011000
#define GPIOC_CRH     (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_BSRR    (*(volatile uint32_t *)(GPIOC_BASE + 0x10))

#define LED_PIN        13
#define LED_ON         (1 << LED_PIN)
#define LED_OFF        (1 << (LED_PIN + 16))

void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__("nop");
    }
}

int main(void)
{
    RCC_APB2ENR |= (1 << 4);

    GPIOC_CRH &= ~(0xF << ((LED_PIN - 8) * 4));
    GPIOC_CRH |=  (0x2 << ((LED_PIN - 8) * 4));

    for (;;) {
        GPIOC_BSRR = LED_ON;
        delay(500000);
        GPIOC_BSRR = LED_OFF;
        delay(500000);
    }

    return 0;
}