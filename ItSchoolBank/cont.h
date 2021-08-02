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
	inline std::string getNume() {	return nume;} 
	inline std::string getPrenume() { return prenume; }
	inline int getSold() { return sold; }
	inline std::string getIBAN() { return IBAN; }
	inline void setSoldValue(int value) { sold = value; }

	~ContBancar();

};

