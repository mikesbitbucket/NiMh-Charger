/**
  Generated Main Source File

  Company:
  SupraTech

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
   NiMh Battery Charger 
 * This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F06Q40
        Driver Version    :  2.00
*/

/*
 Notes and revisions
 * 
 * 
 * 
*/

#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include "global_defs.h"


uint16_t A2D_Result;



/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    
    TMR0_SetInterruptHandler(IncSysTick);  // Register the Systimer Handler
    
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    TMR0_StartTimer();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    //PWM_SetHigh();
    
    
    while (1)
    {
        // Add your application code
        DoHeartBeat();
        ERROR_LED_Toggle();
        A2D_Result = ADCC_GetSingleConversion(VBAT);
        //PWM_Toggle();
    }
}
/**
 End of File
*/