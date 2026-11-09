#include <iostream>
#include "Volume.h"

int main()
{
	Volume v;

	std::cout << v.get() << std::endl;
	v.up();
	v.up(60);
	std::cout << v.get() << std::endl;

	v.mute();
	std::cout << v.get() << std::endl;

	v.unmute();
	std::cout << v.get() << std::endl;

	Volume w(-20);
	w.down();
	std::cout << w.get() << std::endl;

	return 0;
}