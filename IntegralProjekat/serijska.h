#pragma once

#include <iostream>
#include <math.h>
#include "Konstante.h"

extern double INTERVAL;

/* izracunavam integral rekurzivno na osnovu formule
   parametri: pocetniInterval = DG - donja granica integrala, krajnjiInterval = GG - gornja granica integrala
   povratnaVr: rezultat izracunavanja integrala
*/
double rekurzivnoRacunanje(double pocetniInterval, double krajnjiInterval);


/* izracunavam integral na osnovu formule na zadatom intervalu i vracam rezultat integrala
   parametri: pocetniInterval = DG - donja granica integrala, krajnjiInterval = GG - gornja granica integrala
   povratnaVr: rezultat izracunavanja integrala
*/
double serijskoRacunanjeIntegrala(double& pocetniInterval, double &krajnjiInterval);


/* Ukoliko je velicina intervala veca od zadate vrednosti pravim dva zadatka koja racunaju integral na prepolovljenom intervalu
   parametri: pocetni1, krajnji1 - donja i gornja granica intervala za prvi zadatak
		   pocetni2, krajnji2 - donja i gornja granica intervala za drugi zadatak
   povratnaVr: rezultat izracunavanja prvog zadatka + rezultat izracunavanja drugog zadatka */
double serijskaDvaZad(double pocetni1, double krajnji1, double pocetni2, double krajnji2);


/* Funkcija na osnovu velicine intervala odlucuje da li ce praviti dva zadatka
   za izracunavanje integrala ili ce izracunati integral nad celim intervalom
   parametri: pocetniInterval - donja granica intervala nad kojom se racuna integral
              krajnjiInterval - gornja granica intervala nad kojom se racuna integral
   povratnaVr: rezultat izracunavanja integrala
 */
double serijskaProvera(double pocetniInterval, double krajnjiInterval);
