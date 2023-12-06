################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/personal\ project.cpp 

OBJS += \
./src/personal\ project.o 

CPP_DEPS += \
./src/personal\ project.d 


# Each subdirectory must supply rules for building sources it contributes
src/personal\ project.o: ../src/personal\ project.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/personal project.d" -MT"src/personal\ project.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


