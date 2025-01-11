#include<iostream>
#include<fstream>
using namespace std;


void writeFile(int a[],int size) {
	ofstream outFile("file_xuat_mang.txt", ios::app);
	if (outFile.is_open()) {
		for (int i = 0; i < size; i++) {
			outFile << a[i] << endl;	
		}
		outFile.close();
	}
}


void readFile(int* &b, int size) {
	b = new int[size];
	ifstream inf("file_xuat_mang.txt");
	if(inf.is_open()) {
		if (inf.eof() == false) {
			for (int i = 0; i < size; i++) {
				inf >> b[i];
			}
		}
		inf.close();
	}
	
}

void xuat(int* b, int size) {
	for (int i = 0; i < size;i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[] = { 3, 4 , 9 , 1 ,2 };
	int* b;
	int size = sizeof(a) / sizeof(a[0]);
	//writeFile(a, size);
	readFile(b, size);
	xuat(b, size);
	delete[]b;
	return 0;
}