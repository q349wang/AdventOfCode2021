#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct Bingo
{
    map<int, int> valToOffset;
    int values[25];
    bool marked[25];
    bool won;
};

int main()
{
    vector<int> numbers;
    vector<Bingo> boards;

    string input;

    getline(cin, input);

    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        numbers.push_back(stoi(token));
        input.erase(0, pos + delimiter.length());
    }
    numbers.push_back(stoi(input));

    int val;

    while (cin >> val)
    {
        Bingo board;
        board.won = false;
        board.values[0] = val;
        board.valToOffset[val] = 0;
        board.marked[0] = false;
        for (int i = 1; i < 25; i += 1)
        {
            cin >> val;
            board.values[i] = val;
            board.valToOffset[val] = i;
            board.marked[i] = false;
        }

        boards.push_back(board);
    }

    int lastWin = 0;

    for (auto num : numbers)
    {
        for (auto &board : boards)
        {
            if (board.won)
            {
                continue;
            }
            if (board.valToOffset.find(num) != board.valToOffset.end())
            {
                int index = board.valToOffset[num];
                board.marked[index] = true;

                int row = index / 5;
                int col = index % 5;

                // check row
                bool win = true;
                for (int i = 0; i < 5; i += 1)
                {
                    win &= board.marked[row * 5 + i];
                }

                if (win)
                {
                    int sum = 0;
                    for (int i = 0; i < 25; i += 1)
                    {
                        if (!board.marked[i])
                        {
                            sum += board.values[i];
                        }
                    }
                    board.won = true;
                    lastWin = sum * num;
                }

                // check column
                win = true;
                for (int i = 0; i < 5; i += 1)
                {
                    win &= board.marked[i * 5 + col];
                }

                if (win)
                {
                    int sum = 0;
                    for (int i = 0; i < 25; i += 1)
                    {
                        if (!board.marked[i])
                        {
                            sum += board.values[i];
                        }
                    }
                    board.won = true;
                    lastWin = sum * num;
                }
            }
        }
    }

    cout << lastWin << endl;
}
