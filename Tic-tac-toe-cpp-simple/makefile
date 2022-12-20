#https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

files := $(call rwildcard,src/,*.o)

TicTacToe: $(files)
	cd src/ && make -f makefile.main
	echo $(files)
	g++ $(files) -o TicTacToe

clean:
	cd src/ && make -f makefile.main clean

