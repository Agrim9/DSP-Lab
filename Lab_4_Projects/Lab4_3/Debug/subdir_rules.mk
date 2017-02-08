################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
asmcircbuff.obj: ../asmcircbuff.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/opt/ti/ccsv7/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/opt/ti/ccsv7/tools/compiler/c5500_4.4.1/include" --include_path="/home/agrim/Downloads/C5515_Support_Files/C5515_Includes" --define=c5515 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="asmcircbuff.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"/opt/ti/ccsv7/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="/opt/ti/ccsv7/tools/compiler/c5500_4.4.1/include" --include_path="/home/agrim/Downloads/C5515_Support_Files/C5515_Includes" --define=c5515 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


