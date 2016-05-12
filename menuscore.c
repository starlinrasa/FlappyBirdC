#include "header.h"

void menuscore (void) {

  SDL_Surface *ecran=NULL, *fond=NULL,*score=NULL,*dist = NULL;
  SDL_Rect positionFond,positionScore,positionDistance;
  TTF_Font *police2 = NULL;
  int dis=0;
////////////// MODIFICATION 2 ///////////////////
  ecran = SDL_SetVideoMode(840,640, 32,SDL_HWSURFACE | SDL_DOUBLEBUF); // resolution a revoir
////////////// MODIFICATION 2 ///////////////////
  SDL_Color couleurFond = {219,218, 150,0};
  SDL_Color couleurNoir = {0, 0, 0,0};
  char distance[20]="";
    
  positionFond.x=0;
  positionFond.y=0;
    
  positionScore.x=200;
  positionScore.y=200;
    
  positionDistance.x=550;
  positionDistance.y=305;
    
 
  fond = IMG_Load("Images/fond.png");
  score = IMG_Load("Images/score.png");
  police2 = TTF_OpenFont("racer.ttf", 40);
    
  FILE * in;
  in = fopen("score.txt","r");
    
  int c;
    
  fscanf(in,"%d",&c);
    
  fclose(in);
    
  dis = c;
  sprintf(distance, "%d", dis);
  dist = TTF_RenderText_Shaded(police2, distance, couleurNoir,couleurFond);
    
 
    
 
  SDL_BlitSurface(fond, NULL, ecran, &positionFond);
  SDL_BlitSurface(score, NULL, ecran, &positionScore);
  SDL_BlitSurface(dist, NULL, ecran, &positionDistance);
  SDL_Flip(ecran);
  SDL_Delay(550);
 
  SDL_FreeSurface(fond);
  SDL_FreeSurface(score);
  TTF_CloseFont(police2);
  SDL_FreeSurface(dist);

 
}
