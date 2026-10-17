#include <iostream>
#include <string>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b)
{
	return a > b ? a : b;
}

template <typename T>
T my_max_template(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	std::cout << "Vrijednost a: " << a << std::endl;
	std::cout << "Vrijednost b: " << b << std::endl;
	std::cout << "Vrijednost c: " << c << std::endl;

	int i = 3;

	std::cout << "Poziv MAX:" << MAX(++i, 2) << std::endl;
	std::cout << "Vrijedost i nakon MAX poziva: " << i << std::endl;

	i = 3;

	std::cout << "Poziv funkcije my_max: " << my_max(++i, 2) << std::endl;
	std::cout << "Vrijednost i nakon funkcije: " << i << std::endl;

	std::cout << "Poziv my_max_template za int, double, char i string:" << std::endl;
	std::cout << my_max_template(3, 5) << std::endl;
	std::cout << my_max_template(2.5, 4.7) << std::endl;
	std::cout << my_max_template('a', 'z') << std::endl;
	std::cout << my_max_template(std::string("Ana"), std::string("Marko")) << std::endl;

	return 0;

}