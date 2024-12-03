#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define MAX_LEN = 1000;

void part1() {
    int distance = 0;
    vector<int> left, right;

    ifstream infile("day1.txt");

    string l, r;
    while (infile >> l >> r) {
        left.push_back(stoi(l));
        right.push_back(stoi(r));
    }
    infile.close();
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++) {
        distance += abs(left[i] - right[i]);
    }
    cout << "Distance: " << distance << endl;
}

void part2() {
    int score = 0;

    ifstream infile("day1.txt");

    unordered_map<string, int> map;
    string l, r;
    vector<string> A;

    while(infile >> l >> r) {
        if (map.find(r) == map.end()) {
            map[r] = 1;
        }
        else {
            map[r]++;
        }
        A.push_back(l);    
    }
    infile.close();

    for (string a:A) {
        score += stoi(a) * map[a];
    }
    cout << "Score: " << score << endl;
} 

int main() {
    part1();
    part2();
    return 0;
}
