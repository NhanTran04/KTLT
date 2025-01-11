#include<iostream>
#include<fstream>
using namespace std;


void nhap(int** &a, int &r, int &c) {
	cout << "Nhap so luong cot: ";
	cin >> r;
	cout << "Nhap so luong dong: ";
	cin >> c;
	a = new int*[r];
	for (int i = 0; i < r; i++)
		a[i] = new int[c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}
}

void xuat(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void ghiFile(int** a, int r, int c) {
	ofstream outFile("file_b3.txt", ios::app);
	if(outFile.is_open()){
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				outFile << a[i][j] << " ";
			outFile << endl;
		}
		outFile.close();
	}
}

void docFile(int** &b, int r, int c) {
	b = new int*[r];
	for (int i = 0; i < r; i++)
		b[i] = new int[c];
	ifstream inFile("file_b3.txt");
	if (inFile.is_open()) {
		if (inFile.eof()==false) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					inFile >> b[i][j];

			}
		}
		inFile.close();
	}
}

int tinhTongMang(int **a, int r, int c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}


int main() {
	int** a;
	int r, c;
	int** b;
	nhap(a, r, c);
	xuat(a, r, c);
	//ghiFile(a, r, c);
	docFile(b, r, c);
	xuat(b, r, c);
	for (int i = 0; i < r; i++)
		delete a[i];
	delete[]a;
	for (int i = 0; i < r; i++)
		delete b[i];
	delete[]b;
	return 0;
}