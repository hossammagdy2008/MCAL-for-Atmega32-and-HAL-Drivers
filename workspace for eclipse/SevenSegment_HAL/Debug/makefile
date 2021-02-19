################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SevenSegment_HAL.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: SevenSegment_HAL.elf secondary-outputs

# Tool invocations
SevenSegment_HAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SevenSegment_HAL.map -mmcu=atmega32 -o "SevenSegment_HAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SevenSegment_HAL.lss: SevenSegment_HAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SevenSegment_HAL.elf  >"SevenSegment_HAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SevenSegment_HAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SevenSegment_HAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SevenSegment_HAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
