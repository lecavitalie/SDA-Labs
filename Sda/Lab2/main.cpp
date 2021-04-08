#include "functii.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>

int main (){
Casa *S,*B;
char adresa[40];  
int n,nm,flag;
while(1) // for(;;)
{
	system("cls");
	puts("\t MENU:");
	puts("1. Alocarea dinamica a memoriei p/u lista de structuri");
	puts("2. Introducerea elementelor listei de la tastatura");
	puts("3. Afisarea la ecran");
	puts("4. Cautarea elementului");
	puts("5. Redactarea elementului listei");
	puts("6. Determinarea ultimului element din lista");
	puts("7. Determinarea lungimii listei(nr de elemente) ");
	puts("8. Interschimbarea a 2 elemente din lista ");
	puts("9. Sortarea Listei ");
	puts("10. Eliberarea memoriei  ");
	puts("0. Iesire din program ");
	
	printf("\nAlegeti optiunea din menu: ");
	scanf("%d", &nm);
	
	switch(nm)
	{
		case 1:
			
		printf("Dati numarul de case: ");
		scanf("%d", &n);	
		flag=createList(n);
		if(flag!=1){
			puts("Memoria nu a fost alocata");
			exit (1);
		}
		puts("Memoria a fost alocata cu succes");
		puts("Pentru a continua apasati tasta Enter");
		getch(); 
		break;
		
		case 2:
			
		readInfo();
		puts("Pentru a continua apasati tasta Enter");
		getch(); 
		break;
		
		case 3:
			
		showInfo();
		getch(); 
		break;
		
		case 4:
			
		puts("Dati adresa casei cautate:  ");
		fflush(stdin);
		gets(adresa);
		S=searchElement(adresa);
		if(S==NULL){
			puts("Casa cautata nu a fost gasita in tablou ");}
		else{
			puts("Info despre casa: ");
			printf("Adresa: %s Nr.camere: %d  Pretul: %.2f Suprafata: %.2f Telefonul: %s \n",S->adresa,S->nr_odai,S->costul,S->suprafata,S->telefonul);
		}	
	
		puts("Pentru a continua apasati tasta Enter");
		getch();
		break;
		
		case 5:
			
		puts("Dati adresa casei de modificat:");
		fflush(stdin);
		gets(adresa);
		S=searchElement(adresa);
		if(S==NULL){
			puts("Casa cautat nu a fost gasit in tablou ");
		}
		else{
			puts("Info despre casa: ");
			printf("Adresa: %s Nr.camere: %d  Pretul: %.2f Suprafata: %.2f Telefonul: %s \n",S->adresa,S->nr_odai,S->costul,S->suprafata,S->telefonul);
			modifyInfo(S);
		}	
	
		puts("Pentru a continua apasati tasta Enter");
		getch(); 
		break;
		
		case 6:
			
		S=lastElement();
		printf("Adresa ultimui element al listei: %p %p \n", S, S->next);
		getch(); 
		break;
		
		case 7:
			
		n=sizeList();
		printf("Lungime listei este %d\n", n);
		getch(); 
		break;
			
		case 8:
		 
		puts("Dati adresa casei pentru interschimbare");
		fflush(stdin);
		gets(adresa);
		S=searchElement(adresa);
		if(S==NULL){
		puts ("Casa nu a fost gasita");
		}
		else{
		puts ("Info despre casa:");
		printf("Adresa: %s Nr.camere: %d  Pretul: %.2f Suprafata: %.2f Telefonul: %s \n",S->adresa,S->nr_odai,S->costul,S->suprafata,S->telefonul);
		}
		puts("Dati adresa casei pentru interschimbare");
		fflush(stdin);
		gets(adresa);
		B=searchElement(adresa);
		if(S==NULL){
			puts ("Casa nu a fost gasita");
		}
		else{
			puts ("Info despre casa:");
			printf("Adresa: %s Nr.camere: %d  Pretul: %.2f Suprafata: %.2f Telefonul: %s \n",B->adresa,B->nr_odai,B->costul,B->suprafata,B->telefonul);
		}
		if (S!=NULL && B!=NULL){
			swap(S,B);
			puts("Interschimbarea produsa cu sussces. Tastati enter pentru a continua");
		}
		else{
		puts("UPS. mai incearca");
		}
		getch(); 
		break;
		
		case 9:
			
		sortList();
		puts("Lista a fost sortata. Tastati enter pentru a continua");
		getch(); 
		break;
		
		case 10:
			
		freeMemory();
		puts("memoria a fost eliberata. Tastati enter pentru a continua");
		getch(); 
		break;
			
		case 0:
			
		printf("Doriti sa iesiti din program? (1/0): ");
		scanf("%d", &flag);
		if(flag==1) return 0;	
		puts("Pentru a continua apasati tasta Enter");
		getch(); 
		break;
		default: puts("Alegeti optiunea corecta din menu! ");
		puts("Pentru a continua apasati tasta Enter");
		getch(); 	
	} // end switch
					
} // end while
}
