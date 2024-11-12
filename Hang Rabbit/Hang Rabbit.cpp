// Hang Rabbit

#include <iostream>
#include <string>
using namespace std;

void gallows0()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows1()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "o   |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows2()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "o_  |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows3()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "o_. |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows4()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "o_. |\n";
    cout << " |  |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows5()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "o_. |\n";
    cout << " || |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows6()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "/   |\n";
    cout << "o_. |\n";
    cout << " || |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}

void gallows7()
{
    cout << "_____\n";
    cout << "|   |\n";
    cout << "//  |\n";
    cout << "o_. |\n";
    cout << " || |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "    |\n";
    cout << "--------\n";
}
void printBlankWord(string blankWord, int wordLength)
{
    for (int i = 0; i < wordLength; i++)
    {
        cout << blankWord[i] << ' ';

    }
    cout << endl;
    return;
}
int main()
{
    bool gameOver = 0;
    int errorCount = 0;
    char userGuess;
    int rightLetter = 0;

    unsigned int seedTime = static_cast<unsigned int>(time(NULL));
    srand(seedTime);
    int wordIndex = rand() % 10;

    string hangRabbitWords[10] = { "murder","dirt","duck","gordy","children","everyone","shadow","sun","water","fire" };

    cout << "Welcome to Hang Rabbit!\n";

    string userWord = hangRabbitWords[wordIndex];
    int wordLength = size(userWord);


    //cout << userWord << endl;
    //cout << wordLength << endl;

    string blankWord = hangRabbitWords[wordIndex];
    for (int i = 0; i < wordLength; i++)
    {
        blankWord[i] = '_';
    }

    printBlankWord(blankWord, wordLength);

    gallows0();
    cout << endl;
    while (!gameOver)
    {
        cout << "Guess a letter!\n";
        cin >> userGuess;
        userGuess = tolower(userGuess);

        if (!(userWord.find(userGuess) < wordLength))
        {
            cout << "Nope" << endl;
            errorCount++;
        }
        else
        {
            cout << "Yep" << endl;

            for (int i = 0; i < wordLength; i++)
            {
                if (userWord[i] == userGuess)
                {
                    blankWord[i] = userGuess;
                }

            }
            rightLetter++;
        }

        printBlankWord(blankWord, wordLength);

        if (errorCount > 6)
        {
            cout << "You lost!\n";
            gameOver = 1;
        }
        if (rightLetter == wordLength)
        {
            cout << "You win!\n";
            gameOver = 1;
        }

        switch (errorCount)
        {
        case 0: gallows0(); break;
        case 1: gallows1(); break;
        case 2: gallows2(); break;
        case 3: gallows3(); break;
        case 4: gallows4(); break;
        case 5: gallows5(); break;
        case 6: gallows6(); break;
        case 7: gallows7(); break;
        default: break;
        }
    }
    cout << "Done." << endl;
    return 0;
}
