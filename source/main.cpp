#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int points = 0;

void printQuestions(int argc, char const *argv[]);
void checkAnswer(string correctAnswer);

void checkAnswer(string correctAnswer)
{
    string playerAnswer;

    cout << endl << "Your answer: ";
    cin >> playerAnswer;

    if (playerAnswer == correctAnswer)
    {
        points++;
    }

}

void printQuestions(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        ifstream fin(argv[i]);
        string line;
        while (getline(fin, line))
        {
            stringstream rin(line);
            string question;
            getline(rin, question, ',');

            cout << question << endl;

            for (int i = 0; i < 4; i++)
            {
                string answer;
                getline(rin, answer, ',');
                cout << answer << endl;
            }

            string correctAnswer;
            getline(rin, correctAnswer, ',');
            
            checkAnswer(correctAnswer);
        }
    }
}

int main(int argc, char const *argv[])
{
    printQuestions(argc, argv);
    system("cls");
    cout << points << endl;

    return 0;
}