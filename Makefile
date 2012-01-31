CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CFLAGS  = 
LFLAGS = -lSDL_image  `sdl-config --cflags --static-libs`
EXEC_NAME = BeatEmUp
OS := $(shell uname)
ifeq ($(OS), Linux)
LFLAGS = -lglut -lSDLmain -lSDL -lSDL_image -lGL `sdl-config --cflags --static-libs`
endif

all: $(OBJ_FILES)
	g++ -o $(EXEC_NAME) $(OBJ_FILES)  $(LFLAGS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(CFLAGS)

clean:
	rm obj/*