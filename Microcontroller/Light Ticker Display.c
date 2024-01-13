#include <stdio.h>
#include <user_definitions.h>
char IAS = 0;
int printed_letter = 73;
int i;
int j = 0; // n represent the number of modules
char LATEbits.LATE0; //The values are initialized to run and test in local.
char LATEbits.LATE1;
char LATEbits.LATE2;
13
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
 if (IAS == 0)
 {
 IAS = 1;
 for (i=0; i<3*8; i++)
 {
 if (i<8){
 printed_letter = 73; // print I
 }
 else if (i>= 8 && i<16){
 printed_letter = 65; // print A
 }
 else if (i>=16 && i<24){
 printed_letter = 83; // print S
 }
 //printf("%d", printed_letter);
 for (j=0; j<8; j ++){
 LATEbits.LATE0 = char[printed_letter][i%8].bitwise.b0; //taking corresponding row in 
the char generator and selecting the bit
 LATEbits.LATE1 = char[printed_letter][i%8].bitwise.b1;
 LATEbits.LATE2 = char[printed_letter][i%8].bitwise.b2;
 LATEbits.LATE3 = char[printed_letter][i%8].bitwise.b3;
 LATEbits.LATE4 = char[printed_letter][i%8].bitwise.b4;
 LATEbits.LATE5 = char[printed_letter][i%8].bitwise.b5;
 LATEbits.LATF6 = char[printed_letter][i%8].bitwise.b6;
 LATEbits.LATD0 = char[printed_letter][i%8].bitwise.b7;
 LATEbits.LATD2 = char[printed_letter][i%8].bitwise.b8;
 LATEbits.LATE8 = 1; // CLOCK line should be high
 LATEbits.LATD3 = 1; // STROBE should be high
 LATEbits.LATD1 = 0; // ENABLE should be low
 printf("%d", LATEbitsLATE0);
 } 
 delay_us(100*1000);// 100 millisecond delay
 }
 }
 else
 {
 IAS = 0;
 LATEbits.LATE8 = 0; // CLOCK-line should be low
 LATEbits.LATD3 = 0; // STROBE should be low
 LATEbits.LATD1 = 1; // ENABLE should be high
 printf("%d", LATEbitsLATD1);
 }
}