#include "fileIO.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "incorrect command line!" << std::endl;
		std::cout << "Waited: command in_file out_file" << std::endl;
		exit(1);
	}

	std::ifstream ifst(argv[1]);
	std::ofstream ofst(argv[2]);

	if (!ifst || !ofst)
	{
		std::cout << "No files were found" << std::endl;
		return 0;
	}

	std::cout << "Start" << std::endl;

	container c;
	try
	{
		c.In(ifst);
		c.Sort();

		ofst << "Filled container. " << std::endl;

		c.OutWithAge(ofst);
		//c.Out(ofst);
		//c.OutOOP(ofst);
		//c.OutProc(ofst);


		c.Clear();
		ofst << "Empty container." << std::endl;
		c.Out(ofst);

		std::cout << "Stop" << std::endl;
	}
		catch ( std::invalid_argument &c )
	{	
		std::cerr << c.what()<< " или неправильное количество аргументов, или их порядок";
		return 2;
	}
	catch (std::out_of_range const &e)
	{
		 std::cerr << e.what();
		 return 4;
		
	}
	catch ( ... )
	{
		std::cerr << "Провал";
		return 3;
	}
	return 0;
}