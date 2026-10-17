#include <iostream>

inline bool ascending(int a, int b)
{
	return a < b;
}
inline bool descending(int a, int b)
{
	return a > b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(arr[j], arr[i]))
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 5, 2, 8, 1, 9, 3 };
	int n = 6;


	my_sort(arr, n, ascending);
	std::cout << "Ispis niza nakon poziva funkcije my_sort ascending: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	my_sort(arr, n, descending);
	std::cout << "Ispis niza nakon poziva funkcije my_sort descending: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;



}