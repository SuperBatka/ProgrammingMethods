#include "fileIO.h"

void ReadFromFile(std::ifstream &fin, std::vector<progLanguage> &container)
{
	int a = 0;
	fin>>a;
	container.resize(a);
	for(int i = 0; i < a; i++)
	{
		fin >> container[i].type;
		if ( container[i].type == OOP)
		{
			fin >> container[i].name;
			fin >> container[i].inherence;
			fin >> container[i].year;	
			fin >> container[i].linksCount;
		} else 
		{
			fin >> container[i].name;
			fin >> container[i].isAbstract;
			fin >> container[i].year;
			fin >> container[i].linksCount;	
		}
	}
}

void WriteToFile(std::ofstream &fout, std::vector<progLanguage> &container)
{
	int a = static_cast<int>(container.size());

	for(int i = 0; i < a; i++)
	{	
		if(container[i].type == OOP )
		{
			fout << "Объектно ориентированный язык программирования ";
		} else 
		{
			fout << "Процедурный язык программирования ";
		}

		fout << container[i].name; 
		if(container[i].inherence == SINGLE)
		{
			fout << " с одиночным наследованием";
		} else if(container[i].inherence == MULTIPLE)
		{
			fout << " c множественным наследованием";

		} else if (container[i].inherence == INTERFACE)
		{
			fout << " c поддержкой интерфейсов";
		}

		fout << " был разработан в " << container[i].year << " году.";
		fout << " Количество упоминаний о данном языке в сети Интернет: " << container[i].linksCount <<std::endl;
	}
}