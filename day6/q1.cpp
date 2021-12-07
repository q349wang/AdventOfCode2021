#include <string>
#include <iostream>
using namespace std;

int simulate(int initial, int days)
{
    int breedDay = days - initial - 1;
    int newFish = 0;
    if (breedDay >= 0)
    {
        newFish = breedDay / 7 + 1;
    }

    int numFish = 1;

    for (int i = 0; i < newFish; i += 1)
    {
        numFish += simulate(8, breedDay - i * 7);
    }

    return numFish;
}

int main()
{

    int numFish = 0;
    int numDays = 80;

    string input;

    getline(cin, input);

    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        numFish += simulate(stoi(token), numDays);
        input.erase(0, pos + delimiter.length());
    }
    numFish += simulate(stoi(input), numDays);

    cout << numFish << endl;
}
