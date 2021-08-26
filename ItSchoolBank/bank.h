#pragma once
#include"cont.h"
#include"arhiva.h"
#include <vector>
#include <iostream>
#include<cstdlib>
#include<ctime>





class bank
{

	std::vector<ContBancar*> m_ConturiBancare;
	std::string createIban();
	void setSoldValue();
	TIP_CONT etipCont();
	//set arhiva csv
	//void setArhiva(std::string arhivaBanca, std::vector<std::pair<std::string, std::vector<std::string>>> dataset);
	// sfarsit set arhiva
public:

	bank(); // constructor
	
	~bank(); // destructor
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
	void meniuPrincipal();
	float operatiuni();
	
	
};

