#inspired by:
# https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files

BUILDDIR = . 
SOURCEDIR = ../src
NAME = TicTacToe
RM = del

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

cppFiles := $(call rwildcard,$(SOURCEDIR),*.cpp)

oFiles := $(wildcard *.o)

all: $(NAME).exe

$(NAME).exe: $(oFiles)
	g++ $(cppFiles) -o $(NAME)

clean:
	$(RM) $(NAME).exe
