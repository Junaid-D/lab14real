
#include <iostream>
#include "Screen.h"


int main()
{
	Screen screen1(6,6,' ');

	for (int i=0;i<6;i++)
	{
		screen1.set('*');
		screen1.forward();
	}

	screen1.move(2,3);

	for (int i=0;i<4;i++)
	{
		screen1.set('*');
		screen1.forward();
		screen1.set('*');
		screen1.back();
		screen1.down();
	}
	screen1.forward();
	for (int i=0;i<4;i++)
	{
		screen1.set('*');
		screen1.back();
	}

	screen1.display();
	return 0;

}