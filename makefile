CXX ?= g++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror -MMD -MP -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fPIC

SRCDIR = src
INCDIR = include
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(addprefix $(BINDIR)/, $(notdir $(SRCS:.cpp=.o)))
TARGET = main.out

.PHONY: compile clean run release debug

$(BINDIR)/$(TARGET): $(BINDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCDIR)

-include $(OBJS:.o=.d)

$(BINDIR):
	mkdir -p $(BINDIR)

compile: $(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJS) $(BINDIR)/$(TARGET)

run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

release: CXXFLAGS += -O2 -march=native
debug: CXXFLAGS += -g -O0 -fsanitize=address,undefined
