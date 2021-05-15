#include <iostream>

using namespace std;

class point
{
private:
    int x;
    int y;
public:
    point(int, int);
    void setX(int);
    void setY(int);
    int getX()const;
    int getY()const;
    friend ostream &operator<<(ostream &left, const point &ob);
    friend class board;
    ~point();
};

class board
{
private:
    int dimension;
    char **table;
public:
    board(int);
    board();
    board(board &);
    void setBoard(point, char);
    char getBoard(point)const;
    void insertPoint(point);
    bool operator=(const board &right);
    friend ostream &operator<<(ostream &left, const board &ob);
    void printBoard(ostream &);
    void clear();
    ~board();
};

point::point(int X, int Y)
{
    if(X > 0 && X < 59)
        x = X;
    else
    {
        cout<<"Insufficient value for x"<<endl;
        x = 0;
    }

    if(Y > 0 && Y < 59)
        y = Y;
    else
    {
        cout<<"Insufficient value for y"<<endl;
        y = 0;
    }
}

void point::setX(int X)
{
    x = X;
}

void point::setY(int Y)
{
    y = Y;
}

int point::getX() const
{
    return x;
}

int point::getY() const
{
    return y;
}

ostream &operator<<(ostream &left, const point &ob)
{
    left<<"("<<ob.x<<", "<<ob.y<<")"<<endl;

    return left;
}

point::~point()
{

}

board::board()
{

}

board::board(int newDimensions)
{
    int i;
    int j;
    dimension = newDimensions;
    table = new char *[dimension];

    if (!table)
    {
        cout<<"Error in memoy allocation";
        exit(0);
    }

    for(i = 0; i < dimension; i++)
    {
        table[i] = new char [dimension];
        if(!table[i])
        {
            cout<<"Error in memory allocation";
            exit(0);
        }
    }

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            table[i][j] = '.';
        }
    }
}

board::board(board &otherBoard)
{
    int i, j;

    dimension = otherBoard.dimension;


    table = new char *[dimension];

    if (!table)
    {
        cout<<"Error in memory allocation";
        exit(0);
    }

    for (i = 0; i < dimension; i++)
    {
        table[i] = new char [dimension];
        if (!table[i])
        {
            cout<<"Error in memory allocation";
            exit(0);
        }
    }

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            table[i][j] = otherBoard.table[i][j];
        }
    }
}

bool board::operator=(const board &right)
{
    int flag = 0;
    int i, j;

    if (dimension == right.dimension)
        flag = 1;
    else
    {
        flag = 0;
        return false;
    }

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if (table[i][j] != right.table[i][j])
            {
                flag = 0;
                return false;
            }
        }
    }

    if (flag = 0)
        return false;
    else
        return true;
}

void board::setBoard(point a, char character)
{
    table[a.getX()][a.getY()] = character;
}

char board::getBoard(point a) const
{
    return table[a.getX()][a.getY()];
}

void board::insertPoint(point a)
{
    if (a.x >= dimension || a.y >= dimension)
        cout<<"Out of bounds";
    else
        table[a.x][a.y] = 'O';
}

ostream &operator<<(ostream &left, const board &ob)
{
    int i, j;

    for (i = ob.dimension-1; i >= 0; i--)
    {
        for (j = 0; j < ob.dimension; j++)
        {
            left<<ob.table[i][j]<<" ";
        }
        left<<endl;
    }

    return left;
}

void board::printBoard(ostream &plaisio)
{
    int i, j;

    for (i = dimension-1; i >= 0; i--)
    {
        for (j = 0; j < dimension; j++)
        {
            plaisio<<table[i][j]<<" ";
        }
        plaisio<<endl;
    }
}

void board::clear()
{
    int i, j;

    for (i = dimension-1; i >= 0; i--)
    {
        for (j = 0; j < dimension; j++)
            table[i][j] = '.';
    }
}

board::~board()
{
    int i;

    for(i = 0; i < dimension; i++)
        delete[] table[i];

    delete table;
}


int main() {
    int choice;
    point tempPoint(0, 0);
    int tempInt;
    board b(5);


    while (true)
    {
        cout<<"MENU"<<endl;
        cout<<"1 - Insert point"<<endl;
        cout<<"2 Print board"<<endl;
        cout<<"3 Clear the board"<<endl;
        cout<<"4 Exit"<<endl;
        cout<<"What is your choice?";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Please give the x coordinate"<<endl;
                cin>>tempInt;
                tempPoint.setX(tempInt);
                cout<<"Please give the y coordinate"<<endl;
                cin>>tempInt;
                tempPoint.setY(tempInt);
                b.insertPoint(tempPoint);
                break;
            case 2:
                cout<<b<<endl;

                break;
            case 3:
                b.clear();
                cout<<"The board is cleared"<<endl;

                break;
            case 4:
                cout<<"Goodbye"<<endl;
                exit(0);

                break;
            default:
                cout<<"Wrong input"<<endl;

                break;
        }
    }

    return 0;
}
