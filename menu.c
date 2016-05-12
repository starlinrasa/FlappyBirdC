#include "header.h"


void menu (void) {

  SDL_Surface *ecran=NULL, *fond=NULL;
  SDL_Rect positionFond;
    
    
  ecran = SDL_SetVideoMode(840, 680, 32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE ); // resolution a revoir
    
  SDL_Event evente;
    
  positionFond.x=0;
  positionFond.y=0;
    
  fond = IMG_Load("Images/menu.png");
    
  while (!globall.finn)
    {
      while(SDL_PollEvent(&evente)){
	switch(evente.type)
	  {
	  case SDL_QUIT:
                    
	    globall.finn=1;
	    break;
                    
	  case SDL_MOUSEBUTTONUP:
	    if (evente.button.button == SDL_BUTTON_LEFT){
	      if (evente.button.x >= 335 && evente.button.x <= 454 && evente.button.y >= 179 && evente.button.y <= 205){
		jouer();
		break;
	      }
	      if (evente.button.x >= 335 && evente.button.x <= 454 && evente.button.y >= 266 && evente.button.y <= 290){
                            
		menuscore();
		break;
	      }
	      if (evente.button.x >= 324 && evente.button.x <= 469  && evente.button.y >= 338 && evente.button.y <= 364){
                          
		menuoption();
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
