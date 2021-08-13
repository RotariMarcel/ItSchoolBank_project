#include "cont.h"


ContBancar::ContBancar(std::string nume, std::string prenume, std::string IBAN)
{
	this->nume = nume;
	this->prenume = prenume;
	this->IBAN = IBAN;
	sold = 0;
	etipCont = TIP_CONT::CONT_RON;
}

ContBancar::~ContBancar()
{
	// ContBancar.clear();
}


