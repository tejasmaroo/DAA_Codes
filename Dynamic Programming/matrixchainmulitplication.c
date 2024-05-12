#include <stdio.h>

#define INF 999999

void printParenthesis(int i, int j, int n, int *bracket, char name) {
    if (i == j) {
        printf("%c%d", name, i);
        return;
    }
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}

int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("Optimal Parenthesization is: ");
    printParenthesis(1, n - 1, n, (int *)bracket, 'A');
    printf("\n");
    return m[1][n - 1];
}

int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, size));

    return 0;
}
