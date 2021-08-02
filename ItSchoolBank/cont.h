#pragma once
#include<string>

enum class TIP_CONT
{
	CONT_RON, 
	CONT_EURO, 
	CONT_DOLAR
};

class ContBancar
{
private:
	std::string nume;
	std::string prenume;
	TIP_CONT etipCont;
	std::string IBAN;
	int sold;

public:

	ContBancar(std::string nume, std::string prenume, std::string IBAN);
	~ContBancar();

};

