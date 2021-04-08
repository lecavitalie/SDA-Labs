#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "casa.c"
int main()
{
Casa *S=NULL;
 int n=0,k,m,k1,k2,nr,nd,nm,com, l;

 char fnume[100],y;
 char denumire[100];
 Casa *M;
while(1){
system("cls");
 printf("\t\t|Meniu |\n-------------------------------------------------");
 printf("\n[ 1 ] Introducerea informatiei despre Casa manual");
 printf("\n[ 2 ] Citirea informatiei despre elementele tabloului din fisier");
 printf("\n[ 3 ] Lista cu Casei");
 printf("\n[ 4 ] Cautarea Casei dorita");
 printf("\n[ 5 ] Sortarea Casei dupa alfabet");
 printf("\n[ 6 ] Adaugarea Casei la inceputul listei");
 printf("\n[ 7 ] Adaugarea Casei la sfirsitul listei");
 printf("\n[ 8 ] Modificarea unei Case");
 printf("\n[ 9 ] Interschimbarea a 2 Case");
 printf("\n[ 10 ] Adaugarea Casei inaintea elementului inserat");
 printf("\n[ 11 ] Adaugarea Casei dupa elementul inserat");
 printf("\n[ 12 ] Stergerea  a unei Case");
 printf("\n[ 13 ] Salvarea listei cu Case in fisier");
 printf("\n[ 0 ] Exit");
 printf("\n\n Introduceti numarul comenzi >> ");
  scanf("%d",&com);
  system("cls");
  switch(com){
case 0:
		free(S);
                puts ("Doriti sa iesiti din program?\n 1/0");
            	scanf ("%d", &l);
				if (l==1)
            	{
                	return 0;
				}
            	else
            	{
					if (l==0)
	            	{
	            		break;
					}
					else
					{
						system ("cls");
						puts ("Nu ati ales optiunea corecta!\nAlegeti optiunea din nou!\n");
						puts ("\nPentru a continua apasati ENTER!");
						system ("pause");
						break;
					}
				}
case 1:
		system ("cls");
		printf("Introdu numarul de Case: ");
 		scanf("%d",&n);
 	    S=(Casa*) calloc (n, sizeof (*S));
				if (!S)
				{
					puts ("\nMemoria nu a fost alocata!\n");
					puts ("Pentru a iesi din program apasati ENTER!\n");
					system ("pause");
					exit (1);
				}
				else{
				    reads(S, n);
					system ("pause");
					break;
				}
case 2: 
		system ("cls");
		printf("Introduceti numele fisierului salvat anterior pentru citire:\n");
		scanf("%s",&fnume);
		strcat(fnume,".txt");
		S=loads(S,fnume,&n);
		printf("%d\n",n);
		system ("pause");
		break;
case 3:
		system ("cls");
		shows(S,n);
		system ("pause");
		break;
case 4:
		system ("cls");
		puts ("Introduceti denumirea Casei pentru cautare:");
        scanf ("%s",&denumire);
		searchs (S, n, denumire);
		system ("pause");
		break;
case 5:
		system ("cls");	
		printf("Sortarea Caselor dupa alfabet:\n");
		sorts(S,n);
		system ("pause");
		break;
case 6:
		system ("cls");
		S=prepends (S, &n);		
	    system ("pause");
		break;
case 7:
		system ("cls");
		
		S=appends(S, &n);
		system ("pause");
	    break;
case 8:
		system ("cls");
		puts ("\t\tcasele initiale\n*********************************************");
		shows(S, n);
		printf("Introduceti numarul de ordine a Casei:");
		scanf("%d",&nm);
		if(nm<=n && nm>=1)
		 {modifys(S, nm);
		 system ("pause");}
		else
		 {printf("\nNu exista Casa cu asa numar de ordine\a\n");}
		 system ("pause");
		break;
case 9:
		system ("cls");
		puts ("\t\tLista cu Case\n*********************************************");
		shows(S, n);
		printf ("Alegeti primul element care trebuie de interschimbat:");
		scanf ("%d", &k1);
		printf ("Alegeti al doilea element care trebu de interschimbat:");
		scanf ("%d", &k2);
		swaps (S, k1, k2);
		break;
case 10:
	    system ("cls");
	    puts ("\t\tLista cu case\n*********************************************");
		shows(S, n);
		printf ("Alegeti elementul in fata caruia doriti sa inserati noul element:");
		scanf ("%d", &k);
		S=insert_befores (S, &n, k);
		system ("pause");
		break;
case 11:	
       	system ("cls");
       	puts ("\t\tLista cu disciplini\n*********************************************");
		shows(S, n);
		printf ("Alegeti elementul dupa care doriti sa inserati noul element:");
		scanf ("%d", &k);
		S=insert_afters (S, &n, k);
		system ("pause");
		break;
case 12:
	    system ("cls");
	    printf("Introduceti numarul Casei pentru stergere:");
        scanf ("%d",&nd);
        M=deletes(S, &n, nd-1);
        if(M==NULL)
        {puts ("Memoria nu a fost alocata");}
        else
        {S=M;}
        printf("\nStergerea a avut loc cu succes!\a\n\n");
        system ("pause");
        getch();
        break;
case 13:
		system ("cls");
				printf("Introdu numele fisierului pentru salvare:");
		scanf("%s",&fnume);
		strcat(fnume,".txt");
		saves(S,n,fnume);
		printf("\nSalvare a avut loc cu succes!\a\n");
		system ("pause");
		break;
		default: 
		printf("\aAti introdus o comanda gresita!\n");
		system("pause");
		break;
        }  
    }
}
