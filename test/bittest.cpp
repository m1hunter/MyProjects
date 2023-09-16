#include <iostream>

using namespace std;

int main()
{
    int d = 4;
    int count = 0;
    for (int i = 0; i < d; i++)
    {
        if (d % 2 == 1)
            d /= 2;
            count++;
    }
    cout << count;
}