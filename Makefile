CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CFLAGS  = 
LFLAGS = `sdl-config --cflags --static-libs`
EXEC_NAME = BeatEmUp
OS := $(shell uname)
ifeq ($(OS), Linux)
LFLAGS = -lGL -lglut `sdl-config --cflags --static-libs`
endif

all: $(OBJ_FILES)
	g++ -o $(EXEC_NAME) $(OBJ_FILES)  $(LFLAGS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(CFLAGS)
