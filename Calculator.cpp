//============================================================================
//Calculator.cpp
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;
int gcd(int a, int b) {
    while (b != 0)  {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
class Fraction{

    public:
    int numerator;
    int denominator;
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }


    void simplify(){
        int divisor = gcd(abs(numerator), abs(denominator));
        this->numerator /= divisor;
        this->denominator /= divisor;
    }

};

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

Fraction addition(Fraction one, Fraction two){
    int denominator = lcm(one.denominator, two.denominator);
    int numerator = one.numerator*(denominator/one.denominator) + two.numerator*(denominator/two.denominator);
    Fraction result(numerator, denominator);
    result.simplify();
    return result;
}
Fraction subtraction(Fraction one, Fraction two){
    two.numerator *= -1;
    return addition(one, two);
}
Fraction multiplication(Fraction one, Fraction two){
    int numerator = one.numerator*two.numerator;
    int denominator = one.denominator*two.denominator;
    Fraction result(numerator, denominator);
    result.simplify();
    return result;
}
Fraction division(Fraction one, Fraction two){
    two.numerator = two.numerator + two.denominator;  // x now becomes 15
    two.denominator = two.numerator - two.denominator;  // y becomes 10
    two.numerator = two.numerator - two.denominator;
    return multiplication(one, two);

}
void equality(Fraction one, Fraction two){
    one.simplify();
    two.simplify();
    if (one.numerator == two.numerator && one.denominator == two.denominator){
        cout << "the two fractions are equal";
    }
    else {
        cout << "the two fractions are not equal";
    }
}
void greaterThan(Fraction one, Fraction two){
    int denominator = lcm(one.denominator, two.denominator);
    int one_numerator = one.numerator*(denominator/one.denominator);
    int two_numerator = two.numerator*(denominator/two.denominator);
    if (one_numerator > two_numerator) {
        cout << one.numerator << "/" << one.denominator << " is greater than " << two.numerator << "/" << two.denominator;
    }
    else if (one_numerator == two_numerator){
        cout << one.numerator << "/" << one.denominator << " is equal to " << two.numerator << "/" << two.denominator;
        }
    else{
        cout << one.numerator << "/" << one.denominator << " is less than " << two.numerator << "/" << two.denominator;
    }
}
void display(Fraction result) {
    cout<<result.numerator<<"/"<<result.denominator;
}
int main() {
	Fraction frac1(1,2);
	Fraction frac2(5,8);
	Fraction result(1,1);
	result = addition(frac1, frac2);
	cout << "addition ";
	display(result);
	cout << "\n\n";

	result = subtraction(frac1, frac2);
	cout << "subtraction ";
	display(result);
	cout << "\n\n";

	result = multiplication(frac1, frac2);
	cout << "multiplication ";
	display(result);
	cout << "\n\n";

	result = division(frac1, frac2);
	cout << "division ";
	display(result);
	cout << "\n\n";

	equality(frac1, frac2);
	cout << "\n\n";

	greaterThan(frac1, frac2);
	cout << "\n\n";
}
