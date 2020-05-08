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
	case 1:
		sp = new procLang;
		break;
	case 2:
		sp = new oopLang;
		break;
	case 3:
		sp = new funcLang;
		break;
	default:
		return 0;
	}
	sp->InData(ifst);
	return sp;
}


void procLang::InData(std::ifstream &ifst)
{
	ifst >> isAbstract >> year;
}
void procLang::Out(std::ofstream &ofst)
{
	ofst << "Это процедурный язык программирования, который был создан в " << year << " году и наличие абстрактных классов - " << isAbstract << std::endl;
}

void oopLang::InData(std::ifstream &ifst)
{
	ifst >> inherence >> year;
}

void oopLang::Out(std::ofstream &ofst)
{
	ofst << "Это объектно-ориентированный язык программирования, который был создан в " << year << " году c наследованием  - " << inherence << std::endl;
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
		ofst <<"с поддержкой ленивый вычислений"<< std::endl;;
}

void funcLang::InData(std::ifstream &ifst)
{
	ifst >> typization >> lazyEval;
}

container::container() : len(0) {}