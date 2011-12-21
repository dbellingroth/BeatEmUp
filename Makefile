CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CFLAGS  = 
LFLAGS = `sdl-config --cflags --static-libs`
EXEC_NAME = BeatEmUp

all: $(OBJ_FILES)
	g++ -o $(EXEC_NAME) $(OBJ_FILES)  $(LFLAGS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(CFLAGS)
