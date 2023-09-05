#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

void selection(int* arr, int size)
{
	auto begin = chrono::steady_clock::now();
	int minimum;
	for (int i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minimum])
				minimum = j;
		}
		int temp = arr[minimum];
		arr[minimum] = arr[i];
		arr[i] = temp;
	}
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
	cout << "Время выполнения работы сортировки: " << elapsed_ms.count();
}

void insertion(int* arr, int size)
{
	auto begin = chrono::steady_clock::now();
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	//for (int k = 0; k < size; k++)
		//cout << arr[k] << " ";
	//cout << endl;
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
	cout << "Время выполнения работы сортировки: " << elapsed_ms.count();
}
int main()
{
	setlocale(0, "");
	int s,size = 0;
	cout << "Введите размер массива от 10 до 1000000: ";
	cin >> size;
	int* arr = new int[size];
	int v;
	cout << "Выберите сортировку: 1 - selection, 2 - insertion: ";
	cin >> s;
	cout << "Выберите заполнение массива: 1 - в порядке возрастания, 0 - в обратном: ";
	cin >> v;
	for (int i = 0; i < size; i++)
	{
		if (v == 1)
		{
			arr[i] = i;
		}
		if (v == 0)
		{
			arr[i] = size - i;
		}
	}
	int k;
	cout << endl;
	if (s == 1)
		selection(arr, size);
	if (s == 2)
		insertion(arr, size);
	delete[]arr;
}