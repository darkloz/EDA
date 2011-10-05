################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Garbage\ Collector.cpp 

OBJS += \
./src/Garbage\ Collector.o 

CPP_DEPS += \
./src/Garbage\ Collector.d 


# Each subdirectory must supply rules for building sources it contributes
src/Garbage\ Collector.o: ../src/Garbage\ Collector.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Garbage Collector.d" -MT"src/Garbage\ Collector.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


