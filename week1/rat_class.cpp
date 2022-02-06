#include <iostream>
#include <string>
using namespace std;

class Rat {
    int n;
    int d;

    public:
        // constructors

        // Default Constructor
        // provided unless explicitly provided
        Rat() : n(0), d(1) {}

        Rat(int num, int denum) : n(num), d(denum) {}

        // conversion constructor
        Rat(int num) : n(num), d(1) {}

        // getters
        int getN()
        {
            return n;
        }

        int getD()
        {
            return d;
        }

        // setters
        void setN(int n){
            this->n = n;
        }
        void setD(int d){
            this->d = d;
        }

        // operations on rats
        // overloaded method to add two rats
        Rat operator+(const Rat& other)
        {
            return Rat(n * other.d + other.n * d, d * other.d);
        }
        // overloaded method to substract two rats
        Rat operator-(const Rat& other)
        {
            return Rat(n * other.d - other.n * d, d * other.d);
        }
        // overloaded method to multiply two rats
        Rat operator*(const Rat& other)
        {
            return Rat(n * other.n, d * other.d);
        }
        // overloaded method to divide two rats
        Rat operator/(const Rat& other)
        {
            return Rat(n * other.d, d * other.n);
        }

        // overloaded method to print to cout
        // keyword friend grants access to class variables
        friend ostream& operator<<(ostream& os, const Rat& rat);
}; // end class Rat

ostream& operator<<(ostream& os, const Rat& rat)
{
    os << ((rat.d == 1) ? to_string(rat.n): to_string(rat.n) + "/" + to_string(rat.d));
    return os;
}

int main(int argc, char** argv)
{
    Rat my_rat1 = Rat(1,2);
    Rat my_rat2 = Rat(2,1);
    cout << my_rat1 << " + " << my_rat2 << " = " << my_rat1 + my_rat2 << endl;
    cout << my_rat1 << " - " << my_rat2 << " = " << my_rat1 - my_rat2 << endl;
    cout << my_rat1 << " * " << my_rat2 << " = " << my_rat1 * my_rat2 << endl;
    cout << "(" << my_rat1 << ")/(" << my_rat2 << ") = " << my_rat1 / my_rat2 << endl;
    cout << my_rat1 + 3 << endl; // conversion constructor usage
    cout << (my_rat1 * 2) - 2 + Rat(-1, 4) << endl; // operations chaining
    return 0;
}