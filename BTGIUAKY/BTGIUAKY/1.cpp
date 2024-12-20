#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void nhap(int*& a, int& n) {
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
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}


int main() {
	int n, * a = NULL;
	nhap(a, n);
	xuat(a, n);
	return 0;
}