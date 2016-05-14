#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int l = str.length();
    int last;
    if(str.length() == 1){
        cout << str << str;
        return 0;
    }
    for(int i = 0; i < str.length()-1; i++){
        bool palindrome = true;
        for(int j = 0; j <= i/2; j++){
            char a = str[l-1-(i+1)/2-j];
            char b = str[l-1-i/2+j];
            if(a != b){
                palindrome = false;
                break;
            }
        }
        if(palindrome){
            last = i;
        }
    }
    cout << str;
    for(int i = l-1-1-last; i >= 0; i--){
        cout << str[i];
    }
    return 0;
}