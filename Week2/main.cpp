#include <iostream>
using namespace std;

typedef double (*Func) (double);

double square(double x) { return x * x;}

double integrate(Func f, double a, double b)
{
    return f(b) - f(a);
}

int main(int argc, char **argv)
{
    cout << integrate(square, 1, 5) << endl;
    return 0;
}