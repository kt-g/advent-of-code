#include <bits/stdc++.h>
using namespace std;

int parseInt(string str, int i) {
    if (str[i] == ' ') {
        return 0;
    }
    return atoi(str.substr(i).c_str());
}

int checkMul(string str, int i) {
    string start = "mul(";
    if (start.compare(str.substr(i, 4)) != 0) {
        return 0;
    }
    i += 4;
    int x = parseInt(str, i);
    i += to_string(x).length();
    if (str[i] != ',') {
        return 0;
    }
    i++;
    int y = parseInt(str, i);
    if (str[i + to_string(y).length()] != ')') {
        return 0;
    }
    return x * y;
}

void part1(string str) {
    int n = str.length();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'm') {
            sum += checkMul(str, i);
        }
    }
    cout << "Sum: " << sum << endl;

}



void part2(string str) {
    int n = str.length();
    int sum = 0;
    bool mul = true;

    auto checkDo = [&](int i) {
        string enable = "do()";
        string disable = "don't()";
        if (enable.compare(str.substr(i, 4)) == 0) {
            mul = true;
        }
        if (disable.compare(str.substr(i, 7)) == 0) {
            mul = false;
        }
    };

    for (int i = 0; i < n; i++) {
        if (str[i] == 'd') {
            checkDo(i);
        }
        if (str[i] == 'm' && mul) {
            sum += checkMul(str, i);
        }
    }

    cout << "Sum2: " << sum << endl;

}

int main() {
    string str;
    char c;
    while (scanf("%c", &c) != EOF) {
        str += c;
    }
    str += "wwwwwwwwwwww";

    part1(str);
    part2(str);
    
    return 0;
}