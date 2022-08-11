//Directivas 
#include <16f887.h>

#fuses xt, nowdt
#use delay(clock=4M)
#include <lcd.c>

#byte TRISC = 0x87
#byte TRISB = 0x86
#byte PORTC = 0x07

#byte OP_REG = 0x81
#byte WPUB =  95

int main() {
    lcd_init();
    TRISC = 0x00; //Puerto C como salidas
    TRISB = 0xFF; //Puerto B como entrada 
    PORTC = 0x00;   //Puerto C a nivel bajo 
    OP_REG = 0b00000000; //Activo el ~RBUP
    WPUB =    0b00000111;   //los pull-up de r0,r1,r2 estan configurados
    
    while(1)
    {
        lcd_cursor_on(TRUE);
        //printf(lcd_putc, 'lol');
    }
    return (0);
}

