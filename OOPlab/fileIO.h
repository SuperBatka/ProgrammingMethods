#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum
{
    STRICT_TYPE = 0,
    DYNAMIC_TYPE
};

enum
{
    OOP = 0,
    PROCEDURE,
    FUNCTIONAL
};

enum
{
    SINGLE = 0,
    MULTIPLE,
    INTERFACE
};

class progLanguage
{
    int _linksCount;
    int year;

   public:
    static progLanguage* In( std::ifstream& ifst );

    virtual void InData( std::ifstream& ifst );
    virtual void Out( std::ofstream& ofst );
    virtual int languageAge() = 0;
    virtual void OutProc( std::ofstream& ofst );
    virtual void OutOOP( std::ofstream& ofst );

    virtual void MultiMethod( std::ofstream& ofst, progLanguage* other ) = 0;
    virtual void MMoop( std::ofstream& ofst ) = 0;
    virtual void MMprocedure( std::ofstream& ofst ) = 0;
    virtual void MMfunctional( std::ofstream& ofst ) = 0;

    void setLinksCount( int s );
    int getLinksCount();
    int getYear();
    void setYear( int s );
    
    bool Compare( progLanguage& compareTo );

   protected:
    progLanguage()
    {
    }
};

class procLang : public progLanguage
{
    bool isAbstract;
   public:
    bool getAbstract();
    void setAbstract( bool s );

    void InData( std::ifstream& ifst ) override;
    void Out( std::ofstream& ofst ) override;
    int languageAge() override;
    void OutProc( std::ofstream& ofst ) override;

    void MultiMethod( std::ofstream& ofst, progLanguage* other ) override;
    void MMoop( std::ofstream& ofst ) override;
    void MMprocedure( std::ofstream& ofst ) override;
    void MMfunctional( std::ofstream& ofst ) override;
    procLang()
    {
    }
};

class oopLang : public progLanguage
{
    int inherence;

   public:
    int getInherence();
    void setInherence( int s );

    void InData( std::ifstream& ifst ) override;
    void Out( std::ofstream& ofst ) override;
    int languageAge() override;
    void OutOOP( std::ofstream& ofst ) override;

    void MultiMethod( std::ofstream& ofst, progLanguage* other ) override;
    void MMoop( std::ofstream& ofst ) override;
    void MMprocedure( std::ofstream& ofst ) override;
    void MMfunctional( std::ofstream& ofst ) override;
    oopLang()
    {
    }
};

class funcLang : public progLanguage
{
    int typization;
    bool lazyEval;

   public:
    int getTypization();
    void setTypization( int s );

    bool getLazyEval();
    void setLazyEval( bool s );

    void InData( std::ifstream& ifst ) override;
    void Out( std::ofstream& ofst ) override;
    int languageAge() override;

    void MultiMethod( std::ofstream& ofst, progLanguage* other ) override;
    void MMoop( std::ofstream& ofst ) override;
    void MMprocedure( std::ofstream& ofst ) override;
    void MMfunctional( std::ofstream& ofst ) override;
    funcLang()
    {
    }
};

class container
{
    std::vector<progLanguage*> cont;
    int len;

   public:
    void In( std::ifstream& ifst );
    void Out( std::ofstream& ofst );
    void OutWithAge( std::ofstream& ofst );
    void OutProc( std::ofstream& ofst );
    void OutOOP( std::ofstream& ofst );
    void Clear();
    void Sort();

    void setContainerItemAt( int i, progLanguage* item );
    progLanguage* getContainerItemAt( int i );
    void pushBackContainer( progLanguage* item );

    void setLength( int s );
    int getLength();

    void MultiMethod( std::ofstream& ofst );

    container();
    ~container()
    {
        Clear();
    }
};