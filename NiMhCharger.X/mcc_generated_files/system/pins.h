/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define PWM_TRIS                 TRISAbits.TRISA2
#define PWM_LAT                  LATAbits.LATA2
#define PWM_PORT                 PORTAbits.RA2
#define PWM_WPU                  WPUAbits.WPUA2
#define PWM_OD                   ODCONAbits.ODCA2
#define PWM_ANS                  ANSELAbits.ANSELA2
#define PWM_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PWM_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PWM_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PWM_GetValue()           PORTAbits.RA2
#define PWM_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PWM_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PWM_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PWM_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PWM_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PWM_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PWM_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define PWM_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)
   
// get/set RA4 aliases
#define THERMISTOR_TRIS                 TRISAbits.TRISA4
#define THERMISTOR_LAT                  LATAbits.LATA4
#define THERMISTOR_PORT                 PORTAbits.RA4
#define THERMISTOR_WPU                  WPUAbits.WPUA4
#define THERMISTOR_OD                   ODCONAbits.ODCA4
#define THERMISTOR_ANS                  ANSELAbits.ANSELA4
#define THERMISTOR_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define THERMISTOR_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define THERMISTOR_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define THERMISTOR_GetValue()           PORTAbits.RA4
#define THERMISTOR_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define THERMISTOR_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define THERMISTOR_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define THERMISTOR_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define THERMISTOR_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define THERMISTOR_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define THERMISTOR_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define THERMISTOR_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)
   
// get/set RA5 aliases
#define VBAT_TRIS                 TRISAbits.TRISA5
#define VBAT_LAT                  LATAbits.LATA5
#define VBAT_PORT                 PORTAbits.RA5
#define VBAT_WPU                  WPUAbits.WPUA5
#define VBAT_OD                   ODCONAbits.ODCA5
#define VBAT_ANS                  ANSELAbits.ANSELA5
#define VBAT_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VBAT_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VBAT_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VBAT_GetValue()           PORTAbits.RA5
#define VBAT_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VBAT_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VBAT_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VBAT_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VBAT_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VBAT_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VBAT_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define VBAT_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)
   
// get/set RC0 aliases
#define TX_TRIS                 TRISCbits.TRISC0
#define TX_LAT                  LATCbits.LATC0
#define TX_PORT                 PORTCbits.RC0
#define TX_WPU                  WPUCbits.WPUC0
#define TX_OD                   ODCONCbits.ODCC0
#define TX_ANS                  ANSELCbits.ANSELC0
#define TX_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TX_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TX_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TX_GetValue()           PORTCbits.RC0
#define TX_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define TX_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define TX_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define TX_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define TX_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define TX_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)
   
// get/set RC1 aliases
#define RX_TRIS                 TRISCbits.TRISC1
#define RX_LAT                  LATCbits.LATC1
#define RX_PORT                 PORTCbits.RC1
#define RX_WPU                  WPUCbits.WPUC1
#define RX_OD                   ODCONCbits.ODCC1
#define RX_ANS                  ANSELCbits.ANSELC1
#define RX_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RX_GetValue()           PORTCbits.RC1
#define RX_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RX_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RX_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)
   
// get/set RC2 aliases
#define TP3_TRIS                 TRISCbits.TRISC2
#define TP3_LAT                  LATCbits.LATC2
#define TP3_PORT                 PORTCbits.RC2
#define TP3_WPU                  WPUCbits.WPUC2
#define TP3_OD                   ODCONCbits.ODCC2
#define TP3_ANS                  ANSELCbits.ANSELC2
#define TP3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TP3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TP3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TP3_GetValue()           PORTCbits.RC2
#define TP3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TP3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define TP3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define TP3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define TP3_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define TP3_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define TP3_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define TP3_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)
   
// get/set RC3 aliases
#define DISCHARGE_TRIS                 TRISCbits.TRISC3
#define DISCHARGE_LAT                  LATCbits.LATC3
#define DISCHARGE_PORT                 PORTCbits.RC3
#define DISCHARGE_WPU                  WPUCbits.WPUC3
#define DISCHARGE_OD                   ODCONCbits.ODCC3
#define DISCHARGE_ANS                  ANSELCbits.ANSELC3
#define DISCHARGE_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DISCHARGE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DISCHARGE_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DISCHARGE_GetValue()           PORTCbits.RC3
#define DISCHARGE_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DISCHARGE_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DISCHARGE_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define DISCHARGE_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define DISCHARGE_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define DISCHARGE_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define DISCHARGE_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define DISCHARGE_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)
   
// get/set RC4 aliases
#define ERROR_LED_TRIS                 TRISCbits.TRISC4
#define ERROR_LED_LAT                  LATCbits.LATC4
#define ERROR_LED_PORT                 PORTCbits.RC4
#define ERROR_LED_WPU                  WPUCbits.WPUC4
#define ERROR_LED_OD                   ODCONCbits.ODCC4
#define ERROR_LED_ANS                  ANSELCbits.ANSELC4
#define ERROR_LED_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ERROR_LED_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ERROR_LED_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ERROR_LED_GetValue()           PORTCbits.RC4
#define ERROR_LED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ERROR_LED_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define ERROR_LED_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define ERROR_LED_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define ERROR_LED_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define ERROR_LED_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define ERROR_LED_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define ERROR_LED_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)
   
// get/set RC5 aliases
#define GRN_LED_TRIS                 TRISCbits.TRISC5
#define GRN_LED_LAT                  LATCbits.LATC5
#define GRN_LED_PORT                 PORTCbits.RC5
#define GRN_LED_WPU                  WPUCbits.WPUC5
#define GRN_LED_OD                   ODCONCbits.ODCC5
#define GRN_LED_ANS                  ANSELCbits.ANSELC5
#define GRN_LED_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define GRN_LED_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define GRN_LED_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define GRN_LED_GetValue()           PORTCbits.RC5
#define GRN_LED_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define GRN_LED_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define GRN_LED_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define GRN_LED_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define GRN_LED_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define GRN_LED_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define GRN_LED_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define GRN_LED_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)
   
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/