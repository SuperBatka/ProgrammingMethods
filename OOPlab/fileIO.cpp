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
	default:
		return 0;
	}
	sp->InData(ifst);
	return sp;
}

void progLanguage::InData(std::ifstream &ifst)
{
	ifst >> _linksCount;
}

void progLanguage::Out(std::ofstream &ofst)
{
	ofst << "Количество упоминаний о данном языке в сети Интернет: " << _linksCount << std::endl;
}

void procLang::InData(std::ifstream &ifst)
{
	ifst >> isAbstract >> year;
	progLanguage::InData(ifst);
}

void procLang::Out(std::ofstream &ofst)
{
	ofst << "It is procedure language: year is " << year << " and abstract is " << isAbstract << std::endl;
	progLanguage::Out(ofst);
}

void oopLang::InData(std::ifstream &ifst)
{
	ifst >> inherence >> year;
	progLanguage::InData(ifst);
}

void oopLang::Out(std::ofstream &ofst)
{
	ofst << "It is a oop language, which was created in " << year << " with inherence " << inherence << std::endl;
	progLanguage::Out(ofst);
}

container::container() : len(0) {}