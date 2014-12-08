void menu ()
{
  printf("HANJIE\n\n");
  printf("1.Nouvelle partie\n");
  printf("2.Charger une partie\n");
  printf("3.Meilleurs score\n");
  printf("4.Quitter\n");
  scanf("%d", &menu);

  switch (menu)
    {
    case 1:
      printf("Choisissez un niveau");
      break;

    case 2:
      printf("selectionnez la sauvegarde");
      break;

    case 3:
      printf("Liste des meilleurs performances par niveau");
      break;

    case 4:
      printf("Vous quittez HANJIE");
      return 0;
      break;

    default:
      printf("Veuillez saisir une commande valable");
      break;
    }
} 
