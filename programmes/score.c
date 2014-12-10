int main ()
{
FILE *fichier = NULL;
int score[3] = {0};

fichier = fopen("Score.sav", "r");

if (fichier != NULL)
{
fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
printf("Vos meilleurs scores: 1.%d\n 2.%d\n 3.%d", score[0], score[1], score[2]);

fclose(fichier);
}
return 0;
}