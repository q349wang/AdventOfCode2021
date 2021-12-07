#include <string>
#include <memory>
#include <iostream>
using namespace std;

struct Node
{
    Node() : count{0}, value{-1}, left{nullptr}, right{nullptr} {}
    int count;
    int value;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
};

void addToTrie(Node *head, int value, int height)
{
    Node *curr = head;

    int mask = 1 << height;
    for (int i = 0; i < height; i += 1)
    {
        mask >>= 1;
        bool isZero = !(value & mask);

        if (isZero)
        {
            if (!curr->left)
            {
                curr->left = make_unique<Node>();
            }

            curr = curr->left.get();
        }
        else
        {
            if (!curr->right)
            {
                curr->right = make_unique<Node>();
            }

            curr = curr->right.get();
        }

        curr->count += 1;
        // Only need value if it is the only one that exists (ok for overwrite)
        curr->value = value;
    }
}

int main()
{
    string num = "";

    unique_ptr<Node> trie = make_unique<Node>();

    int size = -1;

    int count = 0;
    while (cin >> num)
    {
        if (size == -1)
        {
            size = num.length();
        }

        int value = stoi(num, 0, 2);

        addToTrie(trie.get(), value, size);

        count += 1;
    }

    int half = count / 2;

    Node *o2 = trie.get();
    Node *co2 = trie.get();

    int oxygen = 0;
    int carbonDioxide = 0;

    for (int i = 0; i < size; i += 1)
    {
        if (!o2->right)
        {
            o2 = o2->left.get();
        }
        else if (!o2->left)
        {
            o2 = o2->right.get();
        }
        else if (o2->right->count >= o2->left->count)
        {
            o2 = o2->right.get();
        }
        else
        {
            o2 = o2->left.get();
        }

        if (o2->count == 1)
        {
            oxygen = o2->value;
            break;
        }
    }

    for (int i = 0; i < size; i += 1)
    {
        if (!co2->right)
        {
            co2 = co2->left.get();
        }
        else if (!co2->left)
        {
            co2 = co2->right.get();
        }
        else if (co2->right->count < co2->left->count)
        {
            co2 = co2->right.get();
        }
        else
        {
            co2 = co2->left.get();
        }

        if (co2->count == 1)
        {
            carbonDioxide = co2->value;
            break;
        }
    }

    cout << carbonDioxide * oxygen << endl;
}
