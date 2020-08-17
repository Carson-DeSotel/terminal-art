DEFAULT = pokeball.ppm

all : 
	g++ -o terminal-art *.cpp
default : terminal-art
	@./terminal-art ${DEFAULT}
clean : 
	@rm terminal-art
