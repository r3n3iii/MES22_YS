# MES3_YS
Homework for Making Embedded Systems - Classpert course

## Instructions
Make blinky for yourself. Then add a button to turn the LED on and off. Bonus points for making the button cause an interrupt. Triple bonus points for debouncing the button signal. 
Board: STM32F411 Discovery Kit
### About the code
The Board has a push button configured, with internal pullup resistor, in PA2. A timer of 5ms is used to evalute the push-button's reading. Debouncing the button is done with code from Jack Ganssle's Debouncing post, found here: http://www.ganssle.com/debouncing-pt2.htm
After the debouncing, the four LED's in the board (PD12 to PD15) are toggled at 4Hz. The push-button toggles on/off the blinking.

## Questions
- What build environment are you using?
Stm32CubeIDE. Code was generated with initial Peripheral configurations, later I manualy removed unnecesary initializations.
Also tried Generating the Makefile using STM32CubeMx. Installing arm gcc toolchain. Editing in VScode. Flashing was done with STM32CubeProgrammer.

- Can you step through the code to see what each line does?
The discovery board comes with st-link v2. After configuring the debugger, I can set hardware points, view the register values and step through the code.

Investigate further, using the processor manual: 
- What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.) 
GPIOx_BSRR is the register to set individual pins of the input and output data registers (GPIOx_IDR and GPIOx_ODR).

- What are the registers that you read in order to find out the state of the button? 
GPIOx->IDR it is used to read the pin status.

- Can you read the register directly and see the button change in a debugger or by printing out the value of the memory at the register’s address?
Yes, putting a breakpoint where the button is being read, and opening SFR>GPIOA->IDR>'pinNumber'.
