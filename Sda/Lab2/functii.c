#include "Casa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>

int createList(int n)
{
	Casa* c, *p;
	int i;
	for(i=0;i<n;i++){
		c=(Casa*)calloc(1,sizeof(*c));
		if (c==NULL) { head=NULL; return 0;}
			if(i==0) { head =c; }
			else
			{ p->next=c; }
			p=c;
}
c->next=NULL; // c->next=head;
return 1;
}
void readInfo(void)
{
	Casa *c;
	int i;
	puts("Dati info despre Case: ");
	c=head;
	i=0;
while(c)
{
	printf("Casa %d: ", i+1);
	printf("Adresa: ");
	fflush(stdin);
	gets(c->adresa);
	printf("Telefonul: ");
	fflush(stdin);
	gets(c->telefonul);
	printf("Suprafata: ");
	scanf("%f", &c->suprafata);
	printf("Dati numarul de odai: ");
	scanf("%d", &c->nr_odai);
	printf("Costul: ");
	scanf("%f", &c->costul);
	c=c->next;
	i++;
}
return;
}

void showInfo(void)
{
	Casa*c;
	int i;
	c=head;
	i=0;
	puts("Info despre Casa: ");
	while(c)
	{
		printf("Casa [%d]\n Adresa: %s\n Telefonul: %s\n Suprafata: %f\n  Numarul de odai: %d\n Costul: %f\n ",i+1,c->adresa,c->telefonul,c->suprafata,c->nr_odai,c->costul);
		i++;
		printf("\tAdressa elem:%x\t",c);
		c=c->next;
		printf("adresa next:%x\n",c);
		if(c==head) break;	
	}
return;
}

Casa* searchElement(char* v)
{
	Casa*c;
	c=head;
	while(c)
	{
		if(stricmp(c->adresa, v)==0) {return c;}
		c=c->next;
		if(c==head) break;
	}
return NULL;
}

void modifyInfo(Casa* c)
{
	int f;
	printf("De modificat adresa casei? (1/0):  ");
	scanf("%d", &f);
	if(f!=0)
	{
		printf("Dati adresa:");
		fflush(stdin);
		gets(c->adresa);
	}
	printf("De modificat telefonul? (1/0):  ");
	scanf("%d", &f);
	if(f!=0)
	{
		printf("Dati alt telefonul:");
		fflush(stdin);
		gets(c->telefonul);
	}
	printf("De modificat suprafata? (1/0):  ");
	scanf("%d", &f);
	if(f!=0)
	{
	printf("Dati suprafata:");
	scanf("%f", &c->suprafata);
	}
	printf("De modificat numarul de odai? (1/0):  ");
	scanf("%d", &f);
	if(f!=0)
	{
	printf("Dati numarul de odai:");
	scanf("%d", &c->nr_odai);
}
	printf("De modificat costul? (1/0):  ");
	scanf("%d", &f);
	if(f!=0)
	{
	printf("Dati costul:");
	scanf("%f", &c->costul);
}
	return;	


}

Casa* lastElement(void)
{
	Casa*c;
	c=head;
	while(c->next!=NULL)
	{
		c=c->next;
		if (c->next==head){
			break;
		}
	
	}
return c;
}

int sizeList(void)
{
	Casa*c;
	int n;
	c=head;
	n=0;
	while(c){
		n++;
		c=c->next;
		if(c==head) break;
	}
return n;
}

void swap(Casa *s1, Casa *s2)
{
	Casa *na, *nb;
	Casa t;
	na=s1->next;
	nb=s2->next;
	t=*s1;
	*s1=*s2;
	*s2=t;
	s1->next=na;
	s2->next=nb;
return;	
}

void sortList(void)
{
int i,k;
	Casa *a,*b;
	int n;
	n=sizeList();
	
	for(i=0; i<n;i++)
	{a=head;
	 b=a->next;
		for(k=0;k<n-1-i;k++)
		{
			if(stricmp(a->adresa,b->adresa)>0)
			{
				swap(a,b);
			}
		a=a->next;
		b=b->next;	
		}
	}
return;		
}

void freeMemory(void)
{
	Casa*c,*p;
	c=head;
	while(c){
		p=c;
		c=c->next;
		free(p);
		if(c==head) break;
	}
return; 
}



