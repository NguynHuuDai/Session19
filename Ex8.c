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

void printSinhviens(struct Sinhvien sinhviens[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printSinhvien(sinhviens[i]);
    }
}

int main() {
    struct Sinhvien sinhviens[5] = {
        {1, "Nguyen Anh Minh", 20, "0123456789"},
        {2, "Tran Bao Ngoc", 21, "0123456790"},
        {3, "Le Cao Thành", 22, "0123456801"},
        {4, "Pham Viet Dung", 23, "0123456812"},
        {5, "Hoang Anh Minh", 24, "0123456823"}
    };
    
    int n = 5;  
    
    printf("Danh sach sinh vien ban dau:\n");
    printSinhviens(sinhviens, n);
    
    sapXepSinhvien(sinhviens, n);
    
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printSinhviens(sinhviens, n);
    
    return 0;
}

