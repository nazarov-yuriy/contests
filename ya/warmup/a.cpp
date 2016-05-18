#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    char last_v = 0, last_c = 0;
    for (int i = str.length(); i >= 0; i--) {
        switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                last_v = str[i];
                break;
            default:
                last_c = str[i];
                break;
        }
    }
    if (last_v == 0) {
        cout << "Consonant";
    } else if (last_c == 0) {
        cout << "Vowel";
    } else if (last_v < last_c) {
        cout << "Consonant";
    } else {
        cout << "Vowel";
    }
    return 0;
}