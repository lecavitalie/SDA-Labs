

#include "casa.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void show2(casa *head){
    casa *p;
    p=head;
        printf(" Adresa: %s\n ",p->adresa);
        printf("  Telefonul: %s\n ",p->telefonul);
        printf(" Suprafata: %f\n ",p->suprafata);
        printf(" NUmarul de odai: %d\n ",p->nr_odai);
        printf(" Costul: %f\n ",p->costul);
}
void introducere(casa* head)
{
    casa *p;
  p=head;
  if(!p)
  p = (casa*)malloc(sizeof(*p));
  printf(" Adresa: ");
  fflush(stdin);
  gets(p->adresa);
  printf(" Telefonul: ");
  fflush(stdin);
  gets(p->telefonul);
  printf(" Costul: ");
  scanf("%f",&p->costul);
  p=p->next;
  printf(" Suprafata: ");
  scanf("%f",&p->suprafata);
  p=p->next;
  printf(" Numarul de odai: ");
  scanf("%d",&p->nr_odai);
  p=p->next;


}


int create(casa* head,int n) {
    casa *p,*q;
int i;
    for(i=0;i<n;i++){
    p=(casa*)malloc(sizeof(*p));

    if(!p)
    return NULL;
    if(i==0)
    {head=p;}
    else
    {q->next=p;}
    p->next=NULL;
    q=p;
  }
   puts(" Memoria a fost alocata cu succes!!!");
  return head;

}

void read(casa* head,int n){
    casa *p;
     int i=1;
     printf(" Dati informatia despre casa\n");
     p=head;
     while(p){
        printf("\nCasa %d\n",i++);
         printf(" Adresa: ");
         fflush(stdin);
         gets(p->adresa);
         printf(" Telefonul: ");
         fflush(stdin);
         gets(p->telefonul);
         printf(" Costul: ");
         scanf("%f",&p->costul);
         p=p->next;
         printf(" Suprafata: ");
         scanf("%f",&p->suprafata);
         p=p->next;
         printf(" Numarul de odai: ");
         scanf("%d",&p->nr_odai);
         p=p->next;
        if(p==head){
        break;}
     }
}
void show(casa* head){
    int i=1;
    casa *p;
    p=head;
    while(p){
        printf(" Adresa: %s\n ",p->adresa);
        printf("  Telefonul: %s\n ",p->telefonul);
        printf(" Suprafata: %f\n ",p->suprafata);
        printf(" NUmarul de odai: %d\n ",p->nr_odai);
        printf(" Costul: %f\n ",p->costul);
        p=p->next;

    }
}

casa* searchs(casa* head,char adr[]){
    casa *p;
     p=head;
     while(p){
        if(stricmp(p->adresa,adr)==0){return p;}
        p=p->next;
     }
     return NULL;
}
void modify(casa *head,casa* a) {
    int t;
    printf(" Doriti sa modificati adresa?(1/0): ");
    scanf("%d", &t);
    if (t) {
        printf(" Dati adresa noua: ");
        fflush(stdin);
        gets(a->adresa);
    }
    printf(" Doriti sa modificati telefonul?(1/0): ");
    scanf("%d", &t);
    if (t) {
        printf(" Dati telefonul nou: ");
        fflush(stdin);
        gets(a->telefonul);
    }
    printf(" Doriti sa modificati costul?(1/0): ");
    scanf("%d", &t);
    if (t) {
        printf(" Dati numarul nou al costului: ");
        fflush(stdin);
        scanf("%f", &a->costul);

        printf(" Doriti sa modificati suprafata?(1/0): ");
        scanf("%d", &t);
        if (t) {
            printf(" Dati numarul nou al suprafetei: ");
            fflush(stdin);
            scanf("%f", &a->suprafata);
        }
        printf(" Doriti sa modificati numarul de odai?(1/0): ");
        scanf("%d", &t);
        if (t) {
            printf(" Dati numarul nou al odailor: ");
            fflush(stdin);
            scanf("%d", &a->nr_odai);
        }
    }
}
int lenght(casa* head){
    casa *p;
    int l=0;
    p=head;
    while(p){
        l++;
        p=p->next;
        if(p==head)break;
    }
    return l;
}
void sorts(casa* head){
    casa *a,*b;
    int i,k,l;
    a=(casa*)malloc(sizeof(casa));
    if(!a){puts(" Memoria nu a fost alocata");
    exit(1);}
	b=(casa*)malloc(sizeof(casa));
	if(!b){puts(" Memoria nu a fost alocata");
    exit(1);}
    l=lenght(head);
    for(i=0;i<l-1;i++){
        a=head;
        b=a->next;
        for(k=0;k<l-1-i;k++){
        if(stricmp(a->adresa,b->adresa)>0){
        swaps(a,b);
        }
        a=a->next;
        b=b->next;
        }
    }
}
void swaps(casa* a,casa* b){
    casa *na,*nb;
    casa t;
     na=a->next;
     nb=b->next;
     t=*a;
     *a=*b;
     *b=t;
     a->next=na;
     b->next=nb;
}
casa *freem(casa* head){
    casa*p,*q;
    if(head==NULL)
    return NULL;
     p=head;
     while(p){
    q=p;
    p=p->next;
    free(p);
    if(p==head)
    break;
  }
  head=NULL;
  return NULL;
}

int insertafter(casa* head,casa *b,casa a,int *n)
 {
     casa *p;
	p=(casa *) malloc (sizeof (casa));
	if (p==NULL)
	return -1;
	*p=a;
	if(b->next==NULL)
	{
		p->next=NULL;
		b->next=p;
	}
	else
	{
		p->next=b->next;
		b->next=p;
	}
	*n=*n+1;
	return 1;
 }
casa* insertbefore(casa* head,casa *a,casa b,int *n)
{
    casa *p, *q;
	p=(casa *) malloc (sizeof (casa));
	if (p==NULL)
	return p;
	if (a==head)
	{
		*p=b;
		p->next=a;
		head=p;
		return head;
	}
	q=head;
	while (q->next!=a)
	{q=q->next;}
	*p=b;
	q->next=p;
	p->next=a;
	*n=*n+1;
	return head;
}


int prepend()
{
    casa *p;
    p=(casa*)malloc(sizeof(*p));
    if(!p) return 0;
    printf(" Adresa: ");
    fflush(stdin);
    gets(p->adresa);
    printf(" Telefonul: ");
    fflush(stdin);
    gets(p->telefonul);
    printf(" Costul: ");
    scanf("%f",&p->costul);
    p=p->next;
    printf(" Suprafata: ");
    scanf("%f",&p->suprafata);
    p=p->next;
    printf(" Numarul de odai: ");
    scanf("%d",&p->nr_odai);
    if(head!=NULL)
    {p->next=head;}
    else
    {p->next=NULL;}
    head=p;
    return 1;
}

int append(casa* head,casa a,int *n)
{
    casa *p, *q;
	if (head==NULL)
	return 0;
    q=head;
    while(q->next)
  {
    q=q->next;
    if(q==head)
    break;
  }
	p=(casa *)malloc (sizeof(casa));
	if (p==NULL)
	return -1;
	*p=a;
	q->next=p;
	p->next=NULL;
	*n=*n+1;
	return 1;

}


casa *deletes(casa* head,casa* a,int *n)
 {
     casa *p;
	p=head;
	if (p->next==NULL)
	{
		head=NULL;
		free(p);
		return head;
	}
	if(p==a)
	{
		head=p->next;
		free(p);
	}
	else
	{
	while(p->next!=a)
	{p=p->next;}
	p->next=a->next; free(a);}
	*n=*n-1;
	return head;
 }


int save(casa* head,char*fname)
 {
     casa*p;
	FILE*fp;
	fp=fopen(fname,"w");
	if(!fp)
	return 0;
	p=head;
	while(p)
	{
		fprintf(fp,"%s %s %f %f %d",p->adresa,p->telefonul,p->costul,p->suprafata, p->nr_odai);
		p=p->next;
		if(p==head)
		break;
	}
	fclose(fp);
	return 1;
 }

int load(casa* head,char*fname)
 {
     casa*p;
	FILE *fp;
	int i=1,l;
	l=lenght(head);
	fp=fopen(fname,"r");
	p=head;
	for(i=0;i<l;i++){
		fscanf(fp,"%s%s%f%f%d",p->adresa,p->telefonul,p->costul,p->costul, p->nr_odai);
		p=p->next;
	}
	fclose(fp);
	return 1;
}
void join(casa* head,casa **head1){
    casa *p;
	p=head;
	while(p){
		if(p->next==NULL){
			p->next=*head1;
			break;
		}
		p=p->next;
	}
	*head1=NULL;
}
void split(casa *head,casa **head1, int n1){
    casa *p;
	p=head;
	int i=0;
		while(p){
			if(i==n1-1){
				*head1=p->next;
				p->next=NULL;
				break;
			}
			i++;
			p=p->next;
}
		return;
}
void showhead1(casa *head,casa *head1){
    int i=1;
    casa *p;
    p=head1;
    while(p){
        printf("Casa %d\n ",i++);
        printf(" Adresa: %s\n ",p->adresa);
        printf("  Telefonul: %s\n ",p->telefonul);
        printf(" Suprafata: %f\n ",p->suprafata);
        printf(" Numarul de odai: %d\n ",p->nr_odai);
        printf(" Costul: %f\n ",p->costul);
        p=p->next;

    }
}
