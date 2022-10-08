#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define RESET "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

#include <stdio.h>
//#include <windows.h>

void menu();
void keepUsing();
void colorShift(int j);

//nCk 
long long int tohop(int k, int n){
	if(k==n || k==0) return 1;
	return tohop(k,n-1) * n/(n-k);

}

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
//================================================================================================================
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
                printf("%lld",c);
            }else{
                if(no_row < 5){
                    printf("% 2lld",c);
                }else if(no_row < 14){
                    printf("% 4lld",c);
                }else if(no_row < 21){
                    printf("% 6lld",c);
                }else if(no_row >= 21){
                    printf("% 8lld",c);
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
    //ẽSetConsoleOutputCP(CP_UTF8);
    
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
        //exit(1);
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
