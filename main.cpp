#include <iostream>

using namespace std;

int main()
{
    int times;
    while (cin >> times)
    {
        for (int t = 0; t < times; t++)
        {
            size_t length;
            cin >> length;
            int *list = new int[length];
            for (int i = 0; i < length;i++)
            {
                cin >> list[i];
            }
        }
    }
}