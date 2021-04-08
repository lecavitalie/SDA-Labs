typedef struct Casa
{   
    char adresa[100];
    int telefonul;
    int suprafata;
    int nr_odai;
    int	 costul;
} Casa;
void reads (Casa*S, int n);
void shows (Casa*S, int n);
void searchs(Casa *S, int n, char *adresa);
void sorts (Casa*S, int n);
void modifys (Casa*S, int nm);
Casa*appends (Casa*S, int*n);
Casa*prepends (Casa*S, int*n);
Casa*insert_befores(Casa*S, int*n,int k);
Casa*insert_afters(Casa*S, int*n,int k);
Casa*deletes (Casa*S, int*n, int nd);
void swaps(Casa*S, int k1, int k2);
void saves(Casa*S, int n, char *fnume);
Casa* loads (Casa *S, char*fnume, int *n);
void form_Casa (Casa*nr);
