#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "arbore.h"
int inq(nod *x){
    elq *c;
    c=(elq*)malloc(sizeof(elq));
    if(!c) return 0;
    if(!first){
        first = c;
    } else {
        last->next=c;
    }
    last=c;
    c->next=NULL;
    c->adrnod=x;
    return 1;
}

nod* delq(){
    elq *c=first;
    nod *x;
    if(c == last){
        first=last=NULL;
    } else {
        first=c->next;
    }
    x=c->adrnod;
    free(c);
    return x;
}

int push(nod *x){
    els *c;
    c=(els*)malloc(sizeof(els));
    if(!c) return 0;
    c->prev=top;
    c->adrnod=x;
    top=c;
    return 1;
}

nod* pop(){
    els *c=top;
    nod *x;
    top=c->prev;
    x=c->adrnod;
    free(c);
    return x;
}

int create_q(){
    int f;
    nod *c,*p;
    first=last=NULL;
    printf(" Doriti sa creati radacina arborelui (1/0)?: ");
    scanf("%d",&f);
    if(f){
        c=(nod*)malloc(sizeof(nod));
        if(!c) return -1;
        printf(" Introduceti datele radacinei:\n");
        printf("\nIntroduceti datele :\n");\
	    printf("Adresa : ");
        scanf("%s",&c->adresa);\
		printf("Telefonul : ");
        scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
        scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
        scanf("%d",&c->numar_odai);\
		printf("Costul : ");
        scanf("%f",&c->costul);
        if(!inq(c)) return -2;
        root = c;
    }else {
        root = NULL;
    }
    while(first){
        p = delq();
        printf(" Doriti sa creati copilul sting al nodului %s (1/0)?: ",p->adresa);
        scanf("%d",&f);
        if(f){
            c=(nod*)malloc(sizeof(nod));
            if(!c) return -3;
            printf(" Introduceti datele copilului sting\n");
            printf("\nIntroduceti datele :\n");\
	    printf("Adresa : ");
            scanf("%s",&c->adresa);\
		printf("telefonul : ");
            scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
            scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
            scanf("%d",&c->numar_odai);\
		printf("Costul : ");
            scanf("%f",&c->costul);
            p->left=c;
            if(!inq(c)) return -2;
        } else {
            p->left=NULL;
        }
        printf(" Doriti sa creati copilul drept al nodului %s (1/0)?: ",p->adresa);
        scanf("%d",&f);
        if(f){
            c=(nod*)malloc(sizeof(nod));
            if(!c) return -3;
            printf(" Introduceti datele copilului drept\n");
            printf("\nIntroduceti datele :\n");\
	    printf("Adresa : ");
            scanf("%s",&c->adresa);\
		printf("telefonul : ");
            scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
            scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
            scanf("%d",&c->numar_odai);\
		printf("Costul : ");
            scanf("%f",&c->costul);
            p->right = c;
            if(!inq(c)) return -2;
        } else {
            p->right = NULL;
        }
    }
    return 1;
}

int show_q(){
    nod *p,*c;
    first=last=NULL;
    if(!root) return 0;
    p=root;
    if(!inq(p)) return -2;
    printf(" Lista nodurilor\n\n");
    while(first){
        p=delq();
        printf("==================================================\n\n");
        printf("Adresa                        %s\n",p->adresa);
        printf("Telefonul                       %s\n",p->telefonul);
        printf("Suprafata                     %f\n",p->suprafata);
        printf("Numar de odai            %d\n",p->numar_odai);
        printf("Costul                         %f\n\n",p->costul);
        c=p->left;
        if(c){
            if(!inq(c)) return -2;
        }
        c=p->right;
        if(c){
            if(!inq(c)) return -2;
        }
    }
    return 1;
}
nod* search_q(char *fname){
    nod *p,*c;
    first=last=NULL;
    if(!root) return NULL;
    p=root;
    if(!inq(p)) return NULL;
    while(first){
        p=delq();
        if(!strcmp(p->adresa,fname)) return p;
        c=p->left;
        if(c){
            if(!inq(c)) return NULL;
        }
        c=p->right;
        if(c){
            if(!inq(c)) return NULL;
        }
    }
    return NULL;
}


int size_q(){
    int s=0;
    nod *p,*c;
    first=last=NULL;
    if(!root) return 0;
    p=root;
    if(!inq(p)) return -2;
    while(first){
        p=delq();
        s++;
        c=p->left;
        if(c){
            if(!inq(c)) return -2;
        }
        c=p->right;
        if(c){
            if(!inq(c)) return -2;
        }
    }
    return s;
}

int freemem_q(){
    nod *p,*c;
    first=last=NULL;
    if(!root) return 0;
    p=root;
    if(!inq(p)) return -2;
    while(first){
        p=delq();
        c=p->left;
        if(c){
            if(!inq(c)) return -2;
        }
        c=p->right;
        if(c){
            if(!inq(c)) return -2;
        }
        free(p);
    }
    return 1;
}
int height_q(nod *c){
    int l=0,r=0;
    if(!c) return -1;
    l=1+height_q(c->left);
    r=1+height_q(c->right);
    if(l>r) return l;
    else return r;
}

int creat_s(){
    nod *p, *c;
    int f;
    root=NULL;
    top=NULL;
    printf(" Doriti sa creati radacina arborelui (1/0)? : ");
    fflush(stdin);
    scanf("%d",&f);
    if(f){
        c=(nod*)malloc(sizeof(nod));
        if(!c) return -1;
        printf(" Introduceti datele \n");
        printf("Adresa : ");
        scanf("%s",&c->adresa);\
		printf("Telefonul : ");
        scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
        scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
        scanf("%d",&c->numar_odai);\
		printf("Costul : ");
        scanf("%f",&c->costul);
        if(!push(c)) return -5;
        root=c;
        while(top){
            p=pop();
            printf(" Doriti sa creati copilul drept al nodului %s (1/0)?: ",p->adresa);
            fflush(stdin);
            scanf("%d",&f);
            if(f){
                c=(nod*)malloc(sizeof(nod));
                if(!c) return -3;
                printf(" Introduceti datele\n");
                printf("Adresa : ");
                scanf("%s",&c->adresa);\
		printf("Telefonul : ");
                scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
                scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
                scanf("%d",&c->numar_odai);\
		printf("Costul : ");
                scanf("%f",&c->costul);
                p->right = c;
                if(!push(c)) return -5;
            } else {
                p->right = NULL;
            }
            printf(" Doriti sa creati copilul sting al nodului %s (1/0)?: ",p->adresa);
            fflush(stdin);
            scanf("%d",&f);
            if(f){
                c=(nod*)malloc(sizeof(nod));
                if(!c) return -3;
                printf(" Introduceti datele\n");
                printf("Adresa : ");
                scanf("%s",&c->adresa);\
		printf("Telefonul : ");
                scanf("%s",&c->telefonul);\
	    printf("Suprafata : ");
                scanf("%f",&c->suprafata);\
		printf("Numar de odai : ");
                scanf("%d",&c->numar_odai);\
		printf("Costul : ");
                scanf("%f",&c->costul);
                p->left=c;
                if(!push(c)) return -5;
            } else {
                p->left=NULL;
            }
        }
    }
    return 1;
}

int show_s(){
    nod *p,*c;
    top=NULL;
    if(!root) return 0;
    p=root;
    if(!push(p)) return -5;
    printf("Lista nodurilor\n\n");
    while(top){
        p=pop();
        printf("==================================================\n\n");
        printf("Adresa                        %s\n",p->adresa);
        printf("Telefonul                       %s\n",p->telefonul);
        printf("Suprafata                     %f\n",p->suprafata);
        printf("Numar de odai            %d\n",p->numar_odai);
        printf("Costul                         %f\n\n",p->costul);
        c=p->right;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
        c=p->left;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
    }
    printf("\n");
    return 1;
}

int size_s(){
    nod *p,*c;
    int s=0;
    top=NULL;
    if(!root) return 0;
    p=root;
    if(!push(p)) return -5;
    while(top){
        p=pop(); s++;
        c=p->right;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
        c=p->left;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
    }
    return s;
}

nod* search_s(char *fname){
    nod *p,*c;
    top=NULL;
    if(!root) return NULL;
    p=root;
    if(!push(p)) return NULL;
    while(top){
        p=pop();
        if(!strcmp(fname,p->adresa)) return p;
        c=p->right;
        if(c!=NULL){
            if(!push(c)) return NULL;
        }
        c=p->left;
        if(c!=NULL){
            if(!push(c)) return NULL;
        }
    }
    return NULL;
}


int freemem_s(){
    nod *p,*c;
    top=NULL;
    if(!root) return 0;
    p=root;
    if(!push(p)) return -5;
    while(top){
        p=pop();
        c=p->right;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
        c=p->left;
        if(c!=NULL){
            if(!push(c)) return -5;
        }
        free(p);
    }
    return 1;
}
int height_s(nod *c){
    int l=0,r=0;
    if(!c) return -1;
    l=1+height_s(c->left);
    r=1+height_s(c->right);
    if(l>r) return l;
    else return r;
}

nod* creat_rsd(nod* parent){
    nod *c;
    int f;
    c=(nod*)malloc( sizeof(*c) );
    if(!c) return NULL;

    printf(" Introduceti datele\n");
    printf(" Adresa: ");
    fflush(stdin);
    scanf("%s",&c->adresa);
    printf(" Telefonul: ");
    scanf("%s",&c->telefonul);
    printf(" Suprafata: ");
    scanf("%f",&c->suprafata);
    printf(" Numar de odai: ");
    scanf("%d",&c->numar_odai);
    printf(" Costul: ");
    scanf("%f",&c->costul);
    printf(" Doriti sa creati copilul sting al nodului %s (1/0)?: ",c->adresa);
    fflush(stdin);
    scanf("%d",&f);
    if(f){
        c->left=creat_rsd(c);
    } else {
        c->left=NULL;
    }
    printf(" Doriti sa creati copilul drept al nodului %s (1/0)?: ",c->adresa);
    fflush(stdin);
    scanf("%d",&f);
    if(f){
        c->right=creat_rsd(c);
    } else {
        c->right=NULL;
    }
    return c;
}
void show_rsd(nod *c){
    if(!c){
        return;
    }
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Suprafata                     %f\n",c->suprafata);
    printf("Numar de odai            %d\n\n",c->numar_odai);
    printf("Costul                         %f\n\n",c->costul);
    show_rsd(c->left);
    show_rsd(c->right);
}
void show_rds(nod *c){
    if(!c){
        return;
    }
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Suprafata                     %f\n",c->suprafata);
    printf("Numar de odai            %d\n",c->numar_odai);
    printf("Costul                         %f\n\n",c->costul);
    show_rds(c->right);
    show_rds(c->left);
}
void show_srd(nod *c){
    if(!c){
        return;
    }
    show_srd(c->left);
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Suprafata                     %f\n",c->suprafata);
    printf("Numar de odai            %d\n",c->numar_odai);
    printf("Costul                         %d\n\n",c->costul);
}
void show_drs(nod *c){
    if(!c){
        return;
    }
    show_drs(c->right);
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Numar de odai                     %d\n",c->numar_odai);
    printf("Suprafata            %f\n",c->suprafata);
    printf("Costul                         %f\n\n",c->costul);
    show_drs(c->left);
}
void show_sdr(nod *c){
    if(!c){
        return;
    }
    show_sdr(c->left);
    show_sdr(c->right);
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Suprafata                     %f\n",c->suprafata);
    printf("Numar de odai            %d\n",c->numar_odai);
    printf("Costul                         %f\n\n",c->costul);
}

void show_dsr(nod *c){
    if(!c){
        return;
    }
    show_dsr(c->right);
    show_dsr(c->left);
    printf(" ---Nodul %s---\n",c->adresa);
    printf("==================================================\n\n");
    printf("Adresa                        %s\n",c->adresa);
    printf("Telefonul                       %s\n",c->telefonul);
    printf("Suprafata                     %f\n",c->suprafata);
    printf("Numar de odai            %d\n",c->numar_odai);
    printf("Costul                         %f\n\n",c->costul);
}
void freemem_rsd(nod *c)
{
    if(!c) return;
    freemem_rsd(c->left);
    freemem_rsd(c->right);
    free(c);
}

nod* search_rsd(nod* c, char *fname){
    nod* t=NULL;
    if(!c) return NULL;
    if (!strcmp(c->adresa,fname)) return c;
    t=search_rsd(c->left,fname);
    if (t) return t;
    t=search_rsd(c->right,fname);
    if (t) return t;
    return NULL;
}


int size_rsd(nod *c){
    int n=0;
    if(!c){return n;}
    return 1 + size_rsd(c->left) + size_rsd(c->right);
}
int height_rsd(nod *c){
    int l=0,r=0;
    if(!c) return -1;
    l=1+height_rsd(c->left);
    r=1+height_rsd(c->right);
    if(l>r) return l;
    else return r;
}
