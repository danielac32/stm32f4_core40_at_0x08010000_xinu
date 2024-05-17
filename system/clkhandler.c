#include <kernel.h>
#include <interrupt.h>
#include <process.h>
 

/*-----------------------------------------------------------------------
 * clkhandler - high level clock interrupt handler
 *-----------------------------------------------------------------------
 */

//void __attribute__ ((naked)) clkhandler()



void TIM2_Handler()
{ 
  TIM2->SR &= ~(1U << 0);
  //sys_time += 1;
  /*if(ready_preemptive){
        
        
        if((--preempt) == 0) {
            preempt = QUANTUM;

            PEND_SV(); 
        } 
  } */
}


