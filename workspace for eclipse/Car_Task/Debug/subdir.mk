################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../KeyPad.c \
../Lcd.c \
../Lcd_car_task.c \
../Led.c \
../Motor.c \
../Port.c 

OBJS += \
./Dio.o \
./KeyPad.o \
./Lcd.o \
./Lcd_car_task.o \
./Led.o \
./Motor.o \
./Port.o 

C_DEPS += \
./Dio.d \
./KeyPad.d \
./Lcd.d \
./Lcd_car_task.d \
./Led.d \
./Motor.d \
./Port.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


