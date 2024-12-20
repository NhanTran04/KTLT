#include<iostream>
using namespace std;

void hoanVi(int* a, bool* b, int*&temp, int n, int index) {
	if (index == n)
	{
		for (int i = 0; i < n; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		if (!b[i])
		{
			b[i] = true;
			temp[index] = a[i];
			hoanVi(a, b, temp, n, index + 1);
			b[i] = false;
		}
	}
}

int main() {
	int n;
	do {
		cin >> n;
		if (n < 0)
			cout << "vui long nhap lai!" << endl;
	} while (n < 0);
	
	int* a = new int[n];
	bool* b = new bool[n];
	int* temp = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		b[i] = false;
	}
	cout << "Tất cả các hoán vị của tập hợp A:\n";
	hoanVi(a, b, temp, n, 0);
	delete[]a;
	delete[]b;
	delete[]temp;
}