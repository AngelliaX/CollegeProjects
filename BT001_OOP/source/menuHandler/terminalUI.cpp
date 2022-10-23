#include <iostream>
#include "terminalUI.h"
#include "ANSI_colorCode.h"

using namespace std;

string black = "\033[30m";
string red = "\033[31m";
string green = "\033[32m";
string yellow = "\033[33m";
string blue = "\033[34m";
string magenta = "\033[35m";
string cyan = "\033[36m";
string white = "\033[37m";

// background colors
string bg_black = "\033[40m";
string bg_red = "\033[41m";
string bg_green = "\033[42m";
string bg_yellow = "\033[43m";
string bg_blue = "\033[44m";
string bg_magenta = "\033[45m";
string bg_cyan = "\033[46m";
string bg_white = "\033[47m";

//formmat
string reset = "\033[0m";
string bold = "\033[1m";
string italy = "\033[3m";
string underline = "\033[4m";
string inverse = "\033[7m"; //(swap foreground and background colours

terminalUI::terminalUI(){
   
}

terminalUI::~terminalUI(){

}

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

bool ascending(double salary1, double salary2) {
    return salary1 < salary2;
}
bool descending(double salary1, double salary2) {
    return salary1 > salary2;
}

int terminalUI::quickSortBySalaryUI(){
    cout << underline + "Pick an option to "+yellow+"sort"+reset + underline+", type "+"\""+red+"asc"+reset+underline+"\" for ascending, "+"\""+red+"des"+reset+underline+"\" for descending "+":" + reset;

    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    if(str == std::string("asc")){
        List.quickSortBySalary(0,List.currentEmptyPos-1,ascending);
    }else if(str == std::string("des")){
        List.quickSortBySalary(0,List.currentEmptyPos-1,descending);
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        quickSortBySalaryUI();
    }
    
    cout << "\033[2J\033[1;1H";
    cout << green +"Operation done successfully...\n\n";
    mainMenu();
    return 1;
}

int binarySearch(Nhanvien arr[], int l, int r, double x) {
    if (r >= l) {
        int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn
 
    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (arr[mid].Salary == x)
        return mid;
 
    // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    if (arr[mid].Salary > x)
        return binarySearch(arr, l, mid - 1, x);
 
    // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
    return binarySearch(arr, mid + 1, r, x);
    }
 
    // Nếu không tìm thấy
    return -1;
}

int terminalUI::findObjectUI(){
    cin.clear();
    fflush(stdin);

    std::cout << underline + "Type the salary's number: " + reset;
    double number; cin >> number;
    List.quickSortBySalary(0,List.currentEmptyPos-1,ascending);

    cout << "\033[2J\033[1;1H";
    cout << green +"To use "+red+"binary sort"+green+", the list "+yellow+"automatically"+green+" get sorted in ascending order.\n\n";
    string text = "Employees with the salary of "; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +yellow+ to_string(number) +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    int index = binarySearch(List.array,0,List.currentEmptyPos-1,number);
    if(index != -1){
        cout << to_string(index+1) + ". " << List.array[index] << endl;
    }else{
        cout << red + "No value founded" << endl;
    }
    cout << green + string(terminalWidth, '=') + reset << '\n';
    
    mainMenu();
    return 1;
}

int terminalUI::updateObjectUI(){
    cout << underline + "Pick a position to "+yellow+"update"+reset + underline+", type "+"\""+red+"first"+reset+underline+"\" for 1st place, "+"\""+red+"last"+reset+underline+"\" for last place, "+"\""+red+"<number>"+reset+underline+"\" for a specific place, " +":" + reset;
    int pos;

    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    if(isNumber(str)){
        pos = stoi(str);
        if(pos < 1 || pos > (List.currentEmptyPos)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(List.currentEmptyPos) + "\n" + reset;
            updateObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = List.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        updateObjectUI();
    }

    List.updateObject(pos);
    cout << "\033[2J\033[1;1H";
    cout << green +"Operation done successfully...\n\n";
    mainMenu();
    return 1;
}

int terminalUI::deleteObjectUI(){
    cout << underline + "Pick a position to "+red+"delete"+reset + underline+", type "+"\""+red+"first"+reset+underline+"\" for 1st place, "+"\""+red+"last"+reset+underline+"\" for last place, "+"\""+red+"<number>"+reset+underline+"\" for a specific place, " +":" + reset;
    int pos;

    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    if(isNumber(str)){
        pos = stoi(str);
        if(pos < 1 || pos > (List.currentEmptyPos)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(List.currentEmptyPos) + "\n" + reset;
            deleteObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = List.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        deleteObjectUI();
    }

    List.deleteObject(pos);
    cout << "\033[2J\033[1;1H";
    cout << green +"Operation done successfully...\n\n";
    mainMenu();
    return 1;
}



int terminalUI::printTheListUI(){
    string text = "The List"; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    for (int i = 0; i < List.currentEmptyPos; i++)
    {
        cout << to_string(i+1) + ". " << List.array[i] << endl;
    }
    cout << green + string(terminalWidth, '=') + reset << '\n';
    return 1;
}

int terminalUI::addNewObjectUI(){
    cout << underline + "Pick a position to "+green+"add"+reset + underline+", type "+"\""+red+"first"+reset+underline+"\" for 1st place, "+"\""+red+"last"+reset+underline+"\" for last place, "+"\""+red+"<number>"+reset+underline+"\" for a specific place, " +":" + reset;
    int pos;

    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    if(isNumber(str)){
        pos = stoi(str);
        if(pos < 1 || pos > (List.currentEmptyPos+1)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(List.currentEmptyPos+1) + "\n" + reset;
            addNewObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = List.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        addNewObjectUI();
    }

    Nhanvien Nv;
    cin >> Nv;
    List.addNewObject(Nv,pos);
    cout << "\033[2J\033[1;1H";
    cout << green +"Operation done successfully...\n\n";
    mainMenu();
    return 1;
}

void printLicense(){
    cout << "  _______             _______ _           _____             _   " << endl;
    cout << " |__   __|           |__   __| |         / ____|           | |  " << endl;
    cout << "    | |_   _ _ __   __ _| |  | |__   ___| |  __  ___   __ _| |_ " << endl;
    cout << "    | | | | | '_ \\ / _` | |  | '_ \\ / _ \\ | |_ |/ _ \\ / _` | __|" << endl;
    cout << "    | | |_| | | | | (_| | |  | | | |  __/ |__| | (_) | (_| | |_ " << endl;
    cout << "    |_|\\__,_|_| |_|\\__, |_|  |_| |_|\\___|\\_____|\\___/ \\__,_|\\__|" << endl;
    cout << "                    __/ |                                       " << endl;
    cout << "                   |___/                                        " << endl;

}

int terminalUI::getInputOption(){
    cout << underline + "Choose your option:" + reset;
    int option;
    cin >> option; cout << endl;
    switch (option)
    {
    case 0:
        cout << "\033[2J\033[1;1H";
        cout << green + "Thank you for using the program\n";
        printLicense();
        exit(0);
        break;
    case 1:
        this->printTheListUI();
        getInputOption();
        break;
    case 2:
        this->addNewObjectUI();
        break;
    case 3:
        this->deleteObjectUI();
        break;
    case 4:
        this->updateObjectUI();
        break;
    case 5:
        this->findObjectUI();
        break;
    case 6:
        this->quickSortBySalaryUI();
        break;
    default:
        cout << red + "Option not found, please re-enter.\n" + reset;
        this->getInputOption();
        break;
    }

    return 1;
}
int terminalUI::mainMenu(){
    string text = "A random program"; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +reset + green+  string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    cout <<  red + "0. Quit the program" << endl;
    cout <<  blue + "1. Print all the values in the list" << endl;
    cout <<  blue + "2. "+green+"Add"+blue+" a new object" << endl;
    cout <<  blue + "3. "+red+"Delete"+blue+" an object" << endl;
    cout <<  blue + "4. "+yellow+"Update"+blue+" an object" << endl;
    cout <<  blue + "5."+yellow+" Find"+blue+" an object by "+yellow+"salary"+red+" (automatically sort)" << endl;
    cout <<  blue + "6."+yellow+" Sort"+blue+" the list by "+yellow+"salary,"+blue+" whether "+red+"ascending"+blue+" or "+red+"descending"+reset << endl;
    cout << green + string(terminalWidth, '=') + reset << '\n';
    printTheListUI();
    getInputOption();
    return 1;
}
