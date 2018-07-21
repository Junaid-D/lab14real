// complex.cpp
// Multiplying complex numbers

#include <iostream>	// contains the definition of cout, endl
#include <complex>	// contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

int main()
{
	using cFloat=complex<float>;//alias for complex of <float>

	auto num1 = cFloat{2.0, 2.0};  // use auto for type deduction
	auto num2 = cFloat{4.0, -2.0}; // use uniform initialisation syntax (curly braces)

	auto answer = num1 * num2; // type deduced for 'answer' is: complex<float>

	cout << "The answer is: " << answer << endl;
	cout << "Or in a more familiar form: " << answer.real() 
			<< " + " << answer.imag() << "j" 
			<< endl	<< endl;

	// answer++;
	/*no overloading of the ++ operator has ben implemented for the complex class
	the decision not to implement the operator overloading is likely because its usage would be ambiguous
	should it increment the real part, imaginary part, or both?
	*/
	return 0;
}
