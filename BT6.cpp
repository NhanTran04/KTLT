#include <iostream>
using namespace std;

class Gio {
public:
    // Constructor không tham số
    Gio();

    // Constructor với tham số
    Gio(int gio, int phut, int giay);

    // Destructor
    ~Gio();

    // Getter cho giờ
    int layGio() const { return gio; }

    // Getter cho phút
    int layPhut() const { return phut; }

    // Setter cho giờ
    void ganGio(int g) {
        if (g >= 0 && g < 24) {
            gio = g;
        }
        else {
            cout << "Gia tri gio khong hop le.\n";
        }
    }

    // Setter cho phút
    void ganPhut(int p) {
        if (p >= 0 && p < 60) {
            phut = p;
        }
        else {
            cout << "Gia tri phut khong hop le.\n";
        }
    }

    // Kiểm tra giờ phút hợp lệ
    bool laHopLe() const {
        return (gio >= 0 && gio < 24) && (phut >= 0 && phut < 60);
    }

    // Xác định AM/PM
    string xacDinhAMPM() const {
        if (gio >= 0 && gio < 12) {
            return "AM";
        }
        else {
            return "PM";
        }
    }

    // Hiển thị thông tin giờ
    void hienThi() const {
        cout << "Gio: " << gio << "h "
            << phut << "m "
            << giay << "s "
            << "(" << xacDinhAMPM() << ")\n";
    }

private:
    int gio;
    int phut;
    int giay;
};

// Định nghĩa constructor không tham số
Gio::Gio() {
    gio = 0;
    phut = 0;
    giay = 0;
}

// Định nghĩa constructor với tham số
Gio::Gio(int g, int p, int s) {
    gio = g;
    phut = p;
    giay = s;
}

// Định nghĩa destructor
Gio::~Gio() {
    // Hủy đối tượng
}

// Hàm main kiểm chứng
int main() {
    // Khởi tạo đối tượng bằng constructor không tham số
    Gio g1;
    g1.hienThi();

    // Khởi tạo đối tượng bằng constructor với tham số
    Gio g2(10, 45, 30);
    g2.hienThi();

    // Kiểm tra hợp lệ và xác định AM/PM
    if (g2.laHopLe()) {
        cout << "Gio hop le: " << g2.xacDinhAMPM() << "\n";
    }
    else {
        cout << "Gio khong hop le.\n";
    }

    return 0;
}
