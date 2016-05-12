#include "header.h"


void menuoption (void) {
  SDL_Surface *ecran=NULL, *fond=NULL,*dragon=NULL,*flap = NULL,*avion= NULL,*son=NULL,*cadre=NULL;
  SDL_Rect positionFond,positionFlap,positionDragon,positionAvion,positionSon,positionCadre;
 
  int j=0;
    
  ecran = SDL_SetVideoMode(840, 680, 32,SDL_HWSURFACE | SDL_DOUBLEBUF); // resolution a revoir

  SDL_Event evente;
    
  positionFond.x=0;
  positionFond.y=0;
    
  positionFlap.x=120;
  positionFlap.y=200;
    
  positionDragon.x=340;
  positionDragon.y=200;
    
  positionAvion.x=560;
  positionAvion.y=200;
    
  positionSon.x=220;
  positionSon.y=400;
    
  positionCadre.x=positionFlap.x-30;
  positionCadre.y=positionFlap.y-35;
    
  fond = IMG_Load("Images/fond.png");
  son =  IMG_Load("Images/optionson.png");
    
  cadre = IMG_Load("Images/cadre.png");
    
  while (!globall.finn)
    {
    
        
      //---------------------------- Flappy ----------------------------------
    
      if(j%4==0){
        flap = IMG_Load("Images/bird1.png");
      }
    
      if(j%4==1){
        flap = IMG_Load("Images/bird2.png");
      }
      if(j%4==2){
        flap = IMG_Load("Images/bird1.png");
      }
      if(j%4==3){
        flap = IMG_Load("Images/bird3.png");
      }
    
    
      //---------------------------- Dragon ------------------------------------
    
      if(j%10==0){
        dragon = IMG_Load("Images/dragon1.png");
      }//
    
      if(j%10==1){
        dragon = IMG_Load("Images/dragon2.png");
      }
    
      if(j%10==2){
        dragon = IMG_Load("Images/dragon3.png");
      }//
    
      if(j%10==3){
        dragon = IMG_Load("Images/dragon4.png");
      }
    
      if(j%10==4){
        dragon = IMG_Load("Images/dragon5.png");
      }
    
      if(j%10==5){
        dragon = IMG_Load("Images/dragon6.png");
      }
    
      if(j%10==6){
        dragon = IMG_Load("Images/dragon7.png");
      }
    
      if(j%10==7){
        dragon = IMG_Load("Images/dragon8.png");
      }
    
      if(j%10==8){
        dragon = IMG_Load("Images/dragon9.png");
      }
    
      if(j%10==9){
        dragon = IMG_Load("Images/dragon10.png");
      }

      //----------------------------- Avion ----------------------------------

      if(j%2==0){
        avion = IMG_Load("Images/avion1.png");
      }//
    
      if(j%2==1){
        avion = IMG_Load("Images/avion2.png");
      }
        
      //----------------------------- Son --------------------------------------
    
      while(SDL_PollEvent(&evente)){
        switch(evente.type)
	  {
	  case SDL_QUIT:
	    globall.fin=1;
	    globall.finn=1;
	    break;
                
	  case SDL_MOUSEBUTTONUP:
	    if (evente.button.button == SDL_BUTTON_LEFT){
	      if (evente.button.x >= positionFlap.x && evente.button.x <= positionFlap.x + 60 && evente.button.y >= positionFlap.y && evente.button.y <= positionFlap.y + 45){
                        
		positionCadre.x=positionFlap.x-30;
		positionCadre.y=positionFlap.y-35;
		globall.perso=1;
                      
		break;
	      }
	      if (evente.button.x >= positionDragon.x && evente.button.x <= positionDragon.x + 75 && evente.button.y >= positionDragon.y && evente.button.y <= positionDragon.y + 65){
                        
		positionCadre.x=positionDragon.x-25;
		positionCadre.y=positionDragon.y-30;
		globall.perso=2;
                       
		break;
	      }
	      if (evente.button.x >= positionAvion.x && evente.button.x <= positionAvion.x + 115 && evente.button.y >= positionAvion.y && evente.button.y <= positionAvion.y + 65){
                        
		positionCadre.x=positionAvion.x-3;
		positionCadre.y=positionAvion.y-35;
		globall.perso=3;
                       
		break;
	      }
                    
	      if (evente.button.x >= positionSon.x+164 && evente.button.x <= positionSon.x + 188 && evente.button.y >= positionSon.y+11 && evente.button.y <= positionSon.y + 32){
                        
		son =  IMG_Load("Images/optionsonoui.png");
		globall.music=0;
		globall.finn=1;
                        
		break;
	      }
                    
	      if (evente.button.x >= positionSon.x+252 && evente.button.x <= positionSon.x + 276 && evente.button.y >= positionSon.y+10 && evente.button.y <= positionSon.y + 32){
                        
		son =  IMG_Load("Images/optionsonnon.png");
		globall.music=1;
		globall.finn=1;
                        
		break;
	      }
                    
                    
	    }
	    break;
                
	  default:break;
	  }}
      j++;
      SDL_Delay(50);
        
    
      SDL_BlitSurface(fond, NULL, ecran, &positionFond);
      SDL_BlitSurface(cadre, NULL, ecran, &positionCadre);
      SDL_BlitSurface(flap, NULL, ecran, &positionFlap);
      SDL_BlitSurface(dragon, NULL, ecran, &positionDragon);
      SDL_BlitSurface(avion, NULL, ecran, &positionAvion);
      SDL_BlitSurface(son, NULL, ecran, &positionSon);
        
      SDL_Flip(ecran);
    
    }
  SDL_FreeSurface(fond);
  SDL_FreeSurface(flap);
  SDL_FreeSurface(dragon);
  SDL_FreeSurface(avion);
  SDL_FreeSurface(cadre);
    
  jouer();
}
