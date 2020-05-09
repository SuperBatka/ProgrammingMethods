#include <iostream>
#include <vector>
#include <string>
#include <fstream>


enum {
	OOP = 0,
	PROCEDURE
};

	enum{
		SINGLE =0,
		MULTIPLE,
		INTERFACE
	};

struct progLanguage
{
	std::string name;
	int year;
	bool isAbstract;
	int type;
	int inherence;
};

void ReadFromFile(std::ifstream &fin, std::vector<progLanguage> &container);
void WriteToFile(std::ofstream &fout, std::vector<progLanguage> &container);
int languageAge(progLanguage &lang);