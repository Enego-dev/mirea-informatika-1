#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> generate_array() {
    vector<int> v(4);
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int n = rand() % 10;
        while (count(v.begin(), v.end(), n) > 0) {
            n = rand() % 10;
        }
        v[i] = n;
    }
    return v;
}

string check_string(vector<int> initVector, vector<int> userVector) {
    string ans;
    for (int i = 0; i < initVector.size(); i++) {
        if (initVector.at(i) == userVector.at(i)) {
            ans += '+';
        }
        else if (count(initVector.begin(), initVector.end(), userVector.at(i)) > 0) {
            ans += '-';
        }
    }
    return ans;
}

int main()
{
    setlocale(0, "");

    auto arr = generate_array();

    for (const auto& e : arr) {
        cout << e << ' ';
    }
    cout << endl << endl << endl;

    string return_string;
    int n1, n2, n3, n4;
    while (return_string != "++++") {
        cout << "Введите 4 числа через пробел: " << endl;
        cin >> n1 >> n2 >> n3 >> n4;
        return_string = check_string(arr, vector<int>(4) = { n1, n2, n3, n4 });
        cout << return_string << endl << endl;
    }

    cout << "Вы угадали! Мои поздравления!" << endl;
}