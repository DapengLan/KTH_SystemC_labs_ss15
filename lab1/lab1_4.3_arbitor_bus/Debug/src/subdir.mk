################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/UART.cpp \
../src/arbitor.cpp \
../src/change_case.cpp \
../src/filter.cpp \
../src/m_bus.cpp \
../src/testbench.cpp \
../src/top.cpp 

OBJS += \
./src/UART.o \
./src/arbitor.o \
./src/change_case.o \
./src/filter.o \
./src/m_bus.o \
./src/testbench.o \
./src/top.o 

CPP_DEPS += \
./src/UART.d \
./src/arbitor.d \
./src/change_case.d \
./src/filter.d \
./src/m_bus.d \
./src/testbench.d \
./src/top.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


