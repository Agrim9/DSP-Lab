################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lab2main.c \
../sine_checkpoint.c 

CMD_SRCS += \
../lnkx.cmd 

OBJS += \
./lab2main.obj \
./sine_checkpoint.obj 

C_DEPS += \
./lab2main.pp \
./sine_checkpoint.pp 

OBJS__QTD += \
".\lab2main.obj" \
".\sine_checkpoint.obj" 

C_DEPS__QTD += \
".\lab2main.pp" \
".\sine_checkpoint.pp" 

C_SRCS_QUOTED += \
"../lab2main.c" \
"../sine_checkpoint.c" 


# Each subdirectory must supply rules for building sources it contributes
lab2main.obj: ../lab2main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/TI/ccsv4/emulation/boards/usbstk5515_v1/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="lab2main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

sine_checkpoint.obj: ../sine_checkpoint.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/TI/ccsv4/emulation/boards/usbstk5515_v1/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="sine_checkpoint.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


