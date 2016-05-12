#include "header.h"


void jouer (void) {
  
  int tempsA=0,tempsP=0,regle=0,i=0,dis=0;
  int grav = 0,bonus=0,avant=0;

SDL_Surface * tabSurface[9];

//////////// MODIFICATION 1 /////////////
int NBobjet=5;
int j,k;
char buf[100];
SDL_Surface *objet[NBobjet];
SDL_Rect posObjet[NBobjet];
for(j=0;j<NBobjet;j++){
posObjet[j].x=rand()%650+150;
posObjet[j].y=rand()%500+30;
}

//////////// MODIFICATION 1 /////////////

  SDL_Rect positionFond,positionFlap,positionDistance,positionTexte,positionCrash, positionDistance2;
    
  TTF_Font *police = NULL;
  TTF_Font *police2 = NULL;
  SDL_Color couleurRouge = {255,0, 0,0};
  SDL_Color couleurBlanche = {255, 255, 255,0};     //variable permettant d'afficher du blanc
  SDL_Color couleurVert = {83, 190, 206,0};
  SDL_Color couleurFond = {219,218, 150,0};
  SDL_Color couleurNoir = {0, 0, 0,0};
  char distance[20]="";

  srand(time(0));
  pos();
  
  // afftab(poss.tuyx,TUY);
  positionTexte.x=175;                            //abscisse du rectangle comportant le texte "You Lose"
  positionTexte.y=150;

  positionDistance.x=785;                         //abscisse du rectangle comportant la distance parcouru pendant le jeu
  positionDistance.y=15;
    
  positionFond.x=0;
  positionFond.y=0;
  
  positionFlap.x=30;
  positionFlap.y=200;
    
  positionDistance2.x=200;
  positionDistance2.y=300;
    
  

  
tabSurface[TYPE_ecran] = SDL_SetVideoMode(840, 680, 32,SDL_HWSURFACE | SDL_DOUBLEBUF); // resolution a revoir
  
    
  
 
  //  flap = IMG_Load("Images/bird.png");
  
  police2 = TTF_OpenFont("racer.ttf", 20);
  // flap = IMG_Load("Images/bird1.png");
  
//////////// MODIFICATION 3 /////////////
tabSurface[TYPE_fond] = IMG_Load("Images/flappy-bird.png");
tabSurface[TYPE_tuy1] = IMG_Load("Images/tuy1.png");
tabSurface[TYPE_tuy2] = IMG_Load("Images/tuy2.png");
tabSurface[TYPE_score2]= IMG_Load("Images/score2.png");
//////////// MODIFICATION 3 /////////////

//////////// MODIFICATION 1 /////////////
  objet[0]=IMG_Load("Images/Super_etoile2.png");
  objet[1]=IMG_Load("Images/glace.png");
  objet[2]=IMG_Load("Images/coca.gif");
  objet[3]=IMG_Load("Images/frite.gif");
  objet[4]=IMG_Load("Images/hum.gif");

//////////// MODIFICATION 1 /////////////


  SDL_BlitSurface(tabSurface[TYPE_fond], NULL, tabSurface[TYPE_ecran], &positionFond);
  SDL_Flip(tabSurface[TYPE_ecran]);
    
  sprintf(distance, "%d", dis);
  tabSurface[TYPE_dist] = TTF_RenderText_Shaded(police2, distance, couleurBlanche,couleurVert);
  
  if(tabSurface[TYPE_ecran] == NULL){
    printf("Impossible de charger le mode vidéo\n");
    exit(EXIT_FAILURE);
    
  }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
      printf("%s", Mix_GetError());
    }
    
  Mix_Music *musique; //Création du pointeur de type Mix_globall.music
  musique = Mix_LoadMUS("son/smb11.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer ingloball.finiment la musique
  Mix_VolumeMusic(MIX_MAX_VOLUME);
    
  Mix_AllocateChannels(7); //Allouer 3 canaux
  Mix_Volume(1, MIX_MAX_VOLUME); //Mettre à mi-volume le post 1
  Mix_Chunk *son,*son2,*son3,*son4,*son5,*son6;//Créer un pointeur pour stocker un .WAV
 
  son = Mix_LoadWAV("son/piece.wav");//Chargement de la musique
  Mix_VolumeChunk(son, MIX_MAX_VOLUME);
    
  son2 = Mix_LoadWAV("son/saut.wav");//Chargement de la musique
  Mix_VolumeChunk(son2, MIX_MAX_VOLUME);
    
  son3 = Mix_LoadWAV("son/game-over.wav");//Chargement de la musique
  Mix_VolumeChunk(son3, MIX_MAX_VOLUME);
    
  son4 = Mix_LoadWAV("son/Boum.wav");//Chargement de la musique
  Mix_VolumeChunk(son4, MIX_MAX_VOLUME);
    
  son5 = Mix_LoadWAV("son/Ziou!.wav");//Chargement de la musique
  Mix_VolumeChunk(son5, MIX_MAX_VOLUME);
    
  son6 = Mix_LoadWAV("son/Wouhouhou!.wav");//Chargement de la musique
  Mix_VolumeChunk(son6, MIX_MAX_VOLUME);
    
  if(globall.music==1){
    Mix_HaltMusic(); //Arrête la musique
  }
    
  while (!globall.fin)
    {

      SDL_Event event;
 

	  
      while (SDL_PollEvent(&event))
        {

	  switch (event.type)
            {
            case SDL_QUIT:
	      globall.fin = 1;
	      break;
	      
            case SDL_KEYDOWN:
	      {
		switch (event.key.keysym.sym){
		  
		case SDLK_ESCAPE:
		  {
		    
		    globall.fin = 1;
		    globall.finn=1;
		    
		  }
		  break;
                  
                case SDLK_SPACE:
		  {
		    Mix_PlayChannel(2, son2, 0);
		    positionFlap.y=positionFlap.y-40;
		    grav=1;
		    
		  }
		  break;
		case SDLK_RETURN:
	
		  regle=1;
		  break;
		default:;
		}
	      }
            }
        }
      
      if(regle==1){
	tabSurface[TYPE_fond] = IMG_Load("Images/fond.png");
          
         
		
	//	system("clear");
	//		printf("%d\n",globall.compteur);

	globall.depart = 600;


	if (poss.positiontuy1[globall.compteur].x+30 <= positionFlap.x) {
	  Mix_PlayChannel(1, son, 0);
	  globall.compteur += 1;
    
	}

	//printf("%d\n",globall.compteur);
	dis = globall.compteur; /* On rajoute 100 m au globall.compteur */
	sprintf(distance, "%d", dis); /* On Ècrit dans la chaÓne "distance" la nouvelle distance parcouru */
	SDL_FreeSurface(tabSurface[TYPE_dist]); /* On supprime la surface prÈcÈdente */
	tabSurface[TYPE_dist] = TTF_RenderText_Shaded(police2, distance, couleurBlanche,couleurVert); /* On Ècrit la chaÓne distance dans la SDL_Surface */

	SDL_BlitSurface(tabSurface[TYPE_dist], NULL, tabSurface[TYPE_ecran], &positionDistance); /* Blit de la distance parcouru */
	SDL_Flip(tabSurface[TYPE_ecran]);  //mis a jour de l'ecran
	
	tempsA = SDL_GetTicks();   //SDL_GetTicks : retourne le nombre de millisecondes écoulées depuis le lancement du programme.
	if (tempsA - tempsP >= 30) /* Si 30 ms se sont écoulées */
	  {
	    //flap = IMG_Load("Images/birddown.png");
	    
	    if(grav==0){
	      positionFlap.y += 10;
	    }else{
	      positionFlap.y += 7;
	     
	      for (globall.tyx = 0;globall.tyx != TUY ;globall.tyx++) {

		poss.positiontuy1[globall.tyx].x = poss.positiontuy1[globall.tyx].x-globall.vitesse;
		poss.positiontuy2[globall.tyx].x = poss.positiontuy2[globall.tyx].x-globall.vitesse;
       

	      }
//////////// MODIFICATION 1 /////////////
		int i;
		for(i=0;i<NBobjet;i++)
		  posObjet[i].x -=globall.vitesse;
//////////// MODIFICATION 1 /////////////
	    

	    }
	    tempsP = tempsA; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
	  }



//////////// MODIFICATION 1 /////////////

	for(j=0;j<NBobjet;j++)
	if((posObjet[j].x >= positionFlap.x + 45)//droite
	   || (posObjet[j].x + 30 <= positionFlap.x)//gauche
	   || (posObjet[j].y >= positionFlap.y + 35)//bas
	   || (posObjet[j].y + 35 <= positionFlap.y)//haut
	   ){       
	} else{
posObjet[j].x=rand()%650+150;
	posObjet[j].y=rand()%500+30;
	avant=globall.compteur;
	bonus=1;
	}

	for(j=0;j<NBobjet;j++)
	if(!(posObjet[j].x>=0&&posObjet[j].x<=840)&&(posObjet[j].y>=0&&posObjet[j].y<=680)){

		posObjet[j].x=rand()%650+150;
		posObjet[j].y=rand()%500+30;
		}
//////////// MODIFICATION 1 /////////////


	if(bonus==1){
	  Mix_PlayChannel(6, son6, 0);
	  bonus=0;
	}
          
        if(globall.compteur-avant==10){
	  bonus=0;
	  Mix_PlayChannel(5, son5, 0);
	}
/////////
/// if(bonus==2)
 
/////////////// MODIFICATION 4 /////////////////////
	if(CollisionGameOver(positionFlap)) {
/////////////// MODIFICATION 4 /////////////////////
	    Mix_HaltMusic(); //Arrête la musique
	    score(globall.compteur);
	    Mix_PlayChannel(3, son3, 0);
        
	    if(globall.perso==3){
	      Mix_PlayChannel(4, son4, 0);
	      positionCrash.x=positionFlap.x+45;
	      positionCrash.y=positionFlap.y-15;
        
	      positionFlap.y=800;


////////////// MODIFICATION 5 ///////////////////
		for(k=0;k<19;k++){
		memset(buf,0,100);
		if(k<10)snprintf(buf,100,"Images/00%d.gif",k);
		else snprintf(buf,100,"Images/0%d.gif",k);

////////////// MODIFICATION 5 ///////////////////


////////////// MODIFICATION 3 ///////////////////
		tabSurface[TYPE_crash] = IMG_Load(buf);
		if(tabSurface[TYPE_crash]==NULL)fprintf(stderr,"img load err\n");
	        SDL_BlitSurface(tabSurface[TYPE_crash], NULL, tabSurface[TYPE_ecran], &positionCrash);
	        SDL_Flip(tabSurface[TYPE_ecran]);
	        SDL_Delay(50);
		}
	        SDL_BlitSurface(tabSurface[TYPE_fond], NULL, tabSurface[TYPE_ecran], &positionFond);
		}
////////////// MODIFICATION 3 ///////////////////


	    positionFlap.y=800;

////////////// MODIFICATION 3 ///////////////////
	    SDL_BlitSurface(tabSurface[TYPE_flap], NULL, tabSurface[TYPE_ecran], &positionFlap);
////////////// MODIFICATION 3 ///////////////////

	  police = TTF_OpenFont("racer.ttf", 65);
	    tabSurface[TYPE_texte] = TTF_RenderText_Blended(police, "You Lose !!", couleurRouge);  //Affiche en rouge le texte "You Lose"
       
	    positionDistance.x=550;
	    positionDistance.y=400;
        


////////////// MODIFICATION 3 ///////////////////
	    SDL_BlitSurface(tabSurface[TYPE_texte], NULL, tabSurface[TYPE_ecran], &positionTexte);
////////////// MODIFICATION 3 ///////////////////



	    sprintf(distance, "%d", dis); /* On Ècrit dans la chaÓne "distance" la nouvelle distance parcouru */
	    SDL_FreeSurface(tabSurface[TYPE_dist]); /* On supprime la surface prÈcÈdente */
	    tabSurface[TYPE_dist] = TTF_RenderText_Shaded(police2, distance, couleurNoir,couleurFond); /* On Ècrit la chaÓne distance dans la SDL_Surface */
	    SDL_BlitSurface(tabSurface[TYPE_score2], NULL, tabSurface[TYPE_ecran], &positionDistance2);
	    SDL_BlitSurface(tabSurface[TYPE_dist], NULL, tabSurface[TYPE_ecran], &positionDistance); /* Blit de la distance parcouru */
	   
	    SDL_Flip(tabSurface[TYPE_ecran]);
	    sleep(1);
	    menujouer();
	  }


	switch (globall.perso)
          {
                  
	  case 1:
                  
	    globall.flapxg=7;
	    globall.flapxd=45;
	    globall.flapxh=7;
	    globall.flapxb=35;
                  
////////////// MODIFICATION 5 ///////////////////
	
           for(j=0;j<3;j++)
	    if(i%3==j){
		memset(buf,0,100);
		snprintf (buf, 100,"Images/bird%d.png", j+1);
	      tabSurface[TYPE_flap] = IMG_Load(buf);   
		assert(tabSurface[TYPE_flap]);    
	    }
////////////// MODIFICATION 5 ///////////////////

	    break;
	  case 2:
	    globall.flapxg=3;
	    globall.flapxd=62;
	    globall.flapxh=6;
	    globall.flapxb=52;
////////////// MODIFICATION 5 ///////////////////
           for(j=0;j<10;j++)
	    if(i%10==j){
		memset(buf,0,100);
		snprintf (buf, 100,"Images/dragon%d.png", j+1);
	      tabSurface[TYPE_flap] = IMG_Load(buf);      
		assert(tabSurface[TYPE_flap]);       
	    }
////////////// MODIFICATION 5 ///////////////////
	    break;
	  case 3:
	    globall.flapxg=5;
	    globall.flapxd=109;
	    globall.flapxh=6;
	    globall.flapxb=56;
                  
	    if(i%2==0){
////////////// MODIFICATION 3 ///////////////////
	        tabSurface[TYPE_flap] = IMG_Load("Images/avion1.png");
		assert(tabSurface[TYPE_flap]!=NULL);
////////////// MODIFICATION 3 ///////////////////
                      
	    }//
                  
	    if(i%2==1){
////////////// MODIFICATION 3 ///////////////////
	      	tabSurface[TYPE_flap] = IMG_Load("Images/avion2.png");
		assert(tabSurface[TYPE_flap]!=NULL);
////////////// MODIFICATION 3 ///////////////////
	    }
                  
                  
                  
	    break;
                  
	  default:break;
          }

//////////// MODIFICATION 1 /////////////
	SDL_BlitSurface(tabSurface[TYPE_fond], NULL, tabSurface[TYPE_ecran], &positionFond);
	for(j=0;j<NBobjet;j++)
	SDL_BlitSurface(objet[j], NULL, tabSurface[TYPE_ecran], &posObjet[j]);
	SDL_BlitSurface(tabSurface[TYPE_flap], NULL, tabSurface[TYPE_ecran], &positionFlap);
//////////// MODIFICATION 1 /////////////

	for (globall.tyx = 0;globall.tyx != TUY ;globall.tyx++) {
	  SDL_Rect temp3 = poss.positiontuy1[globall.tyx];

//////////// MODIFICATION 3 /////////////
	  SDL_BlitSurface(tabSurface[TYPE_tuy1], NULL, tabSurface[TYPE_ecran], &temp3);
//////////// MODIFICATION 3 /////////////

	  SDL_Rect temp2 = poss.positiontuy2[globall.tyx];

//////////// MODIFICATION 3 /////////////
	  SDL_BlitSurface(tabSurface[TYPE_tuy2], NULL, tabSurface[TYPE_ecran], &temp2);
//////////// MODIFICATION 3 /////////////

	}
	SDL_Delay(50);
	SDL_Flip(tabSurface[TYPE_ecran]);
	i++;
      }


    }
//////////// MODIFICATION 1 /////////////
for(j=0;j<NBobjet;j++)
  SDL_FreeSurface(objet[j]);
//////////// MODIFICATION 1 /////////////

for(j=0;j<9;j++)
  SDL_FreeSurface(tabSurface[j]);
 
 TTF_CloseFont(police2);
  TTF_CloseFont(police);
  Mix_FreeChunk(son);//Libération du son 1
  Mix_FreeChunk(son2);
  Mix_FreeChunk(son3);
  Mix_FreeChunk(son4);
  Mix_FreeChunk(son5);
  Mix_FreeChunk(son6);
  Mix_FreeMusic(musique); //Libération de la musique
  Mix_CloseAudio();

 
}
