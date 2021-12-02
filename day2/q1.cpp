#include <string>
#include <iostream>
using namespace std;

int main()
{
    string fwd = "forward";
    string down = "down";
    string up = "up";

    int x = 0;
    int y = 0;

    string cmd = "";
    int value = 0;
    while (cin >> cmd >> value)
    {
        if (cmd == fwd)
        {
            x += value;
        }
        else if (cmd == down)
        {
            y += value;
        }
        else if (cmd == up)
        {
            y -= value;
        }
    }

    cout << x * y << endl;
}