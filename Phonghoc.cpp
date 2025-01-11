#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int n;
int* p;
int* a;
string *phongThi;
string* monHoc;
int* soGhe;
int* dangKy;

void printSo() {
	ofstream outFile("phonghoc.out.txt", ios::app);
	if (outFile.is_open()) {
		for (int i = 0; i < n; i++) {
			outFile << monHoc[i] << "-" << phongThi[i] << " ";
		}
		outFile << endl;
		outFile.close();
	}

	for (int i = 0; i < n; i++) {
		cout << monHoc[i] << "-" << phongThi[i] << " ";
	}
}

//void hoanVi(int i) {
//	for(int j = 1 ; j < n+1 ;j++){
//		if (p[j] == -1 && dangKy[i] <= soGhe[j - 1]) {
//			a[i] = j;
//			p[j] = 1;
//			if (i == n - 1)
//				print();
//			else
//				hoanVi(i + 1);
//			p[j] = -1;
//		}
//	}
//}
void hoanVi(int i) {
	for (int j = 1; j < n + 1; j++) {
		if (p[j] == -1 && dangKy[i] <= soGhe[j - 1]) {
			a[i] = j;
			p[j] = 1;
			if (i == n - 1)
			{
				printSo();
			}
			else
				hoanVi(i + 1);
			p[j] = -1;
		}
	}
}



int main() {
	ifstream inFile("phonghoc.inp.txt");
	if (inFile.is_open()) {
		inFile >> n;
		a = new int[n];
		p = new int[n + 1];
		phongThi = new string[n];
		monHoc = new string[n];
		soGhe = new int[n];
		dangKy = new int[n];

		for (int i = 1; i < n + 1; i++) {
			p[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			inFile >> phongThi[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> monHoc[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> soGhe[i];
		}
		for (int i = 0; i < n; i++) {
			inFile >> dangKy[i];
		}
		hoanVi(0);
		delete[]a;
		delete[]p;
		delete[]soGhe;
		delete[]monHoc;
		delete[]dangKy;
		delete[]phongThi;
		inFile.close();
	}
	return 0;
}