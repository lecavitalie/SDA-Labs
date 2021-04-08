//Arbore
#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    char adresa[100];
    char telefonul[100];
    float suprafata;
    int numar_odai;
    float costul;
    struct nod *left;
    struct nod *right;
}nod;

/*typedef struct nod{
    char denumire[100];
    char universitate[100];
    char profesor[100];
    char specialitate[100];
    int numaruldecredite;
    struct nod *left;
    struct nod *right;
}nod;
 */

nod *root=NULL;
// Coada
typedef struct elq{
    nod *adrnod;
    struct elq *next;
}elq;
elq *first=NULL;
elq *last=NULL;
// Stiva
typedef struct els{
    nod *adrnod;
    struct els* prev;
}els;
els *top=NULL;
int inq(nod *inf);
nod* delq();
int push(nod *inf);
nod* pop();
int create_q();
int creat_s();
nod* creat_rsd(nod *parent);
int show_q();
int show_s();
void show_rsd(nod *c);
void show_rds(nod *c);
void show_srd(nod *c);
void show_drs(nod *c);
void show_sdr(nod *c);
void show_dsr(nod *c);
nod* search_q(char *fname);
nod* search_s(char *fname);
nod* search_rsd(nod* c, char *fname);
int size_q();
int size_s();
int size_rsd(nod *c);
void freemem_rsd(nod *c);
int freemem_q();
int freemem_s();
int height_rsd(nod *c);
