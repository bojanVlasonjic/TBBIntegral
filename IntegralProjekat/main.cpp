#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "serijska.h"
#include "paralelna.h"

using namespace std;
using namespace tbb;

double INTERVAL; //delta X

int main() {

	double rezSerijski, rezParalelno;
	double vremeSerijski, vremeParalelno;
	double dg = DG, gg = GG; //kako bih prosledio po referenci

	//otvaram datoteke
	ifstream test("Testovi.txt");
	ofstream rez("Rezultati.txt");
	rez << "SERIJSKO             |     PARALELNO    | INTERVAL" << endl;

	int brojac = 0; //broji testove radi urednijeg ispisa

	/* Za svaku vrednost intervala iz datoteke Testovi.txt ispisujem rezultate i vreme izvrsavanja
	   za serijsku i paralelnu verziju programa i upisujem ih u tekstualnu datoteku Rezultati.txt
	*/
	while (test >> INTERVAL) {

		brojac++;
		cout << "Test " << brojac << "  -->  Vrednost intervala: " << INTERVAL << endl;

		//racunam serijski i merim vreme
		tick_count pocetak = tick_count::now();
		rezSerijski = serijskoRacunanjeIntegrala(dg, gg);
		tick_count kraj = tick_count::now();
		vremeSerijski = (kraj - pocetak).seconds() * 1000;

		//ispisujem rezultate serijskog izracunavanja
		cout << "\nRezultat serijskog: " << rezSerijski << endl;
		cout << "Izracunavanje za serijsko je trajalo: " << vremeSerijski << " ms" << endl;


		//racunam Paralelno i merim vreme
		pocetak = tick_count::now();
		task_scheduler_init init; //inicijalizujem rasporedjivac zadataka
		rezParalelno = ParalelnoRacunanje(dg, gg);
		kraj = tick_count::now();
		vremeParalelno = (kraj - pocetak).seconds() * 1000;

		//ispisujem rezultate paralelnog izracunavanja
		cout << "Rezultat paralelnog: " << rezParalelno << endl;
		cout << "Izracunavanje za paralelno je je trajalo: "
			<< vremeParalelno << " ms" << endl;

		//Proveravam da li ima ubrzanja i racunam faktor radi lepseg ispisa
		if (vremeSerijski < vremeParalelno)
			cout << "\nNEMA UBRZANJA" << endl;
		else
			cout << "\nPOSTIGNUTO UBRZANJE " << vremeSerijski/vremeParalelno << " PUTA" << endl;

		cout << "\n\n" << endl;

		//upisujem rezultate u datoteku Rezultati.txt
		rez << rezSerijski << ", " << vremeSerijski << "ms|" 
			<< rezParalelno << ", " << vremeParalelno << "ms| " << INTERVAL <<  endl;

	}

	cin.get();
}