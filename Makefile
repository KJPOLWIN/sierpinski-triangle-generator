SFMLINC = D:\SFML-2.5.1\include
SFMLLIB = D:\SFML-2.5.1\lib
#SFML = -lsfml-graphics -lsfml-window -lsfml-system
SFML = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 -lopengl32 -lwinmm -lgdi32 -D SFML_STATIC
INC = ./include/
SRC = ./source/

TITLE = Sierpinski_triangle_generator

OPTIONS = -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wpedantic

OBJ = main.o

output: $(OBJ)
	g++ $(OBJ) -o $(TITLE).exe -L$(SFMLLIB) -mwindows $(SFML)
	
debug: $(OBJ)
	g++ $(OBJ) -g -o $(TITLE)-debug.exe -L$(SFMLLIB) -static-libstdc++ $(SFML)

main.o: $(SRC)main.cpp
	g++ -c $(SRC)main.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I./include