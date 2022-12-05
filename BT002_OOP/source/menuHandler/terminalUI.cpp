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
        Quanlinhanvien.quickSortBySalary(0,Quanlinhanvien.currentEmptyPos-1,ascending);
    }else if(str == std::string("des")){
        Quanlinhanvien.quickSortBySalary(0,Quanlinhanvien.currentEmptyPos-1,descending);
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
    Quanlinhanvien.quickSortBySalary(0,Quanlinhanvien.currentEmptyPos-1,ascending);

    cout << "\033[2J\033[1;1H";
    cout << green +"To use "+red+"binary sort"+green+", the list "+yellow+"automatically"+green+" get sorted in ascending order.\n\n";
    string text = "Employees with the salary of "; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +yellow+ to_string(number) +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    int index = binarySearch(Quanlinhanvien.array,0,Quanlinhanvien.currentEmptyPos-1,number);
    if(index != -1){
        cout << to_string(index+1) + ". " << Quanlinhanvien.array[index] << endl;
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
        if(pos < 1 || pos > (Quanlinhanvien.currentEmptyPos)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(Quanlinhanvien.currentEmptyPos) + "\n" + reset;
            updateObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = Quanlinhanvien.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        updateObjectUI();
    }

    Quanlinhanvien.updateObject(pos);
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
        if(pos < 1 || pos > (Quanlinhanvien.currentEmptyPos)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(Quanlinhanvien.currentEmptyPos) + "\n" + reset;
            deleteObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = Quanlinhanvien.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        deleteObjectUI();
    }

    Quanlinhanvien.deleteObject(pos);
    cout << "\033[2J\033[1;1H";
    cout << green +"Operation done successfully...\n\n";
    mainMenu();
    return 1;
}



int terminalUI::printTheListUI(){
    string text = "D.sach n.vien k.soat boi quan li ten " + red + Quanlinhanvien.tennguoiquanli; 
    cout << green + string(terminalWidth/3, '=') +yellow+underline+ text +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    for (int i = 0; i < Quanlinhanvien.currentEmptyPos; i++)
    {
        cout << to_string(i+1) + ". " << Quanlinhanvien.array[i] << endl;
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
        if(pos < 1 || pos > (Quanlinhanvien.currentEmptyPos+1)){
            cout << red + "\nInput need to be >= 1 and <= " + std::to_string(Quanlinhanvien.currentEmptyPos+1) + "\n" + reset;
            addNewObjectUI();
            return 0;
        }
    }else if(str == std::string("first")){
        pos = 1;
    }else if(str == std::string("last")){
        pos = Quanlinhanvien.currentEmptyPos+1;
    }else{
        cout << red + "\nOption not found, please re-enter.\n"+reset ;
        addNewObjectUI();
    }

    Nhanvien Nv;
    cin >> Nv;
    Quanlinhanvien.addNewObject(Nv,pos);
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
        this->canonMenu();
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
    string text = "Ch.trinh n.vien thuoc nguoi quan li ten " + red + Quanlinhanvien.tennguoiquanli; 
    cout << green + string(terminalWidth/3, '=') +yellow+underline+ text +reset + green+  string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    cout <<  red + "0. Quay lai Menu Chinh" << endl;
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

int terminalUI::canonMenu(){
    this->setQuanlinhanvien();
    string text = "Menu Chinh "; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +reset + green+  string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    cout <<  red + "0. Quit the program" << endl;
    cout <<  blue + "1. "+yellow+"In ra"+blue+" danh sach "+yellow+"cac nguoi quan li" << endl;
    cout <<  blue + "2. "+yellow+"Mo menu "+blue+"kiem soat nhan vien "+yellow+"cua nguoi quan li" << endl;
    cout <<  blue + "3. "+red+"Xoa"+blue+" nguoi quan li" << endl;
    cout <<  blue + "4. "+green+"Them"+blue+" nguoi quan li" << endl;
    cout <<  blue + "5."+yellow+" Tim"+blue+" nguoi quan li theo "+yellow+"ten" << endl;
    cout <<  blue + "6."+yellow+" Sap xep"+blue+" danh sach nguoi quan li theo "+yellow+"so luong nhan vien"+reset << endl;
    cout << green + string(terminalWidth, '=') + reset << '\n';
    Display(data);
    canongetInputOption();
    return 1;
}

int terminalUI::canongetInputOption(){
    cin.clear();
    fflush(stdin);
    
    cout << underline + "Choose your option:" + reset;
    int option;
    cin >> option; cout << endl;
    switch (option)
    {
    case 0:
        cout << "\033[2J\033[1;1H";
        cout << green + "Thank you for using the program\n" + reset;
        printLicense();
        exit(0);
        break;
    case 1:
        this->Display(data);
        canongetInputOption();
        break;
    case 2:
        this->getQuanlinhanvien();
        cout << "\033[2J\033[1;1H";
        mainMenu();
        break;
    case 3:
        this->DeleteByLocation(data);
        cout << "\033[2J\033[1;1H";
        this->canonMenu();
        break;
    case 4:
        this->themnguoiquanli();
        cout << "\033[2J\033[1;1H";
        this->canonMenu();
        break;
    case 5:
        this->timnguoiquanli();
        break;
    case 6:
        this->sortQuanli(data);
        cout << "\033[2J\033[1;1H";
        this->canonMenu();
        break;
    default:
        cout << red + "Option not found, please re-enter.\n" + reset;
        this->canongetInputOption();
        break;
    }

    return 1;
}

using NODE = terminalUI::NODE;

void terminalUI::Display(NODE * tail) {

    string text = "D.sach cac nguoi quan li"; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    
    NODE * current = tail;
    if (tail != NULL) {
        int stt = 1;
        do {
            current = current->next;
            //printf(" %d -> ", current -> data);
            cout << to_string(stt) + ". " << current->Quanlinhanvien << endl;
            stt++;
        } while (current != tail);
    }
        
    cout << green + string(terminalWidth, '=') + reset << '\n';
}

NODE * terminalUI::CreateNewNode(class Quanlinhanvien Ql) {
    NODE * newNode = new Node;
    newNode -> Quanlinhanvien = Ql;
    return newNode;
}

NODE * terminalUI::InsertAtHead(NODE * tail, class Quanlinhanvien Quanlinhanvien) {
    NODE * newNode = CreateNewNode(Quanlinhanvien);
    if (tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = tail -> next;
        tail -> next = newNode;
    }
    return tail;
}

NODE * terminalUI::InsertAtEnd(NODE * tail, class Quanlinhanvien Quanlinhanvien) {
    // simply insert at head and return the next node pointed by tail
    return InsertAtHead(tail, Quanlinhanvien) -> next;
}
template <typename T>
NODE * terminalUI::InsertAtArbitrary(NODE * tail, class Quanlinhanvien Quanlinhanvien, T location) {
    int len = Length(tail), i;
    if (location < 1 || location > len + 1) {
        cout << red + "Invalid location to enter data\n";
    } else {
        if (tail == NULL) return InsertAtHead(tail, Quanlinhanvien);
        NODE * newNode = CreateNewNode(Quanlinhanvien), * current = tail;
        for (i = 1; i != location; i++) current = current -> next;
        newNode -> next = current -> next;
        current -> next = newNode;
        if (location == len + 1) tail = newNode;
    }
    return tail;
}

void terminalUI::getQuanlinhanvien() {
    cin.clear();
    fflush(stdin);
   
    std::cout << underline + "Nhap ID nguoi quan li: " + reset;
    cin >> currentIndex;

    NODE * current = data;
    if (data != NULL) {
        int stt = 1;
        do {
            current = current->next;
            if(stt == currentIndex){
                Quanlinhanvien = current->Quanlinhanvien;
                return;
            }
            stt++;
        } while (current != data);
    }
}

void terminalUI::setQuanlinhanvien() {
    if(currentIndex == 0){
        return;
    }
    NODE * current = data;
    if (data != NULL) {
        int stt = 1;
        do {
            current = current->next;
            if(stt == currentIndex){
                current->Quanlinhanvien = Quanlinhanvien;
                return;
            }
            stt++;
        } while (current != data);
    }
}

int terminalUI::Length(NODE * tail) {
    NODE * current = tail;
    int i = 1;
    if (tail == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != tail) {
            i++;
            current = current -> next;
        }
    }
    return i;
}

NODE * terminalUI::DeleteByLocation(NODE * tail) {
    cin.clear();
    fflush(stdin);
    
    int location;
    std::cout << underline + "Nhap ID nguoi quan li muon xoa: " + reset;
    cin >> location;
    
    NODE * current, * previous = tail;
    int len = Length(tail), i;
    if(location == len){

    }else if (location < 1 || location > len) {
        cout << red + "Invalid Location to delete\n" + reset;
    } else if (len == 1) {
        tail = NULL;
        free(current);
    } else {
        current = tail -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == tail) tail = previous;
        free(current);
    }
 
    return tail;
}

void terminalUI::themnguoiquanli(){
    cin.clear();
    fflush(stdin);
    
    std::cout << underline + "Nhap vi tri muon them vao: " + reset;
    int temp; cin >> temp;
    
    int len = Length(data);
    try
    {
        if (temp < 1 || temp > len + 1) {
            throw 0;
        }
    }
    catch(const int& error)
    {
        cout << red + "\nInvalid location, please re-enter\n" + reset;
        themnguoiquanli();
        return;
    }
    
    class Quanlinhanvien ql;
    cin.clear();
    fflush(stdin);
    std::cout << underline + "Nhap ten nguoi quan li: " + reset;
    getline(cin, ql.tennguoiquanli);
    
    if(temp == len + 1){
        InsertAtEnd(data,ql);
    }else{
        InsertAtArbitrary(data,ql,temp);
    }
}

void terminalUI::timnguoiquanli(){
    cin.clear();
    fflush(stdin);

    std::cout << underline + "Nhap ten nguoi can tim: " + reset;
    string ten;
    getline(cin, ten);

    cout << "\033[2J\033[1;1H";
    string text = "Danh sach nguoi quan ly ten " + ten; 
    cout << green + string(terminalWidth/3, '=') +red+underline+ text +reset+ green+ string(terminalWidth - terminalWidth/3 - text.length(), '=') + reset<< '\n';
    
    NODE * current = data;
    if (data != NULL) {
        int stt = 1;
        do {
            current = current->next;
            string tengoc = current->Quanlinhanvien.tennguoiquanli;
            for(auto& a : tengoc)
            {
                a = tolower(a);
            }
            for(auto& b : ten)
            {
                b = tolower(b);
            }
            if(tengoc.compare(ten) == 0){
                cout << to_string(stt) + ". " << current->Quanlinhanvien << endl;
            }
            stt++;
        } while (current != data);
    }

    cout << green + string(terminalWidth, '=') + reset << '\n';
    
    canonMenu();
}

NODE * terminalUI::sortQuanli(NODE * tail) {
    if (Length(tail) < 2) return tail;
    NODE * ptr1 = tail -> next, * ptr2, * min;
    int temp;
    // selection sort implementation
    while (ptr1 -> next != tail -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != tail -> next) {
            if (min -> Quanlinhanvien.currentEmptyPos > ptr2 -> Quanlinhanvien.currentEmptyPos) min = ptr2;
            ptr2 = ptr2 -> next;
        }
        if (min != ptr1) {
            temp = min -> Quanlinhanvien.currentEmptyPos;
            min -> Quanlinhanvien.currentEmptyPos = ptr1 -> Quanlinhanvien.currentEmptyPos;
            ptr1 -> Quanlinhanvien.currentEmptyPos = temp;
        }
        ptr1 = ptr1 -> next;
    }
    return tail;
}