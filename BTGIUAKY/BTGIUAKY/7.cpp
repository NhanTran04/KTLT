#include<iostream>
using namespace std;

void xuat(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

double giaiThua(int n) {
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}

double boTri(int n, int k) {
	return giaiThua(n) / giaiThua(n - k);
}


int main() {
	int n, k;
	do {
		cin >> n;
		cin >> k;
		if (n < 0 || n > 10 || k < 0 || k >n)
			cout << "Vui long nhap lai!" << endl;
	} while (n < 0 || n > 10 || k < 0 || k >n);
	cout << boTri(n, k);
	return 0;
}