#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class  progLanguage
{
public:
	static progLanguage* In(std::ifstream &ifst);
	virtual void InData(std::ifstream &ifst) = 0;
	virtual void Out(std::ofstream &ofst) = 0;
	virtual void OutProc(std::ofstream &ofst);
	virtual void OutOOP(std::ofstream &ofst);
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
	void OutProc(std::ofstream &ofst);
	procLang() {}
};

class oopLang : public progLanguage
{
	int year;
	int inherence;
public:
	void InData(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	void OutOOP(std::ofstream &ofst);
	oopLang() {}
};


class container
{
	std::vector<progLanguage*> cont;
	int len;

public:
	void In(std::ifstream &ifst);
	void Out(std::ofstream &ofst);
	void OutProc(std::ofstream &ofst);
	void OutOOP(std::ofstream &ofst);
	void Clear();
	container();
	~container() { Clear(); }
};