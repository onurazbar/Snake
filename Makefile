EXEC = snake

BINDIR = bin
OBJDIR = obj
SRCDIR = src
INCDIR = include

CXX = g++
CXXFLAGS = -Wall
SFML = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(EXEC): $(OBJDIR) $(OBJECTS) $(BINDIR)
	$(CXX) $(OBJECTS) $(SFML) -o $@

$(BINDIR):
	mkdir -p ./$(BINDIR)

$(OBJDIR):
	mkdir -p ./$(OBJDIR)

$(OBJDIR)/Main.o: $(SRCDIR)/Main.cpp $(OBJDIR)/Game.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Game.o: $(SRCDIR)/Game.cpp $(INCDIR)/Game.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR) $(OBJDIR)