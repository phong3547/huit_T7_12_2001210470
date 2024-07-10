﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tinhTuoi(int namSinh);

int main() {
    int namSinh;
    int tuoi;

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    tuoi = tinhTuoi(namSinh);

    if (tuoi == -1) {
        printf("Loi: Nam sinh phai tu nam 1920 tro di\n");
    }
    else if (tuoi == -2) {
        printf("Loi: Nam sinh khong duoc lon hon nam hien tai\n");
    }
    else {
        printf("Tuoi cua ban la: %d\n", tuoi);
    }

    return 0;
}

int tinhTuoi(int namSinh) {
    // Lấy năm hiện tại
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    int namHienTai = now->tm_year + 1900;

    // Kiểm tra các trường hợp ngoại lệ
    if (namSinh < 1920) {
        return -1; // Lỗi: Nam sinh phải từ năm 1920 trở đi
    }
    else if (namSinh > namHienTai) {
        return -2; // Lỗi: Nam sinh không được lớn hơn năm hiện tại
    }

    return namHienTai - namSinh;
}
