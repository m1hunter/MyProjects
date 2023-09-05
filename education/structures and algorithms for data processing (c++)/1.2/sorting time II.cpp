#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void shell(int* arr, int size)
{   
	int d = 1;
	while (d < size / 2) 
	{
		d = d * 2 + 1;
	}
	while (d >= 1) {
		for (int i = d; i < size; i++) {
			int j = i - d;
			int temp = arr[i];
			while (j >= 0 && arr[j] > temp) {
				arr[j + d] = arr[j];
				j -= d;
			}
			arr[j + d] = temp;
		}
		d /= 2;
	}
}

void insertion(int* arr, int size)
{
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
}

void merge(int* arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[q + 1 + j];
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
	//for (int l = 0; l < r+1; l++)
		//cout << arr[l] << " ";
}

void merge_sort(int* arr, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main()
{
	setlocale(0, "");
	int s, size = 0;
	cout << "Введите размер массива от 10 до 1000000: ";
	cin >> size;
	int* arr = new int[size];
	int v;
	cout << "Выберите алгоритм: 1 - Простой алгоритм (вставками), 2 - Шелла со смещением Д. Кнута, Способ 2, 3 - Простое слияние: ";
	cin >> s;
	cout << "Выберите заполнение массива: 1 - в порядке возрастания, 2 - в обратном, 3 - случайное заполнение (средняя сложность): ";
	cin >> v;
	for (int i = 0; i < size; i++)
	{
		if (v == 1)
		{
			arr[i] = i;
		}
		if (v == 2)
		{
			arr[i] = size - i;
		}
		if (v == 3)
		{
			int min = 1;
			int max = size;
			arr[i] = 1 + rand() % 1000;
		}
	}
	if (s == 1)
	{
		auto begin = chrono::steady_clock::now();
		insertion(arr, size);
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
		cout << "Время выполнения работы сортировки в мс: " << elapsed_ms.count() << endl;
	}
	if (s == 2)
	{
		auto begin = chrono::steady_clock::now();
		shell(arr, size);
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
		cout << "Время выполнения работы сортировки в мс: " << elapsed_ms.count() << endl;
	}
	if (s == 3)
	{
		auto begin = chrono::steady_clock::now();
		merge_sort(arr, 0, size - 1);
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
		cout << "Время выполнения работы сортировки в мс: " << elapsed_ms.count() << endl;
	}
	delete[]arr;
}