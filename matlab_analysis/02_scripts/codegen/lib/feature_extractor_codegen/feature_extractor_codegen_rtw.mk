###########################################################################
## Makefile generated for component 'feature_extractor_codegen'. 
## 
## Makefile     : feature_extractor_codegen_rtw.mk
## Generated on : Tue Sep 16 20:44:30 2025
## Final product: ./feature_extractor_codegen.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = feature_extractor_codegen
MAKEFILE                  = feature_extractor_codegen_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2025a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2025a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/dltjr/OneDrive/Desktop/git/Project-GH/matlab_analysis/02_scripts
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = feature_extractor_codegen_rtw_comp.rsp
CMD_FILE                  = feature_extractor_codegen_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = feature_extractor_codegen.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    8.x
# ToolchainInfo Version:   2025a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./feature_extractor_codegen.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=feature_extractor_codegen

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_data.c $(START_DIR)/codegen/lib/feature_extractor_codegen/rt_nonfinite.c $(START_DIR)/codegen/lib/feature_extractor_codegen/rtGetNaN.c $(START_DIR)/codegen/lib/feature_extractor_codegen/rtGetInf.c $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_initialize.c $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_terminate.c $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen.c $(START_DIR)/codegen/lib/feature_extractor_codegen/mean.c $(START_DIR)/codegen/lib/feature_extractor_codegen/blockedSummation.c $(START_DIR)/codegen/lib/feature_extractor_codegen/std.c $(START_DIR)/codegen/lib/feature_extractor_codegen/rms.c $(START_DIR)/codegen/lib/feature_extractor_codegen/corrcoef.c $(START_DIR)/codegen/lib/feature_extractor_codegen/minOrMax.c $(START_DIR)/codegen/lib/feature_extractor_codegen/periodogram.c $(START_DIR)/codegen/lib/feature_extractor_codegen/FFTImplementationCallback.c $(START_DIR)/codegen/lib/feature_extractor_codegen/gradient.c $(START_DIR)/codegen/lib/feature_extractor_codegen/abs.c $(START_DIR)/codegen/lib/feature_extractor_codegen/norm.c $(START_DIR)/codegen/lib/feature_extractor_codegen/sum.c $(START_DIR)/codegen/lib/feature_extractor_codegen/var.c $(START_DIR)/codegen/lib/feature_extractor_codegen/trapz.c $(START_DIR)/codegen/lib/feature_extractor_codegen/findpeaks.c $(START_DIR)/codegen/lib/feature_extractor_codegen/eml_setop.c $(START_DIR)/codegen/lib/feature_extractor_codegen/pca.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xzsvdc.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xzlangeM.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xnrm2.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xdotc.c $(START_DIR)/codegen/lib/feature_extractor_codegen/geomean.c $(START_DIR)/codegen/lib/feature_extractor_codegen/sqrt.c $(START_DIR)/codegen/lib/feature_extractor_codegen/sort.c $(START_DIR)/codegen/lib/feature_extractor_codegen/sortIdx.c $(START_DIR)/codegen/lib/feature_extractor_codegen/insertionsort.c $(START_DIR)/codegen/lib/feature_extractor_codegen/introsort.c $(START_DIR)/codegen/lib/feature_extractor_codegen/heapsort.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xaxpy.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xrotg.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xrot.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xswap.c $(START_DIR)/codegen/lib/feature_extractor_codegen/xzlascl.c $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_emxutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = feature_extractor_codegen_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj feature_extractor_codegen_initialize.obj feature_extractor_codegen_terminate.obj feature_extractor_codegen.obj mean.obj blockedSummation.obj std.obj rms.obj corrcoef.obj minOrMax.obj periodogram.obj FFTImplementationCallback.obj gradient.obj abs.obj norm.obj sum.obj var.obj trapz.obj findpeaks.obj eml_setop.obj pca.obj xzsvdc.obj xzlangeM.obj xnrm2.obj xdotc.obj geomean.obj sqrt.obj sort.obj sortIdx.obj insertionsort.obj introsort.obj heapsort.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj xzlascl.obj feature_extractor_codegen_emxutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feature_extractor_codegen_data.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feature_extractor_codegen_initialize.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feature_extractor_codegen_terminate.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feature_extractor_codegen.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/mean.c
	$(CC) $(CFLAGS) -o "$@" "$<"


blockedSummation.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/blockedSummation.c
	$(CC) $(CFLAGS) -o "$@" "$<"


std.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/std.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rms.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/rms.c
	$(CC) $(CFLAGS) -o "$@" "$<"


corrcoef.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/corrcoef.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/minOrMax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


periodogram.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/periodogram.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FFTImplementationCallback.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/FFTImplementationCallback.c
	$(CC) $(CFLAGS) -o "$@" "$<"


gradient.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/gradient.c
	$(CC) $(CFLAGS) -o "$@" "$<"


abs.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/abs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


norm.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/norm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sum.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/sum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


var.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/var.c
	$(CC) $(CFLAGS) -o "$@" "$<"


trapz.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/trapz.c
	$(CC) $(CFLAGS) -o "$@" "$<"


findpeaks.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/findpeaks.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_setop.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/eml_setop.c
	$(CC) $(CFLAGS) -o "$@" "$<"


pca.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/pca.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzsvdc.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xzsvdc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlangeM.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xzlangeM.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xdotc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


geomean.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/geomean.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sqrt.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/sqrt.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/sort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/sortIdx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


insertionsort.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/insertionsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


introsort.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/introsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


heapsort.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/heapsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xaxpy.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xrotg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xrot.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xswap.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlascl.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/xzlascl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feature_extractor_codegen_emxutil.obj : $(START_DIR)/codegen/lib/feature_extractor_codegen/feature_extractor_codegen_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


