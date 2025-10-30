#include "stm32f4xx.h"   // CMSIS header for device definitions
#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)
#define GPIOD_MODER   (*(volatile unsigned int*)0x40020C00)
#define GPIOD_ODR     (*(volatile unsigned int*)0x40020C14)

void delay(void);

int main(void)
{
    // 1️⃣ Enable clock for GPIOD (bit 3)
    RCC_AHB1ENR |= (1 << 3);

    // 2️⃣ Configure PD13 as output mode (bits 27:26 = 01)
    //GPIOD_MODER &= ~(3 << 26);   // Clear bits 27 and 26
    //GPIOD_MODER |=  (1 << 26);   // Set bit 26 -> output mode
	GPIOD_MODER &= ~(0xFF << 24);  // clear bits for PD12–PD15
	GPIOD_MODER |=  (0x55 << 24);  // set output mode for PD12–PD15
	//GPIOD_ODR ^= (0xF << 12);      // toggle bits 12–15


    // 3️⃣ Infinite loop to toggle LED
    while (1)
    {
        //GPIOD_ODR ^= (1 << 13);  // Toggle bit 13
    	GPIOD_ODR ^= (0xF << 12);      // toggle bits 12–15
        delay();                 // crude delay
    }
}

// 4️⃣ Simple software delay
void delay(void)
{
    for (volatile int i = 0; i < 500000; i++);  // Adjust for blink speed
}
