#include <string>
#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

struct Line
{
    int x1, x2, y1, y2;
    bool isStraight;
};

int main()
{

    std::string delimiter = ",";

    vector<Line> lines;

    string input;

    while (cin >> input)
    {
        int x1, x2, y1, y2;
        size_t pos = 0;
        std::string token;
        while ((pos = input.find(delimiter)) != std::string::npos)
        {
            token = input.substr(0, pos);
            x1 = stoi(token);
            input.erase(0, pos + delimiter.length());
        }
        y1 = stoi(input);

        cin >> input;

        cin >> input;

        while ((pos = input.find(delimiter)) != std::string::npos)
        {
            token = input.substr(0, pos);
            x2 = stoi(token);
            input.erase(0, pos + delimiter.length());
        }
        y2 = stoi(input);

        Line line;
        line.x1 = x1;
        line.x2 = x2;
        line.y1 = y1;
        line.y2 = y2;
        line.isStraight = x1 == x2 || y1 == y2;

        lines.push_back(line);
    }

    map<pair<int, int>, int> overlaps;

    for (const auto &line : lines)
    {
        if (!line.isStraight)
        {
            continue;
        }

        if (line.x1 == line.x2)
        {
            int y_min = min(line.y1, line.y2);
            int y_max = max(line.y1, line.y2);
            for (int i = y_min; i <= y_max; i += 1)
            {
                auto coord = make_pair(line.x1, i);
                if (overlaps.find(coord) == overlaps.end())
                {
                    overlaps[coord] = 0;
                }
                overlaps[coord] += 1;
            }
        }
        else if (line.y1 == line.y2)
        {
            int x_min = min(line.x1, line.x2);
            int x_max = max(line.x1, line.x2);
            for (int i = x_min; i <= x_max; i += 1)
            {
                auto coord = make_pair(i, line.y1);
                if (overlaps.find(coord) == overlaps.end())
                {
                    overlaps[coord] = 0;
                }
                overlaps[coord] += 1;
            }
        }
    }

    int num_overlaps = 0;
    for (const auto & data : overlaps)
    {
        if (data.second > 1)
        {
            num_overlaps += 1;
        }
    }

    cout << num_overlaps << endl;
}
