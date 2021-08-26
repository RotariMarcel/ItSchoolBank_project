#include "arhiva.h"

arhiva::arhiva()
{

}


void arhiva::setArhiva(std::string arhivaBanca, std::vector<std::pair<std::string, std::string>> dataset)
{
	std::ofstream arhivaB(arhivaBanca);

	for (int j = 0; j<dataset.size(); j++)
	{
		arhivaB << dataset.at(j).first;
		if (j != dataset.size() - 1) arhivaB << ",";
	}
	arhivaB << "\n";

	for (int i = 0; i < dataset.at(0).second.size(); i++) {
		for (int j = 0; j < dataset.size(); j++) {
			arhivaB << dataset.at(j).second.at(i);
			if (j != dataset.size() - 1)arhivaB << ",";
		}
		arhivaB << "\n";
	}

	arhivaB.close();
}








/*
void arhiva::scrieArhiva()
{


	std::string indexB;
	std::string numeB;
	std::string prenumeB;
	std::string ibanB;


	
	ContBancar* cont = new ContBancar(numeB, prenumeB, ibanB);

	

std::vector<std::pair<std::string, std::string>> tabel = { { "Index banca", indexB }, {"Nume",numeB}, {"Prenume",prenumeB }, { "Iban",ibanB } };
setArhiva("ArhivaConturiBanca.csv", tabel);
	}
*/


void arhiva::scrieArhiva(std::vector<ContBancar*> m_ConturiBancare)
{
	std::string indexB;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		indexB += std::to_string(i + 1);
		m_ConturiBancare[i]->getNume();
		m_ConturiBancare[i]->getPrenume(); 
		m_ConturiBancare[i]->getIBAN();

		std::vector<std::pair<std::string, std::string>> tabel = { { "Index banca", indexB } , { "Nume",m_ConturiBancare[i]->getNume() }, { "Prenume",m_ConturiBancare[i]->getPrenume() }, { "Iban",m_ConturiBancare[i]->getIBAN() } };
		setArhiva("ArhivaConturiBanca.csv", tabel);
	}
}






arhiva::~arhiva()
{
	//arhiva.clear();
}
