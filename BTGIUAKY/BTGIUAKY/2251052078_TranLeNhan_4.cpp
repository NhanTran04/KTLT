#include<iostream>
using namespace std;

void nhap(int**&a , int &r, int&c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r <= 0 || c <= 0)
			cout << "Vui long nhap lai" << endl;
	} while (r <= 0 || c <= 0);
	a = new int* [r];
	for (int i = 0; i < r; i++)
	{
		a[i] = new int[c];
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}

}

void xuat(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << a[i][j] << "	";
		cout << endl;
	}
	
}

void xuatkpdd(int** a, int r, int c, bool func(int)) {
	bool found = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (func(*(*(a + i) + j))) {
				cout << *(*(a + i) + j) << "	";
				found = true;
			}
		}
	}
	if (found == false)
		cout << "khong co so nguyen to nao: " << endl;
}

void xuat1Chieu(int* x, int y) {
	cout << "Mang: ";
	for (int i = 0; i < y; i++)
		cout << x[i] << " ";
	cout << endl;
}


int tinhTongKPDD(int** a, int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += *(*(a + i) + j);
		}
	}
	return sum;
}

bool soNguyenTo(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % 2 == 0)
			return false;
	}
	return true;
}

int* diaChiLeDau(int** a, int r, int c) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] %2 != 0)
				return &a[i][j];
	return NULL;
}

int* mangCot(int** a, int r, int c,int &col) {
	do {
		cout << "Nhap vao cot(bat dau tu 0):";
		cin >> col;
		if (col < 0 || col >= c)
			cout << "Vui long nhap lai!" << endl;
	} while (col < 0 || col >= c);
	int *resultCol = new int[r];

	for (int i = 0; i < r; i++)
		resultCol[i] = a[i][col];
	return resultCol;
}

int* mangDong(int** a, int r, int c, int& row) {
	do {
		cout << "Nhap vao dong (bat dau tu 0)";
		cin >> row;
		if (row < 0 || row >= r)
			cout << "Vui long nhap lai!" << endl;
	} while (row < 0 || row >= r);
	int *resultRow = new int[c];
	for (int i = 0; i < c; i++)
		resultRow[i] = a[row][i];
	return resultRow;
}

int* mangCotLuuChan(int** a, int r, int c, int& colChan, int &count) {
	do {
		cout << "Nhap vao cot";
		cin >> colChan;
		if (colChan < 0 || colChan >= c)
			cout << "Vui long nhap lai!" << endl;
	} while (colChan < 0 || colChan >= c);

	count = 0;
	for (int i = 0; i < r; i++) {
		if (a[i][colChan] % 2 == 0) {
			count++;
		}
	}
	if (count == 0) {
		return NULL;
	}
	int* resultCol = new int[count];
	int index = 0;
	for (int i = 0; i < r; i++)
		if (a[i][colChan] % 2 == 0) {
			resultCol[index] = a[i][colChan];
			index++;
		}
	return resultCol;
}

int* mangCotGiam1(int** a, int r, int c, int& colGiam) {
	do {
		cout << "Nhap vao cot(bat dau tu 0):";
		cin >> colGiam;
		if (colGiam < 0 || colGiam >= c)
			cout << "Vui long nhap lai!" << endl;
	} while (colGiam < 0 || colGiam >= c);
	int* resultCol = new int[r];

	for (int i = 0; i < r; i++)
		resultCol[i] = a[i][colGiam] - 1;
	return resultCol;
}


int main() {
	int** a = NULL, r, c;
	nhap(a, r, c);
	xuat(a, r, c);

	/*int sumkpdd = tinhTongKPDD(a, r, c);
	cout << sumkpdd << endl;

	xuatkpdd(a, r, c, soNguyenTo);
	if (diaChiLeDau(a, r, c) == NULL)
		cout << "Mang khong co phan tu le";
	else{
		int* leDau = diaChiLeDau(a, r, c);
		cout << "le dau" << endl;
		cout << "Phan tu le dau tien co gia tri: " << *leDau
			<< ", dia chi: " << leDau << endl;
	}*/

	/*int col;
	int* resultCol = mangCot(a, r, c, col);
	xuat1Chieu(resultCol, r);

	int row;
	int* resultRow = mangDong(a, r, c, row);
	xuat1Chieu(resultRow, c);*/

	/*int colChan, count;
	int* resultColChan = mangCotLuuChan(a, r, c, colChan,count);
	xuat1Chieu(resultColChan, count);*/

	int colGiam;
	int* resultColGiam = mangCotGiam1(a, r, c, colGiam);
	xuat1Chieu(resultColGiam, r);


	for (int i = 0; i < r; i++)
		delete[] a[i];
	delete[] a;
	/*delete[]resultCol;
	delete[]resultRow;*/
	//delete[]resultColChan;
	delete[]resultColGiam;
	system("pause");
	return 0;
}