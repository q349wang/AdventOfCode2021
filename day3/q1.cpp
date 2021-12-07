#include <string>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    string num = "";

    int size = -1;
    unique_ptr<int[]> num_ones;

    int count = 0;
    while (cin >> num)
    {
        if (size == -1)
        {
            size = num.length();

            num_ones = make_unique<int[]>(size);

            for (int i = 0; i < size; i += 1)
            {
                num_ones[i] = 0;
            }
        }

        int value = stoi(num, 0, 2);
        for (int i = 0; i < size; i += 1)
        {
            int one = value & 1;
            num_ones[size - i - 1] += one;

            value >>= 1;
        }

        count += 1;
    }

    int half = count / 2;

    int gamma = 0;
    for (int i = 0; i < size; i += 1)
    {
        gamma <<= 1;
        gamma += num_ones[i] >= half ? 1 : 0;
    }
    
    int epsilon = 0;
    for (int i = 0; i < size; i += 1)
    {
        epsilon <<= 1;
        epsilon += num_ones[i] < half ? 1 : 0;
    }
    cout << gamma * epsilon << endl;
}