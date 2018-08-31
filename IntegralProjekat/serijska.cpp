#include "serijska.h"
using namespace std;


double rekurzivnoRacunanje(double pocetniInterval, double krajnjiInterval) {

	//bazni slucaj je ako velicina intervala < 0.01
	if (krajnjiInterval-pocetniInterval < ZADATA_VR_INTERVALA) {
		double rez = 0.0;
		//nad manjim intervalom primenim formulu za racunanje integrala
		for (double i = pocetniInterval; i < krajnjiInterval; i += INTERVAL) {
			rez += exp(-0.5 * i) * cos(i)*INTERVAL;
		}
		return rez;
	}
	// u suprotnom polovim interval
	else {
		double sredina = pocetniInterval + (krajnjiInterval - pocetniInterval) / 2;
		return rekurzivnoRacunanje(pocetniInterval, sredina) + rekurzivnoRacunanje(sredina, krajnjiInterval);
	}
}


double serijskoRacunanjeIntegrala(double& pocetniInterval, double &krajnjiInterval) {

	double rez = 0.0;
	for (double i = pocetniInterval; i < krajnjiInterval; i += INTERVAL) {
		rez += exp(-0.5 * i) * cos(i)*INTERVAL;
	}
	return rez;
}

