#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;

typedef struct {
    int tu;
    int mau;
} PhanSo;

void taoMangHonSo(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i].phan_nguyen = rand() % 10;
        b[i].tu_so = rand() % 10;
        do {
            b[i].mau_so = rand() % 9 + 1;
        } while (b[i].mau_so == 0);
    }
}

void xuatMangHonSo(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
}

int soSanhHonSo(HonSo a, HonSo b) {
    int phan_nguyen_cmp = a.phan_nguyen - b.phan_nguyen;
    if (phan_nguyen_cmp != 0) return phan_nguyen_cmp;

    int phan_so_a = a.tu_so * b.mau_so;
    int phan_so_b = b.tu_so * a.mau_so;
    return phan_so_a - phan_so_b;
}

PhanSo chuyenHonSoThanhPhanSo(HonSo hs) {
    PhanSo ps;
    ps.tu = hs.phan_nguyen * hs.mau_so + hs.tu_so;
    ps.mau = hs.mau_so;
    return ps;
}

HonSo chuyenPhanSoThanhHonSo(PhanSo ps) {
    HonSo hs;
    hs.phan_nguyen = ps.tu / ps.mau;
    hs.tu_so = ps.tu % ps.mau;
    hs.mau_so = ps.mau;
    return hs;
}

PhanSo congPhanSo(PhanSo a, PhanSo b) {
    PhanSo result;
    result.tu = a.tu * b.mau + b.tu * a.mau;
    result.mau = a.mau * b.mau;
    return result;
}

PhanSo truPhanSo(PhanSo a, PhanSo b) {
    PhanSo result;
    result.tu = a.tu * b.mau - b.tu * a.mau;
    result.mau = a.mau * b.mau;
    return result;
}

PhanSo nhanPhanSo(PhanSo a, PhanSo b) {
    PhanSo result;
    result.tu = a.tu * b.tu;
    result.mau = a.mau * b.mau;
    return result;
}

PhanSo chiaPhanSo(PhanSo a, PhanSo b) {
    PhanSo result;
    result.tu = a.tu * b.mau;
    result.mau = a.mau * b.tu;
    return result;
}

void bubbleSort(HonSo b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (soSanhHonSo(b[j], b[j + 1]) > 0) {
                HonSo temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                swapped = 1;
            }
        }
        // Nếu không có hoán đổi nào xảy ra, mảng đã được sắp xếp
        if (swapped == 0) break;
    }
}

void selectionSort(HonSo b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (soSanhHonSo(b[j], b[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            HonSo temp = b[min_idx];
            b[min_idx] = b[i];
            b[i] = temp;
        }
    }
}

void insertionSort(HonSo b[], int n) {
    for (int i = 1; i < n; i++) {
        HonSo key = b[i];
        int j = i - 1;
        while (j >= 0 && soSanhHonSo(b[j], key) > 0) {
            b[j + 1] = b[j];
            j = j - 1;
        }
        b[j + 1] = key;
    }
}

int main() {
    HonSo b[100];
    int n = 10;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tao mang hon so ngau nhien\n");
        printf("2. Xuat danh sach hon so\n");
        printf("3. So sanh 2 hon so\n");
        printf("4. Chuyen hon so thanh phan so\n");
        printf("5. Chuyen phan so thanh hon so\n");
        printf("6. Tinh tong, hieu, tich, thuong 2 hon so\n");
        printf("7. Sap xep mang\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            taoMangHonSo(b, n);
            break;
        case 2:
            xuatMangHonSo(b, n);
            break;
        case 3: {
            int idx1, idx2;
            printf("Nhap chi so cua 2 hon so de so sanh (0 den %d): ", n - 1);
            scanf_s("%d%d", &idx1, &idx2);
            int result = soSanhHonSo(b[idx1], b[idx2]);
            if (result == 0)
                printf("Hai hon so bang nhau\n");
            else if (result > 0)
                printf("Hon so thu nhat lon hon hon so thu hai\n");
            else
                printf("Hon so thu nhat nho hon hon so thu hai\n");
            break;
        }
        case 4: {
            int idx;
            printf("Nhap chi so cua hon so de chuyen (0 den %d): ", n - 1);
            scanf_s("%d", &idx);
            PhanSo ps = chuyenHonSoThanhPhanSo(b[idx]);
            printf("Phan so tuong ung: %d/%d\n", ps.tu, ps.mau);
            break;
        }
        case 5: {
            PhanSo ps;
            printf("Nhap tu so va mau so cua phan so: ");
            scanf_s("%d%d", &ps.tu, &ps.mau);
            HonSo hs = chuyenPhanSoThanhHonSo(ps);
            printf("Hon so tuong ung: %d %d/%d\n", hs.phan_nguyen, hs.tu_so, hs.mau_so);
            break;
        }
        case 6: {
            int idx1, idx2;
            printf("Nhap chi so cua 2 hon so (0 den %d): ", n - 1);
            scanf_s("%d%d", &idx1, &idx2);
            PhanSo ps1 = chuyenHonSoThanhPhanSo(b[idx1]);
            PhanSo ps2 = chuyenHonSoThanhPhanSo(b[idx2]);

            PhanSo tong = congPhanSo(ps1, ps2);
            PhanSo hieu = truPhanSo(ps1, ps2);
            PhanSo tich = nhanPhanSo(ps1, ps2);
            PhanSo thuong = chiaPhanSo(ps1, ps2);

            printf("Tong: %d/%d\n", tong.tu, tong.mau);
            printf("Hieu: %d/%d\n", hieu.tu, hieu.mau);
            printf("Tich: %d/%d\n", tich.tu, tich.mau);
            printf("Thuong: %d/%d\n", thuong.tu, thuong.mau);
            break;
        }
        case 7: {
            int sapXepChoice;
            printf("Chon thuat toan sap xep:\n");
            printf("1. Bubble Sort\n");
            printf("2. Selection Sort\n");
            printf("3. Insertion Sort\n");
            printf("Nhap lua chon: ");
            scanf_s("%d", &sapXepChoice);

            switch (sapXepChoice) {
            case 1:
                bubbleSort(b, n);
                printf("Da sap xep bang Bubble Sort\n");
                xuatMangHonSo(b, n); // In ra mang sau khi sap xep
                break;
            case 2:
                selectionSort(b, n);
                printf("Da sap xep bang Selection Sort\n");
                xuatMangHonSo(b, n); // In ra mang sau khi sap xep
                break;
            case 3:
                insertionSort(b, n);
                printf("Da sap xep bang Insertion Sort\n");
                xuatMangHonSo(b, n); // In ra mang sau khi sap xep
                break;
            default:
                printf("Lua chon khong hop le!\n");
            }
            break;
            }
        }
    }

    return 0;
}
