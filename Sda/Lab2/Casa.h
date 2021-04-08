//lista simpla inlatuita
typedef struct casa
{
	
	char adresa[40];
	char telefonul[40];
	float suprafata;
  	int nr_odai;
  	float costul;
  	struct casa* next;
}Casa;

Casa *head;

int createList(int n);
void readInfo();
void showInfo();
Casa* searchElement(char *adress);
void modifyInfo(Casa* m);
Casa* lastElement();
int sizeList();
void swap(Casa *s1, Casa *s2);
void sortList();
void freeMemory();



