//Pawe³ Syka³a
#define F_CPU 16000000UL 
#include "lib.h"
#include <Util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

static int widok = 1;
void AddTask(int priorytet, int okres, TPTR pointer, void * parametry){
	zadania[priorytet-1].okres=okres;
	zadania[priorytet-1].task=pointer;
	zadania[priorytet-1].parameter=parametry;
	zadania[priorytet-1].czyGotowy=0;
	zadania[priorytet-1].idzDo=okres;
}
void execute(void){ int a;
	//przypisanie wszystkich zadan
	for(a=0; a<ILOSC_TASKOW;a++){
		if(zadania[a].task==0){
			zadania[a].parameter=0;
			zadania[a].okres= -1; 
			zadania[a].czyGotowy=0; //zero oznacza nie godtowosc, wiecej niz jeden i jeden ze gotowy
			zadania[a].task=0;
			zadania[a].idzDo= -1;
		}
	}
	int zliczacz=0;
	while(1){
		if(0<zadania[zliczacz].czyGotowy ){//jeœli zadanie jest gotowe to zatrzymaj obs³uge przerwania, nastepnie obsluguj zadanie
				if(widok){
					cli();
					widok = 0;
				}
			zadania[zliczacz].czyGotowy--;
			zadania[zliczacz].task(zadania[zliczacz].parameter);
			zliczacz++;
		}else{
			//zadanie nie  jest gotowe idz do przodu
			if(ILOSC_TASKOW>zliczacz+1){
				zliczacz++;
			}
			//zwroc poczatek tablicy, wlaczanie w razie potrzeby przerw
			else{
				if(widok==0){
					widok=1;
					sei();
				}
				zliczacz = 0;
}}}}
void schedule(void)
{	int a;
	for(a=0;a<ILOSC_TASKOW;a++){
			if(zadania[a].idzDo==0){ //jezeli task jest gotowy to rob
				zadania[a].czyGotowy++;
				zadania[a].idzDo=zadania[a].okres-1;
		}else{	//inaczej czeka dekrementacja
			zadania[a].idzDo--;
}}}
int main(void){
	
		execute();
}