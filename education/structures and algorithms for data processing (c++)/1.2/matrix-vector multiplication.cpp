#include "iostream"
#include "cstdlib"

using namespace std;



int main()
{
	setlocale(0, "");
	int n, m, v; //размер матрицы //размер строки
	cout << "Введите кол-во строк матрицы: " << endl;
	cin >> m;
	cout << "Введите кол-во столбцов матрицы: " << endl;
	cin >> n;
	cout << "Введите размер вектор-строки: " << endl;
	cin >> v;
	if (v != n)
	{
		cout << "Если матрица имеет размерность M на N, то вектор должен иметь N элементов, чтобы его можно было умножить на эту матрицу.";
		exit(0);
	}
	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}
	int* vector = new int[v];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Вводите элементы матрицы: ";
			cin >> matrix[i][j];
		}
	}
	cout << "Вектор:" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << "Введите элементы вектора: ";
		cin >> vector[i];
	}
	int* result = new int[v];
	for (int i = 0; i < m; i++)
	{
		result[i] = 0;
		for (int j = 0; j < n; j++)
		{
			result[i] += matrix[i][j] * vector[j];
		}
	}
	cout << "Резульат работы программы:";
	for (int i = 0; i < n; i++)
	{
		cout << result[i];
		if (i < n - 1)
			cout << " ";
	}
	delete[] matrix;
	delete[] vector;
	delete[] result;
	return (0);
}