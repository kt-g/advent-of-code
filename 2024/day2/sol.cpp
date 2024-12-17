#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

vector<int> split(string str, char delimiter) {
    vector<int> res;
    string s;

    stringstream ss(str);
    while(getline(ss, s, delimiter)) {
        res.push_back(stoi(s));
    }

    return res;

}

bool isValid(vector<int> arr) {
    int n = arr.size();
    int inc = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (abs(diff) > 3 || abs(diff) < 1) {
            return false;
        }
        if ((diff > 0) != (inc > 0)) {
            return false;
        }
    }
    return true;

}

void part1() {
    ifstream infile("input.txt");
    string str;
    int count = 0;

    while(getline(infile, str)) {
        vector<int> arr = split(str, ' ');
        if (isValid(arr)) {
            count++;
        }
    }
    cout << "Count: " << count << endl;
}


void part2() {
    ifstream infile("input.txt");
    string str;
    int count = 0;

    while(getline(infile, str)) {
        vector<int> arr = split(str, ' ');
        int n =  arr.size();
        bool valid = false;

        auto remove = [&](int i) {
            vector<int> temp = arr;
            temp.erase(temp.begin() + i);
            if (isValid(temp)) {
                valid = true;
            }
        };

        remove(0);
        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if (abs(diff) > 3 || abs(diff) < 1) {
                remove(i);
                remove(i + 1);
                break;
            }
            if (i + 2 < n) {
                int diff2 = arr[i + 2] - arr[i + 1];
                if ((diff2 > 0) != (diff > 0)) {
                    remove(i);
                    remove(i + 1);
                    remove(i + 2);
                    break;
                }
            }
        }

        if (valid) {
            count++;
        }
        
    }
    cout << "Count: " << count << endl;
}

int main() {
    part1();
    part2();
    return 0;
}