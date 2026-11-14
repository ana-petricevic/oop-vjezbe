#include <iostream>
#include <string>
#include <vector>

class Enemy
{
private:
	std::string name;
	int x; 
	int y;
	int health;
public:
	Enemy(std::string n, int x, int y)
		: name(n), x(x), y(y), health(100)
	{
	}
	std::string get_name() const
	{
		return name;
	}
	int get_x() const
	{
		return x;
	}
	int get_y() const
	{
		return y;
	}
	int get_health() const
	{
		return health;
	}
	bool is_alive() const
	{
		return health > 0;
	}
	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
	void take_damage(int d)
	{
		health -= d;
		if (health < 0)
			health = 0;
	}
};
class Level
{
private:
	int rows;
	int cols;
	std::vector <Enemy> enemies;
public:
	Level(int r, int c)
		: rows(r), cols(c)
	{
	}
	bool add(Enemy e)
	{
		if (e.get_x() < 0 || e.get_x() >= cols || e.get_y() < 0 || e.get_y() >= rows)
		{
			return false;
		}
		enemies.push_back(e);
		return true;
	}
	void step(int dx, int dy)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			int new_x = enemies[i].get_x() + dx;
			int new_y = enemies[i].get_y() + dy;

			if (new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows)
			{
				enemies[i].move(dx, dy);
			}
		}

	}
	void print() const
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			std::cout << enemies[i].get_name() << " " << enemies[i].get_x() << " " << enemies[i].get_y() << " " << enemies[i].get_health() 
				<< " " << std::endl;
		}

	}
	void draw() const
	{
		std::vector<std::vector<char>> board(
			rows + 2,
			std::vector<char>(cols + 2, ' ')
		);

		for (int i = 0; i < rows + 2; i++)
		{
			for (int j = 0; j < cols + 2; j++)
			{
				if (i == 0 || i == rows + 1 ||
					j == 0 || j == cols + 1)
				{
					board[i][j] = '#';
				}
			}
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			int x = enemies[i].get_x();
			int y = enemies[i].get_y();

			board[y + 1][x + 1] = enemies[i].get_name()[0];
		}

		for (int i = 0; i < rows + 2; i++)
		{
			for (int j = 0; j < cols + 2; j++)
			{
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Level cave(5, 10);

	cave.add(Enemy("Gnome", 1, 1));

	std::cout << cave.add(Enemy("Troll", 8, 3)) << ": " << cave.add(Enemy("Bat", 12, 2)) << std::endl;

	cave.step(1, 1);
	cave.print();

	cave.step(1, 1);
	cave.print();

	cave.draw();

	return 0;
}