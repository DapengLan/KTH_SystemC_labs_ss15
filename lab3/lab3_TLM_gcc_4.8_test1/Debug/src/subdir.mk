################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab3_TLM_gcc_4.8_test1.cpp 

OBJS += \
./src/lab3_TLM_gcc_4.8_test1.o 

CPP_DEPS += \
./src/lab3_TLM_gcc_4.8_test1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/parallels/Documents/systemC/TLM-2009-07-15/include/tlm/ -I/home/parallels/Documents/systemC/TLM-2009-07-15/include/tlm/tlm_utils -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


