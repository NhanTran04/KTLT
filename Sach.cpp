#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
using namespace std;

struct Sach
{
	char maSach[10];
	string tenSach;
	char tenTG[21];
	double giaBan;
	int giamGia;
};

struct DSQS
{
	Sach* ds;
	int soluong;
};

void nhap1Sach(Sach &s) {
	cout << "========================" << endl;
	cout << "Nhap ma sach: ";
	cin.getline(s.maSach, 10);
	cout << "Nhap ten sach: ";
	getline(cin, s.tenSach);
	cout << "Nhap ten tac gia: ";
	cin.getline(s.tenTG, 21);
	cout << "Nhap gia ban: ";
	cin >> s.giaBan;
	cout << "Nhap giam gia: ";
	cin >> s.giamGia;
	cin.ignore();
}

void xuat1Sach(Sach& s) {
	cout << "========Thong tin============" << endl;
	cout << "Ma sach: " << s.maSach << endl;
	cout << "Ten sach: " << s.tenSach << endl;	
	cout << "Ten tac gia: " << s.tenTG << endl;
	cout << "Gia ban: " << s.giaBan << endl;
	cout << "Giam gia: " << s.giamGia << endl;
}


void init(DSQS& l) {
	l.ds = NULL;
	l.soluong = 0;
}

void pushBackArr(Sach* &a, int &n, Sach x) {
	if (a == NULL)
	{
		n = 1;
		a = new Sach[n];
		a[0] = x;
	}
	else {
		Sach* aPrev = a;
		a = new Sach[n + 1];
		int j = 0;
		for (int i = 0; i < n; i++) {
			a[j++] = aPrev[i];
		}
		a[n++] = x;
		
		delete[]aPrev;
		aPrev = NULL;
	}
}

bool timTheoMa(Sach s, string x) {
	return strcmp(s.maSach, x.c_str()) == 0;
}

bool timTheoTen(Sach s, string x) {
	return s.tenSach == x;
}

Sach* findSach(DSQS l, string x, bool func(Sach, string)) {
	for(int i = 0; i < l.soluong;i++){
		if (func(l.ds[i],x)) {
			return &l.ds[i];
		}
	}
	return NULL;
}

void docFile(DSQS &l) {
	ifstream inFile("Sach.txt");
	if(inFile.is_open()) {
		while (inFile.eof()== false)
		{
			Sach s;
			inFile.getline(s.maSach, 10);
			getline(inFile, s.tenSach);
			inFile.getline(s.tenTG, 21);
			inFile >> s.giaBan;
			inFile.ignore();
			inFile >> s.giamGia;
			inFile.ignore();

			pushBackArr(l.ds, l.soluong, s);
		}
		inFile.close();
	}
}

void xuatDS(DSQS l) {
	for (int i = 0; i < l.soluong; i++) {
		xuat1Sach(l.ds[i]);
	}
}


void xuatHoaDon(DSQS cart,double total) {
	ofstream outFile("Hoa_don.txt", ios::app);
	if (outFile.is_open()) {
		outFile << total << endl;
		for (int i = 0; i < cart.soluong; i++) {
			outFile << cart.ds[i].maSach << "#";
			outFile << cart.ds[i].tenSach << "#";
			outFile << cart.ds[i].tenTG << "#";
			outFile << cart.ds[i].giaBan << "#";
			outFile << cart.ds[i].giamGia << "\n";
		}
		outFile.close();
	}
}

int main() {
	/*Sach s;
	nhap1Sach(s);
	xuat1Sach(s);*/
	DSQS l;
	init(l);
	docFile(l);
	xuatDS(l);
	
	Sach* x = findSach(l, "awerwar", timTheoMa);
	if (x != NULL) {
		cout << "Thong tin sach tim kiem: " << endl;
		// Sử dụng *x để truy cập giá trị của sách
		xuat1Sach(*x);
	}
	else {
		cout << "Khong tim thay sach!" << endl;
	}
	DSQS cart;
	init(cart);
	string id;
	int chon;
	double total = 0.0;
	do {
		cout << "Nhap ma sach can them: ";
		cin >> id;
		Sach s = *findSach(l, id, timTheoMa);
		pushBackArr(cart.ds, cart.soluong, s);
		total += (s.giaBan - s.giaBan * (s.giamGia / 100.0));
		cout << "Co muon them SP vao gio hang (1-Yes, 0-No-XUAT HOA DON): ";
		cin >> chon;
	} while (chon != 0);
	cout << "===========SAN PHAM TRONG GIO HANG=========\n";
	xuatDS(cart);
	xuatHoaDon(cart, total);
	delete[]l.ds;
	delete[]cart.ds;
	return 0;
}
