#include <stdio.h>
#include <string.h>

int departement_choix;
int i = 0; // index
int c = 0; // counter
int k;     // search by unique number
int d;     // department choice
int t;
int el = 0;
int h; // where to put search value
char name_to_search;
int choix; // user choice
int supprimer_num;
int modifier_num;
char departement_search[15];
char depar_search_moyen[15];
int dex = 0; // variable d affige
typedef struct students
{
  int unique_num;
  char nom[50];
  char prenom[50];
  char birthday[50];
  char departement[50];
  double note_generale;
} students;

students student[85];
/*void search_by_depar()
{
    printf("Liste des etudiants dans le departement %s:\n", departement_search);
    for (int dep = 0; i < c; dep++)
    {
        if (strcmp(etudiants[dep].departement, departement_search) == 0)
        {
            printf("Numero: %s, Nom: %s, Prenom: %s, Note generale: %.2f\n",student[dep].num, student[dep].nom, student[dep].prenom, student[dep].note_generale);
        }
    }
}*/

void ajouter()
{
  student[c].unique_num = c;
  printf("Ajouter le nom: ");
  scanf("%s", &student[c].nom);
  printf("Ajouter le prenom: ");
  scanf("%s", &student[c].prenom);
  printf("Ajouter le birthday: ");
  scanf("%s", &student[c].birthday);
  printf("Choisissez votre departement:\n");
  printf("1 - Math Info\n");
  printf("2 - Biologie Chimie\n");
  printf("3 - Philosophie Literature\n");
  scanf("%d", &departement_choix);
  switch (departement_choix)
  {
  case 1:
    strcpy(student[c].departement, "Math_Info");
    break;
  case 2:
    strcpy(student[c].departement, "Biologie_Chimie");
    break;
  case 3:
    strcpy(student[c].departement, "Philosophie_Litterature");
    break;
  default:
    strcpy(student[c].departement, "Inconnu");
    break;
  }
  printf("Ajouter la note generale: ");
  scanf("%lf", &student[c].note_generale);
}

void affichage()
{
  if (dex < 0 || dex >= c)
  {
    printf("Index invalide.\n");
    return;
  }
  else
  {
    printf("Nom: %s\n", student[dex].nom);
    printf("Prenom: %s\n", student[dex].prenom);
    printf("Birthday: %s\n", student[dex].birthday);
    printf("Departement: %s\n", student[dex].departement);
    printf("Note Generale: %.2lf\n", student[dex].note_generale);
    printf("Nombre Unique: %d\n", student[dex].unique_num);
  }
}

int search()
{
  scanf("%d", &k);
  for (int el = 0; el < c; el++)
  {
    if (student[el].unique_num == k)
    {
      return el;
    }
  }
  return -1;
}
void moyen_par_depart()
{
  float somme = 0;
  int count = 0;
  for (int mdp = 0; mdp < c; mdp++)
  {
    if (strcmp(student[mdp].departement, depar_search_moyen) == 0)
    {
      somme += student[mdp].note_generale;
      c++;
    }
  }
  if (c > 0)
  {
    printf("Moyenne du departement %s: %.2f\n", depar_search_moyen, somme / count);
  }
  else
  {
    printf("cet etudient n existe oas %s.\n", depar_search_moyen);
  }
}

void modifier_etudiant()
{
  for (int mo = 0; mo < c; mo++)
  {
    if (student[mo].unique_num == modifier_num)
    {
      printf("Modification des informations de l'etudiant %s:\n", student[mo].unique_num);
      printf("Ajouter le nom: ");
      scanf("%s", &student[c].nom);
      printf("Ajouter le prenom: ");
      scanf("%s", &student[c].prenom);
      printf("Ajouter le birthday: ");
      scanf("%s", &student[c].birthday);
      printf("Choisissez votre departement:\n");
      printf("1 - Math Info\n");
      printf("2 - Biologie Chimie\n");
      printf("3 - Philosophie Literature\n");
      scanf("%d", &departement_choix);
      switch (departement_choix)
      {
      case 1:
        strcpy(student[c].departement, "Math_Info");
        break;
      case 2:
        strcpy(student[c].departement, "Biologie_Chimie");
        break;
      case 3:
        strcpy(student[c].departement, "Philosophie_Litterature");
        break;
      default:
        strcpy(student[c].departement, "Inconnu");
        break;
      }
      printf("Ajouter la note generale: ");
      scanf("%lf", &student[c].note_generale);
    }
    return;
  }
  printf("Etudiant n existe pas.\n");
}

//**********************************************************
void Nobr_etudiants_par_departement()
{
  int math_inf = 0, bio_chimi = 0, phylo = 0;

  for (int no_depa = 0; no_depa < c; no_depa++)
  {
    if (strcmp(student[no_depa].departement, "Math_Info") == 0)
    {
      math_inf++;
    }
    else if (strcmp(student[no_depa].departement, "Biologie_Chimie") == 0)
    {
      bio_chimi++;
    }
    else if (strcmp(student[no_depa].departement, "Philosophie_Litterature") == 0)
    {
      phylo++;
    }
  }

  printf("Nombre d'etudiants inscrits dans chaque departement:\n");
  printf("Math: %d\n", math_inf);
  printf("PC: %d\n", bio_chimi);
  printf("Info: %d\n", phylo);
}

//******************************************************** */
void affiche_bigger_than_seul()
{
  double seuil;
  printf("Entrez le seuil de la note generale: ");
  scanf("%lf", &seuil);
  printf("Etudiants avec une moyenne generale superieure a %.2f:\n", seuil);
  for (int seui = 0; seui < c; seui++)
  {
    if (student[seui].note_generale > seuil)
    {
      printf("Numero: %d, Nom: %s, Prenom: %s, Note generale: %.2f\n",
             student[seui].unique_num, student[seui].nom, student[seui].prenom, student[seui].note_generale);
    }
  }
}
//**********************************************************
void afficher_bigger_than_seuil10()
{
  double seuil10 = 10;

  printf("Etudiants avec une moyenne generale superieure a %.2f:\n", seuil10);
  for (int seui = 0; seui < c; seui++)
  {
    if (student[seui].note_generale > seui)
    {
      printf("Numero: %d, Nom: %s, Prenom: %s, Note generale: %.2f\n",
             student[seui].unique_num, student[seui].nom, student[seui].prenom, student[seui].note_generale);
    }
  }
}
//**********************************************************
void supprimer()
{
  {
    for (int supi = 0; supi < c; supi++)
    {
      if (supprimer_num == student[supi].unique_num)
      {
        for (int j = i; j < c - 1; j++)
        {
          student[j].unique_num = student[j + 1].unique_num;
        }
        c--;
        printf("Etudiant supprime avec succes.\n");
        return;
      }
    }
    printf("Etudiant non trouve.\n");
  }
}
//************************************************************************
void afficher_top_3_etudiants()
{
  for (int tp3 = 0; tp3 < c - 1; tp3++)
  {
    for (int j = 0; j < c - tp3 - 1; j++)
    {
      if (student[j].note_generale < student[j + 1].note_generale)
      {

        students temp = student[j];
        student[j] = student[j + 1];
        student[j + 1] = temp;
      }
    }
    printf("Top 3 etudiants sont:\n");
    for (int i = 0; i < 3 && i < c; i++)
    {
      printf("Numero: %d, Nom: %s, Prenom: %s, Note generale: %.2f\n",
             student[tp3].unique_num, student[tp3].nom, student[tp3].prenom, student[tp3].note_generale);
    }
  }
}

//**************************************************************************
int main()
{
  int option;
  while (1)
  {
    printf("Choisissez une option:\n");
    printf("1 - Ajouter un eleve\n");
    printf("2 - Rechercher un eleve\n");
    printf("3 - Supprimer un eleve\n");
    printf("4 - Afficher les details d'un eleve\n");
    printf("5-modifier un eleve\n");
    printf("6-moyen par departement\n");
    printf("7_afficher tout\n");
    printf("8_nombre d eleve par departement\n");
    printf("9_donnes les eleves qui ont une note plus grand que votre seul");
    printf("10- Quitter\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1: // ajouter
      ajouter();
      c++;
      break;
    case 2: // search
      printf("Entrez le nombre unique de l eleve a rechercher: ");
      int index = search();
      if (index != -1)
      {
        affichage(index);
      }
      else
      {
        printf("Eleve n existe pas.\n");
      }
      break;
    case 3: // suprimer
      scanf("%d", supprimer_num);
      supprimer();
      c--;
      break;
       case 4: // modification
      printf("donner le nombre d eleve tu va changer");
      scanf("%d", &modifier_num);
      modifier_etudiant();
      break;
    case 5: // modifier
      printf("Entrez le nombre unique de l'eleve a afficher: ");
      int idx;
      scanf("%d", &idx);
      affichage(idx);
      break;
    
    case 6:
    printf("bienvenue dans les statistique");
    printf("1_afficher tout");
    printf("2_afficher le nombre d eleve par departement ");
    printf("3_chercher les etudiant avec une moyene superieur a cotre seuil ");
    printf("4_afficher les 3 premier etudiants ");
    printf("5_afficher les eleves reussie");
    int choix_stats;
    scanf("%d",choix_stat);
    if(choix_stats=1){}
    if(choix-stats=2){ Nobr_etudiants_par_departement();}
    if(choix_stats=3){affiche_bigger_than_seul();}
    if(choix_stats=4){}
    if(choix_stats=5){}
    break;
    case 7:
      affichage();
      break;
    case 8:
      Nobr_etudiants_par_departement();
      break;
    case 9:
      affiche_bigger_than_seul();
    case 10:

        break;
        case 11:
      return 0;
      break;

    default:
      printf("Option invalide. Veuillez reessayer.\n");
    }
  }
  return 0;
}