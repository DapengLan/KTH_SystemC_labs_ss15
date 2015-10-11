################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/adder.cpp \
../src/monitor.cpp \
../src/stimulus.cpp \
../src/top.cpp 

OBJS += \
./src/adder.o \
./src/monitor.o \
./src/stimulus.o \
./src/top.o 

CPP_DEPS += \
./src/adder.d \
./src/monitor.d \
./src/stimulus.d \
./src/top.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


