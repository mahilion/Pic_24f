/* 
 * File:   main.c
 * Author: MAHESH.N
 *
 * Created on January 14, 2015, 12:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p24FJ128GA010.h>

/*
 * 
 */

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
    int x;
    TRISAbits.TRISA0=0;
    LATAbits.LATA0=0;
    OSCCON=0x2280;
    CLKDIV=0x3800;
    T2CON = 0x0020;
    OC1R=0x3000;
    OC1RS=0x3003;
    OC1CON=0x0005;
    //IEC0bits.T2IE=1;
    IFS0bits.OC1IF=0;
    IEC0bits.OC1IE=1;
    T2CONbits.TON=1;
    TMR2 = 0;
     LATAbits.LATA0=1;
    while(1)
    {
      //  /if(TMR2>=0xffff)
         //   LATAbits.LATA0=1;
       



    
    }
    
}
 void __attribute__((__interrupt__,auto_psv))_OC1Interrupt(void)
    {

        LATAbits.LATA0=0;
        IFS0bits.OC1IF=0;
       // OC1R=OC1R+1000;

    }  // int count=0;