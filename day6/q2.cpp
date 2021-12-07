#include <string>
#include <iostream>
using namespace std;

#define NUM_DAYS 257

int main()
{

    long long breedable[NUM_DAYS];
    long long numFish[NUM_DAYS];

    for (int i = 0; i < NUM_DAYS; i += 1)
    {
        breedable[i] = 0;
        numFish[i] = 0;
    }

    string input;

    getline(cin, input);

    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        int day = stoi(token);
        if (day < NUM_DAYS)
        {
            breedable[day + 1] += 1;
        }
        numFish[0] += 1;
        input.erase(0, pos + delimiter.length());
    }
    {
        int day = stoi(input);
        if (day < NUM_DAYS)
        {
            breedable[day + 1] += 1;
        }
        numFish[0] += 1;
    }

    for (int i = 1; i < NUM_DAYS; i += 1)
    {

        if (i - 7 >= 0)
        {
            breedable[i] += breedable[i - 7];
        }

        if (i - 9 >= 0)
        {
            breedable[i] += breedable[i - 9];
        }
        numFish[i] = numFish[i - 1] + breedable[i];
    }

    cout << numFish[NUM_DAYS - 1] << endl;
}
