#include<iostream>
using namespace std;

void nhap(int*& a, int& n) {
	do {
		cin >> n;
		if (n < 0)
			cout << "Vui long nhap lai: " << endl;
	} while (n < 0);
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool isNguyenTo(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int* traDC(int* a, int n,bool func(int)) {
	for (int i = n - 1; i >= 0; i--) {
		if (func(a[i]))
			return &a[i];
	}
	return NULL;
}

int main() {
	int n, * a = NULL;
	nhap(a, n);
	int* x = traDC(a, n, isNguyenTo);
	if (x == NULL)
		cout << "Khong co so nguyen to" << endl;
	else
	{
		cout << "Phần tử nguyên tố cuối cùng: " << *x << endl;
		cout << "Địa chỉ của phần tử đó: " << x << endl;
	}
	delete[]a;
	return 0;
}