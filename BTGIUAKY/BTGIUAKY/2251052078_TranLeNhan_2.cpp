#include<iostream>
using namespace std;

void nhap(int* &a, int &n) {
	cout << "Nhap vao so luong mang: ";
	do {
		cin >> n;
		if (n <= 0)
			cout << "Vui long nhap mang co gia tri" << endl;
	} while (n <= 0);
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
}



void xuat(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isChinhPhuong(int x) {
	if (x < 0) return false;
	int y = sqrt(x);
	return y * y == x;
}

bool isHoanThien(int x) {
	if (x <= 0) return false;
	int sum = 0;
	for (int i = 1; i < x / 2; i++) {
		if (x % i == 0)
			sum += i;
	}
	return sum == x;
}

bool isAm(int x) {
	return x < 0;
}

bool isDuong(int x) {
	return x > 0;
}

bool isNguyenTo(int x) {
	if (x < 2)
		return false;
	if (x == 2)
		return true;
	else
	{
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0)
				return false;
		}
		return true;
	}
}

bool xoa(int* a, int &n) {
	int x; cin >> x;
	if (x < 0 || x >= n) {
		return false; // Chỉ số không hợp lệ
	}
	
	for (int i = x; i < n - 1; i++) {
		a[i] = a[i] + 1;
	}
	n--;
	return true;

}

bool asc(int x, int y) {
	return x > y;
}

bool desc(int x, int y) {
	return x < y;
}

void sort(int* a, int n, bool func(int ,int) = asc)
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (func(a[i],a[j]))
				swap(a[i], a[j]);
		}
	}
}

void sort1Nua(int* a, int n, bool func1(int, int), bool func2(int, int))
{
	int x = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < x; j++) {
			if (func1(a[i], a[j]))
				swap(a[i], a[j]);
		}
		for (int j = x; j < n; j++) {
			if (func2(a[i], a[j]))
				swap(a[i], a[j]);
		}
	}
}


int* timDiaChiChinhPhuongDauTien(int* a, int n, bool func(int)){
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (func(a[i]))
			return &a[i];
	}
	return NULL;
}

int* timDiaChiSoHoanThienCuoiCung(int* a, int n, bool func(int)) {
	int dem = 0;
	for (int i = n -1; i >= 0; i++)
	{
		if (func(a[i]))
			return &a[i];
	}
	return NULL;
}


void mergeArr(int* a, int n, int* b, int n1, int * &merge, int &n2) {
	n2 = n + n1;
	int k = 0;
	merge = new int[n2];
	int i = 0, j = 0;
	while (i < n && j < n1)
	{
		if (a[i] < a[j])
			merge[k++] = a[i++];
		else
			merge[k++] = b[j++];
	}
	while (i < n)
	{
		merge[k++] = a[i++];
	}
	while (j < n1)
	{
		merge[k++] = b[j++];
	}
}


int main() {
	int n, n1, n2;
	int* a =NULL;
	int* b =NULL;
	int* merge = NULL;
	nhap(a, n);
	nhap(b, n1);
	cout << "Xuat:" << endl;
	xuat(a, n);
	xuat(b, n1);
	//xoa(a, n);
	cout << "Tang dan" << endl;
	sort(a, n);
	xuat(a, n);
	cout << "giam dan" << endl;
	sort(a, n,desc);
	xuat(a, n);
	cout << "1 nua" << endl;
	sort1Nua(a, n, asc,asc);
	xuat(a, n);
	mergeArr(a, n, b, n1, merge, n2);
	xuat(merge, n2);
	delete[]a;
	delete[]b;
	delete[]merge;
	return 0;
}