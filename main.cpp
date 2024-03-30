#include <iostream>
#include <random>
#include <string>
using namespace std;

void startGame();
int getUserChoice();
int getComputerChoice();
void showResult(int userChoice, int computerChoice);
void showError(string message);

int main()
{
    startGame();
    return 0;
}

void startGame()
{
    do
    {
        int userChoice = getUserChoice();
        bool isWrongChoice = userChoice < 1 || userChoice > 3;
        if (isWrongChoice)
        {
            showError("Wrong input!\n\n");
            break;
        }
        int computerChoice = getComputerChoice();
        showResult(userChoice, computerChoice);
    } while (true);
}

int getUserChoice()
{
    int userInput;
    cout << "############### Rock Paper Scissor ###############\n\n";
    cout << "Choice:\n1: rock\n2: paper\n3: scissor\n\n";
    cout << "Your input: ";
    cin >> userInput;
    cout << "\n";
    return userInput;
}

int getComputerChoice()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0, 2);
    return dist6(rng);
}

void showResult(int userChoice, int computerChoice)
{
    string rpses[3] = {"Rock", "Paper", "Scissor"};
    bool isUserWin = userChoice == 1 && computerChoice == 3 || userChoice == 2 && computerChoice == 1 || userChoice == 3 && computerChoice == 2;
    bool isDraw = userChoice == computerChoice;
    string message = isDraw ? "Draw!" : isUserWin ? "You won!"
                                                  : "You lose!";
    cout << "You: " << rpses[userChoice - 1] << "\n";
    cout << "Computer: " << rpses[computerChoice - 1] << "\n\n";
    cout << message << "\n\n";
}

void showError(string message)
{
    cout << "Error: " << message;
}