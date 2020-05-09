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
	procLang() {}
};

class oopLang : public progLanguage
{
	int year;
	int inherence;
public:
	void InData(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	oopLang() {}
};


class container
{
	std::vector<progLanguage*> cont;
	int len;

public:
	void In(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	void Clear();
	container();
	~container() { Clear(); }
};