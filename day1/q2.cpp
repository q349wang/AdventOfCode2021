#include <iostream>
using namespace std;

int main()
{
    int prev = -1;
    int curr = -1;

    int n = 0;

    cin >> curr;

    int prevFirst = curr;

    int prevSum = prevFirst;
    int currSum = -1;

    cin >> curr;
    prevSum += curr;
    
    cin >> curr;
    prevSum += curr;
    prev = curr;
    while (cin >> curr)
    {
        currSum = prevSum - prevFirst + curr;

        if (currSum > prevSum)
        {
            n += 1;
        }

        prevFirst = prevSum - prevFirst - prev;
        prevSum = currSum;
        prev = curr;
    }

    cout << n << endl;
}