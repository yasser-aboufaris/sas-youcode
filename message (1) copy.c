#include <stdio.h>
#include <string.h>
int i=0;//indice
 int c=0;//counter
 int k=0;//search by nombre unique
 int d;//choix de departement
 int t;
 int el=0;
 int h;//where to put search value
 char name_to_search;
int choix;//choix de l utulisateur
const char depar_1[20] ="physique";
const char depar_2[20] ="math";
const char depar_3[20] ="informatique";
typedef struct students {
    int unique_num;
    char nom[50];
    char prenom[50];
    char birthday[50];
    char departement[50];
    double note_generale;
}students ;
students student[85] ;
 void ajouter(){
    student[i].unique_num=i;
    printf("ajouter le nom\n");
    scanf("%s",&student[i].nom);
    printf("ajouter le prenom\n");
    scanf("%s",&student[i].prenom);
    printf("ajouter le birthday\n");
    scanf("%s",&student[i].birthday);
    printf("ajouter le departement\n");
    scanf("%s",&student[i].departement);
    printf("ajouter la note generale\n");
    scanf("%lf",&student[i].note_generale);
 }
 void affichage(){
    printf("nom: %s\n",student[i].nom);
    printf("prenom:%s\n",student[i].prenom);
    printf("birthday: %s\n",student[i].birthday);
    printf("departement: %s\n",student[i].departement);
    printf("note_general:%2.lf\n",student[i].note_generale);
    printf("nombre unique:%d\n",student[i].unique_num);
 }
 int search(){
  printf("donner le nombre unique de votre eleve:");
  scanf("%d",&k);
  int ro=0;
  while(ro==0&&el<=c){
  if(k==student[el].unique_num){
    ro=1;}
  else if (k!=student[el].unique_num)
  {
    ro=0;
    el++;
  }
  }
  return el;
 }

  int main(){
  students student[85] ;
  ajouter();
  c++;
  ajouter();
  c++;
  ajouter();
  c++;
  h=search();
  printf("%d",h);
  }