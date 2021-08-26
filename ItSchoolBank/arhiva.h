#pragma once
#include<iostream>
#include<fstream>
#include "bank.h"
#include "cont.h"
#include<utility>
#include<string>
#include<cstdlib>
class arhiva
{
	std::vector<ContBancar*> m_ConturiBancare;
	

public:
	arhiva();
	~arhiva();
	void setArhiva(std::string arhivaBanca, std::vector<std::pair<std::string, std::string>> dataset);
	//bool setArhiva(std::string arhivaBanca, std::string tabel1, std::string tabel2, std::string tabel3, std::string tabel4);

	void scrieArhiva(std::vector<ContBancar*> m_ConturiBancare);
	
};

