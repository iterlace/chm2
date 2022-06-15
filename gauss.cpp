#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main() {
    int i, j, k, n, j_max, count = 0;

    printf("Введіть розмірність матриці:\n");
    scanf("%d", &n);

    float t, a[n][n + 1], det = -1;
    double x[n];  // x[N]-корені;
    printf("Введіть матрицю:\n");
    for (j = 0; j < n; j++)
        for (i = 0; i < n + 1; i++) {
            printf("a[%d][%d] = ", j, i);
            scanf("%f", &a[j][i]);
            count++;
            if (count == (n + 1))
                printf("\n", count = 0);
        }

    printf("Матриця А:\n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < n + 1; i++)
            printf("%6.2f\t", a[j][i]);
        printf("\n");
    }

    // норма матиці А
    double norm_a = 0, temp, d;
    for (i = 0; i < n; i++) {
        temp = 0;
        for (j = 0; j < n; j++)
            temp += fabs(a[i][j]);
        if (temp > norm_a)
            norm_a = temp;
    }

    // норма оберненої матриці А

    float inv[4][4] = {{0.62,   -0.16, 0.24,   -0.054},
                       {-0.36,  0.37,  -0.18,  -0.021},
                       {0.48,   -0.15, 0.53,   -0.07},
                       {-0.026, -0.1,  -0.029, 0.23}};
    double norm_inv = 0;
    temp = 0, d = 0;
    for (i = 0; i < n; i++) {
        temp = 0;
        for (j = 0; j < n; j++)
            temp += fabs(inv[i][j]);
        if (temp > norm_inv)
            norm_inv = temp;
    }
    cout << "Число обумовленості = " << norm_a * norm_inv << endl << endl;


    for (k = 0; k < n; k++) {
        j_max = k;
        for (j = k; j < n; j++)
            if (fabs(a[j_max][k]) < fabs(a[j][k]))
                j_max = j;

        for (i = 0; i < n + 1; i++) {
            t = a[k][i];
            a[k][i] = a[j_max][i];
            a[j_max][i] = t;
            det *= -1;
        }

        det *= a[k][k];

        for (j = n; j >= k; j--)
            a[k][j] = a[k][j] / a[k][k];
        for (i = k + 1; i < n; i++)
            for (j = n; j >= k; j--) {
                a[i][j] = a[i][j] - a[i][k] * a[k][j];
            }

    }

    printf("Вихідна матриця:\n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < n + 1; i++)
            printf("%6.2f\t", a[j][i]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
        x[i] = a[i][n];
    for (i = n - 2; i >= 0; i--)
        for (j = i + 1; j < n; j++)
            x[i] = x[i] - x[j] * a[i][j];

    printf("Корені СЛАУ:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %6.2f\n", i, x[i]);

    printf("Визначник матриці = %f", det);

}
