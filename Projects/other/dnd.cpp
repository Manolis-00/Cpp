#include <iostream>
#include <ctime>

using namespace std;

class Wizard
{
private:
    int age;
    string beardColour;
    int mana;
    int health;
    bool dead;
public:
    //constructors
    Wizard(int , string, int);
    bool checkDead();
    //setters
    int fireBall();
    int thunderBall();
    void wait();
    //getter
    int getMana()const;
    int getHealth()const;
    //channels
    void print(ostream &);
    //overloaded operators
    Wizard &operator+= (int);
    Wizard &operator-= (int);
};

class humanoid
{
private:
    int health;
    bool dead;
public:
    //constructor
    humanoid();
    bool checkDead();
    int attack();
    int getHealth()const;
    //overloaded operators
    humanoid &operator-= (int);
};
//constructors

Wizard::Wizard(int age, string beard, int mana)
{
    this->age = age;
    this->beardColour = beard;
    this->mana = mana;
    this->health = 100;
    this->dead = false;
}

bool Wizard::checkDead()
{
    if (dead == true)
    {
        return true;
    }
    return false;
}

humanoid::humanoid()
{
    this->health = 100;
    this->dead = false;
}

// setters
int Wizard::fireBall()
{
    if (mana < 30)
    {
        cout<<endl<<"Not enough mana\n";
        return 0;
    }
    else
    {
        this->mana = mana - 30;
        cout<<"Gandalf is casting fireball\n"<<getMana()<<"\n";
    }

    return 50 + rand() % (20-0+1);
}

int Wizard::thunderBall()
{
    if (mana < 90)
    {
        cout<<endl<<"Not enough mana\n";
        return 0;
    }
    else
    {
        this->mana = mana - 90;
        cout<<"Gandalf is casting thunderball\n"<<getMana()<<"\n";
    }

    return 10 + rand() % (10-0+1);
}

void Wizard::wait()
{
    this->mana = mana + 10;
    cout<<"Gandalf is waiting\n"<<getMana()<<"\n";
}

int humanoid::attack()
{
    return 1 + rand() % (4-0+1);
}

int humanoid::getHealth() const
{
    return health;
}

bool humanoid::checkDead()
{
    if (dead == true)
    {
        return true;
    }
    return false;
}

//getters
int Wizard::getMana()const
{
    return mana;
}

int Wizard::getHealth() const
{
    return health;
}

//channels
void Wizard::print(ostream &show)
{
   show<<age<<"\n"<<beardColour<<"\n"<<mana<<"\n"<<health<<"\n";
}

//overloaded operators
Wizard &Wizard::operator+=(int right)
{
    if (health == 100)
        cout<<"\n"<<"You can not heal any more"<<"\n";
    else if (health < 100)
    {
        health += right;
        if(health > 100)
            health = 100;
    }
}

Wizard &Wizard::operator-=(int right)
{
    health -= right;

    if (health < 0)
    {
        cout<<"The Wizard died!";
        dead = true;
    }
}

humanoid &humanoid::operator-=(int right)
{
    health -= right;

    if (health < 0)
    {
        cout<<"Humanoid Dead!";
        dead = true;
    }
}

int main()
{
    srand((time(0)));
    Wizard Gandalf(2021, "Grey", 100);
    Gandalf.print(cout);
    humanoid a;
    int r;
    int damage;

    r = 1;
    while(1)
    {
        cout<<"========================================="<<endl;
        cout<<"Round "<<r<<endl;
        //Wizards turn
        if (rand()%2 == 0)
        {
            damage = Gandalf.thunderBall();
            a -= damage;
        }
        else
        {
            damage = Gandalf.fireBall();
            a -= damage;
        }

        //check if humanoid is dead
        if (a.checkDead() == true)
        {
            cout<<"The humanoid died";
            break;
        }
        else
            cout<<"Humanoids remaining life is "<<a.getHealth()<<endl;

        //Humanoids turn
        damage = a.attack();
        Gandalf -= damage;

        if (Gandalf.checkDead() == true)
        {
            cout<<"The wizard died";
            break;
        }
        else
            cout<<"The wizards remaining life is "<<Gandalf.getHealth()<<endl;

        //Increase round
        Gandalf.wait();
        r++;
    }


    return 0;
}
