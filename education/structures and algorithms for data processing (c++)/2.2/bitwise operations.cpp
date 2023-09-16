#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

//3 вариант

/*


    &: поразрядная конъюнкция (операция И или поразрядное умножение). Возвращает 1, если оба из соответствующих разрядов обоих чисел равны 1

    |: поразрядная дизъюнкция (операция ИЛИ или поразрядное сложение). Возвращает 1, если хотя бы один из соответствующих разрядов обоих чисел равен 1

    ^: поразрядное исключающее ИЛИ. Возвращает 1, если только один из соответствующих разрядов обоих чисел равен 1

    ~: поразрядное отрицание или инверсия. Инвертирует все разряды операнда. Если разряд равен 1, то он становится равен 0, а если он равен 0, то он получает значение 1.


*/
int task1(int x)
{
    unsigned int mask = 0x55555555; //5 = 0101
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
    mask1 = ~(mask1 << n);
    return x & mask1;

}

string binary(unsigned int x)
{
    string result;
    for (int i = 0; i < 32; ++i)
    {
        if (x % 2 == 1) result = "1" + result;
        else result = "0" + result;
        x = x / 2;
    }
    return result;
}


int main()
{
    auto x = 0;
    int n = 0;

    setlocale(0, "");

    printf("Введите число, над которым будут производиться операции: ");
    cin >> x;
    printf("Введите n-ный бит (для 5 задания): ");
    scanf_s("%d", &n);

    int res1 = task1(x);
    int res2 = task2(x);
    int res3 = task3(x);
    int res4 = task4(x);
    int res5 = task5(x,n);

    cout << "Исходное число:" << setw(51) << x << " " << binary(x) << endl;
    cout << "Результат первого задания:" << setw(40) << res5 << " " << binary(res5) << endl;
    cout << "Результат второго задания:" << setw(40) << res2 << " " << binary(res2) << endl;
    cout << "Результат третьего задания:" << setw(39) << res3 << " " << binary(res3) << endl;
    cout << "Результат четвертого задания:" << setw(37) << res4 << " " << binary(res4) << endl;
    cout << "Результат пятого задания:" << setw(41) << res5 << " " << binary(res5) << endl;
    

    return 0;
}
