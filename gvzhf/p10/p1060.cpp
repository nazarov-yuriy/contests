#include <iostream>

using namespace std;

uint16_t x[16] = {
        0b0000000000010011,
        0b0000000000100111,
        0b0000000001001110,
        0b0000000010001100,

        0b0000000100110001,
        0b0000001001110010,
        0b0000010011100100,
        0b0000100011001000,

        0b0001001100010000,
        0b0010011100100000,
        0b0100111001000000,
        0b1000110010000000,

        0b0011000100000000,
        0b0111001000000000,
        0b1110010000000000,
        0b1100100000000000
};

uint16_t flip(uint16_t state, uint16_t action) {
    for (int i = 0; i < 16; i++) {
        if (action & (1U << i)) state ^= x[i];
    }
    return state;
}

int bits(uint16_t state) {
    int res = 0;
    for (int i = 0; i < 16; i++) {
        res += (state & (1U << i)) != 0;
    }
    return res;
}

int main() {
    uint16_t state = 0;
    string str;
    for (int i = 0; i < 4; i++) {
        cin >> str;
        state <<= 4;
        if (str[0] == 'w') state |= 0b1000;
        if (str[1] == 'w') state |= 0b0100;
        if (str[2] == 'w') state |= 0b0010;
        if (str[3] == 'w') state |= 0b0001;
    }
    int min_bits = 17;
    for (uint32_t i = 0; i < 65536; i++) {
        uint16_t res = flip(state, i);
        if (0 == res || 0xffffU == res) {
            min_bits = min(min_bits, bits(i));
        }
    }
    if (min_bits < 17)
        cout << min_bits;
    else
        cout << "Impossible";
    return 0;
}