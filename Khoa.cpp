#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

double total = 0;

struct KhoaHoc
{
	char maKhoa[20];
	string tenKhoa;
	char tenGV[20];
	int soTC;
	int hocPhi;
};

struct DSKH
{
	KhoaHoc* ds;
	int n;
};

void nhap1Khoa(KhoaHoc &s) {
	cout << "====================\n";
	cout << "Nhap ma khoa: " << endl;
	cin.getline(s.maKhoa, 20);
	cout << "Nhap ten khoa: " << endl;
	getline(cin, s.tenKhoa);
	cout << "Nhap ten giao vien: " << endl;
	cin.getline(s.tenGV, 20);
	cout << "Nhap so tin chi: " << endl;
	cin >> s.soTC;
	cout << "Nhap hoc phi: " << endl;
	cin >> s.hocPhi;
	cin.ignore();
}

void xuat1Khoa(KhoaHoc s) {
	cout << "===========Thong tin khoa hoc=============" << endl;
	cout << "Ma khoa: " << s.maKhoa << endl;
	cout << "Ten khoa: " << s.tenKhoa << endl;
	cout << "Ten giao vien: " << s.tenGV << endl;
	cout << "So tin chi: " << s.soTC << endl;
	cout << "Hoc phi: " << s.hocPhi << endl;
}

void pushBackArr(KhoaHoc*& s, int& n, KhoaHoc x) {
	if (s == NULL)
	{
		n = 1;
		s = new KhoaHoc[n];
		s[0] = x;
	}
	else {
		KhoaHoc *a = s;
		s = new KhoaHoc[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++) {
			s[j++] = a[i];
		}
		s[n++] = x;
		delete[]a;
		a = nullptr;
	}
}

void docFile(DSKH &l) {
	ifstream inFile("khoahoc.txt");
	if (inFile.is_open()) {
		while (inFile.eof()== false) {
			KhoaHoc s;
			inFile.getline(s.maKhoa, 20,'#');
			getline(inFile, s.tenKhoa, '#');
			inFile.getline(s.tenGV, 20, '#');
			inFile >> s.soTC;
			inFile.ignore();
			inFile >> s.hocPhi;
			inFile.ignore();
			pushBackArr(l.ds, l.n, s);
		}

		inFile.close();
	}
}

void xuatDSKH(DSKH l) {
	for (int i = 0; i < l.n; i++)
		xuat1Khoa(l.ds[i]);
}

bool timTheoMa(KhoaHoc s, string x) {
	return strcmp(s.maKhoa, x.c_str()) == 0;
}

bool timTheoTen(KhoaHoc s, string x) {
	return s.tenKhoa == x;
}

KhoaHoc *findKH(DSKH l, string x,bool func(KhoaHoc,string)){
	for (int i = 0; i < l.n; i++) {
		if (func(l.ds[i], x))
			return &l.ds[i];
	}
	return NULL;
}

void ghiThongTinKH(DSKH l) {
	ofstream outFile("dangkykh.txt",ios::app);
	if (outFile.is_open()) {
		outFile << total << endl;
		for (int i = 0; i < l.n; i++) {
			outFile << l.ds[i].maKhoa << "#";
			outFile << l.ds[i].tenKhoa << "#";
			outFile << l.ds[i].tenGV << "#";
			outFile << l.ds[i].soTC << "#";
			outFile << l.ds[i].hocPhi << "#" << endl;
		}
		outFile.close();
	}

}

void init(DSKH &l){
	l.ds = NULL;
	l.n = 0;
}
int main() {
	/*KhoaHoc s;
	nhap1Khoa(s);
	xuat1Khoa(s);*/
	DSKH l;
	init(l);
	KhoaHoc* x;
	DSKH dk;
	init(dk);
	int chonMenu;
	int chon;
	KhoaHoc y;
	do {
		cout << "0.Ket thuc!\n";
		cout << "1.Nhap va xuat khoa hoc!\n";
		cout << "2.Doc tu file\n";
		cout << "3.Xuat Danh sach\n";
		cout << "4.Tim kiem\n";
		cout << "5.Dang ky khoa hoc\n";
		cout << "Nhap lua chon\n";
		cin >> chonMenu;
		cin.ignore();
		switch (chonMenu)
		{
		case 1:
			nhap1Khoa(y);
			break;
		case 2:
			docFile(l);
			break;
		case 3:
			xuatDSKH(l);
			break;
		case 5:
			do {
				do {
					string id;
					cout << "Nhap vao ma MH!" << endl;
					cin >> id;
					x = findKH(l, id, timTheoMa);
					cin.ignore();
					if (x == NULL)
						cout << "Vui long nhap dung ma MH!" << endl;
				} while (x == NULL);
				total += x->hocPhi;
				pushBackArr(dk.ds, dk.n, *x);

				cout << "1. Chon them - 0. Dung: ";
				cin >> chon;
			} while (chon != 0);
			cout << "Tong tien: " << total << endl;
			xuatDSKH(dk);
			ghiThongTinKH(dk);
			break;
		}
	} while (chonMenu != 0);


	delete[]l.ds;
	delete[]dk.ds;
	return 0;
}