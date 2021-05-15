#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

#define SIZE 10
#define MAX 6

int main()
{
    srand(time(NULL));
    string words[SIZE] = {"hound", "wolf", "feline", "giraffe", "donkey", "ape", "gorilla", "hedgehog", "unicorn", "elephant"};

    int variable = rand()%9;
    int i;
    char guesses = ' ';
    string hidden = words[variable];
    string badGuesses;
    string rightGuesses;
    int badCounter = 0;
    bool flag = true;
    int position;

    string game(hidden.length(), '-');

    while(flag)
    {
        cout<<game<<endl;
        cout<<"Please give a letter:";
        cin>>guesses;

        if(rightGuesses.find(guesses) != rightGuesses.npos || badGuesses.find(guesses) != badGuesses.npos)
        {
            cout<<"This letter has already been chosen"<<endl;
            continue;
        }

        if(hidden.find(guesses) >= 0 && hidden.find(guesses) <= 23)
        {
            position = hidden.find(guesses);
            game[position] = guesses;
            while (position < hidden.length())
            {
                if (hidden.find(guesses, position+1) >= 0 && hidden.find(guesses, position+1) <= 30)
                {
                    position = hidden.find(guesses, position+1);
                    game[position] = guesses;
                }
                else
                {
                    break;
                }
            }
            rightGuesses.push_back(guesses);
            cout<<game<<endl;
            if (game.find('-') > 25)
            {
                cout<<"You won!"<<endl;
                exit(0);
            }
        }
        else
        {
            {
                badGuesses.push_back(guesses);
                cout<<"Letters that are mistaken are "<<badGuesses<<endl;
                badCounter++;
                cout<<"You have made "<<badCounter<<" mistakes."<<" The game will end at "<<MAX<<" mistakes"<<endl;
            }
            if (badCounter >= MAX)
            {
                cout<<"Game Over."<<" The word was "<<words[variable];
                flag = false;
            }
        }
    }

    return 0;
}
