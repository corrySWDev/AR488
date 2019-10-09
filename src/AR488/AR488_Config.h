#ifndef AR488_CONFIG_H
#define AR488_CONFIG_H

/*********************************************/
/***** AR488 GLOBAL CONFIGURATION HEADER *****/
/***** vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv *****/


/***** Firmware version *****/
#define FWVER "AR488 GPIB controller, ver. 0.47.44, 09/10/2019"


/***** BOARD SELECTION *****/
/*
 * At least one board and ONLY ONE board MUST be selected!
 */
#define AR488_UNO
//#define AR488_NANO
//#define AR488_MEGA2560
//#define AR488_MEGA32U4
//#define AR488_CUSTOM

/***** Serial port selection *****/
/*
 * Note: Only ONE port can be used and will receive output
 */
/* UNO and NANO boards */
#ifdef __AVR_ATmega328P__
  // Select HardwareSerial or SoftwareSerial (default = HardwareSerial)
  #define AR_HW_SERIAL
  //#define AR_SW_SERIAL
  // The UNO/NANO default port is 'Serial'
  #define AR_SERIAL_PORT Serial
/* Mega 32u4 based boards (Micro, Leonardo) */
#elif __AVR_ATmega32U4__
  // Comment out if using RXI, TXO pins
  #define AR_CDC_SERIAL
  // The Mega 32u4 default port is a virtual USB CDC port named 'Serial'
  #define AR_SERIAL_PORT Serial
/* Mega 2560 board */
#elif __AVR_ATmega2560__
  // M++addega 2560 supports Serial, Serial1, Serial2, Serial3. Since the pins 
  // associated with Serial2 are used in the default pin layout, Serial2
  // is unavailable. The default port is 'Serial'. Choose ONE port.
  #define AR_HW_SERIAL
  #define AR_SERIAL_PORT Serial
  //#define AR_SERIAL_PORT Serial1
  //#define AR_SERIAL_PORT Serial3
#endif
/*
 * Note: SoftwareSerial support conflicts with PCINT support
 * When using SoftwareSerial, disable USE_PCINTS and enable 
 * USE_PINHOOKS
 */
#ifdef AR_SW_SERIAL
  #define AR_SW_SERIAL_RX 53
  #define AR_SW_SERIAL_TX 51
#endif
/*
 * Note: SoftwareSerial reliable only up to a MAX of 57600 baud only
 */
#define AR_SERIAL_BAUD 115200


/***** Pin State Detection *****/
/*
 * With UNO. NANO and MEGA boards with pre-defined layouts,
 * USE_PCINTS can be used.
 * With AR488_CUSTOM and unknown boards, USE_PINHOOKS should be used.
 * Interrupts may respond faster. Pinhooks (in-loop checking for 
 * state of pin) can be supported on a wider range of platforms.
 */
#ifdef __AVR__
  #if defined (AR488_UNO) || defined (AR488_NANO) || defined (AR488_MEGA2560) || defined (AR488_MEGA32U4)
    #define USE_INTERRUPTS
  #else
    #define USE_PINHOOKS
  #endif
#else
  #define USE_PINHOOKS
#endif


/***** Enable Macros *****/
/*
 * Uncomment to enable macro support. The Startup macro allows the
 * interface to be configured at startup. Macros 1 - 9 can be
 * used to execute a sequence of commands with a single command
 * i.e, ++macro n, where n is the number of the macro
 * 
 * USE_MACROS must be enabled to enable the macro feature including 
 * MACRO_0 (the startup macro). RUN_STARTUP must be uncommented to 
 * run the startup macro when the interface boots up
 */
//#define USE_MACROS    // Enable the macro feature
//#define RUN_STARTUP   // Run MACRO_0 (the startup macro)


/***** Bluetooth (HC05) support *****/

#define AR_BT_EN 6            // Bluetooth enable and control pin
#ifdef AR_BT_EN
  #define AR_BT_BAUD "57600"    // Bluetooth module preferred baud rate
  #define AR_BT_NAME "AR488-BT" // Bluetooth device name
  #define AR_BT_CODE "488488"   // Bluetooth pairing code
  #define AR_BT_LED 13          // Internal LED
#endif


/***** Debug options *****/
//#define DEBUG1  // getCmd
//#define DEBUG2  // setGpibControls
//#define DEBUG3  // gpibSendData
//#define DEBUG4  // spoll_h
//#define DEBUG5  // attnRequired
//#define DEBUG6  // EEPROM
//#define DEBUG7  // gpibReceiveData
//#define DEBUG8  // ppoll_h



/***** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ *****/
/***** AR488 GLOBAL CONFIGURATION HEADER *****/
/*********************************************/


/*******************************/
/***** AR488 CUSTOM LAYOUT *****/
/***** vvvvvvvvvvvvvvvvvvv *****/
#ifdef AR488_CUSTOM

#define DIO1  A0  /* GPIB 1  */
#define DIO2  A1  /* GPIB 2  */
#define DIO3  A2  /* GPIB 3  */
#define DIO4  A3  /* GPIB 4  */
#define DIO5  A4  /* GPIB 13 */
#define DIO6  A5  /* GPIB 14 */
#define DIO7  4   /* GPIB 15 */
#define DIO8  5   /* GPIB 16 */

#define IFC   8   /* GPIB 9  */
#define NDAC  9   /* GPIB 8  */
#define NRFD  10  /* GPIB 7  */
#define DAV   11  /* GPIB 6  */
#define EOI   12  /* GPIB 5  */

#define SRQ   2   /* GPIB 10 */
#define REN   3   /* GPIB 17 */
#define ATN   7   /* GPIB 11 */

#endif
/***** ^^^^^^^^^^^^^^^^^^^ *****/
/***** AR488 CUSTOM LAYOUT *****/
/*******************************/



/********************************/
/***** AR488 MACROS SECTION *****/
/***** vvvvvvvvvvvvvvvvvvvv *****/
/*
 * (See the AR488 user manual for details)
 */
#ifdef USE_MACROS

/***** Startup Macro *****/

#define MACRO_0 "\
++addr 9\n\
++auto 2\n\
*RST\n\
:func 'volt:ac'\
"
/* End of MACRO_0 (Startup macro)*/

/***** User macros 1-9 *****/

#define MACRO_1 "\
++addr 3\n\
++auto 0\n\
M3\n\
"
/*<-End of macro*/

#define MACRO_2 "\
"
/*<-End of macro 2*/

#define MACRO_3 "\
"
/*<-End of macro 3*/

#define MACRO_4 "\
"
/*<-End of macro 4*/

#define MACRO_5 "\
"
/*<-End of macro 5*/

#define MACRO_6 "\
"
/*<-End of macro 6*/

#define MACRO_7 "\
"
/*<-End of macro 7*/

#define MACRO_8 "\
"
/*<-End of macro 8*/

#define MACRO_9 "\
"
/*<-End of macro 9*/


#endif
/***** ^^^^^^^^^^^^^^^^^^^^ *****/
/***** AR488 MACROS SECTION *****/
/********************************/



#endif // AR488_CONFIG_H
