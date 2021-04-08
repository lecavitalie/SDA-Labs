#include "casa.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//introducerea informatiei despre elementele tabloului de la tastatura
void reads(Casa *S, int n)
{int i;
puts("Scriti informatia despre Casa:");
for(i=0; i<n; i++)
   {puts("\n********************");
   	printf("Casa %d:\n\n",i+1);
   	printf("Adresa:");
   	fflush (stdin);
   	gets(S[i].adresa);
   	printf("Telefonul:");
	scanf("%s",&S[i].telefonul);
   	printf("Suprafata:");
   	scanf("%s",&S[i].suprafata);
   	printf("Numarul de odai:");
   	scanf("%s",&S[i].nr_odai);
   	printf("Numarul de odai:");
   	scanf("%s",&S[i].costul);
   	
   	
} 
   return;
}
//afisarea informatiei despre elementele tabloului pe ecran
void shows(Casa *S,int n)
{int i;
puts("Informatia despre Casa:");
for(i=0; i<n; i++)
     {
     printf("****************************************\n\n");
  printf("Datele Casei:         %d\n\n",i+1);
  printf("Adresa:                     %s\n\n",S[i].adresa);
  printf("Telefonul:                  %d\n\n",S[i].telefonul);
  printf("Suprafata:              %d\n\n",S[i].suprafata);
   printf("Costul:           %d\n\n",S[i].costul);
  printf("Numarul de odai:           %d\n\n",S[i].nr_odai);
	 }
	 return;
}
//cautarea  elementului  tabloului dupa denumire
void searchs(Casa *S, int n, char *adresa)
{
int i,j=0;
for(i=0;i<n; i++)
       {
       	if(stricmp(S[i].adresa, adresa)==0)
       	        {
	printf("****************************************\n\n");
  printf("Datele Casei:         %d\n",i+1);
  printf("Adresa:                     %s\n",S[i].adresa);
  printf("Telefonul:                  %d\n",S[i].telefonul);
  printf("Suprafata:              %d\n",S[i].suprafata);
  printf("Numarul de odai:      %d\n",S[i].nr_odai);
  printf("Costul:           %d\n\n",S[i].costul);
  j++;
  }
	   }
	   if(!j)
	   {system("cls");
	printf("Nu s-a gasit Casa: %s\n\n",adresa);
 }
}	
//modificarea cimpurilor elementului tabloului
void modifys(Casa *S, int nm)
{
nm=nm-1;
  printf("\n****************************************\n\n");
  printf("Nr. de ordine:              %d\n",nm+1);
  printf("Adresa:                     %s\n",S[nm].adresa);
  printf("Telefonul:                  %d\n",S[nm].telefonul);
  printf("Suprafata:              %d\n",S[nm].suprafata);
  printf("Numarul de odai:      %d\n",S[nm].nr_odai);
  printf("Costul:           %d\n\n",S[nm].costul);
  printf("****************************************\n\n");
  printf("Introdu datele Casai pentru modificare:\n");
  printf("adresa: ");
   scanf("%s",&S[nm].adresa);
  printf("telefonul: ");
   scanf("%d",&S[nm].telefonul);
  printf("suprafata: ");
   scanf("%d",&S[nm].suprafata);
  printf("numarul de odai: ");
   scanf("%d",&S[nm].nr_odai);
  printf("Costul: ");
   scanf("%d",&S[nm].costul);
}
//sortarea elementelor tabloului dupa alfabet
void sorts(Casa *S,int n)
{int i,k;
Casa t;
for(i=0;i<n-1;i++)
    {
    	for(k=0;k<n-1-i;k++)
    	     {
			      if(stricmp(S[k].adresa,S[k+1].adresa)>0)
    	 {
    	 	t=S[k];
    	 	S[k]=S[k+1];
    	 	S[k+1]=t;
		 }
	         }        
	}
shows(S,n);
}
//interschimbarea a 2 elemente tabloului
void swaps(Casa *S, int k1, int k2) 
{
	Casa t;
	t=S[k1-1];
	S[k1-1]=S[k2-1];
	S[k2-1]=t;
	return;
}
//adaugarea unui element nou la sfirsitul tabloului
Casa *appends(Casa *S, int *n)
{	Casa *M;
	Casa nr;
	form_Casa (&nr);
	M=(Casa*) realloc (S, (*n+1)*sizeof(*M));
	if (!M)
	
{
		return M;
	}
	M[*n]=nr;
	*n=*n+1;
	return M;
}
//adaugarea unui element nou  la inceputul tabloului
Casa* prepends(Casa *S, int *n)
{
	int i;
	Casa *M;
	Casa nr;
	form_Casa (&nr);
	M=(Casa*) realloc (S, (*n+1)*sizeof(*M));
	if (!M)
	{
		return 0;
	}
	for (i=*n; i>0; i--)
	{
		M[i]=M[i-1];
	}
	M[0]=nr;
	*n=*n+1;
	return M;
}
//adaugarea unui element nou inaintea elementului inserat
Casa* insert_befores (Casa *S, int *n, int k)
{
	int i;
	Casa *M;
	Casa nr;
	form_Casa (&nr);
	M=(Casa*) realloc (S, (*n+1)*sizeof(*M));
	if (!M)
	{
		return 0;
	}
	for (i=*n; i>=k; i--)
	{
		M[i]=M[i-1];
	}
	M[k-1]=nr;
	*n=*n+1;
	return M;
}
//adaugarea unui element nou dupa elementul inserat
Casa* insert_afters (Casa*S, int *n, int k)
{         
            int i;
	Casa *M;
	Casa nr;

	form_Casa (&nr);
	M=(Casa*) realloc (S, (*n+1)*sizeof(*M));
	if (!M)
	{
		return 0;
	}
	for (i=*n; i>k; i--)
	{
		M[i]=M[i-1];
	}
	M[k]=nr;
	*n=*n+1;
	return M;
}
//stergerea unui element al tabloului
Casa*deletes (Casa*S, int*n, int nd)
{ Casa*M;
          int i;
          for (i=nd;i<*n;i++)
          { S[i]=S[i+1];}
          M=(Casa*)realloc(S,(*n-1)*sizeof(*M));
          *n=*n-1;
          return M;
}
//salvarea datelor
void saves(Casa *S, int n, char *fnume)
{
int i;
FILE *demo=fopen(fnume,"wt");
 for(i=0;i<n;i++){
  fprintf(demo,"%s %d %d %d %d",S[i].adresa,S[i].telefonul,S[i].suprafata,S[i].nr_odai,S[i].costul);
   if(i<n-1)
    fprintf(demo,"\n");
 }
 fclose(demo);
}
//citirea informatiei despre elementele tabloului din fisier
Casa* loads(Casa *S ,char *fnume, int *n )
{
int i=0,m=0;
FILE *demo=fopen(fnume,"r"); 
 if(!demo){
  printf("\aFisierul nu exista!\n");
  system("pause");
  exit(1);
 }
 while(!feof(demo))
 {
  m++;
S=(Casa*) realloc (S,m*sizeof (*S));
  fscanf(demo,"%s%d%d%d%d",&S[i].adresa,&S[i].telefonul,&S[i].suprafata,&S[i].nr_odai,&S[i].costul);
  i++;
 *n=m;
 }
 fclose(demo);
 return S;    
}
//formarea unui element nou
void form_Casa (Casa *nr)
{
	printf ("Adresa: ");
	fflush (stdin);
    gets (nr->adresa);
    printf ("Telefonul: ");
    scanf ("%d", &nr->telefonul);
    printf ("Suprafata: ");
    scanf ("%d", &nr->suprafata);
    printf ("Numarul de odai: ");
    scanf ("%d", &nr->nr_odai);
    printf ("Costul: ");
    scanf ("%d", &nr->costul);
}
// realocarea memoriei
Casa* reloc(Casa *S,int n)
{
 S=(Casa*)realloc(S,n*sizeof(Casa));
 if(!S){
  printf("\a\nNu sa alocat memorie!\n");
  system("pause");
  exit(1);
 } 
return S;
}
