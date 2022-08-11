//Directivas 
#include <16f887.h>

#fuses xt, nowdt
#use delay(clock=4M)
#include <lcd.c>

#byte TRISC   = 0x87
#byte TRISB   = 0x86
#byte PORTC = 0x07
#byte TRISA   =  0x85
#byte PORTA = 0x05

#byte OP_REG = 0x81
#byte WPUB    =  95

#bit RBO = 0x06.0
#bit RB1  = 0x06.1
#bit RB2  = 0x06.2
#define LCD_DATA_PORT getenv("SFR:PORTC")

int main() {
    
    TRISC   = 0x00;       //Puerto C como salidas
    TRISB   = 0xFF;       //Puerto B como entrada 
    PORTC = 0x00;    //Puerto C a nivel bajo 
    lcd_init();
    
    TRISA   = 0x00;      //Puerto A como salida
    PORTA = 0x00;    //Puerto A en nivel bajo
    
    //OP_REG = 0b00000000; //Activo el ~RBUP
    OP_REG = 0b00000001;
    WPUB    = 0xFF;   //los pull-up de r0,r1,r2 estan configurados
    lcd_cursor_on(TRUE);
    lcd_gotoxy(1,1);
    
    while(1)
    {
        if(!RBO){
            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc, "LED 1");
            PORTA= 0b00000001;
            //delay_ms(1000);
        }
        else if(!RB1){
            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc, "LED 2");
            PORTA= 0b000000010;
            //delay_ms(1000);
        }
        else if(!RB2){
            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc, "LED 3");
            PORTA= 0b000000100;
            //delay_ms(1000);
        }
    }
    return (0);
}

