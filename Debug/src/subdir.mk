################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Digit_5x7.cpp \
../src/DigitalWatch.cpp \
../src/Dot.cpp \
../src/FlipDot.cpp \
../src/HAL_Addr.cpp \
../src/HAL_Button.cpp \
../src/HAL_ShiftRegister.cpp \
../src/Screen.cpp \
../src/Segment.cpp \
../src/Tetris.cpp \
../src/TetrisElement.cpp 

OBJS += \
./src/Digit_5x7.o \
./src/DigitalWatch.o \
./src/Dot.o \
./src/FlipDot.o \
./src/HAL_Addr.o \
./src/HAL_Button.o \
./src/HAL_ShiftRegister.o \
./src/Screen.o \
./src/Segment.o \
./src/Tetris.o \
./src/TetrisElement.o 

CPP_DEPS += \
./src/Digit_5x7.d \
./src/DigitalWatch.d \
./src/Dot.d \
./src/FlipDot.d \
./src/HAL_Addr.d \
./src/HAL_Button.d \
./src/HAL_ShiftRegister.d \
./src/Screen.d \
./src/Segment.d \
./src/Tetris.d \
./src/TetrisElement.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/paul/eclipse/wiringPi/wiringPi -I/home/alexander/rpi/wiringPi/wiringPi -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


