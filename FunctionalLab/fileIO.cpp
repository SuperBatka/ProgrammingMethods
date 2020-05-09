#include "fileIO.h"

void ReadFromFile(std::ifstream &fin, std::vector<progLanguage> &container)
{
	int a = 0;
	fin>>a;
	container.resize(a);
	for(int i = 0; i < a; i++)
	{
		fin >> container[i].type;
		fin >> container[i].name;
		fin >> container[i].inherence;
		fin >> container[i].year;
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
		fout << " На данный момент возраст этого языка равен " << languageAge(container[i]) << std::endl;
	}
}

int languageAge(progLanguage &lang)
{
	return 2020 - lang.year;
}

bool Compare(progLanguage &first, progLanguage &second) 
{
	return languageAge(first) < languageAge(second);
}

void Sort(std::vector<progLanguage> &container) 
{
	for(unsigned int i = 0; i < container.size() -1; i++) 
		{
			for(unsigned int j = i + 1; j < container.size(); j++) 
				{
					if(Compare(container[i], container[j])) 
						{
							progLanguage tmp = container[i];
							container[i] = container[j];
							container[j] = tmp;
						}
				}
		}
}