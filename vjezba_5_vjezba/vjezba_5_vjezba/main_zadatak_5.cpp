#include <iostream>
#include <string>

class Ticket {
private:
	std::string concert;
	int id;

	static int counter;

public:
	Ticket(std::string name) : concert(name), id(++counter)
	{

	}
	int get_id() const
	{
		return id;
	}
	static int issued()
	{
		return counter;
	}
};
int Ticket::counter = 0;

int main()
{
	std::cout << Ticket::issued() << std::endl;

	Ticket t1("Shame, Zagreb");
	Ticket t2("Shame, Zagreb");
	Ticket t3("Viagra Boys, Ljubljana");

	std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << std::endl;

	std::cout << Ticket::issued() << std::endl;

	return 0;
}