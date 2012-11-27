#ifndef UMBRELLASIGN
#define UMBRELLASIGN

/* Push button */
#define PUSH_BUTTON_PIN 2
void buttonInterrupt(void);

/* TLC Output Values */
#define MAX_VALUE 4095
#define NUM_LEDS 28
#define MAX_ROW 9

#define TLC_DEBUG_LED1 30
#define TLC_DEBUG_LED2 31

extern int8_t ledRow[];
extern uint16_t rowValues[];
extern uint16_t ledValues[];
extern int8_t signToIndex[];

/* Definition of sign modes */
typedef int (*mode_function_t)(void *arg);

/* Mode for lights */
#define MODE_EXAMPLE_CIRCULAR 0
#define MODE_EXAMPLE_FADES    1
#define MODE_ALL_ON           2
#define MODE_SWAP_ONE         3
#define MODE_FADE_ONE         4
#define MODE_FADE_ROW         5
#define MODE_COUNT_UP         6
#define MODE_FLASH_ORDERED    7

#define MODE_TOTAL            8

/* Mode functions */
int mode_example_circular(void *arg);
int mode_example_fades(void *arg);
int mode_all_on(void *arg);
int mode_swap_one(void *arg);
int mode_fade_one(void *arg);
int mode_fade_row(void *arg);
int mode_count_up(void *arg);
int mode_flash_ordered(void *arg);

/* Return the current mode value */
int get_current_mode(void);

#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.print(x)
#else
  #define DEBUG_PRINT(x)
#endif

#endif
