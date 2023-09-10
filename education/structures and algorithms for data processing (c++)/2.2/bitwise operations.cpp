#include "iostream" 
#include "iomanip"

using namespace std;

//3 вариант
int task1(int x)
{
    
    int mask = ~0xAAAAAAAA;
    return x | mask;
}

int task2(int x)
{
    unsigned int mask = ~((1 << 11) | (1 << 9) | (1 << 7));
    return x & mask;
}

int task3(int x)
{
    return x << 4;
}

int task4(int x)
{
    return x >> 4;
}

int task5(int x, int n)
{
    unsigned int mask1 = 1;
    unsigned int mask2 = 1 << 31;
    mask1 = ~(mask1 << n);
    return x & mask1;

}


int main()
{
    setlocale(0, "");

    int x = 0;
    int n = 0;

    cout << "Введите значение: " << endl;
    cin >> x;
    cout << "Введите n-ый бит: " << endl;
    cin >> n;

    int res1 = task1(x);
    int res2 = task2(x);
    int res3 = task3(x);
    int res4 = task4(x);
    int res5 = task5(x, n);

    cout << "Результат первого задания:" << setw(40) << res1 << endl;
    cout << "Результат второго задания:" << setw(40) << res2 << endl;
    cout << "Результат третьего задания:" << setw(39) << res3 << endl;
    cout << "Результат четвертого задания:" << setw(37) << res4 << endl;
    cout << "Результат пятого задания:" << setw(41) << res5 << endl;

    return 0;
    //int x = 0x2a; // 42
    //int o = 052; // 2*1+2*8=42
    //int b = 0b00101010; //42

    //если их вывести просто, то выведет 42
    //если cout << hex << showbase, то в основании

}