#include "..\OOPlab\fileIO.h"
#include "..\OOPlab\fileIO.cpp"
#include "..\..\test\UnitTest++\unittest-cpp-master\UnitTest++\UnitTest++.h"

int main()
{
	return UnitTest::RunAllTests();
}


SUITE(procLang)
{
	TEST(indata)
	{
		std::ifstream fin("UnitTest_proc_InData.dat");
		procLang temp;
		int typeClass;
		fin>>typeClass;
		if(typeClass == PROCEDURE)
			temp.InData(fin);

		fin.close();
		CHECK(temp.getYear() == 1935);
		CHECK(temp.getAbstract() == 1);
		CHECK(temp.getLinksCount() ==60);
		
	}
	
	TEST(OutData)
	{
		std::ofstream fout("UnitTest_proc_OutData.dat");
		procLang temp;
		temp.setYear(1993);
		temp.setLinksCount(325);
		temp.setAbstract(1);
		temp.Out(fout);
		fout.close();
		std::ifstream fin("UnitTest_proc_OutData.dat");
		std::string s1;
		getline(fin,s1);
		
		std::string s2 = "Процедурный язык программирования  c наличием абстрактных типов данных был разработан в 1993 году.Количество упоминаний о данном языке в сети Интернет: 325";
		CHECK(s1 == s2);
	}
	
	
}

SUITE(oopLang)
{
	TEST(indata)
	{
		std::ifstream fin("UnitTest_oop_InData.dat");
		oopLang temp;
		int typeClass;
		fin>>typeClass;
		if(typeClass == OOP)
			temp.InData(fin);

		fin.close();
		CHECK(temp.getYear() == 1984);
		CHECK(temp.getInherence() == INTERFACE);
		CHECK(temp.getLinksCount() ==156);
		
	}
	
	TEST(OutData)
	{
		std::ofstream fout("UnitTest_oop_OutData.dat");
		oopLang temp;
		temp.setYear(1984);
		temp.setLinksCount(156);
		temp.setInherence(INTERFACE);
		temp.Out(fout);
		fout.close();
		std::ifstream fin("UnitTest_oop_OutData.dat");
		std::string s1;
		getline(fin,s1);
		
		std::string s2 = "Объектно ориентированный язык программирования  c поддержкой интерфейсов был разработан в 1984 году.Количество упоминаний о данном языке в сети Интернет: 156";
		CHECK(s1 == s2);
	}
}

SUITE(funcLang)
{
	TEST(indata)
	{
		std::ifstream fin("UnitTest_func_InData.dat");
		funcLang temp;
		int typeClass;
		fin>>typeClass;
		if(typeClass == FUNCTIONAL)
			temp.InData(fin);

		fin.close();
		CHECK(temp.getYear() == 2001);
		CHECK(temp.getLazyEval() == 0);
		CHECK(temp.getTypization() == DYNAMIC_TYPE);
		CHECK(temp.getLinksCount() ==412);
		
	}
	
	TEST(OutData)
	{
		std::ofstream fout("UnitTest_func_OutData.dat");
		funcLang temp;
		temp.setYear(2001);
		temp.setLinksCount(412);
		temp.setLazyEval(0);
		temp.setTypization(DYNAMIC_TYPE);
		temp.Out(fout);
		fout.close();
		std::ifstream fin("UnitTest_func_OutData.dat");
		std::string s1;
		getline(fin,s1);
		
		std::string s2 = "Это функциональный язык программирования с динамической типизацией без поддержки ленивый вычислений, который был создан в 2001 году. Количество упоминаний о данном языке в сети Интернет: 412";
		CHECK(s1 == s2);
	}
}

SUITE(container)
{
	TEST(out)
	{
		std::ofstream fout("UnitTest_container_Out.dat");
		container c;
		procLang *temp1 = new procLang;
		temp1->setYear(1993);
		temp1->setLinksCount(325);
		temp1->setAbstract(1);
		
		oopLang *temp2 = new oopLang;
		temp2->setYear(1984);
		temp2->setLinksCount(156);
		temp2->setInherence(INTERFACE);
		
		funcLang *temp3 = new funcLang;
		temp3->setYear(2001);
		temp3->setLinksCount(412);
		temp3->setLazyEval(0);
		temp3->setTypization(DYNAMIC_TYPE);
		
		std::vector <progLanguage*> cont;
		cont.resize(3);
		c.pushBackContainer(temp1);
		c.pushBackContainer(temp2);
		c.pushBackContainer(temp3);
		c.setLength(3);
		c.Out(fout);
		fout.close();
		std::ifstream fin("UnitTest_container_Out.dat");
		
		std::string s1;
		std::string s2 = "Container contents 3 elements. ";
		getline(fin,s1);
		CHECK(s1 == s2);
		
		s2 = "0: Процедурный язык программирования  c наличием абстрактных типов данных был разработан в 1993 году.Количество упоминаний о данном языке в сети Интернет: 325";
		getline(fin,s1);
		CHECK(s1 == s2);
		
		s2 = "1: Объектно ориентированный язык программирования  c поддержкой интерфейсов был разработан в 1984 году.Количество упоминаний о данном языке в сети Интернет: 156";
		getline(fin,s1);
		CHECK(s1 == s2);
		
		s2 = "2: Это функциональный язык программирования с динамической типизацией без поддержки ленивый вычислений, который был создан в 2001 году. Количество упоминаний о данном языке в сети Интернет: 412";
		getline(fin,s1);
		CHECK(s1 == s2);
		
	}
	
	TEST(in)
	{
		std::ifstream fin("UnitTest_container_In.dat");
		container c;
		c.In(fin);
		progLanguage *temp1 ;
		progLanguage *temp2 ;
		progLanguage *temp3 ;
		temp1 = c.getContainerItemAt(0);
		if ( typeid( *temp1 ) == typeid( oopLang ) )
		{
			CHECK(static_cast<oopLang*>(temp1)->getYear() == 1984);
			CHECK(static_cast<oopLang*>(temp1)->getInherence() == INTERFACE);
			CHECK(static_cast<oopLang*>(temp1)->getLinksCount() == 156);			
		} else CHECK(false);
		
		temp2 = c.getContainerItemAt(1);
		if ( typeid( *temp2 ) == typeid( procLang ) )
		{
			CHECK(static_cast<procLang*>(temp2)->getYear() == 1993);
			CHECK(static_cast<procLang*>(temp2)->getAbstract() == 1);
			CHECK(static_cast<procLang*>(temp2)->getLinksCount() == 325);			
		} else CHECK(false);
		
		temp3 = c.getContainerItemAt(2);
		if ( typeid( *temp3 ) == typeid( funcLang ) )
		{
			CHECK(static_cast<funcLang*>(temp3)->getYear() == 2001);
			CHECK(static_cast<funcLang*>(temp3)->getLazyEval() == 0);
			CHECK(static_cast<funcLang*>(temp3)->getTypization() == DYNAMIC_TYPE);
			CHECK(static_cast<funcLang*>(temp3)->getLinksCount() ==412);
		} else CHECK(false);

	}
	TEST(filteredOutProc)
	{
		std::ofstream fout("UnitTest_container_filteredOutPROC.dat");
		container c;
		procLang *temp1 = new procLang;
		temp1->setYear(1993);
		temp1->setLinksCount(325);
		temp1->setAbstract(1);
		
		oopLang *temp2 = new oopLang;
		temp2->setYear(1984);
		temp2->setLinksCount(156);
		temp2->setInherence(INTERFACE);
		
		funcLang *temp3 = new funcLang;
		temp3->setYear(2001);
		temp3->setLinksCount(412);
		temp3->setLazyEval(0);
		temp3->setTypization(DYNAMIC_TYPE);
		
		std::vector <progLanguage*> cont;
		cont.resize(3);
		c.pushBackContainer(temp1);
		c.pushBackContainer(temp2);
		c.pushBackContainer(temp3);
		c.setLength(3);
		c.OutProc(fout);
		fout.close();
		std::ifstream fin("UnitTest_container_filteredOutPROC.dat");
		
		std::string s1;
		std::string s2 = "Only Procedure languages: ";
		getline(fin,s1);
		CHECK(s1 == s2);
		
		std::vector <std::string> test;
		while(!fin.eof())
		{
			getline(fin,s1);
			test.push_back(s1);
		}
		
		s2 = "Процедурный язык программирования  c наличием абстрактных типов данных был разработан в 1993 году.Количество упоминаний о данном языке в сети Интернет: 325";
		CHECK(test.size() == 2); //одна строка + перенос
		CHECK(test[0] == s2);
		


	}
	
	TEST(filteredOutOOP)
	{
		std::ofstream fout("UnitTest_container_filteredOutOOP.dat");
		container c;
		procLang *temp1 = new procLang;
		temp1->setYear(1993);
		temp1->setLinksCount(325);
		temp1->setAbstract(1);
		
		oopLang *temp2 = new oopLang;
		temp2->setYear(1984);
		temp2->setLinksCount(156);
		temp2->setInherence(INTERFACE);
		
		funcLang *temp3 = new funcLang;
		temp3->setYear(2001);
		temp3->setLinksCount(412);
		temp3->setLazyEval(0);
		temp3->setTypization(DYNAMIC_TYPE);
		
		std::vector <progLanguage*> cont;
		cont.resize(3);
		c.pushBackContainer(temp1);
		c.pushBackContainer(temp2);
		c.pushBackContainer(temp3);
		c.setLength(3);
		c.OutOOP(fout);
		fout.close();
		std::ifstream fin("UnitTest_container_filteredOutOOP.dat");
		
		std::string s1;
		std::string s2 = "Only OOP languages: ";
		getline(fin,s1);
		CHECK(s1 == s2);
		
		std::vector <std::string> test;
		while(!fin.eof())
		{
			getline(fin,s1);
			test.push_back(s1);
		}
		
		s2 = "Объектно ориентированный язык программирования  c поддержкой интерфейсов был разработан в 1984 году.Количество упоминаний о данном языке в сети Интернет: 156";
		CHECK(test.size() == 2); //одна строка + перенос
		CHECK(test[0] == s2);
	}
	
	TEST(sort)
	{
		container c;
		procLang *temp1 = new procLang;
		temp1->setYear(1993);
		temp1->setLinksCount(325);
		temp1->setAbstract(1);
		
		oopLang *temp2 = new oopLang;
		temp2->setYear(1984);
		temp2->setLinksCount(156);
		temp2->setInherence(INTERFACE);
		
		funcLang *temp3 = new funcLang;
		temp3->setYear(2001);
		temp3->setLinksCount(412);
		temp3->setLazyEval(0);
		temp3->setTypization(DYNAMIC_TYPE);
		
		std::vector <progLanguage*> cont;
		cont.resize(3);
		c.pushBackContainer(temp1);
		c.pushBackContainer(temp2);
		c.pushBackContainer(temp3);
		c.setLength(3);
		
		c.Sort();
		progLanguage *temp4 ;
		progLanguage *temp5 ;
		progLanguage *temp6 ;
		temp4 = c.getContainerItemAt(0);
		temp5 = c.getContainerItemAt(1);
		temp6 = c.getContainerItemAt(2);
		CHECK(static_cast<oopLang*>(temp4)->getYear() == 1984);
		CHECK(static_cast<procLang*>(temp5)->getYear() == 1993);
		CHECK(static_cast<funcLang*>(temp6)->getYear() == 2001);
	}
}