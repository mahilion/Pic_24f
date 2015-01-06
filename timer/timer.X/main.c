#include <p24fj128ga010.h>
#include <stdio.h>



 int CONFIG2 __attribute__((space(prog), address(0x157FC))) = 0xFAFD ;
//_CONFIG2(
//    POSCMOD_XT &         // Primary Oscillator Select (XT Oscillator mode selected)
//    OSCIOFNC_OFF &       // Primary Oscillator Output Function (OSC2/CLKO/RC15 functions as CLKO (FOSC/2))
//    FCKSM_CSDCMD &       // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are disabled)
//    FNOSC_PRI &          // Oscillator Select (Primary Oscillator (XT, HS, EC))
//    IESO_ON              // Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) enabled)
//);
 int CONFIG1 __attribute__((space(prog), address(0x157FE))) = 0x3F7F ;
//_CONFIG1(
//    WDTPS_PS32768 &      // Watchdog Timer Postscaler (1:32,768)
//    FWPSA_PR128 &        // WDT Prescaler (Prescaler ratio of 1:128)
//    WINDIS_ON &          // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
//    FWDTEN_OFF &         // Watchdog Timer Enable (Watchdog Timer is disabled)
//    ICS_PGx2 &           // Comm Channel Select (Emulator/debugger uses EMUC2/EMUD2)
//    GWRP_OFF &           // General Code Segment Write Protect (Writes to program memory are allowed)
//    GCP_OFF &            // General Code Segment Code Protect (Code protection is disabled)
//    JTAGEN_OFF           // JTAG Port Enable (JTAG port is disabled)
//);
int main(void)
{
    TRISA=0;
    LATA=0x00;
    OSCCON=0x2280;
    CLKDIV=0x3800;
    T1CON = 0x8020;
    TMR1 = 0;
  
    int count=0;

while(1)
{

    if(TMR1>=65534)
    {
        count++;
    }
    switch(count)
    {
        case 1: LATAbits.LATA0=1;
        break;
        case 2: LATAbits.LATA1=1;
        LATAbits.LATA0=0;
        break;
        case 3: LATAbits.LATA2=1;
        LATAbits.LATA1=0;
        break;
        case 4: LATAbits.LATA2=0;
        LATAbits.LATA3=1;
        break;
        case 5: LATAbits.LATA3=0;
        LATAbits.LATA4=1;
        break;
        case 6: LATAbits.LATA5=1;
        LATAbits.LATA4=0;
        break;
        case 7: LATAbits.LATA6=1;
        LATAbits.LATA5=0;
        break;
        case 8: LATAbits.LATA7=1;
        LATAbits.LATA6=0;
        break;
        case 9: LATAbits.LATA7=0;
        count=1;
        break;


    }
    
   
    
}

}


        
        