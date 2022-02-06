#include <iostream>
using namespace std;

int main(int argc, char **argv){
    // assignment / arithmetic
    int a = 5; 
    int b = a;
    cout << "a = " << a << " b = " << b << endl; // a = 5 b = 5
    a += b;
    cout << "a = " << a << " b = " << b << endl; // a = 10 b = 5
    a -= b;
    cout << "a = " << a << " b = " << b << endl; // a = 5 b = 5
    a *= b;
    cout << "a = " << a << " b = " << b << endl; // a = 25 b = 5
    a /= b;
    cout << "a = " << a << " b = " << b << endl; // a = 5 b = 5
    a %= b;
    cout << "a = " << a << " b = " << b << endl; // a = 0 b = 5
    a &= b; // bitwise AND
    cout << "a = " << a << " b = " << b << endl; // a = 0 b = 5
    a |= b; // bitwise OR
    cout << "a = " << a << " b = " << b << endl; // a = 5 b = 5
    a ^= b; // bitwise XOR
    cout << "a = " << a << " b = " << b << endl; // a = 0 b = 5
    a = 2;
    a <<= b; // bitwise left shift
    cout << "a = " << a << " b = " << b << endl; // a = 64 b = 5
    a >>= b; // bitwise right shift
    cout << "a = " << a << " b = " << b << endl; // a = 2 b = 5
    //cout << ~a << endl; // -3 bitwise NOT (?)

    // logical
    bool b1 = false;
    bool b2 = true;
    cout << !b1 << endl; // 1 (true)
    cout << (b1 && b2) << endl; // 0 (false)
    cout << (b1 || b2) << endl; // 1 (true)

    // comparison
    a = 2;
    cout << (a == b) << endl; // 0
    cout << (a != b) << endl; // 1
    cout << (a < b) << endl; // 1
    cout << (a > b) << endl; // 0
    cout << (a <= b) << endl; // 1
    cout << (a >= b) << endl; // 0

    // other
    // comma operator
    int n = 1;
    int m = (++n, std::cout << "n = " << n << '\n', ++n, 2 * n); // n = 2
    cout << "m = " << (++m, m) << '\n'; // m = 7
    // ternary operator
    cout << ((m < n) ? "m is less than n" : "m is greater than or equal to n") << endl;
    
    return 0;
}