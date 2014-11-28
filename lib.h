//Pawe³ Syka³a
#ifndef LIB_H_
#define LIB_H_
#define ILOSC_TASKOW 8 //definiujemy ilosc taskow w tym przypadku bedzie to liczba 8
typedef void(*TPTR)(void*); 
//Tworze strukture o nazwie struktura z elementami jak ponizej
typedef struct{TPTR task; int okres; int czyGotowy; void* parameter; int idzDo; } struktura; 
struktura zadania[ILOSC_TASKOW]; //tablica taskow
void AddTask(int priorytet, int okres, TPTR pointer, void * parametry); //deklaracja funkcji dodawania taska
void execute(void); //deklaracja fukcji wykonawczej
void schedule(void); //deklaracja fukcji harmonogramu
#endif /* LIB_H_ */