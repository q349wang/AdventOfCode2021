#include <iostream>
using namespace std;

int main()
{
    int prev = -1;

    int curr = -1;

    int n = 0;
    while (cin >> curr)
    {
        if (prev != -1 && prev < curr)
        {
            n += 1;
        }

        prev = curr;
    }

    cout << n << endl;
}