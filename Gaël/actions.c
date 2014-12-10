#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "actions.h"

void game(char diff, char numLvl, int tabSize[2], char *playerName, int timer, char **tab, char **board, char showTime)
{
  int start, end, i, j;
  char quit = 0, win = 0;
  char *p = &quit;

  start = time(NULL);

  while(quit == 0 || win == 0){

    reprint(tab, tabSize); //Splitter l'écran du jeu

    win = 1;
    for(j = 0; j < tabSize[1]; j++){ //Vérification du tableau (si le joueur a gagné ou non)
      for(i = 0; i < tabSize[0]; i++){
        if(tab[i][j] != board[i][j]){
	  win = 0;
	}
      }
    }

    if(win = 1){ //Si le joueur a gagné
      printf("Gagné !");
      timer = timer + (end - start); //Calcul du temps mis par le joueur pour terminer la partie
      //... Appeler la fonction saveScore();
      //... Mettre le jeu en attente d'une pression sur une touche (pause)
    }else{
      input(tab, p, tabSize);
    }

  }

  if(quit = 1){
    char chain[2]; //Chaîne qui contiendra soit x soit y
    char error, *enter = NULL;

    do{ //L'utilisateur doit entrer 'y' (yes) ou 'n' (no)
      system("clear");
      printf("Voulez-vous sauvegarder ? (y/n)\n");

      if(fgets(chain, 2, stdin) != NULL){
	enter = strchr(chain, '\n');
	if(enter != NULL){
	  *enter = '\0';
	  purge();
	}else{
	  error = 1;
	  purge();
	}
      }

	if(error == 0){
	  switch(chain[0]){
	  case 'y' :
	    saveGame(playerName, diff, numLvl, time, tabSize, tab);
	    error = 0;
	    break;
	  case 'n' :
	    error = 0;
	    break;
	  default :
	    error = 1;
	    break;
	  }
	}

    }while(error == 1);
  
  }
}

void init(char diff, char numLvl, char showTime)
{

  int tabSize[2];


  FILE* hanjie = NULL;
  int i, j;
  char magicWord[6];
  
  fgets(magicWord, 6, hanjie);
  
  fscanf(hanjie,"%d %d", &tabSize[0], &tabSize[1]);
  
  char board[tabSize[0]][tabSize[1]]; //Création du tableau pour recevoir le hanji
  char tab[tabSize[0]][tabSize[1]]; //Création du tableau que le joueur remplira

    for(i = 0; i < tabSize[0]; i++)
      {
	for(j = 0; j < tabSize[1]; j++)
	  {
	    fscanf(hanjie, "%c", board[i][j]);
	    tab[i][j] = 0;
	  }
      }
  
  for(i = 0; i < tabSize[0]; i++)
    {
      for(j = 0; j < tabSize[1]; j++)
	{
	  printf("%c", board[i][j]);
	  if(j == tabSize[1] - 1)
	    printf("\n");
	}
    }
  fclose(hanjie);

  char playerName[6] = "BABAR";
  
  game(diff, numLvl, tabSize, playerName, 0, (char**)tab, (char**)board, 1);
}
