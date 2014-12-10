#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "display.h"

void reprint(char **tab, int tabSize[2])
{
  system("clear");
  // ...
}

void input(char **tab, char *quit, int tabSize[2])
{
  char chain[6]; //Chaine contenant la saisie de l'utilisateur
  char *enter = NULL, error = 0;
  int i, j;

  if(fgets(chain, 6, stdin) != NULL){
    enter = strchr(chain, '\n');
    if(enter != NULL){
      *enter = '\0';
      purge();
    }else{
      error = 1;
      purge();
    }
  }

  if(error != 1){
    if(chain[0] >= 65 && chain[0] <= 90 && chain[3] >= 65 && chain[3] <= 90 && chain[1] >= 49 && chain[1] <= 57 && chain[4] >= 49 && chain[4] <= 57 && chain[2] == 32){
      if(chain[0] <= (tabSize[0]+64) && chain[3] <= (tabSize[0]+64) && chain[1] <= (tabSize[1]+47) && chain[4] <= (tabSize[1]+47)){

	for(j = (chain[1]-49); j < (chain[4]-48); j++){ //Remplissage de la ou des cases du tableau en noir ou en blanc
	  for(i = (chain[0]-65); i < (chain[3]-64); i++){
	    if(tab[i][j] == 1){
	      tab[i][j] = 0;
	    }else{
	      tab[i][j] = 1;
	    }
	  }
	}
	
      }
      
    }
    
    if(chain[0] == 'q'){
      *quit = 1;
    }
  }
  
}

void purge()
{
  char c;
  while((c=getchar()) != '\n' && c != EOF){
    c = getchar();
  }
}

void menu()
{

  char menu;
  printf("HANJIE\n\n");
  printf("1.Nouvelle partie\n");
  printf("2.Charger une partie\n");
  printf("3.Meilleurs score\n");
  printf("4.Quitter\n");
  scanf("%c", &menu);

  switch (menu)
    {
    case '1':
      printf("Nouvelle partie");
      init();
      break;

    case '2':
      printf("Charger la partie");
      loadGame();
      break;

    case '3':
      printf("Meilleurs temps");
      break;

    case '4':
      printf("Quitter");
      break;

    default:
      printf("Veuillez saisir une commande valable");
      break;
    }
}
