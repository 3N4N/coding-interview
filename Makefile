CC     := g++
CFLAGS := -g -I inc/ -fsanitize=address
LIBS   := -lasan

SRCS   := $(wildcard src/*.cpp)
SRCS   := $(filter-out src/test.cpp, $(SRCS))
OBJS   := $(patsubst src/%.cpp,bin/%.o,$(SRCS))
DEPS   := $(patsubst src/%.cpp,bin/%.d,$(SRCS))
DIRS   := src inc bin
EXE    := a.out

all: $(DIRS) $(EXE)

debug: CFLAGS += -D DEBUG
debug: $(DIRS) $(EXE)

$(DIRS):
	mkdir -p $@

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

bin/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< -MMD -MF $(@:.o=.d)

-include $(DEPS)

clean:
	rm -rf bin *~ *.o *.out $(EXE)
