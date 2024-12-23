#include <stdio.h>
#include <string.h>

struct Sinhvien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void printSinhvien(struct Sinhvien sinhvien) {
    printf("ID: %d\n", sinhvien.id);
    printf("Name: %s\n", sinhvien.name);
    printf("Age: %d\n", sinhvien.age);
    printf("Phone Number: %s\n\n", sinhvien.phoneNumber);
}

void printSinhviens(struct Sinhvien sinhviens[], int n) {
    if (n == 0) {
        printf("Danh sach sinh vien hien tai rong.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printSinhvien(sinhviens[i]);
    }
}

void themSinhvien(struct Sinhvien sinhviens[], int *n) {
    if (*n >= 5) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    struct Sinhvien newSinhvien;
    printf("Nhap ID: ");
    scanf("%d", &newSinhvien.id);
    getchar();
    printf("Nhap ten: ");
    fgets(newSinhvien.name, sizeof(newSinhvien.name), stdin);
    newSinhvien.name[strcspn(newSinhvien.name, "\n")] = '\0';
    printf("Nhap tuoi: ");
    scanf("%d", &newSinhvien.age);
    printf("Nhap so dien thoai: ");
    getchar();
    fgets(newSinhvien.phoneNumber, sizeof(newSinhvien.phoneNumber), stdin);
    newSinhvien.phoneNumber[strcspn(newSinhvien.phoneNumber, "\n")] = '\0';

    sinhviens[*n] = newSinhvien;
    (*n)++;
}

void suaSinhvien(struct Sinhvien sinhviens[], int n) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (sinhviens[i].id == id) {
            found = 1;
            printf("Nhap ten moi: ");
            getchar();
            fgets(sinhviens[i].name, sizeof(sinhviens[i].name), stdin);
            sinhviens[i].name[strcspn(sinhviens[i].name, "\n")] = '\0';
            printf("Nhap tuoi moi: ");
            scanf("%d", &sinhviens[i].age);
            printf("Nhap so dien thoai moi: ");
            getchar();
            fgets(sinhviens[i].phoneNumber, sizeof(sinhviens[i].phoneNumber), stdin);
            sinhviens[i].phoneNumber[strcspn(sinhviens[i].phoneNumber, "\n")] = '\0';
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void xoaSinhvien(struct Sinhvien sinhviens[], int *n) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (sinhviens[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                sinhviens[j] = sinhviens[j + 1];
            }
            (*n)--;
            printf("Sinh vien voi ID %d da duoc xoa.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void timKiemSinhvien(struct Sinhvien sinhviens[], int n) {
    char name[50];
    int found = 0;
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strstr(sinhviens[i].name, name) != NULL) {
            printSinhvien(sinhviens[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ten '%s'.\n", name);
    }
}

void sapXepSinhvien(struct Sinhvien sinhviens[], int n) {
    struct Sinhvien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sinhviens[i].name, sinhviens[j].name) > 0) {
                temp = sinhviens[i];
                sinhviens[i] = sinhviens[j];
                sinhviens[j] = temp;
            }
        }
    }
}

int main() {
    struct Sinhvien sinhviens[5] = {
        {1, "Nguyen A", 20, "0123456789"},
        {2, "Tran B", 21, "0123456790"},
        {3, "Le C", 22, "0123456801"},
        {4, "Pham D", 23, "0123456812"},
        {5, "Hoang E", 24, "0123456823"}
    };
    int n = 5;

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDanh sach sinh vien:\n");
                printSinhviens(sinhviens, n);
                break;
            case 2:
                themSinhvien(sinhviens, &n);
                break;
            case 3:
                suaSinhvien(sinhviens, n);
                break;
            case 4:
                xoaSinhvien(sinhviens, &n);
                break;
            case 5:
                timKiemSinhvien(sinhviens, n);
                break;
            case 6:
                sapXepSinhvien(sinhviens, n);
                printf("Danh sach sinh vien sau khi sap xep:\n");
                printSinhviens(sinhviens, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

