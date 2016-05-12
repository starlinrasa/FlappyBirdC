#include "header.h"


int main(int argc, char *argv[]) {
		
  globall.vitesse = 15;
  globall.depart =600;
  globall.ecart = 175;
  globall.compteur = 0;
  globall.perso=1;
  globall.music=0;
  globall.fin = 0;
  globall.finn=0;
  globall.flapxg=7;
  globall.flapxd=45;
  globall.flapxh=7;
  globall.flapxb=35;
    
    
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_TIMER);
  TTF_Init();
    
  SDL_WM_SetCaption("Flappy bird", NULL);
    
  menu();
    
  TTF_Quit();
  SDL_Quit();
    
  return 0;
}

