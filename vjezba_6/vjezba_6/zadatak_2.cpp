#include <iostream>
#include <string>

class Ticket
{
private:
	std::string concert_name;
	int id;
	static int counter;

public:
	Ticket(const std::string& name)
		: concert_name(name), id(++counter)
	{
	}
	Ticket(const Ticket&) = delete;

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

void print(const Ticket& t)
{
	std::cout << t.get_id() << std::endl;
}

int main()
{
	Ticket t1("Shame, Zagreb");
	Ticket t2("Shame, Zagreb");
	Ticket t3("Viagra Boys, Ljubljana");

	std::cout << "Izdano ulaznica: " << Ticket::issued() << std::endl;


	std::cout << "Ulaznice br: " << t1.get_id() << " " << t2.get_id() << " " << t3.get_id() << std::endl;

	std::cout << "Ulaznice: ";
	print(t1);
	print(t2);
	print(t3);

	std::cout << "Ukupan broj izdanih ulaznica: " << Ticket::issued() << std::endl;

	return 0;
}