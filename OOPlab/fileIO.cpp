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

void progLanguage::MultiMethod(std::ofstream &ofst, progLanguage* other)
{
	ofst << "Неизвестный язык программирования" << std::endl;
}

void progLanguage::MMoop( std::ofstream &ofst)
{
	ofst << "Неизвестный язык программирования" << std::endl;
}

void progLanguage::MMprocedure( std::ofstream &ofst )
{
	ofst << "Неизвестный язык программирования" << std::endl;
}


void procLang::InData(std::ifstream &ifst)
{
	ifst >> isAbstract >> year;
}
void procLang::Out(std::ofstream &ofst)
{
	ofst << "It is procedure language: year is " << year << " and abstract is " << isAbstract << std::endl;

}

void oopLang::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
	other->MMoop( ofst );
}

void oopLang::MMoop( std::ofstream &ofst )
{
	ofst << "ООП язык и ООП язык" << std::endl;
}

void oopLang::MMprocedure( std::ofstream &ofst )
{
	ofst << "Процедурный языки и ООП язык" << std::endl;
}

void oopLang::InData(std::ifstream &ifst)
{
	ifst >> inherence >> year;
}

void oopLang::Out(std::ofstream &ofst)
{
	ofst << "It is a oop language, which was created in " << year << " with inherence " << inherence << std::endl;
}

void procLang::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
	other->MMprocedure( ofst );
}

void procLang::MMoop( std::ofstream &ofst )
{
	ofst << "ООП язык и Процедурный язык" << std::endl;
}

void procLang::MMprocedure( std::ofstream &ofst )
{
	ofst << "Процедурный язык и Процедурный язык" << std::endl;
}


void container::MultiMethod( std::ofstream &ofst )
{
	ofst << "Multimethod result" << std::endl;


	for ( int i = 0; i < cont.size() - 1; i++ )
	{
		for ( int j = i + 1; j < cont.size(); j++ )
		{
			cont[ i ]->MultiMethod(ofst , cont[ j ]);
		}
	}
}

container::container() : len(0) {}