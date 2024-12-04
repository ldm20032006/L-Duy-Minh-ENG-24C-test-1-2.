#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("MENU\n");
    printf("1. Nhap kich co và giá tri các phan tu cua mang\n");
    printf("2. In giá tri các phan tu cua mang theo ma tran\n");
    printf("3. In ra các phan tu nam trên duong bien va tinh tich\n");
    printf("4. In ra các phan tu nam tren duong cheo chinh\n");
    printf("5. In ra cac phan tu nam trên duong cheo phu\n");
    printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
    printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
    printf("8. Thoat\n");
}

void nhap_mang(int **mang, int n) {
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mang[i][j]);
}

void in_ma_tran(int **mang, int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mang[i][j]);
        printf("\n");
    }
}

void bien_va_tich(int **mang, int n) {
    int tich = 1;
    printf("Cac phan tu nam tren duong bien: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("%d ", mang[i][j]);
                tich *= mang[i][j];
            }
        }
    }
    printf("\nTich cua cac phan tu nam tren duong bien: %d\n", tich);
}

void duong_cheo_chinh(int **mang, int n) {
    printf("Cac phan tu nam tren duong cheo chinh: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void duong_cheo_phu(int **mang, int n) {
    printf("Cac phan tu nam tren duong cheo phu: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][n-1-i]);
    printf("\n");
}
 
void sap_xep_cheo_chinh(int **mang, int n) {
    int *chinh = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        chinh[i] = mang[i][i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (chinh[i] > chinh[j]) {
                int temp = chinh[i];
                chinh[i] = chinh[j];
                chinh[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        mang[i][i] = chinh[i];

    free(chinh);
    printf("Duong cheo chinh sau khi sap xep: ");
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i][i]);
    printf("\n");
}

void tim_kiem_phan_tu(int **mang, int n) {
    int x, found = 0;
    printf("Nhap gia tri phan tu can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mang[i][j] == x) {
                printf("Phan tu %d nam o vi tri: (%d, %d)\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found)
        printf("Khong tim thay phan tu %d trong mang.\n", x);
}

int main() {
    int n, choice;
    printf("Nhap kich co cua mang: ");
    scanf("%d", &n);

    int **mang = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mang[i] = (int *)malloc(n * sizeof(int));

    do {
        display_menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhap_mang(mang, n);
                break;
            case 2:
                in_ma_tran(mang, n);
                break;
            case 3:
                bien_va_tich(mang, n);
                break;
            case 4:
                duong_cheo_chinh(mang, n);
                break;
            case 5:
                duong_cheo_phu(mang, n);
                break;
            case 6:
                sap_xep_cheo_chinh(mang, n);
                break;
            case 7:
                tim_kiem_phan_tu(mang, n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop li. Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);

    for (int i = 0; i < n; i++)
        free(mang[i]);
    free(mang);

    return 0;
}

