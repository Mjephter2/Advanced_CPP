#include <iostream>
#include <string>
using namespace std;

class Rat {
    int n;
    int d;

    public:
        // Default Constructor
        // provided unless explicitly provided
        Rat() : n(0), d(1) {}

        // Constructor
        Rat(int num, int denum) : n(num), d(denum) {}

        Rat operator+(const Rat& other)
        {
            return Rat(n * other.d + other.n * d, d * other.d);
        }

        Rat operator-(const Rat& other)
        {
            return Rat(n * other.d - other.n * d, d * other.d);
        }

        Rat operator*(const Rat& other)
        {
            return Rat(n * other.n, d * other.d);
        }

        Rat operator/(const Rat& other)
        {
            return Rat(n * other.d, d * other.n);
        }
};

int main(int argc, char** argv)
{
    Rat my_rat1 = Rat(1,2);
    Rat my_rat2 = Rat(2,1);
    return 0;
}