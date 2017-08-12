################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DigitalWatch.cpp \
../src/Dot.cpp \
../src/FlipDot.cpp \
../src/Segment.cpp \
../src/ShiftRegister.cpp 

OBJS += \
./src/DigitalWatch.o \
./src/Dot.o \
./src/FlipDot.o \
./src/Segment.o \
./src/ShiftRegister.o 

CPP_DEPS += \
./src/DigitalWatch.d \
./src/Dot.d \
./src/FlipDot.d \
./src/Segment.d \
./src/ShiftRegister.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/paul/eclipse/wiringPi/wiringPi -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


