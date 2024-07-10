//#include <stdio.h>
//#include <stdlib.h> // Để sử dụng hàm malloc và free
//#include <time.h>   // Để sử dụng hàm rand và srand
//
//void nhapM1C_SoNguyen(int** a, int* n);
//void xuatM1C_SoNguyen(int* a, int n);
//
//int main() {
//    int* arr;
//    int size;
//
//    nhapM1C_SoNguyen(&arr, &size); // Truyền địa chỉ của con trỏ arr và size vào hàm
//    xuatM1C_SoNguyen(arr, size);
//
//    // Giải phóng bộ nhớ khi không cần thiết nữa
//    free(arr);
//
//    return 0;
//}
//
//void nhapM1C_SoNguyen(int** a, int* n) {
//    *n = 10;
//    *a = (int*)malloc(*n * sizeof(int)); // Cấp phát bộ nhớ cho mảng *a gồm *n phần tử
//
//    // Kiểm tra con trỏ *a có khác NULL hay không trước khi sử dụng
//    if (*a != NULL) {
//        // Khởi tạo số ngẫu nhiên cho từng phần tử trong mảng
//        srand(time(NULL));
//        for (int i = 0; i < *n; i++) {
//            (*a)[i] = rand() % 100;
//        }
//    }
//    else {
//        // Xử lý khi cấp phát bộ nhớ không thành công
//        printf("Loi: Khong the cap phat bo nho.\n");
//        *n = 0; // Đặt *n về 0 để thông báo lỗi khi xử lý ở phần gọi hàm.
//    }
//}
//
//void xuatM1C_SoNguyen(int* a, int n) {
//    for (int i = 0; i < n; i++) {
//        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, a[i], (void*)&a[i]);
//    }
//}
