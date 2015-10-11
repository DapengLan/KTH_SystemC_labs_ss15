################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/channel.cpp \
../src/main.cpp \
../src/sink.cpp \
../src/source.cpp 

OBJS += \
./src/channel.o \
./src/main.o \
./src/sink.o \
./src/source.o 

CPP_DEPS += \
./src/channel.d \
./src/main.d \
./src/sink.d \
./src/source.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc-2.3.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


