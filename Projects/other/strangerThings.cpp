#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define FOUR 4

class demigorgon
{
private:
    int height = 5;
    int weight = 500;
    int health;
public:
    demigorgon();
    int damage();
};

class demidog
{
private:
    int health;
public:
    demidog();
    int damage();
};

class hive
{
private:
    demigorgon *demigorgonPointer;
    demidog *demidogArray;
    int totalDemidogs;
public:
    hive(bool gorgon);
    int damage();
    ~hive();
};

hive::hive(bool gorgon)
{
    if (gorgon)
    {
        demigorgonPointer = new demigorgon;
        if (!demigorgonPointer)
            cout<<"Error with memory allocation";
    }
    else
        demigorgonPointer = NULL;

    int dogs = 10 + rand() % (40-0+1);
    demidogArray = new demidog [dogs];
    if(!demidogArray)
        cout<<"Error with memory allocation";
    totalDemidogs = dogs;
}

int hive::damage()
{
    int damage1;
    int damage2 = 0;

    if (demigorgonPointer != NULL)
    {
        damage1 = demigorgonPointer->damage();
        cout<<"Demigorgon attacks! (damage: "<<damage1<<")"<<endl;
    }

    for (int i = 0; i < totalDemidogs; i++)
    {
        damage2 = demidogArray[i].damage();
        cout<<"Demidog "<<i+1<<" attacks! (damage: "<<demidogArray[i].damage()<<")"<<endl;
    }

    cout<<totalDemidogs<<" attack with a total damage of "<<damage2<<endl;

    cout<<"Total damage received is "<<damage1+damage2<<endl;

    return damage2+damage1;
}

demigorgon::demigorgon()
{
        this->health = 10000;
}

int demigorgon::damage()
{


    return 300 + rand() % (200-0+1);
}

demidog::demidog()
{
    this->health = 100;
}

int demidog::damage()
{
    return 10 + rand() % (20-0+1);
}

hive::~hive()
{
    delete[] demigorgonPointer;
    delete[] demidogArray;
}

int main()
{
    srand(time(nullptr));
    hive h(true);

    int damage;

    damage = h.damage();

    return 0;
}
