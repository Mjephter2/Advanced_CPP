#include <iostream>
using namespace std;

void swap(int* ip, int* jp) 
{
    int temp = *ip;
    *ip = *jp;
    *jp = temp;
}

int main(int argc, char **argv)
{
    int i = 10, j = 20;
    cout << "Before swap: i = " << i << " j =  " << j << endl;
    swap(i, j);
    cout << "After swap : i = " << i << " j =  " << j << endl;
    return 0;
}