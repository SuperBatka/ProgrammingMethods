#include "fileIO.h"

int main( int argc, char* argv[] )
{
    if( argc != 3 )
        {
            std::cout << "wrong arguments! "
                         "Usage: command inputFile outputFile"
                      << std::endl;
            exit( 1 );
        }

    std::ifstream fin( argv[1] );
    std::ofstream fout( argv[2] );
    if( !fin || !fout )
        {
            std::cout << "No files were found!" << std::endl;
            return 0;
        }
    std::vector<progLanguage> abc;
    ReadFromFile( fin, abc );
    MultiMethod( fout, abc );
    WriteToFile( fout, abc );
    return 0;
}