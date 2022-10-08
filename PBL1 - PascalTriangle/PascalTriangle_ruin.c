#include "ANSI-color-codes.h"
#include <stdio.h>
#include <windows.h>

void menu();
void keepUsing();
void colorShift(int j);

//nCk 
//O(n)
long long int tohop(int k, int n){
	if(k==n || k==0) return 1;
	return tohop(k,n-1) * n/(n-k);
}

//O(n^2)
void printNthLineStraight(){
    int n;
    printf(YEL "\nDòng bạn muốn in ra là: " CYN);
    scanf("%d", &n); printf(RESET);
    n -= 1;
    
    if(n <= -1){
        printf(RED "\nSố dòng phải bắt đầu từ số " CYN "1 " RED "trở lên \n\n" RESET);
        keepUsing(); return;
    }

    if(n == 0){
        printf(GRN "\nChỉ có 1 số: " CYN "1 \n\n" RESET);
        keepUsing(); return;
    }
    
    printf(GRN "\nDãy thứ " BBLU); printf("%d",n+1); printf(GRN " gồm có " BBLU "%d",n+1); printf(GRN" chữ số:\n\n" RESET);
    int colorState = 0; 
    long long int keepNumber[100000];
    int pos = (n+1)/2;
    if(n % 2 == 0){ // n = 2;4;6
        for (int i = 0; i <= pos; i++)
        {
            colorShift(colorState);
            long long temp = tohop(i,n);
            if(i == pos){
                printf(RESET "||");
                colorShift(colorState);
                printf(" %lli ",temp);
                printf(RESET "|| ");
                colorState--;
            }else{
                printf("%lli ",temp);
            }
            
            keepNumber[pos+ (i+1)] = temp;
            colorState++;
        }
        for(int i = (n); i > pos; i--){
            colorState--;
            colorShift(colorState);
            printf("%lli ",keepNumber[i]);
        }
        printf("\n");
        printf(RESET);
        //keepUsing(); return;
    }else{ // n = 1;3;5;7
        
        for (int i = 0; i < pos; i++)
        {
            colorShift(colorState);
            long long temp = tohop(i,n);
            printf("%lli ",temp);
            keepNumber[pos+ (i+1)] = temp;
            colorState++;
            if(i == pos-1){
                printf(RESET "|| ");
            }
        }
        for(int i = (n+1); i > pos; i--){
            colorState--;
            colorShift(colorState);
            printf("%lli ",keepNumber[i]);
        }
        printf("\n");
        printf(RESET);
        //keepUsing(); return;
    }
    menu();
}
//================================================================================================================
//O(n^2)================================================================================================================
void printNthLine(){
    int n;
    printf(YEL "\nDòng bạn muốn in ra là: " CYN);
    scanf("%d", &n); printf(RESET);
    n -= 1;
    if(n <= -1){
        printf(RED "\nSố dòng phải bắt đầu từ số " CYN "1 " RED "trở lên \n\n" RESET);
        keepUsing(); return;
    }
    if(n == 0){
        printf(GRN "\nChỉ có 1 số: " CYN "1 \n\n" RESET);
        keepUsing(); return;
    }
    
    printf(GRN "\nDãy thứ " BBLU); printf("%d",n+1); printf(GRN " gồm có " BBLU "%d",n+1); printf(GRN" chữ số\n" RESET);
    int pos = (n + 1)/2;
    if(n % 2 == 0){ // n = 2;4;6
        for (int i = 0; i <= pos; i++)
        {
            printf(GRN "Số thứ " BBLU); printf("%d: ",i+1); printf(GRN ":" RED " %lli\n",tohop(i,n));
        }
        printf(GRN "Bỏ đi số chính giữa thì nửa sau giống nửa trước, nhưng đảo chiều\n");
        printf(RESET);
        //keepUsing(); return;
    }else{ // n = 1;3;5;7
        
        for (int i = 0; i < pos; i++)
        {
            printf(GRN "Số thứ " BBLU); printf("%d: ",i+1); printf(GRN ":" RED " %lli\n",tohop(i,n));
        }
        printf(GRN "Nửa sau giống nửa trước, nhưng đảo chiều\n");
        printf(RESET);
        //keepUsing(); return;
    }
    menu();
}

//Cau 2 https://www.w3resource.com/c-programming-exercises/for-loop/c-for-loop-exercises-33.php=======================================================================
//O(n^2 + n^2)
void printPascalTriangle(int option){
    int no_row,blk,i,j;
    long long int c = 1;
    printf(YEL "\nNhập số dòng muốn in của tam giác: " CYN);
    scanf("%d", &no_row); printf(RESET);
    if(no_row >= 27){
        printf(RED "Từ dòng 27 trở đi sẽ ko đủ chỗ hiển thị, bạn có muốn tiếp tục? (1 = YES, 0 = NO) " CYN);
        int temp; scanf("%d", &temp); printf(RESET);
        if(temp == 0){
            menu(); return;
        }
    }
    
    for(i=0;i<no_row;i++)
    {
        if(option){
            for(blk=1;blk < no_row-i;blk++){
                if(no_row < 5){
                    printf(" ");
                }else if(no_row < 14){
                    printf("  ");
                }else if(no_row < 21){
                    printf("   ");
                }else if(no_row >= 21){
                    printf("    ");
                }
            }
        }
        int pos = -1;
        if(i % 2 != 0){
            pos = 0;
        }
        for(j=0;j<=i;j++)
        {
            if(i % 2 == 0){ //dòng có số chính giữa , i = 0;2;4
                if(j <= i/2){ //set màu tới số chính giữa
                    colorShift(j);
                    pos++;
                }else{
                    pos--;
                    colorShift(pos);
                }
            }else{//ko có số giữa, i = 1;3;5
                if(j < (i+1)/2){ //set màu vế trái
                    colorShift(j);
                    pos++;
                }else{
                    pos--;
                    colorShift(pos);
                }
            }
           
            c = tohop(j,i);
            if(j == 0){
                printf("%d",c);
            }else{
                if(no_row < 5){
                    printf("% 2d",c);
                }else if(no_row < 14){
                    printf("% 4d",c);
                }else if(no_row < 21){
                    printf("% 6d",c);
                }else if(no_row >= 21){
                    printf("% 8d",c);
                }
            }      
        }
        printf("\n");
    }
    printf(RESET); menu();
}
//============================================================================
int option;
void main(){
    SetConsoleOutputCP(CP_UTF8);
    
    menu();
    while(option){
        if(option == 1){
            printNthLineStraight();
        }else if(option == 2){
            printPascalTriangle(0);
        }else if(option == 3){
            printNthLine();
        }else if(option == 4){
            printPascalTriangle(1);
        }else{
            printf(BMAG "\nYêu cầu không hợp lệ, lựa chọn chỉ gồm 5 số " BYEL "1-2-3-4-0 \n"RESET);
            menu();
        }
    }
    printf(UYEL "Cảm ơn bạn đã dùng phần mềm"RESET);
}

void menu(){
    //printf(RED "If" BLU "you" YEL "are" GRN "bored" CYN "do" MAG "this! \n" RESET);
	//printf(BRED "If" BBLU "you" BYEL "are" BGRN "bored" BCYN "do" BMAG "this! \n" RESET); 
	//printf(URED "If" UBLU "you" UYEL "are" UGRN "bored" UCYN "do" UMAG "this! \n" RESET);
    printf("\n");
    printf(BRED "Chương trình:" BBLU " Tam giác Pascal\n" RESET);
    printf(GRN "Các chức năng:\n");
    printf(BBLU "1." YEL " In Một Dòng" GRN " thứ " YEL "N " GRN "của tam giác\n");
    printf(BBLU "2." YEL " In tam giác Vuông" GRN " có " YEL "N " GRN "dòng\n");
    printf(BBLU "3." RED " In Nửa Dòng" GRN " thứ " RED "N " GRN "của tam giác\n");
    printf(BBLU "4." RED " In tam giác Cân" GRN " có " RED "N " GRN "dòng\n");
    printf(BBLU "0." GRN " Kết thúc chương trình\n" RESET);
    printf(RED "Hãy nhập số ứng với chức năng muốn dùng: " CYN);
    scanf("%d", &option);
    printf(RESET);
}

void keepUsing(){
    printf(YEL "Bạn có muốn dùng tiếp không (1 = Yes, 0 = No): " CYN);
    int temp;
    scanf("%d", &temp);
    if(temp){
        menu();
    }else{
        printf(URED "Cảm ơn bạn đã dùng phần mềm"RESET);
        exit(1);
    }
}
void colorShift(int j){
    if(j % 6 == 0){
        printf(BRED);
    }else if(j % 6 == 1){
        printf(BBLU);
    }else if(j % 6 == 2){
         printf(BYEL);
    }else if(j % 6 == 3){
        printf(BGRN);
    }else if(j % 6 == 4){
        printf(BCYN);
    }else if(j % 6 == 5){
        printf(BMAG);
    }
}