#include <iostream>

using namespace std;

/*
A="B=';";
B='A=";?$(B,1,3)+A+$(B,3,2)+$(A,1,3)+B+$(A,3,2)+$(B,5,50)';
?$(B,1,3)+A+$(B,3,2)+$(A,1,3)+B+$(A,3,2)+$(B,5,50)
 */

int main() {
    cout << "A=\"B=';\";";
    cout << "B='A=\";?$(B,1,3)+A+$(B,3,2)+$(A,1,3)+B+$(A,3,2)+$(B,5,50)';";
    cout << "?$(B,1,3)+A+$(B,3,2)+$(A,1,3)+B+$(A,3,2)+$(B,5,50)";
    return 0;
}