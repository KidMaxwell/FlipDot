################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dot.cpp \
../src/FlipDot.cpp \
../src/ShiftRegister.cpp 

OBJS += \
./src/Dot.o \
./src/FlipDot.o \
./src/ShiftRegister.o 

CPP_DEPS += \
./src/Dot.d \
./src/FlipDot.d \
./src/ShiftRegister.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/paul/eclipse/wiringPi/wiringPi -I/home/paul/eclipse/workspace2/FlipDot/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


