#include <iostream>

using namespace std;

int clamp(int n, int min, int max) {
	if (n < min)
		return min;
	else if (n > max)
		return max;
	else
		return n;
}

int main()
{
	setlocale(0, "");

	//5, 2, 1, 3, 9, 0, 4, 6, 8, 7
	int arr[] = { 5,2,1, 10, 15,3,9,0, 81,4,6,8, 14,7 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int leftIndex{ 0 }, rightIndex{ 1 };

	if (arrLen < 2) {
		cout << "Длина массива < 2, нечего сортировать!" << endl;
		return 0;
	}

	// вывод входного массива
	cout << "Входной массив:" << endl;
	for (int i = 0; i < arrLen; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl << "======================" << endl << endl;

	// Gnome sort
	cout << "Сортировка с помощью Gnome sort..." << endl << endl;
	do {
		/*cout << "Промежуточный вывод массива:" << endl;
		for (int i = 0; i < arrLen; i++) {
			cout << arr[i] << ' ';
		}
		cout << "Сравниваем " << arr[leftIndex] << " и " << arr[rightIndex] << endl;
		cout << endl;*/

		if (arr[leftIndex] > arr[rightIndex]) {
			swap(arr[leftIndex], arr[rightIndex]);

			int newLeftIndex = clamp(leftIndex - 1, 0, arrLen - 1);
			int newRightIndex = clamp(rightIndex - 1, 1, arrLen);
			while (arr[newLeftIndex] > arr[newRightIndex]) {
				swap(arr[newLeftIndex], arr[newRightIndex]);
				newLeftIndex = clamp(newLeftIndex - 1, 0, arrLen - 1);
				newRightIndex = clamp(newRightIndex - 1, 1, arrLen);
			}
			continue;
		}

		leftIndex = clamp(leftIndex + 1, 0, arrLen - 1);
		rightIndex = clamp(rightIndex + 1, 1, arrLen);
	} while (leftIndex != arrLen - 1 && rightIndex != arrLen);

	cout << "=============================" << endl;
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < arrLen; i++) {
		cout << arr[i] << ' ';
	}
}