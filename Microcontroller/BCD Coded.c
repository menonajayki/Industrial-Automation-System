#include <stdio.h>
8
void bcd(int number, char *digit, char *digittwo);
void __attribute__ ((__interrupt__, auto_psv)) _T1Interrupt(void);
void Seven_Seg_Config();
void Timer_Config();
char Pin_Toggle (char a);
cha Counter = 0;
int digit[] = [0,0,0,0]
int digittwo[] = [0,0,0,0]
int main()
{
 char number=92;
 bcd(number, digit, digittwo);
 Seven_Seg_Config();
 Timer_Config();
 return 0;
}
void bcd(number, char *digit, char *digittwo)
{
 char firstDigit = number / 10;
 for (int i = 0; i < 4; i++)
 {
 digit[i] = (firstDigit & 0x8) ? 1 : 0;
 firstDigit = firstDigit << 1;
 }
 char secondDigit = number % 10;
 for (int i = 0; i < 4; i++)
 {
 digittwo[i] = (secondDigit & 0x8) ? 1 : 0;
 secondDigit = secondDigit << 1;
 }
}
void Seven_Seg_Config()
{
 TRISBbits.TRISB3 = 0; //set PIN RB3 as output
 TRISBbits.TRISB4 = 0; //set PIN RB4 as output
 TRISBbits.TRISB5 = 0; //set PIN RB5 as output
 TRISBbits.TRISB6 = 0; //set PIN RB6 as output
 TRISBbits.TRISB7 = 0; //set PIN RB7 as output
 TRISBbits.TRISB8 = 0; //set PIN RB8 as output
 //(iv) Initialisation:
 LATBbits.LATB3=0; //PIN RB3 (Signal C) = Low
 LATBbits.LATB4=0; //PIN RB4 (Signal B) = Low
 LATBbits.LATB5=0; //PIN RB5 (Signal D) = Low
 LATBbits.LATB6=0; //PIN RB6 (Signal A) = Low
 LATBbits.LATB7=0; //Select Line 2 = Low. Disable the right display
 LATBbits.LATB8=1; //Select Line 1 = Low. Disable the left display
 }
void __attribute__ ((__interrupt__, auto_psv)) _T1Interrupt(void) //definition Interrupt
{
 Counter++;
if (Counter == 5)
{
9
LATBbits.LATB7= Pin_Toggle(LATBbits.LATB7);//Toggle the right display 
(SelectLine2 = Low)
LATBbits.LATB8= Pin_Toggle(LATBbits.LATB8);//Toggle on the left display 
(SelectLine1 = High)
if (LATBbits.LATB8 == 1)
{
LATBbits.LATB3= digit[0]; //PIN RB3 (Signal C)
 LATBbits.LATB4= digit[1]; //PIN RB4 (Signal B)
 LATBbits.LATB5= digit[2]; //PIN RB5 (Signal D)
 LATBbits.LATB6= digit[3]; //PIN RB6 (Signal A)
}
else
{
LATBbits.LATB3= digittwo[0]; //PIN RB3 (Signal C)
 LATBbits.LATB4= digittwo[1]; //PIN RB4 (Signal B)
 LATBbits.LATB5= digittwo[2]; //PIN RB5 (Signal D)
 LATBbits.LATB6= digittwo[3]; //PIN RB6 (Signal A)
}
Counter =0;
}
IFS0bits.T1IF=0; //ClearInterrupt Flag
}
int Pin_Toggle(int a)
{
 a = a - 1;
 return a;
}
void Timer_Config()
{
 T1CONbits.TON =1;
 PR1=0x7333; //Put value into PR1 register
 IEC0bits.T1IE=1; //Permission for timer 1 to interrupt the process
 IFS0bits.T1IF=0; //Interrupt Flag set to 0 at the beginning
 T1CONbits.TON=0;
}out