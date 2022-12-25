/* ************************************************************************** */
/** Misc Functions

  @Company
    SupraTech

  @File Name
    leds.c

  @Summary
 Funcitons for LED flashing, etc

  @Description
    Various LED handling functions
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
#include "leds.h"
#include "misc.h"  // need for systic
#include "global_defs.h"



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

// These assume 10ms tic on LED timer
// 0 terminates the pattern

static uint8_t LED_Grn_Pattern_Off[] = {5,250,0};  // This will blink every 1/2 sec with 10ms tic
static uint8_t LED_Grn_Pattern_25[] = {5,95,0};   // 100ms on, 900 off - 1 flash
static uint8_t LED_Grn_Pattern_50[] = {5,30,5,95,0}; // 2 flashes
static uint8_t LED_Grn_Pattern_75[] = {5,30,5,30,5,95,0}; // 3 flashes - 500ms off
static uint8_t LED_Grn_Pattern_Full[] = {95,5,0};   // Always on (Slight blink)
static uint8_t *p_LED_Pattern[] = {LED_Grn_Pattern_Off, LED_Grn_Pattern_25, LED_Grn_Pattern_50, LED_Grn_Pattern_75, LED_Grn_Pattern_Full};


static uint8_t GrnPatternState = 0; // this will march through the timing states
static uint8_t GrnFlashPattern = CHARGE_OFF; // one of the enum states

static uint16_t Grn_tmr = 50;
static uint16_t LEDTick = 0;

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


static void FlashGrnLED(void);





/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/** 
  @Function
    DoLEDs 

  @Summary
 Calls all the LED Flash routines

  @Remarks
 Routine for Green LED only
 */
void DoLEDs(void)
{
    // State machine with the Green LED stuff in it
    FlashGrnLED();
    
} // End DoLEDs



/** 
  @Function
    FlashGrnLED 

  @Summary
 Flashes the Green LED at the right rate(s)

  @Remarks
 Routine for Green LED only
 */
static void FlashGrnLED(void)
{
    // State machine with the Green LED stuff in it
    if((uint16_t)(GetLEDTick() - Grn_tmr) >= p_LED_Pattern[GrnFlashPattern][GrnPatternState])
    {
        GrnPatternState++; // Load next time
        if(0 == p_LED_Pattern[GrnFlashPattern][GrnPatternState])
        {
            GrnPatternState = 0; // back to the start
        }
        Grn_tmr = GetLEDTick();  // Get new time
        if(GrnPatternState & 0x01)  // check for odd value = off time
        {
            GRN_LED_OFF;
        }
        else
        {
            GRN_LED_ON;
        }
        
    }
    
}  // End FlashGrnLED


/** 
  @Function
    SetGrnLEDPattern 

  @Summary
 Sets the pattern to blink for the Green LED

  @Remarks
 Takes in the enum pattern states:
    enum LED_Charge_Flash
    {
        CHARGE_OFF = 0,
        CHARGE_25,
        CHARGE_50,
        CHARGE_75,
        CHARGE_FULL
    };
 * 
 */
void SetGrnLEDPattern(uint8_t pattern)
{
    // Set the desired GRN LED pattern
    GrnPatternState = 0;  // Reset back to first element
    GrnFlashPattern = pattern;
    
}  // End SetGrnLEDPattern

/** 
  @Function
    IncLEDTick 

  @Summary
    Increments the LED Tick timer

  @Remarks
 Increment the LED Tick Timer - Set this to be every 10ms
 */
void IncLEDTick(void)
{
    LEDTick++;
}

/** 
  @Function
    GetLEDTick 

  @Summary
    Gets the current LEDTick

  @Remarks
    Get and return current LEDTick
 */
uint16_t GetLEDTick(void)
{
    uint16_t retval;

    PIE3bits.TMR1IE = 0; // Shut off interrupt
    retval = LEDTick;
    PIE3bits.TMR1IE = 1; // turn on interrupt
    return retval;
}


/* *****************************************************************************
 End of File
 */

