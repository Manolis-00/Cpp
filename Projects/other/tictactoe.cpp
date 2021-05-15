#include <iostream>

using namespace std;

#define N 3

class ticTac
{
private:
    char **array;
    char player;
public:
    ticTac();
    bool play(int x, int y);
    char checkWinner();
    void nextPlayer();
    char getPlayer() const;
    void emptyGrid(ostream &);
    ~ticTac();
};

ticTac::ticTac()
{
    array = new char *[N];

    for(int i = 0; i < N; i++)
        array[i] = new char [N];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            array[i][j] = '-';
        }
    }

    player = 'X';
}

bool ticTac::play(int x, int y)
{
    if (array[x][y] == '-')
    {
        array[x][y] = player;
        return true;
    }
    else
        return false;
}

char ticTac::checkWinner()
{
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;

    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            if(array[i][j] == array[i][j+1]  && array[i][j+1] == array[i][j+2] && array[i][j+2] == array[i][j] && array[i][j+2] != '-')
            {
                temp1 = 1;
                return array[i][j];
            }
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(array[i][j] == array[i+1][j] && array[i+1][j] == array[i+2][j] && array[i][j] == array[i+2][j] && array[i][j] != '-')
            {
                temp2 = 1;
                return array[i][j];
            }
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (array[i][j] == array[i+1][j+1] && array[i+1][j+1] == array[i+2][j+2] && array[i][j] == array[i+2][j+2] && array[i][j] != '-')
            {
                temp3 = 1;
                return array[i][j];
            }
        }
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (array[i][j+2] == array[i+1][j+1] && array[i+1][j+1] == array[i+2][j] && array[i][j+2] == array[i+2][j] && array[i][j+2] != '-')
            {
                temp4 = 1;
                return array[i][j+2];
            }
        }
    }

    if(temp1 != 1 && temp2 != 1 && temp3 !=1 && temp4 != 1)
    {
        return '-';
    }
}

void ticTac::nextPlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char ticTac::getPlayer() const
{
    return player;
}

void ticTac::emptyGrid(ostream &grid)
{
    for(int i = 0; i < N; i++)
    {

        for(int j = 0; j < N; j++)
        {
            grid<<array[i][j];
        }
        grid<<endl;
    }
}

ticTac::~ticTac()
{
    delete[] array;
}

int main()
{
    bool flag = true;
    ticTac t;

    int x, y, step = 0;

    while (flag)
    {
        cout << "Plaisio" << endl;
        t.emptyGrid(cout);
        cout << "Player " << t.getPlayer() << " is playing" << endl;

        cout << endl << "Give x coord: ";
        cin >> x;

        cout << endl << "Give y coord: ";
        cin >> y;

        if (t.play(x, y) == false) {
            cout << "Wrong move" << endl;
            continue;
        } else
            step++;

        if (t.checkWinner() != '-') {
            t.emptyGrid(cout);
            cout << "The winner is player " << t.checkWinner() << endl;
            break;
        } else if (step == 9) {
            t.emptyGrid(cout);
            cout << "Draw" << endl;
            flag = false;
        }

        t.nextPlayer();
    }

    return 0;
}
