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

int demChan(int* a, int n,int index = 0,int dem = 0) {
	if (index == n)
		return dem;
	if (a[index] % 2 == 0)
		return demChan(a, n, index + 1, dem + 1);
	return demChan(a, n, index + 1, dem);
}

int main() {
	int* a, n;
	nhap(a, n);
	int dem = demChan(a, n);
	cout << "So chan trong mang: " << dem << endl;

	delete[]a;
	return 0;
}