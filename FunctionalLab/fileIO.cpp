#include "fileIO.h"

void ReadFromFile( std::ifstream &fin, std::vector<progLanguage> &container )
{
    int a = 0;
    fin >> a;
    container.resize( a );
    for( int i = 0; i < a; i++ )
        {
            fin >> container[i].type;
            fin >> container[i].name;
            fin >> container[i].inherence;
            fin >> container[i].year;
        }
}

void WriteToFile( std::ofstream &fout, std::vector<progLanguage> &container )
{
    int a = static_cast<int>( container.size() );

    for( int i = 0; i < a; i++ )
        {
            if( container[i].type == OOP )
                {
                    fout << "Объектно ориентированный язык программирования ";
                }
            else
                {
                    fout << "Процедурный язык программирования ";
                }

            fout << container[i].name;
            if( container[i].inherence == SINGLE )
                {
                    fout << " с одиночным наследованием";
                }
            else if( container[i].inherence == MULTIPLE )
                {
                    fout << " c множественным наследованием";
                }
            else if( container[i].inherence == INTERFACE )
                {
                    fout << " c поддержкой интерфейсов";
                }

            fout << " был разработан в " << container[i].year << " году\n";
        }
}

void MultiMethod( std::ofstream &fout, std::vector<progLanguage> &container )
{
    fout << "Мультиметод: " << std::endl;
    for( int i = 0; i < container.size() - 1; i++ )
        {
            int k1 = container[i].type;

            for( int j = i + 1; j < container.size(); j++ )
                {
                    int k2 = container[j].type;

                    switch( k1 )
                        {
                            case OOP:
                                switch( k2 )
                                    {
                                        case OOP:
                                            fout << "ООП язык и ООП язык" << std::endl;
                                            break;
                                        case PROCEDURE:
                                            fout << "ООП язык и Процедурный язык" << std::endl;
                                            break;
                                        default:
                                            fout << "Неизвестный язык программирования" << std::endl;
                                            break;
                                    }
                                break;
                            case PROCEDURE:
                                switch( k2 )
                                    {
                                        case OOP:
                                            fout << "Процедурный язык и ООП язык" << std::endl;
                                            break;
                                        case PROCEDURE:
                                            fout << "Процедурный язык и Процедурный язык" << std::endl;
                                            break;
                                        default:
                                            fout << "Неизвестный язык программирования" << std::endl;
                                            break;
                                    }
                                break;
                            default:
                                fout << "Неизвестный язык программирования" << std::endl;
                                break;
                        }
                }
        }
}