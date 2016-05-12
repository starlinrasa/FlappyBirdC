#include "header.h"

void score(int sco) {

  
  FILE * in;
  in = fopen("score.txt","r");
  
  int c;

  fscanf(in,"%d",&c);

  fclose(in);

  if (c < sco) {

    in = fopen("score.txt","w");
    fprintf(in,"%d",sco); 


    fclose(in);
  }

}


int randii(int a, int b){
  return rand()%(b-a)+a;
}

void pos()
{
	
  for(globall.tyx = 0; globall.tyx != TUY ; globall.tyx++) {

    poss.tuyx[globall.tyx] = globall.depart;
    poss.positiontuy1[globall.tyx].y = randii(-200,0);
    poss.positiontuy1[globall.tyx].x = poss.tuyx[globall.tyx];

    poss.positiontuy2[globall.tyx].y = poss.positiontuy1[globall.tyx].y +400+ 120;
    poss.positiontuy2[globall.tyx].x = poss.tuyx[globall.tyx];
    globall.depart += globall.ecart;

			
  }
	
}
