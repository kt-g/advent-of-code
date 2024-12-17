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

bool correct(vector<int> arr, unordered_map<int, vector<int>> graph) {
    set<int> seen;

    for (int& x: arr) {
        for (int& y: graph[x]) {
            if (seen.find(y) != seen.end()) {
                return false;
            }
        }
        seen.insert(x);
    }
    return true;
}

void part1() {
    unordered_map<int, vector<int>> graph;
    int sum = 0;

    string line;
    bool order = true;
    while(getline(cin, line)) {
        if(line.empty()) {
            order = false;
            continue;
        }
        if (order) {
            vector<int> arr = split(line, '|');
            graph[arr[0]].push_back(arr[1]);
        } 
        else {
            vector<int> arr = split(line, ',');
            
            if (correct(arr, graph)) {
                sum += arr[arr.size()/2];
            }
        }
    }

    cout << "Sum: " << sum << endl;
}

void part2() {
    unordered_map<int, vector<int>> graph;
    int sum = 0;

    auto cmp = [&] (int a, int b) {
        for (int& x: graph[b]) {
            if (x == a) {
                return true;
            }
        }
        return false;
    };

    string line;
    bool order = true;
    while(getline(cin, line)) {
        if(line.empty()) {
            order = false;
            continue;
        }
        if (order) {
            vector<int> arr = split(line, '|');
            graph[arr[0]].push_back(arr[1]);
        } 
        else {
            vector<int> arr = split(line, ',');
            if(!correct(arr, graph)) {
                sort(arr.begin(), arr.end(), cmp);
                sum += arr[arr.size()/2];
            }
        }
    }

    cout << "Sum: " << sum << endl;
}

int main() {
    part1();
    part2();
    return 0;
}