# FlappyBird
CC= gcc -w -Wall
FLAGS=  `sdl-config --cflags --libs` -lSDL_ttf -lSDL_image -lSDL_mixer 
SRC= mainF.c inis.c collision.c menuoption.c cerveau.c menu.c menuoption.c menurejouer.c menuscore.c
OBJ= $(SRC:%.c=%.o)

jouer:	$(OBJ) 
	$(CC) $^ -o $@ $(FLAGS)

%.o:	%.c
	$(CC) -c -o $@ $^ $(FLAGS)

clean:	
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f jouer
