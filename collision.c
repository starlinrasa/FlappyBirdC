#include "header.h"

//////////////// MODIFICATION 4 /////////////////////////////////
int CollisionGameOver(SDL_Rect positionFlap) {
	int res=0;
	if(!(poss.positiontuy1[globall.compteur].x >= positionFlap.x + globall.flapxd)
 	||(poss.positiontuy1[globall.compteur].x + 60 <= positionFlap.x+globall.flapxg)
  	|| (poss.positiontuy1[globall.compteur].y >= positionFlap.y + globall.flapxb) 
  	|| (poss.positiontuy1[globall.compteur].y + 385 <= positionFlap.y+globall.flapxh));

	else res++;

	if((poss.positiontuy2[globall.compteur].x >= positionFlap.x + globall.flapxd)
        || (poss.positiontuy2[globall.compteur].x + 60 <= positionFlap.x+globall.flapxg)
        || (poss.positiontuy2[globall.compteur].y >= positionFlap.y + globall.flapxb)
        || (poss.positiontuy2[globall.compteur].y +400 <= positionFlap.y)
        );
	else res++;
	
	if(positionFlap.y>=640)res++;

  	return res!=0?1:0;
}
//////////////// MODIFICATION 4 /////////////////////////////////

/*
int Collision(SDL_Rect positionFlap) {
  if((poss.positiontuy1[globall.compteur].x >= positionFlap.x + globall.flapxd)// trop à droite
     || (poss.positiontuy1[globall.compteur].x + 60 <= positionFlap.x+globall.flapxg) // trop à gauche
     || (poss.positiontuy1[globall.compteur].y >= positionFlap.y + globall.flapxb) // trop en bas
     || (poss.positiontuy1[globall.compteur].y + 385 <= positionFlap.y+globall.flapxh)  // trop en haut

     ){
    return 0;
  }
  else
    return 1;
}

int Collision2 (SDL_Rect positionFlap) {
 

  if ( (poss.positiontuy2[globall.compteur].x >= positionFlap.x + globall.flapxd)
       || (poss.positiontuy2[globall.compteur].x + 60 <= positionFlap.x+globall.flapxg)
       || (poss.positiontuy2[globall.compteur].y >= positionFlap.y + globall.flapxb)
       || (poss.positiontuy2[globall.compteur].y +400 <= positionFlap.y)
       ) { 
	

    return 0;
  }
  else{

          return 1;
}
}
*/


