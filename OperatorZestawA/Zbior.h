#pragma once
#include <iostream>
using namespace std;
class Zbior
{
private:
	int *dynamicznaTablicaLiczbCalkowitych;
	int dlugoscTablicy;

public:
	Zbior();
	Zbior(int pierwszyElement);
	Zbior(Zbior &zbior);
	~Zbior();

	//Operatory
	//obliczenie sumy zbiorów (operator+)
	Zbior operator+ (Zbior &z) {
		Zbior nowy = Zbior(*(this));

		for (int i = 0; i < z.dlugoscTablicy; i++) {
			nowy = nowy + z.dynamicznaTablicaLiczbCalkowitych[i];
		}

		return nowy;
	};


	//obliczenie ró¿nicy zbiorów (operator+)
	Zbior operator- (Zbior &z) {
		Zbior nowy = Zbior(*(this));

		for (int i = 0; i < z.dlugoscTablicy; i++) {
			nowy = nowy - z.dynamicznaTablicaLiczbCalkowitych[i];
		}

		return nowy;
	};

	//obliczenie iloczynu zbiorów
	Zbior operator* (Zbior &z) {
		Zbior nowy;
		
		int dlugosc = 0;

		for (int i = 0; i < this->dlugoscTablicy; i++) {
			for (int a = 0; a < z.dlugoscTablicy; a++) {
				if (this->dynamicznaTablicaLiczbCalkowitych[i] == z.dynamicznaTablicaLiczbCalkowitych[a]) {
					nowy = nowy + this->dynamicznaTablicaLiczbCalkowitych[i];
				}
			}
		}

		return nowy;
	};

	//porównanie zbiorów(operator==),
	bool operator ==(const Zbior & z)
	{
		for (int i = 0; i < this->dlugoscTablicy; i++) {
			if (this->dynamicznaTablicaLiczbCalkowitych[i] != z.dynamicznaTablicaLiczbCalkowitych[i])
			{
				return false;
			}
		}
		return true;
	}

	//zwrócenie liczby elementów w zbiorze (wykorzystaj operator rzutowania na typ int)
	operator int() const { return this->dlugoscTablicy; }

	//dodanie nowego elementu do zbioru (operator+)	Zbior operator+ (int z) {
		Zbior nowy = Zbior(*this);
		for (int i = 0; i < nowy.dlugoscTablicy; i++) {
			if (nowy.dynamicznaTablicaLiczbCalkowitych[i] == z) {
				return nowy;
			}
		}

		nowy.dlugoscTablicy++;
		int *dyn = new int[nowy.dlugoscTablicy];
		for (int i = 0; i < nowy.dlugoscTablicy; i++) {
			dyn[i] = nowy.dynamicznaTablicaLiczbCalkowitych[i];
		}
		dyn[nowy.dlugoscTablicy-1] = z;
		delete []nowy.dynamicznaTablicaLiczbCalkowitych;

		nowy.dynamicznaTablicaLiczbCalkowitych = dyn;
		return nowy;
	};

	//odejmowanie elementu ze zbioru (operator-)	Zbior operator- (int z) {
		Zbior nowy = Zbior(*this);
		for (int i = 0; i < nowy.dlugoscTablicy; i++) {
			if (nowy.dynamicznaTablicaLiczbCalkowitych[i] == z) {
				nowy.dlugoscTablicy--;
				int *dyn = new int[nowy.dlugoscTablicy];
				for (int a = 0; a < nowy.dlugoscTablicy; a++) {
					if (nowy.dynamicznaTablicaLiczbCalkowitych[a] != z) {
						dyn[a] = nowy.dynamicznaTablicaLiczbCalkowitych[a];
					}
				}
				delete[]nowy.dynamicznaTablicaLiczbCalkowitych;
				nowy.dynamicznaTablicaLiczbCalkowitych = dyn;
				break;
			}
		}
		return nowy;
	};

	//wypisanie elementów zbioru(operator«)	friend ostream & operator<< (ostream &wyjscie, const Zbior &z) {
		
		for (int = 0; i < z.dlugoscTablicy; i++) {
			wyjscie << z.dynamicznaTablicaLiczbCalkowitych[z] << endl;
		}
		return wyjscie;
	}
};

