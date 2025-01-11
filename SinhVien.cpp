#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<algorithm>
using namespace std;

struct SV {
    int maSV;
    string hoTen;
    char maLop[6];
    double dtb;
};

struct DSSV {
    SV* ds;
    int n;
};

void init(DSSV& l) {
    l.ds = nullptr;
    l.n = 0;
}

void nhapSV(SV& s) {
    cout << "Nhap ma SV: ";
    cin >> s.maSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, s.hoTen);
    cout << "Nhap ma lop (toi da 5 ky tu): ";
    cin.getline(s.maLop, 6);
    cout << "Nhap diem trung binh: ";
    cin >> s.dtb;
}

void nhapDSSV(DSSV& l) {
    cout << "Nhap so luong sinh vien: ";
    cin >> l.n;
    l.ds = new SV[l.n];
    for (int i = 0; i < l.n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        nhapSV(l.ds[i]);
    }
}

void xuatSV(const SV& s) {
    cout << "Ma SV: " << s.maSV << "\n";
    cout << "Ho ten: " << s.hoTen << "\n";
    cout << "Ma lop: " << s.maLop << "\n";
    cout << "Diem TB: " << s.dtb << "\n";
}

void xuatDSSV(const DSSV& l) {
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < l.n; i++) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        xuatSV(l.ds[i]);
        cout << "------------------\n";
    }
}

void docFile(DSSV& l) {
    ifstream inFile("file_b4.txt");
    inFile >> l.n;
    inFile.ignore();
    l.ds = new SV[l.n];
    for (int i = 0; i < l.n; i++) {
        inFile >> l.ds[i].maSV;
        inFile.ignore();
        getline(inFile, l.ds[i].hoTen, '#');
        inFile.getline(l.ds[i].maLop, 6, '#');
        inFile >> l.ds[i].dtb;
        inFile.ignore();
    }
    inFile.close();
}

int demLopCS20(const DSSV& l) {
    int count = 0;
    for (int i = 0; i < l.n; i++) {
        if (strcmp(l.ds[i].maLop, "CS20") == 0) count++;
    }
    return count;
}


int demDTB8(const DSSV& l) {
    int count = 0;
    for (int i = 0; i < l.n; i++) {
        if (l.ds[i].dtb >= 8.0) count++;
    }
    return count;
}

void sapXepDTBGiamDan(DSSV& l) {
    for (int i = 0; i < l.n; i++) {
        for (int j = i; j < l.n; j++)
            if (l.ds[j].dtb > l.ds[i].dtb)
                swap(l.ds[j], l.ds[i]);
    }
}

void capNhatSV(DSSV& l, int index) {
    if (index < 0 || index >= l.n) {
        cout << "Chi so khong hop le!\n";
        return;
    }
    cout << "Cap nhat thong tin sinh vien thu " << index + 1 << ":\n";
    nhapSV(l.ds[index]);
}

void xoa(DSSV& l, int x) {
    if (x < 0 || x>= l.n)
        cout << "Nhap sai!";
    else {
        for (int i = x; i < l.n- 1; i++) {
            l.ds[i] = l.ds[i + 1];
        }
        l.n--;
    }
}

void themSV(DSSV& l) {
    SV s;
    nhapSV(s);
    SV* temp = new SV[l.n + 1];
    for (int i = 0; i < l.n; i++) {
        temp[i] = l.ds[i];
    }
    temp[l.n] = s;
    delete[] l.ds;
    l.ds = temp;
    l.n++;
}

void ghiHocBong(const DSSV& l) {
    ofstream outFile("hoc_bong.txt");
    int count = 0;
    for (int i = 0; i < l.n; i++) {
        if (l.ds[i].dtb >= 8.0) count++;
    }
    outFile << count << "\n";
    for (int i = 0; i < l.n; i++) {
        if (l.ds[i].dtb >= 8.0) {
            outFile << l.ds[i].maSV << "#" << l.ds[i].hoTen << "#" << l.ds[i].maLop << "#" << l.ds[i].dtb << "\n";
        }
    }
    outFile.close();
}

void ghiTenAnh(const DSSV& l) {
    ofstream outFile("ten_anh.txt");
    int count = 0;
    for (int i = 0; i < l.n; i++) {
        if (l.ds[i].hoTen.find("Anh") != string::npos) count++;
    }
    outFile << count << "\n";
    for (int i = 0; i < l.n; i++) {
        if (l.ds[i].hoTen.find("Anh") != string::npos) {
            outFile << l.ds[i].maSV << "#" << l.ds[i].hoTen << "#" << l.ds[i].maLop << "#" << l.ds[i].dtb << "\n";
        }
    }
    outFile.close();
}

void giaiPhong(DSSV& l) {
    delete[] l.ds;
    l.ds = nullptr;
    l.n = 0;
}

int main() {
    DSSV l;
    init(l);
    docFile(l);
    xuatDSSV(l);
    /*int x;
    cin >> x;
    x = x - 1;
    xoa(l, x);
    xuatDSSV(l);*/
    themSV(l);
    xuatDSSV(l);
    giaiPhong(l);
    return 0;
}