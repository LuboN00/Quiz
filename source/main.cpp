#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
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
            
            string answer;

            for (int i = 0; i < 4; i++)
            {
                getline(rin, answer, ',');
                cout << answer << endl;
            }
        }
    }

    return 0;
}
