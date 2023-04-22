#include <iostream>
#include <string>
#include <vector>

int main(void) {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int score[1001][1001] = {};
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                score[i][j] = score[i - 1][j - 1] + 1;
            } else {
                score[i][j] = std::max(score[i][j - 1], score[i - 1][j]);
            }
        }
    }
    std::cout << score[s1.size()][s2.size()];
    return 0;
}
