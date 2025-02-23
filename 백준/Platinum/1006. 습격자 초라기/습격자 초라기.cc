#include <iostream>

static const int MAX_DISTRICTS = 10'000;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (--T >= 0) {
    int n_districts;
    int n_soldiers;

    std::cin >> n_districts >> n_soldiers;

    int inner[n_districts];
    for (int i = 0; i < n_districts; i++) {
      std::cin >> inner[i];
    }

    int outer[n_districts];
    for (int i = 0; i < n_districts; i++) {
      std::cin >> outer[i];
    }

    auto count = [n_soldiers](int a, int b) -> int {
      return a + b <= n_soldiers ? 1 : 2;
    };

    if (n_districts == 1) {
      std::cout << count(inner[0], outer[0]) << '\n';
      continue;
    }

    int dp[MAX_DISTRICTS][3];  // inner, outer, full

    auto calc = [&n_districts, &inner, &outer, &dp, &count]() -> void {
      for (int i = 2; i < n_districts; i++) {
        dp[i][0] = std::min(dp[i - 1][1] + count(inner[i - 1], inner[i]),
                            dp[i - 1][2] + 1);
        dp[i][1] = std::min(dp[i - 1][0] + count(outer[i - 1], outer[i]),
                            dp[i - 1][2] + 1);
        dp[i][2] = std::min(dp[i - 2][2] + count(inner[i - 1], inner[i]) +
                                count(outer[i - 1], outer[i]),
                            dp[i - 1][2] + count(inner[i], outer[i]));
        dp[i][2] = std::min(dp[i][2], dp[i][0] + 1);
        dp[i][2] = std::min(dp[i][2], dp[i][1] + 1);
      }
    };

    int answer;

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = count(inner[0], outer[0]);

    dp[1][0] = std::min(dp[0][1] + count(inner[0], inner[1]), dp[0][2] + 1);
    dp[1][1] = std::min(dp[0][0] + count(outer[0], outer[1]), dp[0][2] + 1);
    dp[1][2] = std::min(count(inner[0], inner[1]) + count(outer[0], outer[1]),
                        dp[0][2] + count(inner[1], outer[1]));

    calc();

    answer = dp[n_districts - 1][2];

    if (count(inner[n_districts - 1], inner[0]) == 1) {
      dp[0][0] = 1;
      dp[0][1] = MAX_DISTRICTS;
      dp[0][2] = 2;

      dp[1][0] = 3;
      dp[1][1] = 1 + count(outer[0], outer[1]);
      dp[1][2] =
          2 + std::min(count(outer[0], outer[1]), count(inner[1], outer[1]));

      calc();

      answer = std::min(answer, dp[n_districts - 1][1]);
    }

    if (count(outer[n_districts - 1], outer[0]) == 1) {
      dp[0][0] = MAX_DISTRICTS;
      dp[0][1] = 1;
      dp[0][2] = 2;

      dp[1][0] = 1 + count(inner[0], inner[1]);
      dp[1][1] = 3;
      dp[1][2] =
          2 + std::min(count(inner[0], inner[1]), count(inner[1], outer[1]));

      calc();

      answer = std::min(answer, dp[n_districts - 1][0]);
    }

    if (count(inner[n_districts - 1], inner[0]) == 1 &&
        count(outer[n_districts - 1], outer[0]) == 1) {
      dp[0][0] = MAX_DISTRICTS;
      dp[0][1] = MAX_DISTRICTS;
      dp[0][2] = 2;

      dp[1][0] = 3;
      dp[1][1] = 3;
      dp[1][2] = 2 + count(inner[1], outer[1]);

      calc();

      answer = std::min(answer, dp[n_districts - 2][2]);
    }

    std::cout << answer << '\n';
  }

  return 0;
}