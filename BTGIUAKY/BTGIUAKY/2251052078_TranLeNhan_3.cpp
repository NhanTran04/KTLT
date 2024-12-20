#include<iostream>
using namespace std;

void nhap(int*&a, int &bacA) {
	cout << "Nhap vao so bac: ";
	do {
		cin >> bacA;
		if (bacA <= 0)
			cout << "Vui long nhap mang co gia tri" << endl;
	} while (bacA <= 0);
	a = new int[bacA + 1];
	cout << "Nhap vao he so: " << endl;
	for (int i = bacA; i >=0; i--) {
		cin >> a[i];
	}
}

void daThuc(int* a, int bacA) {
	bool first = true;
	for (int i = bacA; i >= 0; i--) {
		if (a[i] != 0) {
			if (!first && a[i] > 0)
				cout << "+";
			if (a[i] < 0)
				cout << "-";
			if (abs(a[i]) != 1 || i == 0)
				cout << abs(a[i]);
			if (i >= 1)
				cout << "x" << "^" << i;
			first = false;
		}
	}
	cout << endl;
}

//tinh gia tri da thuc tai x
double tinhGTDT(int* a, int bacA, int x) {
	double result = 0;
	for (int i = 0; i <= bacA; i++) {
		result += a[i] * pow(x, i);
	}
	return result;
}

int* tinhTong2DT(int* a, int bacA, int* b, int bacB, int &bacTong) {
	bacTong = max(bacA, bacB);
	int *c = new int[bacTong + 1]();
	for (int i = 0; i <= bacA; i++)
		c[i] += a[i];
	for (int i = 0; i <= bacB; i++)
		c[i] += b[i];
	return c;
}

int* tich2DT(int* a, int bacA, int* b, int bacB, int &bacTich) {
	bacTich = bacA + bacB;
	int* c = new int[bacTich + 1]();
	for (int i = 0; i <= bacA; i++) {
		for (int j = 0; j <= bacB; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

int main() {
	int* a = NULL, * b = NULL, bacA, bacB, bacTong, bacTich;
	nhap(a, bacA);
	nhap(b, bacB);
	daThuc(a, bacA);
	double result = tinhGTDT(a, bacA, 4);
	cout << result << endl;
	cout << "da thuc tong: " << endl;
	int *c = tinhTong2DT(a, bacA, b, bacB, bacTong);
	daThuc(c,bacTong);
	int* d = tich2DT(a, bacA, b, bacB, bacTich);
	cout << "da thuc tich: " << endl;
	daThuc(d, bacTich);
	delete[]a;
	delete[]b;
	delete[]c;
	system("pause");
	return 0;
}