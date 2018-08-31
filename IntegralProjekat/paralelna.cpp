#include "serijska.h"
#include "paralelna.h"

using namespace tbb;


IntegralZadatak::IntegralZadatak(double poc, double kr, double* rez) : pocetak(poc), kraj(kr),
rezultat(rez), sredina(pocetak + (kraj-pocetak)/2) { }

task* IntegralZadatak::execute() {

	// ako je velicina intervala dovoljno mala vrsimo rekurzivno racunanje integrala
	if (kraj-pocetak < ZADATA_VR_INTERVALA)
	{
		*rezultat = rekurzivnoRacunanje(pocetak, kraj);
	}
	else {
		double rez1, rez2;
		//pravimo dva zadatka
		IntegralZadatak& a = *new(allocate_child()) IntegralZadatak(pocetak, sredina, &rez1);
		IntegralZadatak& b = *new(allocate_child()) IntegralZadatak(sredina, kraj, &rez2);

		set_ref_count(3); //postavljam referentni brojac na 2 + 1 zbog cekanja
		spawn(b); //pokrecem b
		spawn_and_wait_for_all(a); //pokrecem a i cekam da se zavrse i a i b

		*rezultat = rez1 + rez2; //racunam rezultat
	}
		return NULL; //nemamo pokazivac na sledeci zadatak pa vracamo NULL
	}



double ParalelnoRacunanje(double dg, double gg)
{
	double rez = 0.0;
	IntegralZadatak& a = *new(task::allocate_root()) IntegralZadatak(DG, GG, &rez); //zauzimanje prostora za zadatak
	task::spawn_root_and_wait(a); //pravljenje i pokretanje zadatka
	
	return rez;
}

