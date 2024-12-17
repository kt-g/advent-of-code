#include <bits/stdc++.h>
using namespace std;

bool validIndex(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}


void part1(vector<string> board) {
    const string word = "XMAS";
    int m = board.size();
    int n = board[0].length();

    auto searchAdj = [&](int row, int col) {
        int c = 0;

        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int dir = 0; dir < 8; dir++) {
            int i, x, y;
            x = row + dx[dir], y = col + dy[dir];

            for (i = 1; i < 4; i++) {
                if (!validIndex(x, y, m, n) || board[x][y] != word[i]) {
                    break;
                }
                x += dx[dir], y += dy[dir];
            }
            c += (i == 4);
        }
        return c;
    };

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X') {
                count += searchAdj(i, j);
            }
        }
    }

    cout << "Count: " << count << endl;
}


void part2(vector<string> board){
    int m = board.size();
    int n = board[0].length();
    const string mas = "MAS";
    const string sam = "SAM";


    auto searchX = [&] (int row, int col) {
        string diag1;
        string diag2;
        if (!validIndex(row + 1, col - 1, m, n) || !validIndex(row - 1, col + 1, m, n)) {
            return false;
        }

        diag1 += board[row + 1][col - 1];
        diag1 += board[row][col];
        diag1 += board[row - 1][col + 1];

        if (diag1.compare(mas) != 0 && diag1.compare(sam) != 0) {
            return false;
        }

        if (!validIndex(row - 1, col - 1, m, n) || !validIndex(row + 1, col + 1, m, n)) {
            return false;
        }

        diag2 += board[row - 1][col - 1];
        diag2 += board[row][col];
        diag2 += board[row + 1][col + 1];

        if (diag2.compare(mas) != 0 && diag2.compare(sam) != 0) {
            return false;
        }

        return true;

    };

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'A') {
                count += searchX(i, j);
            }
        }
    }

    cout << "Count: " << count << endl;

}

int main() {
    int m = 140;
    vector<string> board(m);
    for (string& row: board) {
        cin >> row;
    }

    part1(board);
    part2(board);

    return 0;
}