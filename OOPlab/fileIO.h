#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class  progLanguage
{
	int _linksCount;
public:
	static progLanguage* In(std::ifstream &ifst);
	virtual void InData(std::ifstream &ifst);
	virtual void Out(std::ofstream &ofst);
	virtual int languageAge() = 0;
	bool Compare(progLanguage &compareTo);
protected:
	progLanguage() {}
};

class procLang : public progLanguage
{
	bool isAbstract;
	int year;
public:
	void InData(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	int languageAge();
	procLang() {}
};

class oopLang : public progLanguage
{
	int year;
	int inherence;
public:
	void InData(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	int languageAge();
	oopLang() {}
};


class container
{
	std::vector<progLanguage*> cont;
	int len;

public:
	void In(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	void OutWithAge(std::ofstream &ofst);
	void Clear();
	void Sort();
	container();
	~container() { Clear(); }
};