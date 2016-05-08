CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
OUT_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.out)))
LD_FLAGS :=  
CC_FLAGS := -std=c++11

build: ${OUT_FILES}

obj/%.out: %.o
	   g++ $(LD_FLAGS) -o $@ $<

%.o: %.cpp
	   g++ $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f obj/*

