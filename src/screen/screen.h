#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.

class Screen {
public:
	enum class Direction : unsigned char
	{
	    HOME,
		FORWARD,
		BACK,
		UP,
		DOWN,
		END
	};
	// Screen's constructor
	Screen( string::size_type height = 40, string::size_type width = 8, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	/*ex 4.2 the const here guarantees that the function will not 	
	change any member variables or call any non const member functions
	*/

	// get the Screen's width
	string::size_type width() const { return width_; }

	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);

	//ex 4.3
	void move(Direction dir){

		switch (dir)
		{
			case Direction::HOME : home(); break;
			case Direction::FORWARD : forward(); break;
			case Direction::BACK : back(); break;
			case Direction::UP : up(); break;
			case Direction::DOWN : down(); break;
			case Direction::END : end(); break;
			default: cerr<<"Invalid dir specified";break;
		}

		return;
	}


	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }
	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);

	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );

	/* ex 4.2 the const here guarantees that the function will not 	
	change the parameter passed to it-passed by const reference
	this is done as to avoid the overhead of passing by value
	whilst retaining the same safety- not allowing the original value to be changed

	*/


	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');
	/*
	ex 4.2
		the string:: here indicates size_type being a part of the string namespace 
		which in itself is part of the std namespace
		the need for an explicit size type as opposed 
		to an unsigned int etc. is to ensure cross platform compatability
		--depending on the OS and architecture the size type of string will vary
	*/


	/*
	ex 4.5
		the draw square functionality can be implemented fairly
		easily using the existing interface


		This function would probably be more suitable in an additional library of shape drawing functions 
		that builds on top of the functionality of Screen.

		The primary functionality of the Screen class is to allow for easy navigation and setting of characters on the screen.
		Therefore, this function would just be unnecessary from the point of view of someone using the screen class for its core functionality-bloat.

		However, if the functionality of the screen class is to have some basic ability to draw shapes, then including only the functionality of square drawing
		seems like an incomplete implementation and as such the function should be omitted as to present a more consistent definition of the functionality of the screen class

		An additional graphics library built 'on top of' screen would be better suited.

	*/
	void drawSquare(string::size_type row, string::size_type col,string::size_type length)
	{
		if ( !(checkRange(row+length-1,col+length-1)&& checkRange(row,col)) )
		{
			cerr<<"Screen not big enough for this square at the given position/ Invalid start point!"<<endl;

		}else
		{
			move(row,col);
			//draw horizontal
			for (int j=0;j<2;j++)
			{
				for (int i=0;i<length-1;i++)
				{
					set('X');
					forward();
				}
				set('X');
				move(row+length-1,col);
			}
			move(row,col);
			for (int j=0;j<2;j++)
			{
				for (int i=0;i<length-1;i++)
				{
					set('X');
					down();
				}
				set('X');
				move(row,col+length-1);
			}


		}

	}

	/*
	ex 4.6
	
	1)a 2d char array would likely make indexing easier instead of having to use
	(cursor%width)

	2) changing the interface is problematic as this would affect any other code 
	that relies on the current interface-> changes would be needed in code outside
	 of the class as well.

	3) Changing the implementation, provided that behaviour remains the same is fine
	as code that depends on this class relies more on a consistent input-output relationship 
	than the underlying code itself; which may change due to optimization etc.



	*/


	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;
	/* ex 4.2
	 the const here is used to declare
	 a member that will not/can not change in value

	*/
	// private member functions
	string::size_type remainingSpace() const;
	string::size_type row() const;

	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
};


#endif

