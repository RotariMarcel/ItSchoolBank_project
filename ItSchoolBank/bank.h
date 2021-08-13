#pragma once
#include"cont.h"

#include <vector>
#include <iostream>
#include<cstdlib>
#include<ctime>






class bank
{

	std::vector<ContBancar*> m_ConturiBancare;
	std::string createIban();
	

public:

	bank(); // constructor
	
	~bank(); // destructor
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
	void meniuPrincipal();
	float sold();
	
};

