

#include "function.cpp"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    nod *t=NULL;
    char fname[100];
    int optiune=0;
    do{
    system("cls");
 printf(" Meniul programului de prelucrare a arborelui cu ajutorul   \n");
 printf("            algoritmilor iterativi si recursivi             \n");
 printf("                      1. COADA                              \n");
 printf("  1. Crearea arborelui                                      \n");
 printf("  2. Afisarea arborelui                                     \n");
 printf("  3. Cautarea unui nod                                      \n");
 printf("  4. Marimea arborelui                                      \n");
 printf("  5. Inaltimea arborelui                                    \n");
 printf("  6. Eliberarea memoriei                                    \n");
 printf("                     2. STIVA                               \n");
 printf("  7. Crearea arborelui                                      \n");
 printf("  8. Afisarea arborelui                                     \n");
 printf("  9. Cautarea unui nod                                      \n");
 printf(" 10. Marimea arberelui                                      \n");
 printf(" 11. Inaltimea arberelui                                    \n");
 printf(" 12. Eliberarea memoriei                                    \n");
 printf("        PRELUCAREA ARBORELUI FOLOSIND RECURSIVITATEA        \n");
 printf(" 13. Crearea RSD                                            \n");
 printf(" 14. Afisarea RSD                                           \n");
 printf(" 15. Afisarea RDS                                           \n");
 printf(" 16. Afisarea SRD                                           \n");
 printf(" 17. Afisarea DRS                                           \n");
 printf(" 18. Afisarea SDR                                           \n");
 printf(" 19. Afisarea DSR                                           \n");
 printf(" 20. Marimea arborelui                                      \n");
 printf(" 21. Inaltimea arborelui                                    \n");
 printf(" 22. Cautarea unui nod                                      \n");
 printf(" 23. Eliberarea memoriei                                    \n");
 printf("                   IESIRE DIN PROGRAM                       \n");
 printf("  0. Iesire.                                                \n");
    printf("\n Alegeti optiunea: ");
    scanf("%d",&optiune);
    switch (optiune){
        case 1: {
        create_q();
        system("PAUSE");
        break;
        }
        case 2: {
        show_q();
        system("PAUSE");
        break;
        }
        case 3: {
        printf(" Introduceti numele de cautat: ");
		fflush(stdin);
		scanf("%s",&fname);
		t=search_q(fname);
		if(t){
            printf(" ---Nodul %s---\n",t->adresa);
              printf("Adresa                        %s\n",t->adresa);
             printf("Telefonul                       %s\n",t->telefonul);
             printf("Suprafata                     %f\n",t->suprafata);
             printf("Numar de odai            %d\n",t->numar_odai);
             printf("Costul                         %f\n\n",t->costul);
		} else {
			printf(" Nu exista asa adresa!\n");}
        system("PAUSE");
        break;
        }
        case 4: {
        printf(" Nodurile arborelui = %d\n",size_q());
        system("PAUSE");
        break;
        }
        case 5: {
        printf(" Inaltimea arborelui este %d \n", height_q(root));
        system("PAUSE");
        break;
        }
        case 6: {
        freemem_q();
        root=NULL;
        printf(" Eliberarea memoriei a avut loc cu succes!\n");
        system("PAUSE");
        break;
        }
        case 7: {
        creat_s();
        system("PAUSE");
        break;
        }
        case 8: {
        show_s();
        system("PAUSE");
        break;
        }
        case 9: {
         printf(" Introduceti adresa de cautat: ");
		fflush(stdin);
		scanf("%s",&fname);
		t=search_s(fname);
		if(t){
            printf(" ---Nodul %s---\n",t->adresa);
             printf("Adresa                        %s\n",t->adresa);
             printf("Telefonul                       %s\n",t->telefonul);
             printf("Suprafata                     %f\n",t->suprafata);
             printf("Numar de odai            %d\n",t->numar_odai);
             printf("Costul                         %f\n\n",t->costul);
		} else {
			printf(" Nu exista asa adresa!\n");}
        system("PAUSE");
        break;
        }
        case 10: {
        printf(" Nodurile arborelui = %d\n",size_s());
        system("PAUSE");
        break;
        }
        case 11: {
        printf(" Inaltimea arborelui este %d \n", height_s(root));
        system("PAUSE");
        break;
        }
        case 12: {
        freemem_s();
        root=NULL;
        printf(" Eliberarea memoriei a avut loc cu succes!\n");
        system("PAUSE");
        break;
        }
        case 13: {
        creat_rsd(NULL);
        system("PAUSE");
        break;
        }
        case 14: {
        show_rsd(root);
        system("PAUSE");
        break;
        }
        case 15: {
        show_rds(root);
        system("PAUSE");
        break;
        }
        case 16: {
        show_srd(root);
        system("PAUSE");
        break;
        }
        case 17: {
        show_drs(root);
        system("PAUSE");
        break;
        }
        case 18: {
        show_sdr(root);
        system("PAUSE");
        break;
        }
        case 19: {
        show_dsr(root);
        system("PAUSE");
        break;
        }
        case 20: {
        printf(" Nodurile arborelui = %d\n",size_rsd(root));
        system("PAUSE");
        break;
        }
        case 21: {
        printf(" Inaltimea arborelui este %d \n", height_rsd(root));
        system("PAUSE");
        break;
        }
        case 22: {
        printf(" Introduceti numele de cautat: ");
		fflush(stdin);
		scanf("%s",&fname);
		t=search_rsd(root,fname);
		if(t){
		    printf(" ---Nodul %s---\n",t->adresa);
             printf("Adresa                        %s\n",t->adresa);
             printf("Telefonul                       %s\n",t->telefonul);
             printf("Suprafata                     %f\n",t->suprafata);
             printf("Numar de odai            %d\n",t->numar_odai);
             printf("Costul                         %f\n\n",t->costul);
		} else {
			printf(" Nu exista asa nume!\n");}
        system("PAUSE");
        break;
        }
        case 23: {
        freemem_rsd(root);
        root=NULL;
        printf(" Eliberarea memoriei a avut loc cu succes!\n");
        system("PAUSE");
        break;
        }
       case 0:{
        printf(" Daca doriti sa iesiti tastati ENTER\n");
        return 0;
        }
        default:{
        printf(" Optiunea nu exista!\n");
        break;
        }
    }
    }
    while(optiune!=0);
    getch();
    return 0;
}
