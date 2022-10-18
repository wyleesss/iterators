#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

int рішення(vector <int>& A) {
	vector <int> result;
	int firstN, lastN, res;
	vector <int>::iterator itr = A.begin() + 1;
	for (size_t j = 1; j < A.size(); j++)
	{
		firstN = 0, lastN = 0, res = 0;
		for (auto i = A.begin(); i != itr; i++)
			firstN += *i;

		for (auto i = itr; i != A.end(); i++)
			lastN += *i;

		res = abs(firstN - lastN);
		result.push_back(res);
		itr++;
	}
	sort(result.begin(), result.end());
	return result[0];
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, P, random;
	cout << "введіть розмір масиву -> ";
	cin >> N;
	while (N <= 2) {
		cout << "\nпомилка! повторно введіть числo N -> ";
		cin >> N;
	}
	vector<int>A(N);
	cout << "\nвведіть наступний параметр:\n\n<0> - самостійний ввід чисел масиву;\n<будь-яке інше число> - випадкові числа в масиві;\n-> ";
	cin >> random;
	if (random) {
		srand(time(NULL));
		for (auto& i : A)
			i = rand() % 2001 - 1000;
	}
	else {
		cout << "\nвведіть числа по порядку:\n\n";
		int it = 0;
		for (auto& i : A) {
			cout << "A[" << it << "] -> ";
				cin >> i;
				it++;
		}
	}
	cout << endl;
	for (auto& i : A)
		cout << i << " ";
	cout << endl;
	cout << "\n\nрезультат -> " << рішення(A);
}