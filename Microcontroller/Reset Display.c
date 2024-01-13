#include <stdio.h>
char reset_display = 1;
int i = 0;
int n; // n represent the number of modules
char LATEbits.LATE0;
char LATEbits.LATE1;
11
char LATEbits.LATE2;
char LATEbits.LATE3;
char LATEbits.LATE4;
char LATEbits.LATE5;
char LATEbits.LATF6;
char LATEbits.LATD0;
char LATEbits.LATD2;
char LATEbits.LATE8;
char LATEbits.LATD3;
char LATEbits.LATD1;
void main() {
 if (reset_display == 0)
 {
 reset_display = 1;
 for (i=0; i<8 *n; i ++ )
{
 LATEbits.LATE0 = 0;
 LATEbits.LATE1 = 0;
 LATEbits.LATE2 = 0;
 LATEbits.LATE3 = 0;
 LATEbits.LATE4 = 0;
 LATEbits.LATE5 = 0;
 LATEbits.LATF6 = 0;
 LATEbits.LATD0 = 0;
 LATEbits.LATD2 = 0;
 LATEbits.LATE8 = 1; // CLOCK-line should be high
 LATEbits.LATD3 = 1; // STROBE should be high
 LATEbits.LATD1 = 0; // ENABLE should be low
 printf("%d", LATEbitsLATE0);
 }
 }
 else
 {
 reset_display = 0;
 LATEbits.LATE8 = 0; // CLOCK-line should be low
 LATEbits.LATD3 = 0; // STROBE should be low
 LATEbits.LATD1 = 1; // ENABLE should be high
 printf("%d", LATEbitsLATD1);
 }
}