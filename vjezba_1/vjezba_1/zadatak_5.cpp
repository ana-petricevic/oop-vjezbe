#include <iostream>
#include <cmath>

struct Point
{
	double x;
	double y;
};
void move_by(Point* p, double dx, double dy)
{
	p->x = p->x + dx;
	p->y = p->y + dy;
}
double dist(const Point* a, const Point* b)
{
	double dx{ a->x - b->x };
	double dy{ a->y - b->y };

	return std::sqrt(dx * dx + dy * dy);
}

void move_by_ref(Point& p, double dx, double dy)
{
	p.x = p.x + dx;
	p.y = p.y + dy;
}
double dist_ref(const Point& a, const Point& b)
{
	double dx{ a.x - b.x };
	double dy{ a.y - b.y };

	return std::sqrt(dx * dx + dy * dy);
}

int main()
{
	Point p1{ 2.0, 3.0 };

	std::cout << "Pocetna tocka: " << p1.x << ", " << p1.y << std::endl;

	move_by(&p1, 2.0, -1.0);

	std::cout << "Nakon move_by: " << p1.x << ", " << p1.y << std::endl;

	Point p2{ 5.0, 5.0 };

	std::cout << "Udaljenost pomocu pointera: " << dist(&p1, &p2) << std::endl;

	move_by_ref(p1, -1.0, 2.0);

	std::cout << "Nakon move_by_ref: " << p1.x << ", " << p1.y << std::endl;

	std::cout << "Udaljenost pomocu reference: " << dist_ref(p1, p2) << std::endl;

	Point points[]{ {3.0, 4.0}, {1.0, 1.0}, {-2.0, 2.0}, {5.0, 1.0}, {-1.0, -1.0} };

	Point origin{ 0.0, 0.0 };

	int indeks_najblize{ 0 };

	double najmanja_udaljenost{ dist(&points[0], &origin) };

	for (int i{ 1 }; i < 5; i++)
	{
		double trenutna_udaljenost{ dist(&points[i], &origin) };

		if (trenutna_udaljenost < najmanja_udaljenost)
		{
			najmanja_udaljenost = trenutna_udaljenost;
			indeks_najblize = i;
		}
	}
	std::cout << "Tocka najblize ishodistu: " << "(" << points[indeks_najblize].x << ", " << points[indeks_najblize].y << ")" << std::endl;

	return 0;

}