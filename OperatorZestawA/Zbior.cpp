#include "stdafx.h"
#include "Zbior.h"

Zbior::Zbior()
{
	this->dlugoscTablicy = 0;
	this->dynamicznaTablicaLiczbCalkowitych = NULL;
}


Zbior::Zbior(int pierwszyElement)
{
	this->dlugoscTablicy = 1;
	this->dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];
	this->dynamicznaTablicaLiczbCalkowitych[0] = pierwszyElement;
}

Zbior::Zbior(Zbior &zbior)
{
	this->dlugoscTablicy = zbior.dlugoscTablicy;
	this->dynamicznaTablicaLiczbCalkowitych = new int[this->dlugoscTablicy];

	for (int i = 0; i < this->dlugoscTablicy; i++)
	{
		this->dynamicznaTablicaLiczbCalkowitych[i] = zbior.dynamicznaTablicaLiczbCalkowitych[i];
	}

}

Zbior::~Zbior()
{
	delete []dynamicznaTablicaLiczbCalkowitych;
}
