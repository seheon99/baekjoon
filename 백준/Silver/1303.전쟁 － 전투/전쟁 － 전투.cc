#include <iostream>
#include <cmath>

static int countSoldiers(char (*soldiers)[100], int x, int y, int width, int height) {
  char team = soldiers[y][x];
  int count = 1;

  soldiers[y][x] += 'a' - 'A';
  if (x - 1 >= 0 && soldiers[y][x - 1] == team) {
    count += countSoldiers(soldiers, x - 1, y, width, height);
  }
  if (y - 1 >= 0 && soldiers[y - 1][x] == team) {
    count += countSoldiers(soldiers, x, y - 1, width, height);
  }
  if (x + 1 < width && soldiers[y][x + 1] == team) {
    count += countSoldiers(soldiers, x + 1, y, width, height);
  }
  if (y + 1 < height && soldiers[y + 1][x] == team) {
    count += countSoldiers(soldiers, x, y + 1, width, height);
  }
  return count;
}

int main(void) {
  int width, height;
  char soldiers[100][100];
  int ourValue = 0, enemyValue = 0;

  std::cin >> width >> height;
  for (int i = 0; i < height; ++i) {
    std::cin >> soldiers[i];
  }

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (soldiers[i][j] == 'W') {
        ourValue += pow(countSoldiers(soldiers, j, i, width, height), 2);
      } else if (soldiers[i][j] == 'B') {
        enemyValue += pow(countSoldiers(soldiers, j, i, width, height), 2);
      }
    }
  }
  std::cout << ourValue << " " << enemyValue;
  return 0;
}
