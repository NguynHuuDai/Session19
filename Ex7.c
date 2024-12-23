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

void deleteSinhvien(int id, struct Sinhvien sinhviens[], int *currentLength) {
    int i;
    for (i = 0; i < *currentLength; i++) {
        if (sinhviens[i].id == id) {
            for (int j = i; j < *currentLength - 1; j++) {
                sinhviens[j] = sinhviens[j + 1];
            }
            (*currentLength)--;
            printf("Sinh vien co ID %d da duoc xoa.\n", id);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}

void printSinhviens(struct Sinhvien sinhviens[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien hien tai rong.\n");
        return;
    }
    for (int i = 0; i < currentLength; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printSinhvien(sinhviens[i]);
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
    
    int currentLength = 5;
    int idToDelete;
    
    printf("Danh sach sinh vien ban dau:\n");
    printSinhviens(sinhviens, currentLength);
    
    printf("Nhap ID sinh vien can xoa: ");
    if (scanf("%d", &idToDelete) != 1) {
        printf("Loi: Nhap khong hop le.\n");
        return 1;
    }
    
    if (idToDelete < 1 || idToDelete > 5) {
        printf("Loi: ID sinh vien khong hop le. Vui long nhap ID tu 1 den 5.\n");
        return 1;
    }
    
    deleteSinhvien(idToDelete, sinhviens, &currentLength);
    
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printSinhviens(sinhviens, currentLength);
    
    return 0;
}

