/**
  * TMR1 Generated Driver File
  *
  * @file tmr1.c
  *
  * @ingroup tmr1
  *
  * @brief Driver implementation for the TMR1 driver
  *
  * @version TMR1 Driver Version 3.1.0
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
 * Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"

/**
 * Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*LED_Timer_InterruptHandler)(void);

const struct TMR_INTERFACE LED_Timer = {
    .Initialize = LED_Timer_Initialize,
    .Start = LED_Timer_Start,
    .Stop = LED_Timer_Stop,
    .PeriodCountSet = LED_Timer_PeriodCountSet,
    .TimeoutCallbackRegister = LED_Timer_OverflowCallbackRegister,
    .Tasks = NULL
};
static void (*LED_Timer_OverflowCallback)(void);
static void LED_Timer_DefaultOverflowCallback(void);

void LED_Timer_Initialize(void)
{
    //TGGO done; TGSPM disabled; TGTM disabled; TGPOL low; TMRGE disabled; 
    T1GCON = 0x0;
    //TGSS T1GPPS; 
    T1GATE = 0x0;
    //TMRCS FOSC/4; 
    T1CLK = 0x1;
    //TMRH 216; 
    TMR1H = 0xD8;
    //TMRL 239; 
    TMR1L = 0xEF;

    // Load the TMR1 value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    //Set default callback for TMR1 overflow interrupt
    LED_Timer_OverflowCallbackRegister(LED_Timer_DefaultOverflowCallback);

    // Clearing TMRI IF flag before enabling the interrupt.
     PIR3bits.TMR1IF = 0;
    // Enabling TMRI interrupt.
     PIE3bits.TMR1IE = 1;
    
    //TMRON enabled; TRD16 enabled; nTSYNC synchronize; TCKPS 1:4; 
    T1CON = 0x23;
}

void LED_Timer_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void LED_Timer_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

uint16_t LED_Timer_Read(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
    T1CONbits.T1RD16 = 1;
	
    readValLow = TMR1L;
    readValHigh = TMR1H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void LED_Timer_Write(size_t timerVal)
{
    if (T1CONbits.NOT_SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON = 1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;
    }
}

void LED_Timer_Reload(void)
{
    LED_Timer_Write(timer1ReloadVal);
}

void LED_Timer_PeriodCountSet(size_t periodVal)
{
   timer1ReloadVal = (uint16_t) periodVal;
}

void LED_Timer_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO = 1;
}

uint8_t LED_Timer_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}

void LED_Timer_OverflowISR(void)
{

    // Clear the TMR1 interrupt flag
    PIR3bits.TMR1IF = 0;
    LED_Timer_Write(timer1ReloadVal);

    if(LED_Timer_OverflowCallback)
    {
        LED_Timer_OverflowCallback();
    }
}

void LED_Timer_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    LED_Timer_OverflowCallback = CallbackHandler;
}

static void LED_Timer_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use LED_Timer_OverflowCallbackRegister function to use Custom ISR
}

bool LED_Timer_HasOverflowOccured(void)
{
    return(PIR3bits.TMR1IF);
}

void LED_Timer_GateISR(void)
{
    // clear the TMR1 interrupt flag
    PIR3bits.TMR1GIF = 0;
}


/**
  End of File
*/