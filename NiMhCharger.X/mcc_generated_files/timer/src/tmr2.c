/**
 * TMR2 Generated Driver File
 *
 * @file tmr2.c
 * 
 * @ingroup  tmr2
 * 
 * @brief API implementations for the TMR2 module.
 *
 * @version TMR2 Driver Version 3.0.1
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
  Section: Included Files
*/

#include <xc.h>
#include "../tmr2.h"

const struct TMR_INTERFACE mSec_tmr = {
    .Initialize = mSec_tmr_Initialize,
    .Start = mSec_tmr_Start,
    .Stop = mSec_tmr_Stop,
    .PeriodCountSet = mSec_tmr_PeriodCountSet,
    .TimeoutCallbackRegister = mSec_tmr_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*mSec_tmr_OverflowCallback)(void);
static void mSec_tmr_DefaultOverflowCallback(void);

/**
  Section: TMR2 APIs
*/

void mSec_tmr_Initialize(void){

    // Set TMR2 to the options selected in the User Interface
    // TCS FOSC/4; 
    T2CLKCON = 0x1;
    // TMODE Software control; TCKSYNC Not Synchronized; TCKPOL Rising Edge; TPSYNC Not Synchronized; 
    T2HLT = 0x0;
    // TRSEL T2INPPS pin; 
    T2RST = 0x0;
    // PR 62; 
    T2PR = 0x3E;
    // TMR 0x0; 
    T2TMR = 0x0;

    // Set default overflow callback
    mSec_tmr_OverflowCallbackRegister(mSec_tmr_DefaultOverflowCallback);

    // Clearing IF flag before enabling the interrupt.
     PIR3bits.TMR2IF = 0;
    // Enabling TMR2 interrupt.
     PIE3bits.TMR2IE = 1;
    // TCKPS 1:64; TMRON on; TOUTPS 1:1; 
    T2CON = 0xE0;
}

void mSec_tmr_ModeSet(mSec_tmr_HLT_MODE mode)
{
   // Configure different types HLT mode
    T2HLTbits.T2MODE = mode;
}

void mSec_tmr_ExtResetSourceSet(mSec_tmr_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T2RSTbits.T2RSEL = reset;
}

void mSec_tmr_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void mSec_tmr_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

uint8_t mSec_tmr_Read(void)
{
    uint8_t readVal;
    readVal = TMR2;
    return readVal;
}

void mSec_tmr_Write(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;;
}

void mSec_tmr_PeriodCountSet(size_t periodVal)
{
   PR2 = (uint8_t) periodVal;
}

void mSec_tmr_ISR(void)
{
    // clear the TMR2 interrupt flag
     PIR3bits.TMR2IF = 0;

    if(mSec_tmr_OverflowCallback)
    {
        mSec_tmr_OverflowCallback();
    }
}

void mSec_tmr_OverflowCallbackRegister(void (* InterruptHandler)(void)){
    mSec_tmr_OverflowCallback = InterruptHandler;
}

static void mSec_tmr_DefaultOverflowCallback(void){
    // add your TMR2 interrupt custom code
    // or set custom function using mSec_tmr_OverflowCallbackRegister()
}

