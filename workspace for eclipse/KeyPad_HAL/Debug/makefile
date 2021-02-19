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
KeyPad_HAL.lss \

FLASH_IMAGE += \
KeyPad_HAL.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KeyPad_HAL.elf secondary-outputs

# Tool invocations
KeyPad_HAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KeyPad_HAL.map -mmcu=atmega32 -o "KeyPad_HAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KeyPad_HAL.lss: KeyPad_HAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KeyPad_HAL.elf  >"KeyPad_HAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

KeyPad_HAL.hex: KeyPad_HAL.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KeyPad_HAL.elf  "KeyPad_HAL.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KeyPad_HAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KeyPad_HAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KeyPad_HAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
