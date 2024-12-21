################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/adc.c \
../MCAL/external_interrupts.c \
../MCAL/gpio.c \
../MCAL/icu.c \
../MCAL/timer.c 

OBJS += \
./MCAL/adc.o \
./MCAL/external_interrupts.o \
./MCAL/gpio.o \
./MCAL/icu.o \
./MCAL/timer.o 

C_DEPS += \
./MCAL/adc.d \
./MCAL/external_interrupts.d \
./MCAL/gpio.d \
./MCAL/icu.d \
./MCAL/timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


