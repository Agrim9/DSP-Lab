################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main_saregama.c 

CMD_SRCS += \
../lnkx.cmd 

OBJS += \
./main_saregama.obj 

C_DEPS += \
./main_saregama.pp 

OBJS__QTD += \
".\main_saregama.obj" 

C_DEPS__QTD += \
".\main_saregama.pp" 

C_SRCS_QUOTED += \
"../main_saregama.c" 


# Each subdirectory must supply rules for building sources it contributes
main_saregama.obj: ../main_saregama.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/TI/ccsv4/emulation/boards/usbstk5515_v1/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main_saregama.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


