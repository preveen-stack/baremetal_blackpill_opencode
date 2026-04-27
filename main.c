#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)0x40021030)
#define GPIOC_MODER (*(volatile uint32_t *)0x40011000)
#define GPIOC_ODR   (*(volatile uint32_t *)0x4001100C)

void delay(void)
{
    volatile uint32_t i;
    for (i = 0; i < 500000; i++);
}

int main(void)
{
    RCC_AHB1ENR = 0x00000004;
    GPIOC_MODER = 0xA8000000;
    GPIOC_ODR = 0x00002000;

    while (1) {
        GPIOC_ODR = 0xFFFFDFFF;
        delay();
        GPIOC_ODR = 0x00002000;
        delay();
    }
}