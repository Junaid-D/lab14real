// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{	//ex 4.1 comments
	auto myScreen = Screen{6,6};
	//default pos is top left
	myScreen.forward();
	myScreen.set('*');
	myScreen.down();
	myScreen.set('*');
	myScreen.move(3,3);
	myScreen.set("---");//input a block of symbols

	myScreen.display();
	//print screen
	cout << endl;

	myScreen.reSize(16,16);// resize screen to 16x16
	myScreen.display();
	myScreen.clear(' ');// clear- use space as placeholder char

	myScreen.move(7,7);
	myScreen.set("BIG");
	myScreen.move(8,5);
	myScreen.set("SCREEN");
	myScreen.display();

	return 0;
}

