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
Ass_1_3.lss \

FLASH_IMAGE += \
Ass_1_3.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Ass_1_3.elf secondary-outputs

# Tool invocations
Ass_1_3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Ass_1_3.map -mmcu=atmega32 -o "Ass_1_3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Ass_1_3.lss: Ass_1_3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Ass_1_3.elf  >"Ass_1_3.lss"
	@echo 'Finished building: $@'
	@echo ' '

Ass_1_3.hex: Ass_1_3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Ass_1_3.elf  "Ass_1_3.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Ass_1_3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Ass_1_3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Ass_1_3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
