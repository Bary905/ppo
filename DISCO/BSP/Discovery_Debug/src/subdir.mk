################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/Keyboard.cxx \
../src/KeyboardLed.cxx \
../src/Led.cxx \
../src/LedBoard.cxx \
../src/main.cxx 

OBJS += \
./src/Keyboard.o \
./src/KeyboardLed.o \
./src/Led.o \
./src/LedBoard.o \
./src/main.o 

CXX_DEPS += \
./src/Keyboard.d \
./src/KeyboardLed.d \
./src/Led.d \
./src/LedBoard.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.cxx src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_STM32F429I_DISCO -DSTM32F429xx -c -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers/CMSIS/Include" -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers/BSP/STM32F429I-Discovery" -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers/User" -I"C:/Users/swita/OneDrive/Desktop/ppo/DISCO/BSP/Drivers" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/Keyboard.cyclo ./src/Keyboard.d ./src/Keyboard.o ./src/Keyboard.su ./src/KeyboardLed.cyclo ./src/KeyboardLed.d ./src/KeyboardLed.o ./src/KeyboardLed.su ./src/Led.cyclo ./src/Led.d ./src/Led.o ./src/Led.su ./src/LedBoard.cyclo ./src/LedBoard.d ./src/LedBoard.o ./src/LedBoard.su ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

