#include "fileIO.h"

void ReadFromFile( std::ifstream &fin, std::vector<progLanguage> &container )
{
    if( !fin.is_open() )
        {
            throw std::invalid_argument( "Ошибка чтения файла" );
        }

    std::string b;
    fin >> b;
    int a = 0;
    a = std::stoi( b );
    if( a < 1 )
        throw std::invalid_argument( "Количество должно быть целым положительным числом" );

    container.resize( a );
    for( int i = 0; i < a; i++ )
        {
            std::string next_arg;
            fin >> next_arg;
            container[i].type = std::stoi( next_arg );

            if( ( container[i].type < 0 ) || ( container[i].type > 2 ) )
                {
                    throw std::invalid_argument(
                        "Нет такого языка, первым параметром для языка должно быть значение 0, 1 или 2" );
                }

            if( container[i].type == OOP )
                {
                    fin >> next_arg;
                    container[i].name = next_arg;

                    fin >> next_arg;
                    container[i].inherence = std::stoi( next_arg );
                    if( ( container[i].inherence < 0 ) || ( container[i].inherence > 2 ) )
                        {
                            throw std::invalid_argument( "Несуществующий тип наследования" );
                        }

                    fin >> next_arg;
                    container[i].year = std::stoi( next_arg );
                    if( ( container[i].year < 0 ) || ( container[i].year > 2020 ) )
                        {
                            throw std::invalid_argument( "Неправильно введён год" );
                        }

                    fin >> next_arg;
                    container[i].linksCount = std::stoi( next_arg );
                    if( container[i].linksCount < 0 )
                        {
                            throw std::invalid_argument( "Количество не может быть отрицательным" );
                        }
                }
            else if( container[i].type == PROCEDURE )
                {
                    fin >> next_arg;
                    container[i].name = next_arg;

                    fin >> next_arg;
                    int temp = std::stoi( next_arg );
                    if( temp != 0 && temp != 1 )
                        {
                            throw std::invalid_argument( "Наличие или отсутствие абстрактных типов данных должен "
                                                         "описываться булевой переменной" );
                        }
                    container[i].isAbstract = static_cast<bool>( temp );

                    fin >> next_arg;
                    container[i].year = std::stoi( next_arg );
                    if( ( container[i].year < 0 ) || ( container[i].year > 2020 ) )
                        {
                            throw std::invalid_argument( "Неправильно введён год" );
                        }

                    fin >> next_arg;
                    container[i].linksCount = std::stoi( next_arg );
                    if( container[i].linksCount < 0 )
                        {
                            throw std::invalid_argument(
                                "Количество упоминаний в интернете не может быть отрицательным" );
                        }
                }
            else
                {
                    fin >> next_arg;
                    container[i].name = next_arg;

                    fin >> next_arg;
                    int temp = std::stoi( next_arg );
                    if( temp != 0 && temp != 1 )
                        {
                            throw std::invalid_argument( "Наличие или отсутствие поддержки ленивых вычислений должно "
                                                         "описываться булевой переменной" );
                        }
                    container[i].lazyEval = static_cast<bool>( temp );

                    fin >> next_arg;
                    container[i].typization = std::stoi( next_arg );
                    if( container[i].typization != 0 && container[i].typization != 1 )
                        {
                            throw std::invalid_argument(
                                "Несуществующий вид типизации, 0 - строгая , 1 - динамическая" );
                        }

                    fin >> next_arg;
                    container[i].year = std::stoi( next_arg );
                    if( ( container[i].year < 0 ) || ( container[i].year > 2020 ) )
                        {
                            throw std::invalid_argument( "Неправильно введён год" );
                        }

                    fin >> next_arg;
                    container[i].linksCount = std::stoi( next_arg );
                    if( container[i].linksCount < 0 )
                        {
                            throw std::invalid_argument( "Количество не может быть отрицательным" );
                        }
                }
        }
}

void WriteToFile( std::ofstream &fout, std::vector<progLanguage> &container )
{
    if( !fout.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    for( unsigned int i = 0; i < container.size(); i++ )
        {
            if( container[i].type == OOP )
                {
                    fout << "Объектно ориентированный язык программирования ";
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
                }
            else if( container[i].type == PROCEDURE )
                {
                    fout << "Процедурный язык программирования ";
                    if( container[i].isAbstract == 0 )
                        {
                            fout << " без абстрактных типов данных";
                        }
                    else
                        {
                            fout << " c наличием абстрактных типов данных";
                        }
                }
            else
                {
                    fout << "Функциональный язык программирования ";

                    if( container[i].lazyEval == 0 )
                        {
                            fout << " без поддержки ленивый вычислений";
                        }
                    else
                        {
                            fout << " c поддержкой ленивый вычислений";
                        }

                    if( container[i].typization == STRICT_TYPE )
                        {
                            fout << " с строгой типизацией";
                        }
                    else
                        {
                            fout << " c динамической типизацией";
                        }
                }

            fout << " \"" << container[i].name << "\"";

            fout << " был разработан в " << container[i].year << " году.";

            fout << " На данный момент возраст этого языка равен " << languageAge( container[i] ) << ".";

            fout << " Количество упоминаний о данном языке в сети Интернет: " << container[i].linksCount << std::endl;
        }
}

int languageAge( progLanguage &lang )
{
    return 2020 - lang.year;
}

bool Compare( progLanguage &first, progLanguage &second )
{
    return languageAge( first ) < languageAge( second );
}

void Sort( std::vector<progLanguage> &container )
{
    for( unsigned int i = 0; i < container.size() - 1; i++ )
        {
            for( unsigned int j = i + 1; j < container.size(); j++ )
                {
                    if( Compare( container[i], container[j] ) )
                        {
                            progLanguage tmp = container[i];
                            container[i] = container[j];
                            container[j] = tmp;
                        }
                }
        }
}

void filteredOut( std::ofstream &fout, std::vector<progLanguage> &container, int type )
{
    if( !fout.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    if( type == OOP )
        {
            for( unsigned int i = 0; i < container.size(); i++ )
                {
                    if( container[i].type == OOP )
                        {
                            fout << "Объектно ориентированный язык программирования ";
                            if( container[i].inherence == SINGLE )
                                {
                                    fout << " с одиночным наследованием ";
                                }
                            else if( container[i].inherence == MULTIPLE )
                                {
                                    fout << " c множественным наследованием";
                                }
                            else if( container[i].inherence == INTERFACE )
                                {
                                    fout << " c поддержкой интерфейсов" << std::endl;
                                }

                            fout << " \"" << container[i].name << "\"";
                            fout << " был разработан в " << container[i].year << " году\n";
                        }
                    else
                        continue;
                }
        }
    else
        {
            for( unsigned int i = 0; i < container.size(); i++ )
                {
                    if( container[i].type == PROCEDURE )
                        {
                            fout << "Процедурный язык программирования ";
                            if( container[i].isAbstract == 0 )
                                {
                                    fout << " без абстрактных типов данных";
                                }
                            else
                                {
                                    fout << " c наличием абстрактных типов данных";
                                }

                            fout << " \"" << container[i].name << "\"";
                            fout << " был разработан в " << container[i].year << " году\n";
                        }
                    else
                        continue;
                }
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
                                        case FUNCTIONAL:
                                            fout << "ООП язык и Функциональный язык" << std::endl;
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
                                        case FUNCTIONAL:
                                            fout << "Процедурный язык и Функциональный язык" << std::endl;
                                            break;
                                        default:
                                            fout << "Неизвестный язык программирования" << std::endl;
                                            break;
                                    }
                                break;
                            case FUNCTIONAL:
                                switch( k2 )
                                    {
                                        case OOP:
                                            fout << "Функциональный язык и ООП язык" << std::endl;
                                            break;
                                        case PROCEDURE:
                                            fout << "Функциональный язык и Процедурный язык" << std::endl;
                                            break;
                                        case FUNCTIONAL:
                                            fout << "Функциональный язык и Функциональный язык" << std::endl;
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
    fout << "----- Конец мультиметода -----" << std::endl << std::endl;
}