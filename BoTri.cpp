#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int n;
int* a, * p;
string * tenMT;
string* tenKH;
int* khaNang;
int* nhuCau;
int dem = 0;

void print() {
	ofstream outFile("ket_qua_bo_tri.txt");
	if (outFile.is_open()) {
		outFile << dem;
	}
}

void hoanVi(int i) {
	for (int j = 1; j < n + 1; j++) {
		if (p[j] == -1 && nhuCau[i] <= khaNang[j - 1]) {
			a[i] = j;
			p[j] = 1;
			if (i == n - 1)
			{
				dem++;
			}
			else
				hoanVi(i + 1);
			p[j] = -1;
		}
	}
}


int main() {
	ifstream inFile("ThueMayTinh.inp.txt");
	if (inFile.is_open()) {

		inFile >> n;
		a = new int[n];
		p = new int[n + 1];
		tenMT = new string[n];
		tenKH = new string[n];
		nhuCau = new int[n];
		khaNang = new int[n];
		for (int i = 1; i < n + 1; i++)
			p[i] = -1;
		for (int i = 0; i < n; i++) {
			inFile >> tenMT[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> tenKH[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> nhuCau[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> khaNang[i];
		}
		hoanVi(0);
		print();

		delete[]a;
		delete[]p;
		delete[]tenKH;
		delete[]tenMT;
		delete[]nhuCau;
		delete[]khaNang;

		inFile.close();
	}
	return 0;
}