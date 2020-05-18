#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class progLanguage
{
   public:
    static progLanguage* In( std::ifstream& ifst );
    virtual void InData( std::ifstream& ifst ) = 0;
    virtual void Out( std::ofstream& ofst ) = 0;
    virtual void MultiMethod( std::ofstream& ofst, progLanguage* other ) = 0;

    virtual void MMoop( std::ofstream& ofst ) = 0;
    virtual void MMprocedure( std::ofstream& ofst ) = 0;

   protected:
    progLanguage()
    {
    }
};

class procLang : public progLanguage
{
    bool isAbstract;
    int year;

   public:
    void InData( std::ifstream& ifst );
    void Out( std::ofstream& ofst );
    virtual void MultiMethod( std::ofstream& ofst, progLanguage* other );

    virtual void MMoop( std::ofstream& ofst );
    virtual void MMprocedure( std::ofstream& ofst );
    procLang()
    {
    }
};

class oopLang : public progLanguage
{
    int year;
    int inherence;

   public:
    void InData( std::ifstream& ifst );
    void Out( std::ofstream& ofst );
    virtual void MultiMethod( std::ofstream& ofst, progLanguage* other );

    virtual void MMoop( std::ofstream& ofst );
    virtual void MMprocedure( std::ofstream& ofst );
    oopLang()
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
    void MultiMethod( std::ofstream& ofst );
    void Clear();
    container();
    ~container()
    {
        Clear();
    }
};