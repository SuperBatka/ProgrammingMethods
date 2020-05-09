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
	for(unsigned int i = 0; i < container.size(); i++)
	{	
		if(container[i].type == OOP )
		{
			fout << "Объектно ориентированный язык программирования ";
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
		} else 
		{
			fout << "Процедурный язык программирования ";
			if(container[i].isAbstract == 0)
			{
				fout << " без абстрактных типов данных";
			} else 
			{
				fout << " c наличием абстрактных типов данных";
			} 
			
		}
		
		fout << " \"" <<container[i].name << "\""; 		
		fout << " был разработан в " << container[i].year << " году\n";
	}
}

void filteredOut(std::ofstream &fout, std::vector<progLanguage> &container, int type)
{
	if ( type == OOP)
	{
		for(unsigned int i = 0; i < container.size(); i++)
		{	
			if ( container[i].type == OOP)
			{
				fout << "Объектно ориентированный язык программирования ";
				if(container[i].inherence == SINGLE)
				{
					fout << " с одиночным наследованием ";
				} else if(container[i].inherence == MULTIPLE)
				{
					fout << " c множественным наследованием";

				} else if (container[i].inherence == INTERFACE)
				{
					fout << " c поддержкой интерфейсов"<< std::endl;
				}		
				
				fout << " \"" <<container[i].name << "\""; 
				fout << " был разработан в " << container[i].year << " году\n";	
			} else continue;
		}
		
	} else
	{
		for(unsigned int i = 0; i < container.size(); i++)
		{	
			if ( container[i].type == PROCEDURE)
			{
				fout << "Процедурный язык программирования ";
				if(container[i].isAbstract == 0)
				{
					fout << " без абстрактных типов данных";
				} else 
				{
					fout << " c наличием абстрактных типов данных" << std::endl;
				} 
				
				fout << " \"" <<container[i].name << "\""; 
				fout << " был разработан в " << container[i].year << " году\n";
				
			} else continue;
			
		}
	}
}

