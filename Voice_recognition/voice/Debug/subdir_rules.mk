################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
CVECTORS.obj: ../CVECTORS.ASM $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5400 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5400_4.2.0/bin/cl500" --define=c5402 --include_path="C:/ti/ccsv5/tools/compiler/c5400_4.2.0/include" --include_path="E:/DSP/workspace/Voice_recognition/headerfile" --symdebug:dwarf --diag_warning=225 --display_error_number --silicon_version=548 --preproc_with_compile --preproc_dependency="CVECTORS.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

McBSP.obj: ../McBSP.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5400 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5400_4.2.0/bin/cl500" --define=c5402 --include_path="C:/ti/ccsv5/tools/compiler/c5400_4.2.0/include" --include_path="E:/DSP/workspace/Voice_recognition/headerfile" --symdebug:dwarf --diag_warning=225 --display_error_number --silicon_version=548 --preproc_with_compile --preproc_dependency="McBSP.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

exram.obj: ../exram.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5400 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5400_4.2.0/bin/cl500" --define=c5402 --include_path="C:/ti/ccsv5/tools/compiler/c5400_4.2.0/include" --include_path="E:/DSP/workspace/Voice_recognition/headerfile" --symdebug:dwarf --diag_warning=225 --display_error_number --silicon_version=548 --preproc_with_compile --preproc_dependency="exram.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5400 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5400_4.2.0/bin/cl500" --define=c5402 --include_path="C:/ti/ccsv5/tools/compiler/c5400_4.2.0/include" --include_path="E:/DSP/workspace/Voice_recognition/headerfile" --symdebug:dwarf --diag_warning=225 --display_error_number --silicon_version=548 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

