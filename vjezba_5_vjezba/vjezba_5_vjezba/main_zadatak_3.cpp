#include <iostream>
#include <string>
#include <vector>

struct Song {
	std::string title;
	std::string artist;
	int seconds;
};
class Album {
private:
	std::string title;
	int year;
	std::vector<Song> songs;

public:
	Album(std::string t, int y, Song first)
		: title(t), year(y), songs{ first }
	{

	}
	bool add(Song s)
	{
		for (const Song& song : songs)
		{
			if (song.title == s.title)
			{
				return false;
			}

		}
		songs.push_back(s);
		return true;
	}
	int duration() const
	{
		int total = 0;
		for (const Song& song : songs)
		{
			total += song.seconds;
		}
		return total;
	}
	void print() const
	{
		int total = duration();
		int minutes = total / 60;
		int seconds = total % 60;

		std::cout << title << " (" << year << " ), " << songs.size() << " pjesme, " << minutes << ":";

		if (seconds < 10)
			std::cout << "0";

		std::cout << seconds << std::endl;

		for (int i = 0; i < songs.size(); i++)
		{
			std::cout << " " << i + 1 << ". " << songs[i].title << std::endl;
		}
	}
};

int main()
{
	Album a("Sol Invictus", 2015, { "Sol Invictus", "Faith No More", 156 });

	a.add({ "Superhero", "Faith No More", 315 });

	a.add({ "Matador", "Faith No More", 368 });

	std::cout << a.add({ "Superhero", "Faith No More", 315 }) << '\n';

	a.print();

	return 0;
}