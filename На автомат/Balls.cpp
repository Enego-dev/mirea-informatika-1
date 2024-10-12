#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void print_arr(int* arr, int lenght) {
    for (int i = 0; i < lenght; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int check_arr(int* ballsArr, int ballsArrLength) {
    bool flag = false;
    for (int i = 0; i < ballsArrLength; i++) {
        //cout << "Текущее значение перебора от 1 до n: " << i + 1 << "\t" << "Текущее значение массива: " << *(ballsArr + i) << endl;
        //cout << i + 1 << " -> " << *(ballsArr + i) << endl;

        if (i + 1 == *(ballsArr + i))
            flag = true;
    }
    //cout << endl;
    return flag == true;
}

int get_permutations(int *ballsArr, int ballsArrLength) {
    int ans = 0;
    int i = 0;
    do {
        ans += check_arr(ballsArr, ballsArrLength);
        next_permutation(ballsArr, ballsArr + ballsArrLength);
        i++;
    } while (i < factorial(ballsArrLength));

    next_permutation(ballsArr, ballsArr + ballsArrLength);
    cout << "Ответ: " << ans << endl;
    return ans;
}

int main()
{
    setlocale(0, "");

    const int BALLSCOUNT = 12;
    int balls[BALLSCOUNT];
    for (int i = 0; i < BALLSCOUNT; i++) {
        balls[i] = i + 1;
    }

    int answers[13]{ 0, 1, 1, 4, 15, 76, 455, 3186, 25487, 229384, 2293839, 25232230, 302786759 };

    int a = get_permutations(balls, sizeof(balls) / sizeof(balls[0]));
    cout << "Проверка\n" << (a == answers[BALLSCOUNT]) << std::endl;
}