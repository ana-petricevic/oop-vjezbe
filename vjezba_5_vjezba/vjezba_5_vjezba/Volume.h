#ifndef VOLUME_H
#define VOLUME_H

#include <cassert>

class Volume {
private:
	int level;
	int previous_level;

	static int clamp(int val)
	{
		if (val < 0)
			return 0;

		if (val > 100)
			return 100;
		return val;
	}
	bool valid() const
	{
		return level >= 0 && level <= 100;

	}
public:
	Volume(int L) : level(clamp(L)), previous_level(clamp(L))
	{
		assert(valid());
	}
	Volume () : Volume (50){}

	void up(int step = 10)
	{
		level = clamp(level + step);
		assert(valid());
	}
	void down(int step = 10)
	{
		level = clamp(level - step);
		assert(valid());
	}
	void mute()
	{
		if (level != 0)
		{
			previous_level = level;

		}
		level = 0;
		assert(valid());
	}
	void unmute()
	{
		level = previous_level;
		assert(valid());
	}
	int get() const
	{
		return level;
	}
};
#endif
