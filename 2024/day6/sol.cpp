#include <bits/stdc++.h>
using namespace std;

enum Direction {UP, DOWN, LEFT, RIGHT};

void turn(enum Direction* dir) {
    switch(*dir) {
        case UP:
            *dir = RIGHT;
            break;
        case RIGHT:
            *dir = DOWN;
            break;
        case DOWN:
            *dir = LEFT;
            break;
        case LEFT:  
            *dir = UP;
            break;
    } 
}

void walk(int* i, int* j, enum Direction* dir, vector<string> board) {
    int new_i = *i;
    int new_j = *j;
    switch(*dir) {
        case UP:
            new_i = *i - 1;
            break;
        case DOWN:
            new_i = *i + 1;
            break;
        case LEFT:
            new_j = *j - 1;
            break;
        case RIGHT:
            new_j = *j + 1;
            break;
    }
    if (board[new_i][new_j] == '#') {
        turn(dir);
    } else{
        *i = new_i;
        *j = new_j;
    }
}

set<pair<int, int>> part1(vector<string> board) {
    enum Direction dir = UP;
    set<pair<int, int>> visited;

    int m = board.size();
    int n = board[0].length();
    int start_i;
    int start_j;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == '^') {
                start_i = i;
                start_j = j;
                break;
            }
        }
    }

    while(start_i >= 0 && start_i < m && start_j >= 0 && start_j < n) {
        visited.insert({start_i, start_j});
        walk(&start_i, &start_j, &dir, board);
    }

    cout << "Visited: " << visited.size() << endl;
    return visited;
}

void part2(vector<string> board) {
    int count = 0;
    int m = board.size();
    int n = board[0].length();
    int start_i;
    int start_j;
    enum Direction dir = UP;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == '^') {
                start_i = i;
                start_j = j;
                break;
            }
        }
    }

    int temp_i = start_i;
    int temp_j = start_j;

    auto consider = [&] (int i, int j) {
        board[i][j] = '#';
        // cout << "Considering: " << i << " " << j << endl;
        for (int k = 0; k < 25000; k++) {
            // cout << k << endl;
            walk(&temp_i, &temp_j, &dir, board);
            if (temp_i < 0 || temp_i >= m || temp_j < 0 || temp_j >= n) {
                board[i][j] = '.';
                // cout << k << endl;
                // cout << temp_i << " " << temp_j << endl;
                return;
            }
        }
        board[i][j] = '.';
        count++;
    };

    set<pair<int, int>> visited = part1(board);

    for (pair<int, int> p: visited) {
        temp_i = start_i;
        temp_j = start_j;
        dir = UP;
        consider(p.first, p.second);
    }

    cout << "Count: " << count << endl;


}

int main() {
    int m = 130;
    vector<string> board(m);
    for (string& row: board) {
        cin >> row;
        // cout << row << endl;
    }

    // part1(board);
    part2(board);

    return 0;
}