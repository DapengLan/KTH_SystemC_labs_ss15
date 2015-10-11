################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/memory.cpp \
../src/tb_mem.cpp \
../src/tb_noise.cpp 

OBJS += \
./src/main.o \
./src/memory.o \
./src/tb_mem.o \
./src/tb_noise.o 

CPP_DEPS += \
./src/main.d \
./src/memory.d \
./src/tb_mem.d \
./src/tb_noise.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX11__ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


