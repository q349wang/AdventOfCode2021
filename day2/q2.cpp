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
    int aim = 0;

    string cmd = "";
    int value = 0;
    while (cin >> cmd >> value)
    {
        if (cmd == fwd)
        {
            x += value;
            y += aim * value;
        }
        else if (cmd == down)
        {
            aim += value;
        }
        else if (cmd == up)
        {
            aim -= value;
        }
    }

    cout << x * y << endl;
}