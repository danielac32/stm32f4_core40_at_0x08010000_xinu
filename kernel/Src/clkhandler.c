#include <kernel.h>
#include <interrupt.h>
#include <process.h>
 

/*-----------------------------------------------------------------------
 * clkhandler - high level clock interrupt handler
 *-----------------------------------------------------------------------
 */


void TIM2_Handler()
{ 
  TIM2->SR &= ~(1U << 0);
  if(ready_preemptive){
        
        
        /*if((--preempt) == 0) {
            preempt = QUANTUM;

            PEND_SV(); 
        } */
  } 
}


