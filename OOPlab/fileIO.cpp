#include "fileIO.h"

void container::In(std::ifstream &ifst)
{
	while (!ifst.eof())
	{
		cont.push_back(progLanguage::In(ifst));
		len = cont.size();
	}
}

void container::Out(std::ofstream &ofst)
{
	ofst << "Container contents " << len << " elements. " << std::endl;
	for (int i = 0; i < len; i++)
	{
		ofst << i << ": ";
		cont[i]->Out(ofst);
	}
}

void container::OutWithAge(std::ofstream &ofst)
{
	ofst << "Container contents " << len << " elements. " << std::endl;
	for (int i = 0; i < len; i++)
	{
		ofst << i << ": ";
		cont[i]->Out(ofst);
		ofst << "Возраст данного языка равен " << cont[i]->languageAge() << std::endl;
	}
}

void container::Sort()
{
	for ( int i = 0; i < len; i++)
	{
		for( int j = i + 1; j < len; j++)
		{
			if(cont[i]->Compare(*cont[j]))
			{
				progLanguage *tmp = cont[i];
				cont[i] = cont[j];
				cont[j] = tmp;
			}
		}
	}
}

void container::OutProc(std::ofstream &ofst)
{
	ofst << "Only Procedure languages: " << std::endl;
	for (int i = 0; i < len; i++)
	{
		//ofst << i << ": ";
		cont[i]->OutProc(ofst);
	}
}

void container::OutOOP(std::ofstream &ofst)
{
	ofst << "Only OOP languages: " << std::endl;
	for (int i = 0; i < len; i++)
	{
		//ofst << i << ": ";
		cont[i]->OutOOP(ofst);

	}
}

void container::Clear()
{
	cont.clear();
	len = 0;
}

progLanguage* progLanguage::In(std::ifstream &ifst)
{
	progLanguage *sp;
	int k = 0;
	ifst >> k;
	switch (k)
	{

	case 0:
		sp = new oopLang;
		break;
	case 1:
		sp = new procLang;
		break;
	case 2:
		sp = new funcLang;
		break;
	default:
		return 0;
	}
	sp->InData(ifst);
	return sp;
}


bool progLanguage::Compare(progLanguage &compareTo)
{
	return languageAge() < compareTo.languageAge();
}

void progLanguage::InData(std::ifstream &ifst)
{
	ifst >> _linksCount;
}

void progLanguage::Out(std::ofstream &ofst)
{
	ofst << "Количество упоминаний о данном языке в сети Интернет: " << _linksCount << std::endl;
}

void progLanguage::OutProc(std::ofstream &ofst)
{
	if (false)
		ofst << std::endl;
}

void progLanguage::OutOOP(std::ofstream &ofst)
{
	if(false)
		ofst << std::endl;
}

void procLang::InData(std::ifstream &ifst)
{
	ifst >> isAbstract >> year;
	progLanguage::InData(ifst);
}

void procLang::Out(std::ofstream &ofst)
{
	ofst << "Процедурный язык программирования ";
	if(isAbstract == 0)
	{
		ofst << " без абстрактных типов данных";
	} else 
	{
		ofst << " c наличием абстрактных типов данных";
	}
	ofst << " был разработан в " << year << " году.";
	progLanguage::Out(ofst);
}


int procLang::languageAge()
{
	return 2020  - year;
}

void procLang::OutProc(std::ofstream &ofst)
{
	Out(ofst);
}


void oopLang::InData(std::ifstream &ifst)
{
	ifst >> inherence >> year;
	progLanguage::InData(ifst);
}

void oopLang::Out(std::ofstream &ofst)
{
	ofst << "Объектно ориентированный язык программирования ";
	if(inherence == SINGLE)
	{
		ofst << " с одиночным наследованием";
	} else if(inherence == MULTIPLE)
	{
		ofst << " c множественным наследованием";
	
	} else if (inherence == INTERFACE)
	{
		ofst << " c поддержкой интерфейсов";
	}
	
	ofst << " был разработан в " << year << " году.";
	progLanguage::Out(ofst);
}


int oopLang::languageAge()
{
	return 2020 - year;	
}


void funcLang::Out(std::ofstream &ofst)
{
	ofst <<  "Это функциональный язык программирования ";
	if(typization == STRICT_TYPE)
		ofst << "со строгой типизацией ";
	else 
		ofst << "с динамической типизацией ";
	if(lazyEval == 0)
		ofst << "без поддержки ленивый вычислений";
	else 
		ofst <<"с поддержкой ленивый вычислений"<< std::endl;
	ofst << ", который был создан в " << year << " году. "; 
	progLanguage::Out(ofst);
}

void funcLang::InData(std::ifstream &ifst)
{
	ifst >> lazyEval >> typization >> year;
	progLanguage::InData(ifst);
}

int funcLang::languageAge()
{
	return 2020 - year;
}

void oopLang::OutOOP(std::ofstream &ofst)
{
	Out(ofst);
}

container::container() : len(0) {}