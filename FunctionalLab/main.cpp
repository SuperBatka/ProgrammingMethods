#include "fileIO.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "wrong arguments! "
			"Usage: command inputFile outputFile" << std::endl;
		exit(1);
	}

	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2]);
	if (!fin || !fout)
	{
		std::cerr << "No files were found!" << std::endl;
		return 1;
	}
	try
	{
	std::vector<progLanguage> abc;
	ReadFromFile(fin,abc);
	
	//Sort(abc);
	WriteToFile(fout,abc);
	//filteredOut(fout,abc,PROCEDURE);
	}
	catch ( std::invalid_argument &c )
	{	
		std::cerr << c.what()<< " или неправильное количество аргументов, или их порядок";
		return 2;
	}
	catch (std::out_of_range const &e)
	{
		 std::cerr << "Вы ввели слишком большое число, которое не вмещается в int";
		
	}
	catch ( ... )
	{
		std::cerr << "Провал";
		return 3;
	}
	std::cout<<"Успех!"<<std::endl;
    return 0;
}