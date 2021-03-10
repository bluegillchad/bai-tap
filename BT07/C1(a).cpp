#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int diceRoll();

int main()
{
    srand(time(0));
    int firstPlayerPoints = 0, secondPlayerPoints = 0;
    const int firstPlayersTurn = 0, secondPlayersTurn = 1;
    int currentTurn = firstPlayersTurn;
    while (firstPlayerPoints < 100 || secondPlayerPoints < 100)
    {
        int currentDiceRoll = diceRoll();
        switch (currentTurn)
        {
            case firstPlayersTurn:
                firstPlayerPoints += currentDiceRoll;
                cout << "xuc xac nguoi choi 1: " << currentDiceRoll << " 	Tong nguoi 1: " << firstPlayerPoints << endl;
                currentTurn = secondPlayersTurn;
                break;
            case secondPlayersTurn:
                secondPlayerPoints += currentDiceRoll;
                cout << "xuc xac nguoi choi 2: " << currentDiceRoll << " 	Tong nguoi 2: " << secondPlayerPoints << endl;
                currentTurn = firstPlayersTurn;
                break;
        }
    }
    return 0;
}

int diceRoll()
{
    return rand() % 6 + 1;
}
