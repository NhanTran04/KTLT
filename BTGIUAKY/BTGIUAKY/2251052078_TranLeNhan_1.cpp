#include<iostream>
using namespace std;

void nhap(double &a, double &b, double &c) {
	do {
		cout << "Nhap he so cho phuong trinh bac 2: ax2 + bx + c \n";
		cin >> a >> b >> c;
		if (a == 0) {
			cout << "Vui long nhap a khac 0" << endl;
		}
	} while (a == 0);
}

void tinhNghiem(double a, double b, double c) {
	double x = b * b - 4 * a * c;
	double y = -b / (2 * a);
	if (x < 0)
		cout << "Phuong trinh vo nghiem" << endl;
	else if(x == 0)
	{
		cout << "Phuong trinh co nghiem kep la: x1 = x2 = " << y << endl;
	}
	else
	{
		cout << "Phuong trinh co 2 nghiem phan biet!" << endl;
		cout << "x1 = " << (-b + sqrt(x)) / (2 * a) << endl;
		cout << "x2 = " << (-b - sqrt(x)) / (2 * a) << endl;
	}
}


int main() {
	double a, b, c;
	nhap(a, b, c);
	tinhNghiem(a, b, c);
	return 0;
}
