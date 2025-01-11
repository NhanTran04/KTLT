#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct Lop {
    char maLop[21];
    char tenLop[51];
    char tenKhoa[51];
    int soSV;
    Date ngayKG;
};

struct DanhSachLop {
    Lop* ds;
    int n;
};

// Kiểm tra năm nhuận
bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}




// Lấy số ngày trong tháng
int getSoNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang == 2 && laNamNhuan(nam))
        return 29;
    return ngayTrongThang[thang];
}

// Kiểm tra ngày hợp lệ
bool kiemTraNgayHopLe(Date d) {
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1)
        return false;

    return d.ngay <= getSoNgayTrongThang(d.thang, d.nam);
}

// Chuyển chuỗi ngày sang struct Date
Date chuyenChuoiSangNgay(char* str) {
    Date d;
    char* token = strtok(str, "/");
    d.ngay = atoi(token);
    token = strtok(NULL, "/");
    d.thang = atoi(token);
    token = strtok(NULL, "/");
    d.nam = atoi(token);
    return d;
}

// Nhập một lớp
void nhapLop(Lop& l) {
    cout << "Nhap ma lop: ";
    cin.getline(l.maLop, 21);
    cout << "Nhap ten lop: ";
    cin.getline(l.tenLop, 51);
    cout << "Nhap ten khoa: ";
    cin.getline(l.tenKhoa, 51);
    cout << "Nhap so sinh vien: ";
    cin >> l.soSV;
    cin.ignore();

    do {
        cout << "Nhap ngay khai giang (dd/mm/yyyy): ";
        char ngay[11];
        cin.getline(ngay, 11);
        l.ngayKG = chuyenChuoiSangNgay(ngay);
    } while (!kiemTraNgayHopLe(l.ngayKG));
}

// Nhập danh sách lớp
void nhapDSLop(DanhSachLop& dsl) {
    cout << "Nhap so luong lop: ";
    cin >> dsl.n;
    cin.ignore();

    dsl.ds = new Lop[dsl.n];
    for (int i = 0; i < dsl.n; i++) {
        cout << "\nNhap thong tin lop thu " << i + 1 << ":\n";
        nhapLop(dsl.ds[i]);
    }
}

// Xuất một lớp
void xuatLop(const Lop& l) {
    cout << "Ma lop: " << l.maLop << endl;
    cout << "Ten lop: " << l.tenLop << endl;
    cout << "Ten khoa: " << l.tenKhoa << endl;
    cout << "So sinh vien: " << l.soSV << endl;
    cout << "Ngay khai giang: " << l.ngayKG.ngay << "/"
        << l.ngayKG.thang << "/" << l.ngayKG.nam << endl;
}

// Xuất danh sách lớp
void xuatDSLop(const DanhSachLop& dsl) {
    for (int i = 0; i < dsl.n; i++) {
        cout << "\nThong tin lop thu " << i + 1 << ":\n";
        xuatLop(dsl.ds[i]);
    }
}

// Tổng số SV khoa CNTT
int tongSVKhoaCNTT(const DanhSachLop& dsl) {
    int sum = 0;
    for (int i = 0; i < dsl.n; i++) {
        if (strcmp(dsl.ds[i].tenKhoa, "Cong nghe thong tin") == 0) {
            sum += dsl.ds[i].soSV;
        }
    }
    return sum;
}

// Đếm số lớp khoa Ngoại ngữ
int demLopKhoaNgoaiNgu(const DanhSachLop& dsl) {
    int count = 0;
    for (int i = 0; i < dsl.n; i++) {
        if (strcmp(dsl.ds[i].tenKhoa, "Ngoai ngu") == 0) {
            count++;
        }
    }
    return count;
}

// Xóa một lớp tại vị trí pos
void xoaLop(DanhSachLop& dsl, int pos) {
    if (pos < 0 || pos >= dsl.n) return;

    for (int i = pos; i < dsl.n - 1; i++) {
        dsl.ds[i] = dsl.ds[i + 1];
    }
    dsl.n--;
}

// Xóa các lớp thuộc khoa Cơ bản
void xoaLopKhoaCoBan(DanhSachLop& dsl) {
    for (int i = 0; i < dsl.n; i++) {
        if (strcmp(dsl.ds[i].tenKhoa, "Co ban") == 0) {
            xoaLop(dsl, i);
            i--;
        }
    }
}

// Ghi danh sách lớp khoa Kinh tế và quản lý công xuống file
void ghiDSLopKinhTeQL(const DanhSachLop& dsl) {
    ofstream outFile("ds_ktql.txt");
    if (!outFile) return;

    // Đếm số lớp thuộc khoa
    int count = 0;
    for (int i = 0; i < dsl.n; i++) {
        if (strcmp(dsl.ds[i].tenKhoa, "Kinh te va quan ly cong") == 0) {
            count++;
        }
    }

    outFile << count << endl;
    for (int i = 0; i < dsl.n; i++) {
        if (strcmp(dsl.ds[i].tenKhoa, "Kinh te va quan ly cong") == 0) {
            outFile << dsl.ds[i].maLop << "#" << dsl.ds[i].tenLop << "#"
                << dsl.ds[i].tenKhoa << "#" << dsl.ds[i].soSV << "#"
                << dsl.ds[i].ngayKG.ngay << "/" << dsl.ds[i].ngayKG.thang
                << "/" << dsl.ds[i].ngayKG.nam << endl;
        }
    }
    outFile.close();
}

int main() {
    DanhSachLop dsl;
    int choice;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Nhap danh sach lop\n";
        cout << "2. Xuat danh sach lop\n";
        cout << "3. Tong so SV khoa CNTT\n";
        cout << "4. Dem so lop khoa Ngoai ngu\n";
        cout << "5. Xoa lop khoa Co ban\n";
        cout << "6. Ghi DS lop Kinh te va quan ly cong\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            nhapDSLop(dsl);
            break;
        case 2:
            xuatDSLop(dsl);
            break;
        case 3:
            cout << "Tong so SV khoa CNTT: " << tongSVKhoaCNTT(dsl) << endl;
            break;
        case 4:
            cout << "So lop khoa Ngoai ngu: " << demLopKhoaNgoaiNgu(dsl) << endl;
            break;
        case 5:
            xoaLopKhoaCoBan(dsl);
            cout << "Da xoa cac lop khoa Co ban\n";
            break;
        case 6:
            ghiDSLopKinhTeQL(dsl);
            cout << "Da ghi file thanh cong\n";
            break;
        }
    } while (choice != 0);

    delete[] dsl.ds;
    return 0;
}