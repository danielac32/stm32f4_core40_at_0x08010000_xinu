#include <kernel.h>
#include <interrupt.h>
#include <process.h>
#include <queue.h>


/*------------------------------------------------------------------------
 * clkinit  -  Initialize the clock and sleep queue at startup
 *------------------------------------------------------------------------
 */
uint32  clktime;        /* Seconds since boot           */
uint32  count1000;              /* ms since last clock tick             */
qid16   sleepq;         /* Queue of sleeping processes      */
uint32  preempt;        /* Preemption counter           */


void clkinit(void)
{
	
    
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->CR1 |= (1 << 2);
    TIM2->PSC = 0x7;
    TIM2->ARR = 0x1000;
    TIM2->DIER |= 0x1;
    //TIM2->CR1 |= (1 << 0);
    //NVIC_SetPriority(TIM2_IRQn, 3); // Priority level 2

    sleepq = newqueue();

    preempt = QUANTUM;  /* Set the preemption time      */
    clktime = 0;        /* Start counting seconds       */
    count1000 = 0;

    NVIC_EnableIRQ(TIM2_IRQn);

	return;
}
