#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Введите A (стоимость основания спиннера), B (стоимость 1 лопасти), C (максимальная стоимость спиннера)" << endl;
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Стоимость не может быть <= 0!";
        return 0;
    }

    if (a > c) {
        cout << "Основание спиннера не может стоить больше спиннера целеком!";
        return 0;
    }

    // 1-й способ:
    int n = (c - a) / b;
    cout << n << endl;
}