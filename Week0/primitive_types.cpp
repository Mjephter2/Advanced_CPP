/**
 * review of some of the C++ primitive data types
 * reference: https://en.cppreference.com/w/cpp/language/types
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * @brief computes the binary representation of integer x
 * 
 * @param x: an integer value
 * @param is_signed: indicates whether the value is signed or not
 * @return:  string representing the binary representation
 */
string bin_rep(int x, bool is_signed = false)
{
    if(x==0) return "0";
    bool neg = false;
    string rep = "";
    if (x < 0)
    {
        neg = true;
        x *= -1; 
    }
    while(x > 0)
    {
        rep = to_string(x%2) + rep;
        x /= 2;
    }
    return is_signed ? (neg ? "1" + rep : "0" + rep) : rep;
}

int main(int argc, char** argv)
{
    // signed / unsigned integers
    cout << "unsigned representation of " << 131 << " \t= " << bin_rep(131, false) << std::endl;
    cout << "signed representation of " << 131 << " \t= " << bin_rep(131, true) << std::endl;
    cout << "unsigned representation of " << -131 << " = " << bin_rep(-131, false) << std::endl;
    cout << "signed representation of " << -131 << " \t= " << bin_rep(-131, true) << std::endl;
    // short vs long vs long long
    // short : optimized for space and width of at least 16 bits
    // long  : width of at least 32 bits
    // long long : width of at least 64 bits
    cout << "Maximum short value 2^16 - 1: " << pow(2, 16) - 1 << std::endl; // 65535
    cout << "Maximum long value 2^32 - 1: " << (long)pow(2, 32) - 1 << std::endl; // 4294967295
    cout << "Maximum short value 2^64 - 1: " << (long long)pow(2, 64) - 1 << std::endl; // 9223372036854775806

    // boolean type
    // bool : either true or false
    cout << "Size of a boolean variable is " << sizeof(bool) << " byte." << endl;
    cout << (5 <= 4) << endl; // 0 (false)
    cout << (4 <= 5) << endl; // 1 (true)

    // Character types
    // char : type for character representation which can be most efficiently processed on the target system
    // wchar_t : type for wide character representation. Required to be large enough to represent any supported character code point
    // * char16_t * : type for UTF-16 character representation, required to be large enough to represent any UTF-16 code unit (16 bits).
    // * char32_t * : type for UTF-32 character representation, required to be large enough to represent any UTF-32 code unit (32 bits).
    // * char8_t *  : type for UTF-8 character representation, required to be large enough to represent any UTF-8 code unit (8 bits).
    cout << (1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)) << endl; // 1 (true)
    char ch_0 = '0';
    char ch_1 = '1';
    char ch_2 = '2';
    cout << ch_0 << ch_1 << ch_2 << endl; // 012

    // Floating-point types
    // float : single precision
    // double : double precision
    // long double : extended precision
    // special values:
    //      INFINITY
    //      negative zero : -0.0
    //      NaN : not-a-number
    cout << INFINITY << endl; // inf
    cout << isinf(1.0/0.0) << endl; // 1 (true)
    return 0;
}