#include <stdarg.h>
#include <kernel.h>
#include <stdint.h>
#include <stdio.h>
#include <interrupt.h>
#include <string.h>
#include <syscall.h>

#include <usb_cdc_conf.h>

extern  void _doprnt(char *, va_list, int (*)(int));

 
int lib_putc(int ch)
{

  uint32 q = irq_disable();//
  while(1){
      int len = usbd_ep_write(&udev, CDC_TXD_EP, &ch, 1);
      if (len < 0){
          continue;
      }else break;
  }
  //putchar(ch);
  irq_restore(q);//

  return OK;
}

int lib_puts(char *str, int size)
{
 
  syscall(XINU_PUTS,str,size);

  return OK;
}



/*
uint32 kprintf(char *fmt, ...)
{
  va_list ap;
  char output[81];
  char *c;

  memset(output, 0, 81);
  va_start(ap, fmt);
  vsnprintf(output, 80, fmt, ap);
  va_end(ap);

  c = output;
  while(*c) {
    lib_putc(*c);
    c++;
  };

        return OK;
}*/

uint32 kprintf(const char *fmt, ...){

   va_list ap; 
 
   va_start(ap, fmt);
   _doprnt((char *)fmt, ap, lib_putc);
   va_end(ap);
 
   return OK;
}
