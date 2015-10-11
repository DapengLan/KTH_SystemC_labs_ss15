################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TB_Noise.cpp \
../TB_ram.cpp \
../main.cpp \
../ram.cpp 

OBJS += \
./TB_Noise.o \
./TB_ram.o \
./main.o \
./ram.o 

CPP_DEPS += \
./TB_Noise.d \
./TB_ram.d \
./main.d \
./ram.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


