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
../src/bclx111test.cpp \
../src/bclx112test.cpp \
../src/bclx121test.cpp \
../src/bclx123test.cpp \
../src/bclx124test.cpp \
../src/bclx131test.cpp \
../src/bclx134test.cpp \
../src/bclx144.cpp \
../src/bclx177test.cpp 

OBJS += \
./src/BadDude.o \
./src/Gunslinger.o \
./src/Person.o \
./src/PokerPlayer.o \
./src/Test-BCLX.o \
./src/bclx111test.o \
./src/bclx112test.o \
./src/bclx121test.o \
./src/bclx123test.o \
./src/bclx124test.o \
./src/bclx131test.o \
./src/bclx134test.o \
./src/bclx144.o \
./src/bclx177test.o 

CPP_DEPS += \
./src/BadDude.d \
./src/Gunslinger.d \
./src/Person.d \
./src/PokerPlayer.d \
./src/Test-BCLX.d \
./src/bclx111test.d \
./src/bclx112test.d \
./src/bclx121test.d \
./src/bclx123test.d \
./src/bclx124test.d \
./src/bclx131test.d \
./src/bclx134test.d \
./src/bclx144.d \
./src/bclx177test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


