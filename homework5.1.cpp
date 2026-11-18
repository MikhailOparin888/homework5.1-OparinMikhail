#Вариант 7

#1
#include <iostream>

using namespace std;

int main() {
    int n;
    double x;

    cout << "Введите натуральное n: ";
    cin >> n;
    cout << "Введите действительное x: ";
    cin >> x;

    double sum = 1.0;
    double term = 1.0;

    for (int i = 1; i <= n; ++i) {
        term *= x;
        sum += term;
    }

    cout << "Сумма S = " << sum << endl;
    return 0;
}

#2
#include <iostream>

using namespace std;

int main() {
    int k;
    double x;

    cout << "Введите натуральное k: ";
    cin >> k;
    cout << "Введите действительное x: ";
    cin >> x;

    double term = -x; 
    double sum = term;

    for (int n = 1; n <= k; ++n) {
        term = -term * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;
    }

    cout << "Сумма S = " << sum << endl;
    return 0;
}

#3
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double eps;
    cout << "Введите точность eps (eps > 0): ";
    cin >> eps;

    if (eps <= 0) {
        cout << "Ошибка: точность должна быть больше нуля." << endl;
        return 1;
    }

    double sum = 0.0;
    double term = 2.0; 
    int i = 1;

    while (abs(term) >= eps) {
        sum += term;
        i++;
        term /= i;
    }

    cout << "Сумма ряда S = " << sum << endl;
    cout << "Учтено слагаемых: " << i - 1 << endl;

    return 0;
}
#4
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double calculateF(double x, double eps, int& count) {
    double sum = 0.0;
    double term = 1.0;
    double ratio = x / 3.0;
    count = 0;

    while (abs(term) >= eps) {
        sum += term;
        count++;
        term *= ratio; 
    }

    return sum;
}

int main() {
    double eps;
    cout << "Введите точность eps (eps > 0): ";
    cin >> eps;

    if (eps <= 0) {
        cout << "Ошибка: точность должна быть больше нуля." << endl;
        return 1;
    }

    double a = 0.0;
    double b = 0.9;
    double h = 0.1;

    cout << "\n-----------------------------------------------------------------------\n";
    cout << left << setw(8) << "№ п/п"
         << setw(15) << "Значение x"
         << setw(25) << "Значение функции F(x)"
         << "Кол-во слагаемых n" << endl;
    cout << "-----------------------------------------------------------------------\n";

    int steps = static_cast<int>(round((b - a) / h));

    for (int i = 0; i <= steps; ++i) {
        double x = a + i * h;
        int n = 0;
        double fx = calculateF(x, eps, n);

        cout << left << setw(8) << (i + 1)
             << fixed << setprecision(1) << setw(15) << x
             << fixed << setprecision(6) << setw(25) << fx
             << n << endl;
    }

    cout << "-----------------------------------------------------------------------\n";

    return 0;
}
