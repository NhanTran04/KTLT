#include<iostream>
using namespace std;

double giaiThua(int n) {
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}

double giaiThuaCongDon(int n, int x) {
	if (n == 1)
		return 1;
	return giaiThuaCongDon(n-1,x) + giaiThua(n) / pow(x, n);
}

double trongRaNgoai(int n) {
	if (n == 1)
		return sqrt(1);
	return sqrt(n + trongRaNgoai(n - 1));
}

int fibonaci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonaci(n - 1) + fibonaci(n - 2);
}

bool demLe(int x) {
	return x % 2 != 0;
}
bool demChan(int x) {
	return x % 2 == 0;
}
bool demAm(int x) {
	return x < 0;
}
bool demDuong(int x) {
	return x > 0;
}

int dem(int a[100], int n,bool func(int),int count = 0) {
	if (n == 0)
		return count;
	if (func(a[n-1]))
		return dem(a, n - 1, func, count + 1);
	return dem(a, n - 1, func, count);
}

void bubbleSort(int a[], int n) {
	if (n == 1) 
		return;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	bubbleSort(a, n - 1);
}


void bubbleSortRecursive(int a[], int n) {
	if (n == 1)
		return;
	bubbleSort(a, n);
	bubbleSortRecursive(a, n - 1); 
}

int main() {
	//
	int n = 5, x = 4;
	double gtcd = giaiThuaCongDon(n, x);
	cout << "giai thua cong don: " << gtcd << endl;
	
	double trn = trongRaNgoai(n);
	cout << "trong ra ngoai: " << trn << endl;

	int fbc = fibonaci(n);
	cout << "fibonaci: " << fbc << endl;

	int a[100];
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count;
	cout << "dem le: " << dem(a,n,demLe) << endl;
	cout << "dem chan: " << dem(a, n,demChan) << endl;
	cout << "dem am: " << dem(a, n, demAm) << endl;
	cout << "dem duong: " << dem(a, n,demDuong) << endl;

	bubbleSort(a, n);
	cout << "Mang sau khi sap xep: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}