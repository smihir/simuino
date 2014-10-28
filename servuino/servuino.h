
void interruptNow();
void writeStatus();
void stopEncoding();
void updateFromRegister();
void digitalWrite(int pin,int value);
int  digitalRead(int pin);

char  interruptType[50][80];
void  (*interrupt[9])();

#define S_UNIMPLEMENTED            0
#define S_SETUP                    1
#define S_LOOP                     2
#define S_DIGITAL_WRITE_LOW        3
#define S_DIGITAL_WRITE_HIGH       4
#define S_DIGITAL_READ             5
#define S_ANALOG_REFERENCE         6
#define S_ANALOG_WRITE             7
#define S_ANALOG_READ              8
#define S_PIN_MODE_INPUT           9
#define S_PIN_MODE_OUTPUT         10
#define S_DELAY                   11
#define S_DELAY_MS                12
#define S_ATTACH_INTERRUPT_LOW     13
#define S_ATTACH_INTERRUPT_RISING  14
#define S_ATTACH_INTERRUPT_FALLING 15
#define S_ATTACH_INTERRUPT_CHANGE  16
#define S_DETACH_INTERRUPT        17
#define S_SERIAL_BEGIN            18
#define S_SERIAL_END              19
#define S_SERIAL_PRINT_INT        20
#define S_SERIAL_PRINT_INT_BASE   21
#define S_SERIAL_PRINT_CHAR       22
#define S_SERIAL_PRINT_STRING     23
#define S_SERIAL_PRINT_SSTRING    24

#define S_SERIAL_PRINTLN_INT      25
#define S_SERIAL_PRINTLN_INT_BASE 26
#define S_SERIAL_PRINTLN_CHAR     27
#define S_SERIAL_PRINTLN_STRING   28
#define S_SERIAL_PRINTLN_SSTRING  29
#define S_SERIAL_PRINTLN_VOID     30
#define S_SERIAL_WRITE            31

#define S_EEPROM_READ             32
#define S_EEPROM_WRITE            33

#define S_SERIAL_PRINT_UCHAR      34
#define S_SERIAL_PRINTLN_UCHAR    35




#define R_PORT 1
#define R_DDR  2
#define R_PIN  3

void  bitWrite(unsigned int *x, int n,int b);
int   bitRead(int x, int n);
int   readRegister(int reg, int port);
void  writeRegister(int digital, int reg, int port, int value);
void  registerLog();
void  setPINRegister(int step); 





