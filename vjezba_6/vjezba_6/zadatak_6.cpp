#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed
{
private:
	std::string* songs;
	int cap;
	int count;
	int next;
public:
	RecentlyPlayed(int capacity)
	{
		assert(capacity > 0);
		cap = capacity;
		count = 0;
		next = 0;
		songs = new std::string[cap];
	}
	~RecentlyPlayed()
	{
		delete[] songs;
	}
	
	
	RecentlyPlayed(const RecentlyPlayed& other)
	{
		cap = other.cap;
		count = other.count;
		next = other.next;
		songs = new std::string[cap];

		for (int i = 0; i < cap; i++)
		{
			songs[i] = other.songs[i];
		}
	}
	void play(const std::string& title)
	{
		songs[next] = title;
		next = (next + 1) % cap;
		if (count < cap)
			count++;
	}
	int size() const
	{
		return count;
	}
	int capacity() const
	{
		return cap;
	}
	std::string get(int i) const
	{
		assert(i >= 0 && i < count);
		int index = (next - 1 - i + cap) % cap;
		return songs[index];
	}
	void print() const
	{
		for (int i = 0; i < count; i++)
		{
			if (i > 0)
				std::cout << ", ";
			std::cout << get(i);
		}
		std::cout << std::endl;
	}

};
int main()
{
	RecentlyPlayed recent(3);

	recent.play("Heroes");
	recent.play("Literary Mind");

	std::cout << recent.size() << " " << recent.capacity() << std::endl;

	recent.play("Sports");
	recent.print();

	recent.play("Henry Dont Got Love");
	recent.print();

	RecentlyPlayed copy = recent;

	recent.play("Guided by Angels");

	recent.print();
	copy.print();

	std::cout << copy.get(0) << std::endl;

	return 0;
}