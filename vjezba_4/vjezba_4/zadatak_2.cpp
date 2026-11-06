#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Song {
	std::string title;
	std::string artist;
	int year;
	int plays;
};
void print_song(const Song& s)
{
	std::cout << s.title << "-" << s.artist << ", " << s.year << ", slusanja: " << s.plays << std::endl;
}
int main()
{
	std::vector<Song> pjesme = {
		 {"Bohemian Rhapsody", "Queen", 1975, 1500},
		{"Imagine", "John Lennon", 1971, 1200},
		{"Billie Jean", "Michael Jackson", 1982, 2000},
		{"Don't Stop Me Now", "Queen", 1978, 1800},
		{"Hey Jude", "The Beatles", 1968, 1700},
		{"We Will Rock You", "Queen", 1977, 900},
		{"Let It Be", "The Beatles", 1970, 1400}
	};

	std::sort(pjesme.begin(), pjesme.end(), [](const Song& a, const Song& b)
		{
			if (a.year != b.year)
			{
				return a.year < b.year;
			}
			return a.title < b.title;
		});
	std::cout << "Sortirane pjesme: " << std::endl;
	for (const Song& s : pjesme)
		print_song(s);

	std::string ime;
	std::cout << "Unesite ime izvodaca: ";
	std::getline(std::cin >> std::ws, ime);

	int broj = 0;
	const Song* najstarija = nullptr;

	for (const Song& s : pjesme)
	{
		if (s.artist == ime)
		{
			broj++;
			if (najstarija == nullptr || s.year < najstarija->year)
			{
				najstarija = &s;
			}
		}
	}
	std::cout << "Broj pjesama: " << broj << std::endl;

	if (najstarija != nullptr)
	{
		std::cout << "Najstarija pjesma: ";
		print_song(*najstarija);
	}
	else
	{
		std::cout << "Izvodac nije pronaden." << std::endl;
	}
	auto naj = std::max_element(pjesme.begin(), pjesme.end(), [](const Song& a, const Song& b)
		{
			return a.plays < b.plays;
		});

	std::cout << "Najslusanija pjesma : ";
	print_song(*naj);

	return 0;
}	