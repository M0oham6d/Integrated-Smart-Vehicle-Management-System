################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/buzzer.c \
../HAL/ir_sensor.c \
../HAL/lcd.c \
../HAL/three_leds.c \
../HAL/ultrasonic_sensor.c 

OBJS += \
./HAL/buzzer.o \
./HAL/ir_sensor.o \
./HAL/lcd.o \
./HAL/three_leds.o \
./HAL/ultrasonic_sensor.o 

C_DEPS += \
./HAL/buzzer.d \
./HAL/ir_sensor.d \
./HAL/lcd.d \
./HAL/three_leds.d \
./HAL/ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


