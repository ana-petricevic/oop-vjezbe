#include <iostream>

template <typename T>
bool ascending(T a, T b)
{
	return a < b;
}
template <typename T>
bool descending(T a, T b)
{
	return a > b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(arr[j], arr[i]))
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main()
{
	int a[] = { 5, 2, 8, 1, 9 };
	double b[] = { 4.5, 1.2, 8.7, 2.3, 1.5 };
	char c[] = { 'd', 'a', 'c', 'b', 'm' };
	int n = 5;

	my_sort(a, n, ascending<int>);
	std::cout << "Poziv my_sort ascending funkcije za int: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	my_sort(b, n, ascending<double>);
	std::cout << "Poziv my_sort ascending funkcije za double: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	my_sort(c, n, descending<char>);
	std::cout << "Poziv my_sort descending funkcije za char: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}