#include "header.h"


void menujouer (void) { 
  SDL_Surface *ecran=NULL, *fond=NULL;
  SDL_Rect positionFond;
  int finnn=0;
    
    
  ecran = SDL_SetVideoMode(840, 680, 32,SDL_HWSURFACE | SDL_DOUBLEBUF); // resolution a revoir
    
  SDL_Event evente;
    
  positionFond.x=0;
  positionFond.y=0;
    
  globall.compteur=0;
  fond = IMG_Load("Images/rejouer.png");

  while (!finnn)
    {
      while(SDL_PollEvent(&evente)){
	switch(evente.type)
	  {
	  case SDL_QUIT:
                    
	    globall.finn=1;
	    break;
                    
	  case SDL_MOUSEBUTTONUP:
	    if (evente.button.button == SDL_BUTTON_LEFT){
	      if (evente.button.x >= 287 && evente.button.x <= 388 && evente.button.y >= 259 && evente.button.y <= 290){
		jouer();
		break;
	      }
	      if (evente.button.x >= 433 && evente.button.x <= 549 && evente.button.y >= 259 && evente.button.y <= 290){
                         
		exit(0);
		break;
	      }
	    }
	    break;
                    
	  default:break;
	  }
      }
        
      SDL_BlitSurface(fond, NULL, ecran, &positionFond);
        
      SDL_Flip(ecran);
    }
  SDL_FreeSurface(fond);
}

