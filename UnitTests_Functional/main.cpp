#include "..\FunctionalLab\fileIO.h"
#include "..\FunctionalLab\fileIO.cpp"
#include "..\..\test\UnitTest++\unittest-cpp-master\UnitTest++\UnitTest++.h"

int main()
{
	return UnitTest::RunAllTests();
}

TEST(yearAge)
{
	progLanguage fst; 
	fst.year = 2008;

	CHECK(languageAge( fst) == 12);
}

TEST(compare)
{
	progLanguage fst; 
	progLanguage snd;
	fst.year = 2008;
	snd.year = 2009;
	CHECK(Compare(fst,snd) == 0 );
}

TEST(sort)
{
	std::vector<progLanguage> container;
	progLanguage fst; 
	progLanguage snd;
	progLanguage trd; 
	progLanguage frth;
	container.resize(4);
	fst.year = 2008;
	snd.year = 2009;
	trd.year = 2007;
	frth.year = 2015;
	container[0] = fst;
	container[1] = snd;
	container[2] = trd;
	container[3] = frth;
	Sort(container);
	CHECK(container[0].year == 2007);
	CHECK(container[1].year == 2008);
	CHECK(container[2].year == 2009);
	CHECK(container[3].year == 2015);
}

TEST(readFile)
{
	std::ifstream fin("readFileTest.dat");
	std::vector<progLanguage> container;
	container.resize(3);
	progLanguage fst; 
	progLanguage snd;
	progLanguage trd;
	fst.type = 0;
	fst.name = "C#";
	fst.inherence = 1;
	fst.year = 1998;
	fst.linksCount = 60;

	snd.type = 1;
	snd.name = "pascal";
	snd.isAbstract = 1;
	snd.year = 1970;
	snd.linksCount = 60;	
	
	trd.type = 2;
	trd.name = "haskell";
	trd.lazyEval = 0;
	trd.typization = 1;
	trd.year = 1990;
	trd.linksCount = 231;
	std::vector<progLanguage> tested;
	ReadFromFile(fin,tested);
	
	CHECK(tested.size() == 3);
	
	CHECK(tested[0].type == fst.type);
	CHECK(tested[0].name == fst.name);
	CHECK(tested[0].inherence == fst.inherence);
	CHECK(tested[0].year == fst.year);
	CHECK(tested[0].linksCount == fst.linksCount);
	
	CHECK(tested[1].type  == snd.type);
	CHECK(tested[1].name  == snd.name);
	CHECK(tested[1].isAbstract  == snd.isAbstract);
    CHECK(tested[1].year  == snd.year);
    CHECK(tested[1].linksCount  == snd.linksCount); 
	
	CHECK(tested[2].type  == trd.type);
	CHECK(tested[2].name == trd.name);
	CHECK(tested[2].lazyEval  == trd.lazyEval);
	CHECK(tested[2].typization  == trd.typization);
	CHECK(tested[2].year  == trd.year);
	CHECK(tested[2].linksCount  == trd.linksCount);
}


TEST(writeFile)
{
	std::ofstream fout("writeFileTest_result.dat");
	std::ifstream fin("writeFileTest_result.dat");
	
	progLanguage fst; 
	progLanguage snd;
	progLanguage trd;
	fst.type = 0;
	fst.name = "C#";
	fst.inherence = 1;
	fst.year = 1998;
	fst.linksCount = 60;

	snd.type = 1;
	snd.name = "pascal";
	snd.isAbstract = 1;
	snd.year = 1970;
	snd.linksCount = 60;	
	
	trd.type = 2;
	trd.name = "haskell";
	trd.lazyEval = 0;
	trd.typization = 1;
	trd.year = 1990;
	trd.linksCount = 231;	
	
	std::vector<progLanguage> container;
	container.resize(3);
	container[0] = fst;
	container[1] = snd;
	container[2] = trd;
	
	WriteToFile(fout,container);
	
	std::string s1;
	std::string s2 = "Объектно ориентированный язык программирования  c множественным наследованием \"C#\" был разработан в 1998 году. На данный момент возраст этого языка равен 22. Количество упоминаний о данном языке в сети Интернет: 60";
	std::string s3;
	std::string s4 ="Процедурный язык программирования  c наличием абстрактных типов данных \"pascal\" был разработан в 1970 году. На данный момент возраст этого языка равен 50. Количество упоминаний о данном языке в сети Интернет: 60";
	std::string s5;
	std::string s6 ="Функциональный язык программирования  без поддержки ленивый вычислений c динамической типизацией \"haskell\" был разработан в 1990 году. На данный момент возраст этого языка равен 30. Количество упоминаний о данном языке в сети Интернет: 231";
	getline(fin,s1);
	getline(fin,s3);
	getline(fin,s5);
	CHECK(s1 == s2);
	CHECK(s3 == s4);
	CHECK(s5 == s6);
}

TEST(writeFilefiltered)
{
	std::ofstream fout("writeFileTest_filtered_result.dat");
	
	
	progLanguage fst; 
	progLanguage snd;
	progLanguage trd;
	fst.type = 0;
	fst.name = "C#";
	fst.inherence = 1;
	fst.year = 1998;
	fst.linksCount = 60;

	snd.type = 1;
	snd.name = "pascal";
	snd.isAbstract = 1;
	snd.year = 1970;
	snd.linksCount = 60;	
	
	trd.type = 2;
	trd.name = "haskell";
	trd.lazyEval = 0;
	trd.typization = 1;
	trd.year = 1990;
	trd.linksCount = 231;	
	
	std::vector<progLanguage> container;
	container.resize(3);
	container[0] = fst;
	container[1] = snd;
	container[2] = trd;
	
	filteredOut(fout,container,PROCEDURE);
	fout.close();
	std::ifstream fin("writeFileTest_filtered_result.dat");
	
	std::string s3;
	std::string s4 ="Процедурный язык программирования  c наличием абстрактных типов данных \"pascal\" был разработан в 1970 году";
	std::vector<std::string> tested1;
	while(!fin.eof())
	{
		getline(fin,s3);
		tested1.push_back(s3);
	}

	CHECK(tested1.size() == 2); //1 строка плюс перенос строки
	CHECK(tested1[0] == s4);

}