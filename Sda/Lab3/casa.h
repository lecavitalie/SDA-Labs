#ifndef ONE
#define ONE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct casa{
    char telefonul[50];
    char adresa[100];
    float suprafata;
    int nr_odai;
    float costul;
    struct casa* next;
};
typedef struct casa casa;
casa *head;

void show2(casa *head);
void introducere(casa* head);
int create(casa* head,int n);
void read(casa* head,int n);
void show(casa* head);
casa* searchs(casa* head,char adr[]);
void modify(casa *head,casa* a);
int lenght(casa* head);
void sorts(casa* head);
void swaps(casa* a,casa* b);
casa* freem(casa* head);
casa* insertbefore(casa* head,casa *a,casa b,int *n);
int insertafter(casa* head,casa *b,casa a,int *n);
int prepend();
int append(casa* head,casa a,int *n);
casa *deletes(casa* head,casa* a,int *n);
int save(casa* head,char*fname);
int load(casa* head,char*fname);
void join(casa* head,casa **head1);
void split(casa* head,casa **head1,int n1);
void showhead1(casa *head,casa *head1);
#endif // ONE