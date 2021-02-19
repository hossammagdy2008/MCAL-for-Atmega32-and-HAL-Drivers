################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../KeyPad.c \
../Lcd.c \
../Led.c \
../Motor.c \
../Motor_Keypad_LCD_1.c \
../Port.c 

OBJS += \
./Dio.o \
./KeyPad.o \
./Lcd.o \
./Led.o \
./Motor.o \
./Motor_Keypad_LCD_1.o \
./Port.o 

C_DEPS += \
./Dio.d \
./KeyPad.d \
./Lcd.d \
./Led.d \
./Motor.d \
./Motor_Keypad_LCD_1.d \
./Port.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


