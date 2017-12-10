#pragma once
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
	//obliczenie sumy zbior�w (operator+)
	Zbior operator+ (Zbior &z) {
		Zbior nowy;
		nowy.dlugoscTablicy = this->dlugoscTablicy;
		nowy.dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];

		for (int i = 0; i < this->dlugoscTablicy; i++) {
			nowy.dynamicznaTablicaLiczbCalkowitych[i] = this->dynamicznaTablicaLiczbCalkowitych[i] + z.dynamicznaTablicaLiczbCalkowitych[i];
		}

		return nowy;
	};


	//obliczenie r�nicy zbior�w (operator+)
	Zbior operator- (Zbior &z) {
		Zbior nowy;
		nowy.dlugoscTablicy = this->dlugoscTablicy;
		nowy.dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];

		for (int i = 0; i < this->dlugoscTablicy; i++) {
			nowy.dynamicznaTablicaLiczbCalkowitych[i] = this->dynamicznaTablicaLiczbCalkowitych[i] - z.dynamicznaTablicaLiczbCalkowitych[i];
		}

		return nowy;
	};

	//obliczenie iloczynu zbior�w
	Zbior operator* (Zbior &z) {
		Zbior nowy;
		nowy.dlugoscTablicy = this->dlugoscTablicy;
		nowy.dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];
		for (int i = 0; i < this->dlugoscTablicy; i++) {
			nowy.dynamicznaTablicaLiczbCalkowitych[i] = this->dynamicznaTablicaLiczbCalkowitych[i] * z.dynamicznaTablicaLiczbCalkowitych[i];
		}

		return nowy;
	};

	//por�wnanie zbior�w(operator==),
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

	//zwr�cenie liczby element�w w zbiorze (wykorzystaj operator rzutowania na typ int)
	operator int() const { return this->dlugoscTablicy; }

	//dodanie nowego elementu do zbioru (operator+)	Zbior operator+ (int z) {
		Zbior nowy;
		for (int i = 0; i < this->dlugoscTablicy; i++) {
			if (this->dynamicznaTablicaLiczbCalkowitych[i] == z) {
				nowy.dlugoscTablicy = this->dlugoscTablicy;
				nowy.dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];

				for (int a = 0; a < this->dlugoscTablicy; a++) {
					nowy.dynamicznaTablicaLiczbCalkowitych[a] = this->dynamicznaTablicaLiczbCalkowitych[a];
				}
				return nowy;
			}
		}


		nowy.dlugoscTablicy = this->dlugoscTablicy + 1;
		int *dyn = new int[this->dlugoscTablicy + 1];
		for (int i = 0; i < this->dlugoscTablicy; i++) {
			dyn[i] = this->dynamicznaTablicaLiczbCalkowitych[i];
		}
		dyn[this->dlugoscTablicy] = z;
		delete []this->dynamicznaTablicaLiczbCalkowitych;

		nowy.dynamicznaTablicaLiczbCalkowitych = dyn;
		return nowy;
	};

	//odejmowanie elementu ze zbioru (operator-)	Zbior operator- (int z) {
	};
};

