#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://nguyenvanhieu.vn/bai-tap-danh-sach-lien-ket-don/

struct thanhphan{ 
    char hten[15];
    int masv;
    float diemtb;
    struct thanhphan *next;
};
typedef struct thanhphan *List;
List F = NULL;

void menu();
void nhapmoidanhsach();
void themvaocuoi(List p);
List taoList();
void lietke();
void cau1b();
void cau1c();

int option;
void main()
{
    menu();
    while(option){
        if(option == 1){
            nhapmoidanhsach();
        }else if(option == 2){
            cau1b();
        }else if(option == 3){
            cau1c();
        }else if(option == 4){
            lietke();
        }else{
            printf("\nYeu cau khong hop le, hay nhap lai\n");
            menu();
        }
    }
    printf("Cam on ban da dung phan mem");
}

void menu(){
    printf("\n");
    printf("Chuong trinh abcxyz\n");
    printf("Cac chuc nang:\n");
    printf("1. Nhap danh sach moi gom n sinh vien\n");
    printf("2. Nhap diem so x va in sinh vien diem cao hon x\n");
    printf("3. Liet ke sinh vien cao nhat\n");
    printf("4. Liet ke toan bo danh sach\n");
    printf("0. Ket thuc\n");
    printf("Hay nhap so ung voi chuc nang muon dung: ");
    scanf("%d", &option);
}

List taoList(){
    char hten[15];int masv;float diemtb;
    List p = (List)malloc(sizeof(struct thanhphan));
    p->next = NULL;
    
    printf("Nhap ten: ");
    fflush(stdin);gets(hten);
    strcpy(p->hten,hten);

    printf("Nhap ma sv & diem trung binh : ");
    scanf("%d %f",&masv,&diemtb);
    p->masv = masv;
    p->diemtb = diemtb;
    return p;
}

void themvaocuoi(List p){
    if(F == NULL){
        F = p;
    }else{
        List temp = F;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void nhapmoidanhsach(){
    int num;
    printf("Nhap so luong khoi tao: ");
    scanf("%d",&num);
    
    for(int i=0;i<num;i++){
        List p = taoList();
        themvaocuoi(p);
    }
    menu();
}

void lietke(){
    printf("\nDanh sach hien tai:\n");
    printf("%3s%30s%20s%20s\n", "STT", "Ten", "MSSV", "Diem TB");
    int num = 0;
    for(List p = F; p != NULL; p = p->next){
        printf("%3d%30s%20d%20.2f\n", num, p->hten, p->masv, p->diemtb);
        num++;
    }
    menu();
}

void cau1b(){
    int x;
    printf("Nhap diem so x: ");
    scanf("%d",&x);

    printf("\nDanh sach nguoi co diem cao hon %d:\n",x);
    printf("%3s%30s%20s%20s\n", "STT", "Ten", "MSSV", "Diem TB");
    int num = 0;
    for(List p = F; p != NULL; p = p->next){
        if(p->diemtb > x){
            printf("%3d%30s%20d%20.2f\n", num, p->hten, p->masv, p->diemtb);
        }
        num++;
    }
    menu();

}

void cau1c(){
    float highScore;
    for(List p = F; p != NULL; p = p->next){
        if(p->diemtb > highScore){
            highScore = p->diemtb;
        }
    }
    printf("\nDanh sach nguoi co diem cao nhat (%0.2f diem):\n",highScore);
    printf("%3s%30s%20s%20s\n", "STT", "Ten", "MSSV", "Diem TB");
    int num = 0;
    for(List p = F; p != NULL; p = p->next){
        if(p->diemtb == highScore){
            printf("%3d%30s%20d%20.2f\n", num, p->hten, p->masv, p->diemtb);
        }
        num++;
    }
    menu();
}