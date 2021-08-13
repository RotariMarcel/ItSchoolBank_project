
#include "bank.h"
#include<cstdlib>
#include<ctime>


std::string bank::createIban()
{

	std::string iban="123";
	/*
	* DE CAUTAT MOD DE STOCARE NUMAR GENERAT RANDOM
	
	std::vector<std::string> random;
	*/
	int randomN = 0;
	std::srand(time(0));
	for (int i = 0; i <10; i++) {
		
		 randomN = (rand() % 10);
			
	}
	std::cout << "Numar random: " << randomN;
	
	//random.push_back(randomN);
	/*
	for (auto it = random.begin(); it != random.end(); it++) {
		std::cout<<"NUmar " << *it;
	}
	std::cout << std::endl;
	std::cout << "Numarul este "<< randomN;
	
	*/
	
	
	return iban;
}

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
	std::cout << "IBAN alocat: \n";
	std::string IBAN = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, IBAN);
	m_ConturiBancare.push_back(cont);
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
	std::cout << "Numar conturi active: \n"<< m_ConturiBancare.size()<<std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		//std::cout << "Contul " << i+1 << " " << m_ConturiBancare[i]->getNume()<<std::endl;
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume() << m_ConturiBancare[i]->getSold() << std::endl;
		//std::cout << "Solduri " <<i+1<< m_ConturiBancare[i]->getSold() << std::endl;

	}
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
		std::cout << "2 -> Modificare nume\n";
		std::cout << "3 -> Modificare prenume\n";
		std::cout << "4 -> Depunere suma\n";
		std::cout << "5 -> Retragere suma\n";
		std::cout << "6 -> Adaugare IBAN \n";
		std::cout << "9 -> Meniu principal\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			
			m_ConturiBancare.erase(it);
			meniuPrincipal();
			break;
		case'9':
			meniuPrincipal();
			break;
		default:
			break;
		}
		
		
		/*1 modificati nume
		2 modificati prenume
		3 modificati suma
		4 modificati parola
		modificati etc..
		5 stergeti contul*/

	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	std::cin.get();
		// daca exista intrebam ce modificari facem
		// daca nu exista spunem ca nu exista si dam urmatoarele optiuni:
		//return to main
		//creati un cont
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

float bank::sold()
{
	int sold = 0;
	std::cout << "Sold = ";
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
		break;
	case '2':
		if (sold != 0) {
			std::cout << "introduceti suma pe care doriti sa o retrageti ";
			float retragere;
			std::cin >> retragere;
			if (retragere > sold) {
				sold -= retragere;
			}
			else {
				std::cout << "Introduceti alta suma \n";
				
			}
		
		}
		else {
			std::cout << "Nu aveti fonduri\n";
		}
	case '3':
		vizualizareConturi();
		break;
	default:
		break;
	}
	return 0;
}


