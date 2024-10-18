INCLUDE_PATH = ../../raylib/
SOURCE_INCLUDE_PATH = include/
LIBRARY_PATH = libraylib.a
SOURCE_FILES = source/*.cpp source/objects/*.cpp
ARGUMENTS = -Wno-missing-braces -Wall
PRECOMPILED_HEADER_PATH = include/pch
PROGRAM_NAME = game
CPP_VERSION = 17

DEFAULT_OS = mac

default: all_$(DEFAULT_OS)

all_win: win run
all_mac: mac run

win:
	g++ $(SOURCE_FILES) -o $(PROGRAM_NAME) -include $(PRECOMPILED_HEADER_PATH)/PCH.hpp $(ARGUMENTS) -std=c++$(CPP_VERSION) -I $(INCLUDE_PATH) -I $(SOURCE_INCLUDE_PATH) -L $(INCLUDE_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm
win_fast:
	g++ -static -O2 $(SOURCE_FILES) -o $(PROGRAM_NAME) $(ARGUMENTS) -std=c++$(CPP_VERSION) -I $(INCLUDE_PATH) -I $(SOURCE_INCLUDE_PATH) -L $(INCLUDE_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm

mac:
	time g++ $(ARGUMENTS) -include $(PRECOMPILED_HEADER_PATH)/PCH.hpp $(SOURCE_FILES) -std=c++$(CPP_VERSION) -I $(INCLUDE_PATH) -I $(SOURCE_INCLUDE_PATH) -L $(INCLUDE_PATH) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL $(INCLUDE_PATH)$(LIBRARY_PATH) -o $(PROGRAM_NAME)
mac_fast:
	g++ -O2 $(ARGUMENTS) $(SOURCE_FILES) -std=c++$(CPP_VERSION) -I $(INCLUDE_PATH) -I $(SOURCE_INCLUDE_PATH) -L $(INCLUDE_PATH) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL $(INCLUDE_PATH)$(LIBRARY_PATH) -o $(PROGRAM_NAME)

run:
	./$(PROGRAM_NAME)

pch:
	g++ -std=c++$(CPP_VERSION) -I $(INCLUDE_PATH) -x c++-header $(PRECOMPILED_HEADER_PATH)/PCH.cpp -o $(PRECOMPILED_HEADER_PATH)/PCH.hpp.gch

clear:
	rm $(PRECOMPILED_HEADER_PATH)/PCH.hpp.gch
	rm $(PROGRAM_NAME)