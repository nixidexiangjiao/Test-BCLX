################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BadDude.cpp \
../src/Gunslinger.cpp \
../src/Person.cpp \
../src/PokerPlayer.cpp \
../src/Test-BCLX.cpp \
../src/bclx144.cpp 

OBJS += \
./src/BadDude.o \
./src/Gunslinger.o \
./src/Person.o \
./src/PokerPlayer.o \
./src/Test-BCLX.o \
./src/bclx144.o 

CPP_DEPS += \
./src/BadDude.d \
./src/Gunslinger.d \
./src/Person.d \
./src/PokerPlayer.d \
./src/Test-BCLX.d \
./src/bclx144.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


