#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
TOPDIR ?= $(CURDIR)

CC := clang++


#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing header files
#---------------------------------------------------------------------------------

APP_TITLE := openmelee

TARGET 		:= build/$(APP_TITLE)
BUILD 		:= build/linux
SOURCES 	:= source
INCLUDES 	:= source


#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS	:= 


#---------------------------------------------------------------------------------
# source file finding
#---------------------------------------------------------------------------------
SRCEXT 		:= cpp
SRC_FILES 	:= $(shell find $(SOURCES) -type f -name *.$(SRCEXT))
OBJECTS 	:= $(patsubst $(SOURCES)/%,$(BUILD)/%,$(SRC_FILES:.$(SRCEXT)=.o))

INCDIRS 	:= $(shell find $(INCLUDES)/**/* -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST 	:= $(patsubst $(INCLUDES)/%,-I $(INCLUDES)/%,$(INCDIRS))

INCLUDE 	:= -I $(INCLUDES) $(INCLIST) -I /usr/local/include \
	$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
	-D_GNU_SOURCE=1 -D_THREAD_SAFE
BUILDLIST 	:= $(patsubst $(INCLUDES)/%,$(BUILD)/%,$(INCDIRS))


#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
CFLAGS	:=	-g -MD -W -O2 -fpermissive -ffunction-sections $(DEFINES)

CFLAGS	+=	$(INCLUDE) -Wmissing-field-initializers -Wno-gnu-designator -Wno-unused-value -D__LINUX__

CXXFLAGS	:= $(CFLAGS) -Wno-missing-field-initializers -Wno-implicit-fallthrough -std=c++17

ASFLAGS	:=	-g $(ARCH)
LDFLAGS	=	-specs=${DEVKITPRO}/libnx/switch.specs -g -Wl,-Map,$(notdir $*.map)

LIBS	:= -lm -lGLEW -lglfw -lGL

#---------------------------------------------------------------------------------
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "  Linking $(APP_TITLE)"; $(CC) $^ -o $(TARGET) $(LIBS)

$(BUILD)/%.o: $(SOURCES)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "Compiling $<..."; $(CC) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -rf $(BUILD) $(TARGET)
run:
	@./build/openmelee

.PHONY: clean