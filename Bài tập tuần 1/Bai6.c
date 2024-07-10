//#include <stdio.h>
//#include <string.h>
//
//// Hàm tính thời gian nghỉ hưu
//void tinhThoiGianNghiHuu(int namHienTai, int tuoiHuuNam, int tuoiHuuNu,
//    int ngay, int thang, int nam, const char* gioiTinh) {
//    int tuoi = namHienTai - nam;
//
//    // Kiểm tra giới tính và tuổi để tính thời gian nghỉ hưu
//    if (strcmp(gioiTinh, "nam") == 0) {
//        if (tuoi >= tuoiHuuNam && tuoiHuuNam >= 18 && tuoiHuuNam <= 62) {
//            int namNghiHuu = nam + tuoiHuuNam;
//            printf("Thoi gian ban duoc nghi huu thang %02d/%d.\n", thang, namNghiHuu);
//        }
//        else {
//            printf("Tuoi khong thuoc trong khoang tu 18 den 62 nam.\n");
//        }
//    }
//    else if (strcmp(gioiTinh, "nu") == 0) {
//        if (tuoi >= tuoiHuuNu && tuoiHuuNu >= 18 && tuoiHuuNu <= 60) {
//            int namNghiHuu = nam + tuoiHuuNu;
//            printf("Thoi gian ban duoc nghi huu thang %02d/%d.\n", thang, namNghiHuu);
//        }
//        else {
//            printf("Tuoi khong thuoc trong khoang tu 18 den 60 nam.\n");
//        }
//    }
//    else {
//        printf("Gioi tinh khong hop le.\n");
//    }
//}
//
//int main() {
//    char hoTen[100];
//    char gioiTinh[5];
//    int ngay, thang, nam;
//    int namHienTai = 2024; // Giả sử năm hiện tại là 2021
//
//    // Nhập thông tin từ người dùng
//    printf("Nhap ho ten: ");
//    fgets(hoTen, sizeof(hoTen), stdin);
//    hoTen[strlen(hoTen) - 1] = '\0'; // Xóa ký tự newline thừa
//
//    printf("Nhap gioi tinh (nam/nu): ");
//    scanf_s("%s", gioiTinh, sizeof(gioiTinh));
//
//    printf("Nhap ngay sinh (ngay/thang/nam): ");
//    scanf_s("%d/%d/%d", &ngay, &thang, &nam);
//
//    // Xử lý tính thời gian nghỉ hưu
//    tinhThoiGianNghiHuu(namHienTai, 62, 60, ngay, thang, nam, gioiTinh);
//
//    return 0;
//}
//
//
