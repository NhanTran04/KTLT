#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void nhap(int*& a, int& n) {
	srand(time(0));
	do {
		cout << "Nhap n:";
		cin >> n;
		if (n < 0)
			cout << "Vui long nhap lai! " << endl;
	} while (n < 0);
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % 50 + 1;
}


void xuat(int* a, int n) {
	cout << "Mang: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool asc(int x, int y) {
	return x > y;
}
bool desc(int x, int y) {
	return x < y;
}

void sort(int* a, int n, bool func(int,int) = asc, int index = 0) {
	if (index == n - 1)
		return;
	for (int i = 0; i < n - 1 - index; i++) {
		if (func(a[i], a[i + 1])) {
			swap(a[i], a[i + 1]);
		}
	}
	sort(a, n, func, index+ 1);
}


int main() {
	int n, * a = NULL;
	nhap(a, n);
	xuat(a, n);
	sort(a, n, asc);
	xuat(a, n);
	return 0;
}