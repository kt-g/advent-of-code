#include <bits/stdc++.h>
using namespace std;

vector<long> split(string str, char delimiter) {
    vector<long> res;
    string s;

    stringstream ss(str);
    while(getline(ss, s, delimiter)) {
        res.push_back(stol(s));
    }
    return res;

}

long tenPow(int n) {
    long res = 1;
    for (int i = 0; i < n; i++) {
        res *= 10;
    }
    return res;
}

bool addOperation(vector<long> arr, long target, int curr) {
    if (curr == 1) {
        return target == arr[1];
    }
    if (target < arr[curr]) {
        return false;
    }
    else {
        long c = arr[curr];
        if (addOperation(arr, target - c, curr - 1)) {
            return true;
        }
        if (target % c == 0 && addOperation(arr, target / c, curr - 1)) {
            return true;
        }
        // Part 2
        if ((target - c) % tenPow(to_string(c).length()) == 0 && addOperation(arr, (target - c) / tenPow(to_string(c).length()), curr - 1)) {
            return true;
        }
        return false;
    }
}

void part1(vector<string> input) {
    long sum = 0;
    for (string& row: input) {
        if (row.empty()) {
            break;
        }
        vector<long> arr = split(row, ' ');
        long target = arr[0];
        if (addOperation(arr, target, arr.size() - 1)) {
            sum += target;
        }
    }

    cout << "Sum: " << sum << endl;
}

int main() {
    int m = 850;
    vector<string> input(m);
    string row;

    for (string& row: input) {
        getline(cin, row);
   }

    part1(input);
    return 0;
}