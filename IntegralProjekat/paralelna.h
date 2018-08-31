#pragma once

#include <stdlib.h>
#include <iostream>
#include "tbb/task_scheduler_init.h"
#include "tbb/tick_count.h"
#include "tbb/task.h"
#include "Konstante.h"

extern double INTERVAL;

/* Klasa koja realizuje paralelizaciju programa upotrebom tbb zadataka
   Klasa je realizovana po uzoru na primer za racunanje fibonacijevih brojeva upotrebom tbb zadataka
*/
class IntegralZadatak : public tbb::task {

private:
	double pocetak; //donja granica intervala DG
	double kraj; // gornja granica intervala GG
	double sredina; //prepolovljena velicina intervala
	double* const rezultat; //pokazivac na rezultat izracunavanja integrala
public:
	//konstruktor dobija DG, GG, rezultat i izracunava sredinu intervala( DG + (GG-DG)/2)
	IntegralZadatak(double poc, double kr, double* rez); 

	/* Metoda execute() predstavlja samo izracunavanje integrala
	   Ukoliko je velicina intervala(GG-DG) > od zadate vrednosti(0.01) interval biva prepolovljen i prosledjen dvoma zadataka.
	   Sabiramo rezultate zadataka i smestamo u promenljivu rezultat.
	   Pravljenje zadataka i polovljenje se nastavlja dok velicina intervala ne bude < 0.01.
	   Onda se rezultat rekurzivno izracuna nad zadatim intervalom
	   povratnaVr: metoda execute() vraca ili pokazivac na sledeci zadatak ili NULL (u nasem slucaju je to NULL)
	*/
	task* execute();

};

/* Funkcija pravi i pokrece korenski zadatak pomocu allocate_root() i konstruktora klase IntegralZadatak
   kom prosledjuje citav interval i rezultat inicijalizovan na 0.0
   Parametri: dg - donja granica intervala
			  gg - gornja granica intervala
   Povratna vr: rezultat izracunavanja
*/
double ParalelnoRacunanje(double dg, double gg);
