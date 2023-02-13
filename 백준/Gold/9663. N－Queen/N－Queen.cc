#include <cstring>
#include <iostream>

static int board[15];
static int n;

static int n_queen(int row) {
    if (row == n) {
        return 1;
    }

    int count = 0;

    for (board[row] = 0; board[row] < n; board[row]++) {
        int i = 0;
        for (i = 0; i < row; i++) {
            const int &bi = board[i];
            if (board[row] == bi + (row - i) || board[row] == bi - (row - i) ||
                board[row] == bi) {
                break;
            }
        }

        if (i == row) {
            count += n_queen(row + 1);
        }
    }

    return count;
}

int main(void) {
    std::cin >> n;
    std::cout << n_queen(0);
    return 0;
}
