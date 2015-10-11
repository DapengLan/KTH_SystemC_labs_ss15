################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/monitor.cpp \
../src/or_gate.cpp \
../src/testbench.cpp 

OBJS += \
./src/main.o \
./src/monitor.o \
./src/or_gate.o \
./src/testbench.o 

CPP_DEPS += \
./src/main.d \
./src/monitor.d \
./src/or_gate.d \
./src/testbench.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


