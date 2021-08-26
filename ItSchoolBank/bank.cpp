
#include "bank.h"
#include<cstdlib>
#include<ctime>



std::string bank::createIban()
{
	
	std::string iban = "RO_51_ITSCB";
	std::string ron;
	std::string euro;
	std::string dolar;
	TIP_CONT valutaCont{ etipCont() };
	switch (valutaCont)
	{
	case TIP_CONT::CONT_RON:
		
	ron = "_RON_";
	iban += ron; 
	break;
	case TIP_CONT::CONT_EURO:
		
	euro = "_EUR_";
	iban += euro; 
	break;
	case TIP_CONT::CONT_DOLAR:
	
	dolar = "_USD_";
	iban += dolar; 
	break;
	default:
		break;
	}
	int randomN = 0;
	std::srand(time(0));
	for (int i = 0; i <10; i++) {

		 randomN = (rand() % 10);
			iban += std::to_string(randomN);
	
	}
	
	

	return iban;
}

void bank::setSoldValue()
{
	float sold = 160;
	float value = sold;
}

TIP_CONT bank::etipCont()
{
	std::cout << "Selectati valuta contului\n";
	std::cout << "1 -> EURO\n";
	std::cout << "2 -> RON\n";
	std::cout << "3 -> USD\n";
	int moneda = 0;
	std::cin >> moneda;
	switch (moneda)
	{
		case '1':
			return TIP_CONT::CONT_EURO;
			break;
		case '2':
			return TIP_CONT::CONT_RON;
			break;
		case '3':
			return TIP_CONT::CONT_DOLAR;
			break;
		default:
		break;
	}

	
}

/*
void bank::setArhiva(std::string arhivaBanca, std::vector<std::pair<std::string, std::vector<std::string>>> dataset)
{
}
*/







bank::bank()
{
}

bank::~bank()
{
	m_ConturiBancare.clear();
}

void bank::adaugareCont()
{
	system("CLS");
	
	std::cout << "Introduceti numele utilizatorului: \n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele utilizatorului: \n";
	std::string prenume;
	std::cin >> prenume;
	std::string IBAN = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, IBAN);
	m_ConturiBancare.push_back(cont);
	
	//adaugare in arhiva csv
	//arhiva::scrieArhiva("ArhivaConturiBanca.csv", cont);
	
	
	
	/*
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::string indexB;
		indexB += std::to_string(i + 1);
		m_ConturiBancare[i]->getNume();
		m_ConturiBancare[i]->getPrenume();
		m_ConturiBancare[i]->getIBAN();

		std::vector<std::pair<std::string, std::string>> tabel = { { "Index banca", indexB } , { "Nume",m_ConturiBancare[i]->getNume() }, { "Prenume",m_ConturiBancare[i]->getPrenume() }, { "Iban",m_ConturiBancare[i]->getIBAN() } };
		arhiva::setArhiva("ArhivaConturiBanca.csv", tabel);
	}
	*/
	

	// sfarsit adaugare in arhiva csv
	
	std::cout << std::endl;
	std::cout << "1 -> pentru crearea a unui cont nou\n";
	std::cout << "2 - > pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case'1':
		
		adaugareCont();
		break;
	case '2':
		
		meniuPrincipal();
		break;
	default:
		
		break;
	}
	
}

void bank::vizualizareConturi()
{
	system("CLS");
	
	std::cout << "Numar conturi active: "<< m_ConturiBancare.size()<<std::endl;
	std::cout << std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume() <<
			" " << m_ConturiBancare[i]->getPrenume()<<" Sold: "<< m_ConturiBancare[i]->getSold() <<
			" IBAN "<<m_ConturiBancare[i]->getIBAN() << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << "1 -> pentru crearea a unui cont nou\n";
	std::cout << "2 - > pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case'1':
		
		adaugareCont();
		break;
	case'2':
		
		meniuPrincipal();
		break;
	default:
		
		break;
	}
}

void bank::modificareCont()
{
	system("CLS");
	// intrebati operatorul care cont doreste sa il modifice
	std::cout << "Introduceti numele si prenumele contului: \n";
	std::cout << "Introduceti numele de familie\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele\n";
	std::string prenume;
	std::cin >> prenume;
	ContBancar* temp = nullptr;
	// cautati contul
	
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
		{
			temp = m_ConturiBancare[i];
			
			break;
		}

	}

	std::vector<ContBancar*>::iterator it;
	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			break;
		}
	}

	if (temp == nullptr)
	{
		
		std::cout << "Contul nu a fost gasit!\n";
		std::cout << "1 -> Intoarcere la meniul principal\n";
		std::cout << "2 -> creati un cont nou\n";
		std::cout << "3 -> cautati un cont nou\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case'1':
			meniuPrincipal();
			break;
		case '2':
			adaugareCont();
			break;
		case '3':
			system("CLS");
			modificareCont();
			break;
		default:
			
			break;
		}
	}

	else
	{
		
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "1 -> Pentru stergere cont\n";
		std::cout << "2 -> Operatiuni\n";
		std::cout << "3 -> Modificare nume\n";
		std::cout << "4 -> Modificare prenume\n";
		//std::cout << "5 -> Retragere suma\n";
		std::cout << "5 -> Adaugare IBAN \n";
		std::cout << "9 -> Meniu principal\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			
			m_ConturiBancare.erase(it);
			meniuPrincipal();
			break;
		case '2':
			operatiuni();
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			system("CLS");
			createIban();
			break;
		case'9':
			meniuPrincipal();
			break;
		default:
			break;
		}
		

	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	std::cin.get();
		
}

void bank::meniuPrincipal()
{
	//bank* ItSchoolBank = new bank(); // instantam o banca
	bool isRunning = true;

	do
	{
		system("CLS");
		std::cout << "Welcome to ItSchool Bank\n";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Meniu principal\n";
		std::cout << std::endl;

		std::cout << "1 -> Adaugare Cont\n";
		std::cout << "2 -> Vizualizare Conturi\n";
		std::cout << "3 -> Modificare Conturi\n";
		std::cout << "9 -> Exit\n";
		std::cout << std::endl;
		std::cout << "Introduceti optiunea: ";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			system("CLS");
			 adaugareCont();
			break;
		case'2':
			system("CLS");
			vizualizareConturi();
			break;
		case '3':
			system("CLS");
			modificareCont();
			break;
		case'9':
			std::cout << "Va multumim!\n";
			isRunning = false;
			
			system("CLS");
			break;
		default:
			std::cout << "Optiunea nu este valida.\n";
			break;
		}

	} while (isRunning);



	//delete ItSchoolBank;
}

float bank::operatiuni()
{
	system("CLS");
	/*
	float sIban = 0;
	for (int i = 0; i < m_ConturiBancare.size(); i++) {

		float sIban = m_ConturiBancare[i]->getSold();

	}
	float sold =  sIban;
	*/
	
	float sold = 0;
	std::cout << "Sold = "<< sold<<std::endl;
	std::cout << "1 -> Pentru depozit\n";
	std::cout << "2 -> Pentru retragere\n";
	std::cout << "3 -> Vizualizare conturi\n";
	std::cout << "4 -> Meniu principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{case '1':
		std::cout << "Introduceti suma pe care doriti sa o depuneti ";
		float depunere;
		std::cin >> depunere;
		sold += depunere;
		std::cout << "Sold nou " << sold << std::endl;
		system("CLS");
		vizualizareConturi();
		break;
	case '2':
		if (sold != 0) {
			std::cout << "introduceti suma pe care doriti sa o retrageti ";
			float retragere;
			std::cin >> retragere;
			if (retragere > sold) {
				sold -= retragere;
				std::cout << "Sold nou " << sold << std::endl;
				system("CLS");
				vizualizareConturi();
				break;
			}
			else {
				std::cout << "Nu aveti suficiente fonduri pentru aceasta operatiune\n";
				std::cout<< "Introduceti alta suma \n";
				vizualizareConturi();
				break;
			}
		
		}
		else {
			std::cout << "Nu aveti fonduri\n";
			vizualizareConturi();
			break;
		}
	case '3':
		vizualizareConturi();
		break;
	case '4':
		meniuPrincipal();
		break;
	default:
		break;
	}
	return 0;
}

/*
void bank::soldCont()
{

	float sold = 130;

	for (int i = 0; i < m_ConturiBancare.size(); i++) {

		sold = m_ConturiBancare[i]->getSold();

	}
	float soldActual = sold;
}
*/





