/* ************************************************************************** */
/** Misc Functions

  @Company
    SupraTech

  @File Name
    charge.c

  @Summary
    Misc functions - timers, etc.

  @Description
    Various button handling functions
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "mcc_generated_files/system/system.h"
#include "charge.h"
#include "global_defs.h"



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */

enum Charge_States
{
    IDLE = 0,
    PRECHARGE,
    FAST_CHARGE_25,
    FAST_CHARGE_50,
    FAST_CHARGE_75,
    FAST_CHARGE_FULL,
    TOPPING    
};

static uint16_t ChgTick = 0;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}








/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */


// *****************************************************************************

/** 
  @Function
    IncSysTick 

  @Summary
 Increments the System Tic

  @Remarks
 In SysTic
 */
void DoCharge(void)
{
    // do the whole charge routine - start to finish
    static uint8_t st_Charge = IDLE;
    uint16_t ADResult;
    
}

/** 
  @Function
    IncChgTick 

  @Summary
    Increments the Charge function timer  - set at 1 mSec rate so we can get the 5ms rest times, etc we need

  @Remarks
 Increment the Charge Tick Timer - Set this to be every 1 ms
 */
void IncChgTick(void)
{
    ChgTick++;
}

/** 
  @Function
    GetChgTick 

  @Summary
    Gets the current Charge Timer Tick

  @Remarks
    Get and return current Charge Timer Tick - this one goes at 1 mSec rates
 */
uint16_t GetChgTick(void)
{
    uint16_t retval;

    PIE3bits.TMR2IE = 0; // Shut off interrupt
    retval = LEDTick;
    PIE3bits.TMR2IE = 1; // turn on interrupt
    return retval;
}

/* *****************************************************************************
 End of File
 */

