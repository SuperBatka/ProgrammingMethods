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

	c.In(ifst);

	ofst << "Filled container. " << std::endl;
	c.Out(ofst);
    c.MultiMethod(ofst);
	c.Clear();
	ofst << "Empty container." << std::endl;
	c.Out(ofst);


	std::cout << "Stop" << std::endl;
	return 0;
}