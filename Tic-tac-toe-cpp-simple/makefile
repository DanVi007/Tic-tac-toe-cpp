#https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

files := $(call rwildcard,src/,*.o)

TicTacToe: $(files)
	cd src/ && make -f makefile.main
	g++ $(files) -o TicTacToe

#rm does not work for some reason 
#https://stackoverflow.com/questions/33674973/makefile-error-make-e-2-the-system-cannot-find-the-file-specified
clean:
	cd src/ && make -f makefile.main clean
	del TicTacToe.exe

