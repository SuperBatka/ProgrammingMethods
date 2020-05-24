#include "fileIO.h"

void container::In( std::ifstream &ifst )
{
    if( !ifst.is_open() )
        {
            throw std::invalid_argument( "Ошибка чтения файла" );
        }
    while( !ifst.eof() )
        {
            cont.push_back( progLanguage::In( ifst ) );
            len = cont.size();
        }
}

void container::Out( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Container contents " << len << " elements. " << std::endl;
    for( int i = 0; i < len; i++ )
        {
            ofst << i << ": ";
            cont[i]->Out( ofst );
        }
}

void container::OutWithAge( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Container contents " << len << " elements. " << std::endl;
    for( int i = 0; i < len; i++ )
        {
            ofst << i << ": ";
            cont[i]->Out( ofst );
            ofst << "Возраст данного языка равен " << cont[i]->languageAge() << std::endl;
        }
}

void container::Sort()
{
    for( int i = 0; i < len; i++ )
        {
            for( int j = i + 1; j < len; j++ )
                {
                    if( cont[i]->Compare( *cont[j] ) )
                        {
                            progLanguage *tmp = cont[i];
                            cont[i] = cont[j];
                            cont[j] = tmp;
                        }
                }
        }
}

void container::OutProc( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Only Procedure languages: " << std::endl;
    for( int i = 0; i < len; i++ )
        {
            // ofst << i << ": ";
            cont[i]->OutProc( ofst );
        }
}

void container::OutOOP( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Only OOP languages: " << std::endl;
    for( int i = 0; i < len; i++ )
        {
            // ofst << i << ": ";
            cont[i]->OutOOP( ofst );
        }
}

void container::setLength( int s )
{
    if( s < 0 )
        {
            throw std::invalid_argument( "Размер контейнера не может быть отрицательным числом" );
        }
    len = s;
}

int container::getLength()
{
    return len;
}

void container::Clear()
{
    cont.clear();
    len = 0;
}

void container::setContainerItemAt( int i, progLanguage *item )
{
    if( i < 0 )
        {
            throw std::invalid_argument( "номер элемента контейнере не может быть отрицательным числом" );
        }
    cont.at( i ) = item;
}

progLanguage *container::getContainerItemAt( int i )
{
    if( i < 0 )
        {
            throw std::invalid_argument( "номер элемента контейнере не может быть отрицательным числом" );
        }
    return cont.at( i );
}

void container::pushBackContainer( progLanguage *item )
{
    cont.push_back( item );
}

progLanguage *progLanguage::In( std::ifstream &ifst )
{
    progLanguage *sp;
    int k = 0;

    std::string next_arg;
    ifst >> next_arg;
    k = std::stoi( next_arg );

    if( ( k < 0 ) || ( k > 2 ) )
        {
            throw std::invalid_argument(
                "Нет такого языка, первым параметром для языка должно быть значение 0, 1 или 2" );
        }

    switch( k )
        {
            case 0:
                sp = new oopLang;
                break;
            case 1:
                sp = new procLang;
                break;
            case 2:
                sp = new funcLang;
                break;
            default:
                return 0;
        }
    sp->InData( ifst );
    return sp;
}

bool progLanguage::Compare( progLanguage &compareTo )
{
    return languageAge() < compareTo.languageAge();
}

void progLanguage::InData( std::ifstream &ifst )
{
    std::string next_arg;

    ifst >> next_arg;
    _linksCount = std::stoi( next_arg );
    if( _linksCount < 0 )
        {
            throw std::invalid_argument( "Количество упоминаний в интернете не может быть отрицательным" );
        }
}

void progLanguage::Out( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Количество упоминаний о данном языке в сети Интернет: " << _linksCount << std::endl;
}

void progLanguage::OutProc( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    if( false )
        ofst << std::endl;
}

void progLanguage::OutOOP( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    if( false )
        ofst << std::endl;
}

int progLanguage::getLinksCount()
{
    return _linksCount;
}
void progLanguage::setLinksCount( int s )
{
    if( s < 0 )
        {
            throw std::invalid_argument( "Количество не может быть отрицательным" );
        }
    _linksCount = s;
}

int progLanguage::getYear()
{
    return year;
}
void progLanguage::setYear( int s )
{
    if( ( s < 0 ) || ( s > 2020 ) )
        {
            throw std::invalid_argument( "Неправильно введён год" );
        }
    year = s;
}

void progLanguage::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
    ofst << "Неизвестный язык программирования" << std::endl;
}

void progLanguage::MMoop( std::ofstream &ofst )
{
    ofst << "Неизвестный язык программирования" << std::endl;
}

void progLanguage::MMprocedure( std::ofstream &ofst )
{
    ofst << "Неизвестный язык программирования" << std::endl;
}

void progLanguage::MMfunctional( std::ofstream &ofst )
{
    ofst << "Неизвестный язык программирования" << std::endl;
}

void procLang::InData( std::ifstream &ifst )
{
    std::string next_arg;
    ifst >> next_arg;
    int temp = std::stoi( next_arg );
    if( temp != 0 && temp != 1 )
        {
            throw std::invalid_argument(
                "Наличие или отсутствие абстрактных типов данных должен описываться булевой переменной" );
        }
    isAbstract = static_cast<bool>( temp );

    ifst >> next_arg;
    int year = std::stoi( next_arg );
    setYear( year );

    progLanguage::InData( ifst );
}

void procLang::Out( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Процедурный язык программирования ";
    if( isAbstract == 0 )
        {
            ofst << " без абстрактных типов данных";
        }
    else
        {
            ofst << " c наличием абстрактных типов данных";
        }
    ofst << " был разработан в " << getYear() << " году.";
    progLanguage::Out( ofst );
}

int procLang::languageAge()
{
    return 2020 - getYear();
}

void procLang::OutProc( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    Out( ofst );
}
bool procLang::getAbstract()
{
    return isAbstract;
}
void procLang::setAbstract( bool s )
{
    isAbstract = s;
}


void oopLang::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
    other->MMoop( ofst );
}

void oopLang::MMoop( std::ofstream &ofst )
{
    ofst << "ООП язык и ООП язык" << std::endl;
}

void oopLang::MMprocedure( std::ofstream &ofst )
{
    ofst << "Процедурный язык и ООП язык" << std::endl;
}

void oopLang::MMfunctional( std::ofstream &ofst )
{
    ofst << "Функциональный язык и ООП язык" << std::endl;
}

void oopLang::InData( std::ifstream &ifst )
{
    std::string next_arg;
    ifst >> next_arg;
    inherence = std::stoi( next_arg );
    if( ( inherence < 0 ) || ( inherence > 2 ) )
        {
            throw std::invalid_argument( "Несуществующий тип наследования" );
        }

    ifst >> next_arg;
    int year = std::stoi( next_arg );
    setYear( year );
    progLanguage::InData( ifst );
}

void oopLang::Out( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    ofst << "Объектно ориентированный язык программирования ";
    if( inherence == SINGLE )
        {
            ofst << " с одиночным наследованием";
        }
    else if( inherence == MULTIPLE )
        {
            ofst << " c множественным наследованием";
        }
    else if( inherence == INTERFACE )
        {
            ofst << " c поддержкой интерфейсов";
        }

    ofst << " был разработан в " << getYear() << " году.";
    progLanguage::Out( ofst );
}

int oopLang::languageAge()
{
    return 2020 - getYear();
}

int oopLang::getInherence()
{
    return inherence;
}
void oopLang::setInherence( int s )
{
    if( ( s < 0 ) || ( s > 2 ) )
        {
            throw std::invalid_argument( "Несуществующий тип наследования" );
        }
    inherence = s;
}

void procLang::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
    other->MMprocedure( ofst );
}

void procLang::MMoop( std::ofstream &ofst )
{
    ofst << "ООП язык и Процедурный язык" << std::endl;
}

void procLang::MMprocedure( std::ofstream &ofst )
{
    ofst << "Процедурный язык и Процедурный язык" << std::endl;
}

void procLang::MMfunctional( std::ofstream &ofst )
{
    ofst << "Функциональный язык и Процедурный язык" << std::endl;
}

void funcLang::Out( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }

    ofst << "Это функциональный язык программирования ";
    if( typization == STRICT_TYPE )
        ofst << "со строгой типизацией ";
    else
        ofst << "с динамической типизацией ";
    if( lazyEval == 0 )
        ofst << "без поддержки ленивый вычислений";
    else
        ofst << "с поддержкой ленивый вычислений" << std::endl;
    ofst << ", который был создан в " << getYear() << " году. ";
    progLanguage::Out( ofst );
}

void funcLang::InData( std::ifstream &ifst )
{
    std::string next_arg;
    ifst >> next_arg;
    int temp = std::stoi( next_arg );
    if( temp != 0 && temp != 1 )
        {
            throw std::invalid_argument(
                "Наличие или отсутствие поддержки ленивых вычислений должно описываться булевой переменной" );
        }
    lazyEval = static_cast<bool>( temp );

    ifst >> next_arg;
    typization = std::stoi( next_arg );
    if( typization != 0 && typization != 1 )
        {
            throw std::invalid_argument( "Несуществующий вид типизации, 0 - строгая , 1 - динамическая" );
        }

    ifst >> next_arg;
    int year = std::stoi( next_arg );
    setYear( year );

    progLanguage::InData( ifst );
}

int funcLang::languageAge()
{
    return 2020 - getYear();
}

int funcLang::getTypization()
{
    return typization;
}
void funcLang::setTypization( int s )
{
    if( s != 0 && s != 1 )
        {
            throw std::invalid_argument( "Несуществующий вид типизации, 0 - строгая , 1 - динамическая" );
        }
    typization = s;
}

bool funcLang::getLazyEval()
{
    return lazyEval;
}

void funcLang::setLazyEval( bool s )
{
    if( s != 0 && s != 1 )
        {
            throw std::invalid_argument(
                "Наличие или отсутствие поддержки ленивых вычислений должно описываться булевой переменной" );
        }
    lazyEval = s;
}

void funcLang::MultiMethod( std::ofstream &ofst, progLanguage *other )
{
    other->MMprocedure( ofst );
}

void funcLang::MMoop( std::ofstream &ofst )
{
    ofst << "ООП язык и Функциональный язык" << std::endl;
}

void funcLang::MMprocedure( std::ofstream &ofst )
{
    ofst << "Процедурный язык и Функциональный язык" << std::endl;
}

void funcLang::MMfunctional( std::ofstream &ofst )
{
    ofst << "Функциональный язык и Функциональный язык" << std::endl;
}

void oopLang::OutOOP( std::ofstream &ofst )
{
    if( !ofst.is_open() )
        {
            throw std::invalid_argument( "Ошибка записи в файл" );
        }
    Out( ofst );
}

void container::MultiMethod( std::ofstream &ofst )
{
    ofst << "Мультиметод: " << std::endl;

    for( int i = 0; i < cont.size() - 1; i++ )
        {
            for( int j = i + 1; j < cont.size(); j++ )
                {
                    cont[i]->MultiMethod( ofst, cont[j] );
                }
        }
    ofst << "----- Конец мультиметода -----" << std::endl << std::endl;
}
container::container() : len( 0 )
{
}