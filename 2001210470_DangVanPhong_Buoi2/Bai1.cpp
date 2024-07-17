//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// Hàm tạo mảng ngẫu nhiên có số phần tử lớn hơn hoặc bằng 15
//void createRandomArray(int a[], int* n) {
//    *n = 15 + rand() % 16; // n sẽ là một số ngẫu nhiên từ 15 đến 30
//    for (int i = 0; i < *n; i++) {
//        a[i] = rand() % 101; // Các số ngẫu nhiên từ 0 đến 100
//    }
//}
//
//// Hàm tạo mảng chứa toàn số chẵn
//void createEvenRandomArray(int a[], int* n) {
//    *n = 15 + rand() % 16; // n sẽ là một số ngẫu nhiên từ 15 đến 30
//    for (int i = 0; i < *n; i++) {
//        a[i] = (rand() % 51) * 2; // Các số chẵn ngẫu nhiên từ 0 đến 100
//    }
//}
//
//// Hàm tìm kiếm tuyến tính
//int linearSearch(int a[], int n, int x) {
//    for (int i = 0; i < n; i++) {
//        if (a[i] == x) {
//            return i; // Trả về vị trí của x
//        }
//    }
//    return -1; // Không tìm thấy x
//}
//
//// Hàm sắp xếp Interchange Sort
//void interchangeSort(int a[], int n, int ascending) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
//                int temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
//            }
//        }
//    }
//}
//
//// Hàm tìm kiếm nhị phân
//int binarySearch(int a[], int n, int x) {
//    int left = 0, right = n - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (a[mid] == x) {
//            return mid;
//        }
//        else if (a[mid] < x) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return -1;
//}
//
//// Hàm sắp xếp Selection Sort
//void selectionSort(int a[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        int minIndex = i;
//        for (int j = i + 1; j < n; j++) {
//            if (a[j] < a[minIndex]) {
//                minIndex = j;
//            }
//        }
//        int temp = a[minIndex];
//        a[minIndex] = a[i];
//        a[i] = temp;
//    }
//}
//
//// Hàm sắp xếp Quick Sort
//void quickSort(int a[], int left, int right) {
//    int i = left, j = right;
//    int pivot = a[(left + right) / 2];
//    while (i <= j) {
//        while (a[i] < pivot) i++;
//        while (a[j] > pivot) j--;
//        if (i <= j) {
//            int temp = a[i];
//            a[i] = a[j];
//            a[j] = temp;
//            i++;
//            j--;
//        }
//    }
//    if (left < j) quickSort(a, left, j);
//    if (i < right) quickSort(a, i, right);
//}
//
//// Hàm in mảng
//void printArray(int a[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//// Hàm menu
//void menu() {
//    int a[100], n, choice, x, result;
//    srand(time(NULL)); // Khởi tạo seed cho hàm rand()
//
//    while (1) {
//        printf("\nMenu:\n");
//        printf("1. Tao mang ngau nhien\n");
//        printf("2. Tao mang chua toan so chan\n");
//        printf("3. Tim kiem tuyen tinh\n");
//        printf("4. Sap xep tang/giam bang Interchange Sort\n");
//        printf("5. Tim kiem nhi phan\n");
//        printf("6. Sap xep tang dan bang Selection Sort\n");
//        printf("7. Sap xep tang dan bang Quick Sort\n");
//        printf("0. Thoat\n");
//        printf("Lua chon cua ban: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            createRandomArray(a, &n);
//            printf("Mang ngau nhien:\n");
//            printArray(a, n);
//            break;
//        case 2:
//            createEvenRandomArray(a, &n);
//            printf("Mang chua toan so chan:\n");
//            printArray(a, n);
//            break;
//        case 3:
//            printf("Nhap gia tri can tim: ");
//            scanf_s("%d", &x);
//            result = linearSearch(a, n, x);
//            if (result != -1) {
//                printf("Tim thay %d tai vi tri %d\n", x, result);
//            }
//            else {
//                printf("Khong tim thay %d trong mang\n", x);
//            }
//            break;
//        case 4:
//            printf("Chon kieu sap xep (1: Tang, 0: Giam): ");
//            int ascending;
//            scanf_s("%d", &ascending);
//            interchangeSort(a, n, ascending);
//            printf("Mang sau khi sap xep:\n");
//            printArray(a, n);
//            break;
//        case 5:
//            printf("Nhap gia tri can tim: ");
//            scanf_s("%d", &x);
//            interchangeSort(a, n, 1); // Sap xep tang truoc khi tim kiem nhi phan
//            result = binarySearch(a, n, x);
//            if (result != -1) {
//                printf("Tim thay %d tai vi tri %d\n", x, result);
//            }
//            else {
//                printf("Khong tim thay %d trong mang\n", x);
//            }
//            break;
//        case 6:
//            selectionSort(a, n);
//            printf("Mang sau khi sap xep bang Selection Sort:\n");
//            printArray(a, n);
//            break;
//        case 7:
//            quickSort(a, 0, n - 1);
//            printf("Mang sau khi sap xep bang Quick Sort:\n");
//            printArray(a, n);
//            break;
//        case 0:
//            exit(0);
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//        }
//    }
//}
//
//int main() {
//    menu();
//    return 0;
//}
