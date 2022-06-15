#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void solve(
    const vector<float> &a,  // квадратна матриця
    const vector<float> &b,  // вектор вільних елементів
    vector<float> &x,  // сюди буде записано розв'язок
    const float allowed_error  //допустима похибка
) {
    const unsigned n = x.size();
    vector<float> tmp_x(n);
    float error;
    do {
        error = 0;

        tmp_x = b;
        for (unsigned i = 0; i < n; ++i) {
            for (unsigned j = 0; j < n; ++j) {
                if (i != j) {
                    tmp_x[i] -= a[i * n + j] * x[j];
                }
            }

            // оновити x[i] та порахувати похибку
            const float x_updated = tmp_x[i] / a[i * (n + 1)];
            const float e = fabs(x[i] - x_updated);
            x[i] = x_updated;
            if (e > error) { error = e; }
        }
    } while (error > allowed_error);
}

int main() {
    unsigned n;

    cout << "\nВведіть розмір сиcтеми:\nn = ";
    cin >> n;

    vector<float> x(n);
    vector<float> a(n * n);
    vector<float> b(n);

    cout << "\nВведіть вектор вільних елементів: \n";
    for (auto &b_elem: b)
        cin >> b_elem;

    cout << "\nВведіть коефіцієнти системи: \n";
    for (auto &a_elem: a)
        cin >> a_elem;

    float allowed_error;
    cout << "\nВведіть допустиму похибку: \n";
    cin >> allowed_error;

    solve(a, b, x, allowed_error);

    cout << "\nРозв'язок системи: \n";
    for (unsigned i = 0; i < n; ++i)
        cout << "\nx[" << i << "] = " << x[i];

}
