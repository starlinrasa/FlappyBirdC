#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


void jouer (void);
void score (int sco);
int randii (int a, int b);
int Collision (SDL_Rect positionFlap);
int Collision2 (SDL_Rect positionFlap);
void menuoption (void);
void pos (void);
void jouer (void);
void menujouer (void);
void menu (void);
void menuscore (void);

#define TUY 100 // Nombre de tuyaux définis

 



struct Globale{
  int tyx,tuyo;

  int vitesse;

  int depart;

  int ecart;

  int compteur;

  int perso,music,fin,finn;
    
  int flapxg,flapxd,flapxh,flapxb;
	
	
};
typedef struct Globale Globale;

Globale globall;



struct pos{
  SDL_Rect positiontuy1[TUY],positiontuy2[TUY];
  int tuyx[TUY];
};


typedef struct pos Position;

Position poss;


////////////// MODIFICATION 3 ///////////////////
enum{
TYPE_ecran=0,
TYPE_fond=1,
TYPE_flap=2,
TYPE_tuy1=3,
TYPE_tuy2=4,
TYPE_dist=5,
TYPE_texte=6,
TYPE_crash=7,
TYPE_score2=8,
};
////////////// MODIFICATION 3 ///////////////////

