#include <stdio.h>

int N;
double P;

int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%lf", &P);
        printf("$%.2lf\n", P * 0.8);
    }
    return 0;
}