#include "casa.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    casa *head1;
    int i=0,l=0,k,n,n1,m=0,id=0,f,rs;
    casa *a,*b,*p,*cautat,*v;
    casa s,y;
    char adr[100],adr1[100],adr2[100],num[100],*fname;
    int optiune;
    optiune=0;
    do{
        system("CLS");
        puts(" >> MENU <<");
        puts(" 1. Crearea listei.");
        puts(" 2. Introducerea datelor.");
        puts(" 3. Afisarea datelor.");
        puts(" 4. Cautarea unui element.");
        puts(" 5. Modificarea listei.");
        puts(" 6. Determinarea lungimei listei.");
        puts(" 7. Sortarea elementelor.");
        puts(" 8. Interschimbarea a 2 elemente.");
        puts(" 9. Eliberaraea memoriei.");
        puts(" 10.Adaugarea unui element la inceputul listei.");
        puts(" 11.Adaugarea unui element la sfirsitul listei.");
        puts(" 12.Inserarea inainte de element.");
        puts(" 13.Inserarea dupa element.");
        puts(" 14.Stergerea unui element.");
        puts(" 15.Pentru a desparti lista.");
        puts(" 16.Pentru a uni lista.");
        puts(" 17.Scrierea datelor in fisier.");
        puts(" 18.Citirea datelor din fisier.");
        puts(" 0. Iesire.");
        printf("\n Alegeti optiunea: ");
        scanf("%d",&optiune);
        switch (optiune){
            case 1: {
                printf(" Dati numarul de case: ");
                scanf("%d",&n);
                head=create(head,n);
                system("PAUSE");
                break;
            }
            case 2: {
                if(!head){
                    puts(" Memoria nu a fost alocata");
                    getch();
                    break;
                }
                if(!id)
                {  read(head,n);
                    id=1;
                }
                else
                    puts(" Datele au fost deja introduse");
                system("PAUSE");
                break;
            }
            case 3: {
                if(!head){puts(" Memoria nu a fost alocata");}
                if(id)
                {
                    puts(" Lista de structuri");
                    show(head);
                }
                else
                {
                    printf(" Doriti sa introduceti informatia?(1/0): ");
                    scanf("%d",&f);
                    if(f)
                    {read(head,n);
                        id=1;
                        puts(" Lista de structuri");
                        show(head);
                    }
                }

                system("PAUSE");
                break;
            }
            case 4: {
                printf(" Introduceti denumirea de cautat: ");
                fflush(stdin);
                gets(adr);
                p=searchs(head,adr);
                if(p==0){
                    puts(" Casa nu a fost gasit in baza de date");
                    puts(" Pentru a continua apasa-ti tasta 'Enter'");
                    getch();
                    break;
                }
                puts(" Hotelul cautat");
                printf(" Adresa: %s\n Telefonul: %s\n Suprafata: %f\n Numarul de odai: %d\n Costul: %f",p->adresa,p->telefonul,p->suprafata,p->nr_odai, p->costul);
                system("PAUSE");
                break;
            }
            case 5: {
                printf(" Dati adresa casei pe care doriti sa-l modificati: ");
                fflush(stdin);
                gets(adr);
                cautat=searchs(head,adr);
                if(cautat==0)
                {
                    puts(" Casa nu a fost gasit in baza de date");
                    puts(" Pentru a continua apasa-ti tasta 'Enter'");
                    getch();
                    break;
                }
                modify(head,cautat);
                printf(" Doriti sa afisati casa modificat?(1/0): ");
                scanf("%d",&f);
                if(f)
                {
                    puts(" Casa dupa modificare");
                    show2(cautat);
                    puts("\n Pentru a continua apasa-ti tasta 'Enter'");
                    getch();
                    break;
                }
                else break;

                system("PAUSE");
                break;
            }
            case 6: {
                if(!head)
                {
                    puts("Memoria nu a fost alocata");
                    getch();
                    break;
                }
                k=lenght(head);
                printf(" Lungimea listei este << ");
                printf("%d",k);
                printf(" >>\n");
                system("PAUSE");
                break;
            }
            case 7: {
                sorts(head);
                puts(" Lista a fost sortata");
                printf(" Doriti sa afisati lista sortata(1/0): ");
                scanf("%d",&f);
                if(f)
                {
                    puts(" Lista dupa sortare");
                    show(head);
                }
                puts("\n Pentru a continua apasa-ti tasta 'Enter'");
                getch();
                break;
                system("PAUSE");
                break;
            }
            case 8: {
                printf(" Dati adresa primului element de schimbat: ");
                fflush(stdin);
                gets(adr1);
                a=searchs(head,adr1) ;
                if(a==0)
                {
                    puts(" Elementul cu asa adresa nu a fost gasit");
                    getch();
                    break;
                }
                printf(" Dati adresa la al doilea element de schimbat: ");
                fflush(stdin);
                gets(adr2);
                b=searchs(head,adr2);
                if(b==0)
                {
                    puts(" Elementul cu asa adresa nu a fost gasit");
                    getch();
                    break;
                }
                swaps(a,b);
                puts(" Interschimbarea elementelor a fost efectuata cu succes");
                printf(" Doriti sa fie afisata lista modificata(1/0): ");
                scanf("%d",&f);
                if(f)
                {
                    printf(" Lista dupa interschimbare\n");
                    show(head);
                }
                puts("\n Pentru a continua apasa-ti tasta 'Enter'");
                getch();
                break;

                system("PAUSE");
                break;
            }
            case 9: {
                head=freem(head);
                if(head)
                    puts(" Lista nu a fost eliberata") ;
                if(!head)
                    id=0;
                puts(" Memoria a fost eliberata cu succes!!!");
                system("PAUSE");
                break;
            }
            case 10: {
                puts(" Introduce-ti informatia despre elementul de adaugat");
                rs=prepend();
                if (rs==0)
                {puts(" Lista este vida");}
                if (rs==-1) {puts(" Elementul nu a fost adaugat");}
                if (rs==1) {puts(" Elementul a fost adaugat cu succes");}
                system("PAUSE");
                break;
            }
            case 11: {
                puts(" Introduce-ti informatia despre elementul de adaugat");
                introducere(&s);
                rs=append(head,s,&n);
                if (rs==0)
                {puts(" Lista este vida");}
                if (rs==-1) {puts(" Elementul nu a fost adaugat");}
                if (rs==1) {puts(" Elementul a fost adaugat cu succes");}
                system("PAUSE");
                break;
            }
            case 12: {
                printf(" Dati numele elementului inaintea caruia doriti sa inserati: ");
                fflush(stdin); gets(adr);
                cautat=searchs(head,adr);
                if (cautat==NULL)
                {
                    puts(" Acest element nu exista");
                    getch();
                    break;
                }
                puts(" Introduceti datele despre elementul care doriti sa-l adaugati\n ");
                introducere(&s);
                head=insertbefore(head,cautat,s,&n);
                puts(" Elementul a fost adaugat cu succes");
                system("PAUSE");
                break;
            }
            case 13: {
                printf(" Dati numele elementului dupa care doriti sa inserati: ");
                fflush(stdin); gets(adr);
                cautat=searchs(head,adr);
                if (cautat==NULL)
                {
                    puts("Acest element nu exista");
                    getch();
                    break;
                }
                puts(" Introduceti datele despre elementul care doriti sa-l adaugati");
                introducere(&s);
                rs=insertafter(head,cautat,s,&n);
                if (rs==-1) {puts("Elementul nu a fost adaugat");}
                if (rs==1) {puts("Elementul a fost adaugat cu succes");}
                system("PAUSE");
                break;
            }
            case 14: {
                if(!head)
                {
                    puts(" Memoria nu a fost alocata");
                    getch();
                    break;
                }
                puts(" Lista de structuri");
                printf("\n");
                show(head);
                printf(" Dati numele elementului care doriti sa-l stergeti: ");
                fflush(stdin);
                gets(adr);
                cautat=searchs(head,adr);
                if (cautat==NULL)
                {
                    puts(" Acest element nu exista");
                    getch();
                    break;
                }
                head=deletes(head,cautat,&n);
                puts(" Stergerea a fost efectuata cu succes");
                getch();
                break;
                system("PAUSE");
                break;
            }
            case 15: {
                printf(" Dati indicele hotelului de unde doriti sa impartiti lista in doua: ");
                scanf("%d", &n1);
                split(head,&head1, n1);
                show(head);
                puts("\n Lista dupa despartire");
                showhead1(head,head1);
                system("PAUSE");
                break;
            }
            case 16: {
                if(head1){
                    join(head,&head1);
                    puts(" Unirea a avut loc cu succes!");
                }
                else{puts(" Despartiti lista!");	}
                system("PAUSE");
                break;
            }
            case 17: {
                if(!head)
                {
                    puts(" Memoria nu a fost alocata");
                    getch();
                    break;
                }
                printf(" Dati numele fisierului in care doriti sa salvati lista: ");
                fflush(stdin);
                gets(num);
                rs=save(head,num);
                if(rs==0) {puts(" Salvarea nu a avut loc");}
                if(rs==1) {puts(" Salvarea s-a efectuat cu succes");m=1;}
                system("PAUSE");
                break;
            }
            case 18:{
                if(!head)
                {
                    puts(" Memoria nu a fost alocata");
                    getch();
                    break;
                }
                else{
                    printf(" Dati numele fisierului din care doriti sa incarcati lista: ");
                    fflush(stdin);
                    gets(num);
                    rs=load(head,num);
                    if(rs==0)
                    {
                        puts(" Deschiderea nu s-a efectuat");
                        getch();
                        break;
                    }
                    if(rs==1)
                    {
                        id=1;
                        puts(" Deschiderea a fost efectuata cu succes");
                        printf(" Doriti sa afisati lista incarcata?(1/0): ");
                        scanf("%d",&f);
                        if(f)
                        {
                            puts(" Lista incarcata");
                            printf("\n");
                            show(head);
                        }
                    }
                }
                system("PAUSE");
                break;
            }
            case 0:{
                if(head){
                    if(!m)
                    {
                        printf(" Informatia va fi pierduta...salvati?(1/0): ");
                        scanf("%d",&f);
                        if(f)
                        {printf(" Dati numele fisierului in care doriti sa salvati lista: ");
                            fflush(stdin);
                            gets(num);
                            rs=save(head, num);
                            if(rs==0) {puts(" Salvarea nu a avut loc");}
                            if(rs==1) {puts(" Salvarea a  fost efectuata cu succes");}
                        } else
                            printf(" Pentru a iesi apasa-ti tasta 'ENTER'");
                        getch();
                        free(head);
                        head=NULL;
                        return 0;
                    }
                }
                printf(" Doriti sa iesiti?(1/0): ");
                scanf("%d",&f);
                if(f)
                {
                    if(head)
                    {
                        free(head);
                        head=NULL;
                    }
                    return 0;
                }
                else
                    break;
                default:
                    puts(" Alegeti optiunea corect");
                getch();
            }
        }
    }
    while(optiune!=0);
    getch();
    return 0;
}
