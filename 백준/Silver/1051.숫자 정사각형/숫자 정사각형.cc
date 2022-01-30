#include <iostream>

int main(void) {
  int width, height;
  int **table;

  std::cin >> height >> width;
  table = new int*[height];
  for (int i = 0; i < height; i++) {
    char line[width + 1];
    table[i] = new int[width];
    std::cin >> line;
    for (int j = 0; j < width; j++) {
      table[i][j] = line[j] - '0';
    }
  }

  for (int size = (width < height ? width : height); size >= 1; size--) {
    for (int y = 0; y < height - (size - 1); y++) {
      for (int x = 0; x < width - (size - 1); x++) {
        if (table[y][x] == table[y + size - 1][x] && \
            table[y][x] == table[y][x + size - 1] && \
            table[y][x] == table[y + size - 1][x + size - 1]) {
          std::cout << size * size;
          for (int iter = 0; iter < height; iter++) {
            delete table[iter];
          }
          delete table;
          return 0;
        }
      }
    }
  }
  throw ;
}
