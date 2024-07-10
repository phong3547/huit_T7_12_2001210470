//#include <stdio.h>
//#include <stdlib.h> // Để sử dụng hàm malloc, realloc và free
//#include <math.h>   // Để sử dụng hàm sqrt
//#include <time.h>   // Để sử dụng hàm rand và srand
//
//void nhapM1C_SoNguyen(int** a, int* n);
//void xuatM1C_SoNguyen(int* a, int n);
//void timPhanTuLonNhat(int* a, int n, int* giaTriMax, int** diaChiMax);
//void timDiaChiPhanTu(int* a, int n, int* diaChiChanMax, int* diaChiLeMin);
//void xoaPhanTu(int** a, int* n, int viTriXoa);
//void themPhanTu(int** a, int* n, int x);
//int laSoChinhPhuong(int x);
//int tinhTongSoChinhPhuong(int* a, int n);
//void xuatSoCucDai(int* a, int n);
//
//int main() 
//{
//        // Khai báo và cấp phát mảng
//        int* arr;
//        int size;
//        nhapM1C_SoNguyen(&arr, &size);
//        if (size > 0) {
//            // Tìm phần tử lớn nhất và xuất giá trị và địa chỉ của nó
//            int max;
//            int* addressMax;
//            timPhanTuLonNhat(arr, size, &max, &addressMax);
//            printf("Phan tu lon nhat trong mang la: %d, tai dia chi: %p\n", max, (void*)addressMax);
//
//            // Tìm và xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
//            int diaChiChanMax, diaChiLeMin;
//            timDiaChiPhanTu(arr, size, &diaChiChanMax, &diaChiLeMin);
//            if (diaChiChanMax != -1) {
//                printf("Dia chi cua phan tu chan lon nhat: %p\n", (void*)&arr[diaChiChanMax]);
//            }
//            if (diaChiLeMin != -1) {
//                printf("Dia chi cua phan tu le nho nhat: %p\n", (void*)&arr[diaChiLeMin]);
//            }
//
//            // Xóa phần tử có giá trị 0 (nếu có)
//            for (int i = 0; i < size; i++) {
//                if (arr[i] == 0) {
//                    xoaPhanTu(&arr, &size, i);
//                    i--; // Sau khi xóa, cần quay lại xét lại vị trí hiện tại
//                }
//            }
//
//            // Xuất mảng sau khi xóa phần tử có giá trị 0
//            printf("Mang sau khi xoa phan tu co gia tri 0:\n");
//            xuatM1C_SoNguyen(arr, size);
//
//            // Thêm phần tử x vào sau phần tử đầu tiên
//            int x = 999; // Giả sử thêm phần tử có giá trị 999
//            themPhanTu(&arr, &size, x);
//
//            // Xuất mảng sau khi thêm phần tử x
//            printf("Mang sau khi them phan tu %d sau phan tu dau tien:\n", x);
//            xuatM1C_SoNguyen(arr, size);
//
//            // Tính và xuất tổng các phần tử là số chính phương
//            int tongChinhPhuong = tinhTongSoChinhPhuong(arr, size);
//            printf("Tong cac so chinh phuong trong mang la: %d\n", tongChinhPhuong);
//
//            // Xuất các số cực đại trong mảng
//            printf("Cac so cuc dai trong mang la:\n");
//            xuatSoCucDai(arr, size);
//        }
//        else {
//            printf("Mang khong co phan tu.\n");
//        }
//
//        // Giải phóng bộ nhớ khi không cần thiết nữa
//        free(arr);
//
//        return 0;
//    }
//
//    void nhapM1C_SoNguyen(int** a, int* n) {
//        *n = 10;
//        *a = (int*)malloc(*n * sizeof(int)); // Cấp phát bộ nhớ cho mảng *a gồm *n phần tử
//
//        // Kiểm tra con trỏ *a có khác NULL hay không trước khi sử dụng
//        if (*a != NULL) {
//            // Khởi tạo số ngẫu nhiên cho từng phần tử trong mảng
//            srand(time(NULL));
//            for (int i = 0; i < *n; i++) {
//                (*a)[i] = rand() % 100;
//            }
//        }
//        else {
//            // Xử lý khi cấp phát bộ nhớ không thành công
//            printf("Loi: Khong the cap phat bo nho.\n");
//            *n = 0; // Đặt *n về 0 để thông báo lỗi khi xử lý ở phần gọi hàm.
//        }
//    }
//
//    void xuatM1C_SoNguyen(int* a, int n) {
//        for (int i = 0; i < n; i++) {
//            printf("Phan tu thu %d co gia tri %d va dia chi o nho la %p\n", i, a[i], (void*)&a[i]);
//        }
//    }
//
//    void timPhanTuLonNhat(int* a, int n, int* giaTriMax, int** diaChiMax) {
//        if (n <= 0) {
//            printf("Loi: Mang khong co phan tu.\n");
//            return;
//        }
//
//        *giaTriMax = a[0];
//        *diaChiMax = &a[0];
//
//        for (int i = 1; i < n; i++) {
//            if (a[i] > *giaTriMax) {
//                *giaTriMax = a[i];
//                *diaChiMax = &a[i];
//            }
//        }
//    }
//
//    void timDiaChiPhanTu(int* a, int n, int* diaChiChanMax, int* diaChiLeMin) {
//        *diaChiChanMax = -1; // Khởi tạo với giá trị không hợp lệ
//        *diaChiLeMin = -1;   // Khởi tạo với giá trị không hợp lệ
//
//        for (int i = 0; i < n; i++) {
//            if (a[i] % 2 == 0) {
//                if (*diaChiChanMax == -1 || a[i] > a[*diaChiChanMax]) {
//                    *diaChiChanMax = i;
//                }
//            }
//            else {
//                if (*diaChiLeMin == -1 || a[i] < a[*diaChiLeMin]) {
//                    *diaChiLeMin = i;
//                }
//            }
//        }
//
//        // Kiểm tra và thông báo nếu không có phần tử chẵn/lẻ trong mảng
//        if (*diaChiChanMax == -1) {
//            printf("Khong co phan tu chan trong mang.\n");
//        }
//        if (*diaChiLeMin == -1) {
//            printf("Khong co phan tu le trong mang.\n");
//        }
//    }
//
//    void xoaPhanTu(int** a, int* n, int viTriXoa) {
//        if (viTriXoa < 0 || viTriXoa >= *n) {
//            printf("Loi: Vi tri xoa khong hop le.\n");
//            return;
//        }
//
//        // Dịch chuyển các phần tử sang trái để ghi đè phần tử cần xóa
//        for (int i = viTriXoa; i < *n - 1; i++) {
//            (*a)[i] = (*a)[i + 1];
//        }
//
//        // Giảm kích thước mảng đi 1
//        *n = *n - 1;
//
//        // Giải phóng bộ nhớ cuối cùng của mảng
//        *a = (int*)realloc(*a, *n * sizeof(int));
//    }
//
//    void themPhanTu(int** a, int* n, int x) {
//        // Tăng kích thước mảng lên 1
//        *n = *n + 1;
//        *a = (int*)realloc(*a, *n * sizeof(int));
//
//        // Dịch chuyển các phần tử sang phải để tạo chỗ trống cho phần tử mới
//        for (int i = *n - 1; i > 0; i--) {
//            (*a)[i] = (*a)[i - 1];
//        }
//
//        // Thêm phần tử mới vào vị trí đầu tiên
//        (*a)[0] = x;
//    }
//
//    int laSoChinhPhuong(int x) {
//        // Kiểm tra xem x có phải là số chính phương hay không
//        int squareRoot = (int)sqrt(x);
//        return squareRoot * squareRoot == x;
//    }
//
//    int tinhTongSoChinhPhuong(int* a, int n) {
//        int sum = 0;
//
//        for (int i = 0; i < n; i++) {
//            if (laSoChinhPhuong(a[i])) {
//                sum += a[i];
//            }
//        }
//
//        return sum;
//    }
//
//    void xuatSoCucDai(int* a, int n) {
//        for (int i = 1; i < n - 1; i++) {
//            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
//                printf("Phan tu %d la so cuc dai.\n", a[i]);
//            }
//        }
//
//        // Xét riêng phần tử đầu và cuối mảng
//        if (n > 1 && a[0] > a[1]) {
//            printf("Phan tu %d la so cuc dai.\n", a[0]);
//        }
//        if (n > 1 && a[n - 1] > a[n - 2]) {
//            printf("Phan tu %d la so cuc dai.\n", a[n - 1]);
//        }
//}
