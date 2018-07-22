
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

	screen1.move(1,3);

	for (int i=0;i<6;i++)
	{
		screen1.set('*');
		screen1.forward();
		screen1.set('*');
		screen1.back();
		screen1.down();
	}

	for (int i=0;i<3;i++)
	{
		screen1.set('*');
		screen1.back();
	}

	screen1.display();
	return 0;

}