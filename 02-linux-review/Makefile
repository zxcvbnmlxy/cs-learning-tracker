CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS  =

SRCDIR   = src
BUILDDIR = build
TARGET   = $(BUILDDIR)/memory_demo

SRCS     = main.cpp $(SRCDIR)/memory_demo.cpp
OBJS     = $(SRCS:%.cpp=$(BUILDDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Build complete: $@"

$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)
	@echo "Cleaned"

run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS += -DDEBUG -O0
debug: all

.PHONY: all clean run debug
