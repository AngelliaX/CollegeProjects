#include <iostream>
#include <string>
#include "menuHandler.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

menuHandler::menuHandler(){
    this->libraryMenuUtils.bookControl = this->bookControl;
    this->libraryMenuUtils.terminalWidth = this->terminalWidth;

    
}

menuHandler::~menuHandler(){

}

int menuHandler::getInputOption(){
    cout << inverse + "Choose your option:" + reset;
    int option;
    cin >> option; cout << endl;
    switch (option)
    {
    case 0:
        cout << "\033[2J\033[1;1H";
        cout << green + "Thank you for using the program\n";
        exit(0);
        break;
    case 1:
        this->processingAnimation();
        this->printTheLibrary();
        break;
    case 2:
        this->processingAnimation();
        this->printStudentData();
        break;
    default:
        cout << red + "Option not found, please re-enter.\n" + reset;
        this->getInputOption();
        break;
    }

    return 1;
}

int menuHandler::printMenu(){
    string text = "Main Menu";
    cout << string(terminalWidth/3, '=') << red +bold+underline +text+ reset << string(terminalWidth - terminalWidth/3 - text.length(), '=') << '\n';
    // cout << red+"0. Exist program\n"+reset;
    // cout << "1. Open the Library\n";
    // cout << "2. Open the Student menu\n";
    cout <<                                                 right << setw(terminalWidth) << magenta+ "  _               _"+yellow+"   _           "+green+"        _   " +reset << endl;
    cout << red+"0. Exist program"+reset <<            right << setw(terminalWidth - 16) << magenta+ " | |_ _ _ ___ __"+yellow+"_| |_| |_ ___ _"+green+"__ ___ ___| |_ " +reset << endl;
    cout << "1. Open the Library" <<                   right << setw(terminalWidth - 19) << magenta+ " |  _| | |   "+yellow+"| . |  _|   | -"+green+"_| . | . | .'|  _|" +reset << endl;
    cout << "2. Open the Student menu" <<              right << setw(terminalWidth - 24) << magenta+ " |_| |___|"+yellow+"_|_|_  |_| |_|_"+green+"|___|_  |___|__,|_|  " +reset << endl;
    cout <<                                                 right << setw(terminalWidth) << magenta+ "       "+yellow+"      |___|    "+green+"       |___|            " +reset << endl;
    cout << string(terminalWidth, '=') << '\n';
    getInputOption();
    return 1;
}

int callback_printStudentData(void *aClass, int argc, char **argv, char **azColName) {
    class menuHandler* menuHandler = static_cast<class menuHandler*>(aClass);
    
    
    for(int i = 0; i<argc; i++) {  
        if(strcmp(azColName[i], "Id") == 0){
            menuHandler->studentControl.Id = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Name") == 0){
            menuHandler->studentControl.Name = argv[i];
        }else if(strcmp(azColName[i], "Class") == 0){
            menuHandler->studentControl.Class = argv[i];
        }else if(strcmp(azColName[i], "StudentId") == 0){
            menuHandler->studentControl.StudentId = argv[i];
        }else if(strcmp(azColName[i], "Amount_in_borrow") == 0){
            menuHandler->studentControl.Inuse = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Book_info") == 0){
            menuHandler->studentControl.Info = argv[i];
        }
    }
    if (menuHandler->studentControl.Name.length() >= menuHandler->Name_length){
        menuHandler->studentControl.Name = menuHandler->studentControl.Name.substr(0,menuHandler->Name_length-4) + "...";
    }
    if (menuHandler->studentControl.Class.length() >= menuHandler->Class_length){
        menuHandler->studentControl.Class = menuHandler->studentControl.Class.substr(0,menuHandler->Class_length-4) + "...";
    }
    if (menuHandler->studentControl.Info.length() >= menuHandler->Info_length){
        menuHandler->studentControl.Info = menuHandler->studentControl.Info.substr(0,menuHandler->Info_length-4) + "...";
    }
    cout
    << left << setw(menuHandler->Id_length) << menuHandler->studentControl.Id 
    << left << setw(menuHandler->StudentId_length) << menuHandler->studentControl.StudentId
    << left << setw(menuHandler->Name_length) << menuHandler->studentControl.Name
    << left << setw(menuHandler->Class_length) << menuHandler->studentControl.Class 
    << left << setw(menuHandler->Inuse_length) <<  std::to_string(menuHandler->studentControl.Inuse)
    << left << setw(menuHandler->Info_length) << menuHandler->studentControl.Info << "\n";
    return 0;
}

int menuHandler::printStudentData(){
    cout << "\033[2J\033[1;1H";
    char *sql = (char*) "SELECT * from studentinfo";


    string text = "Students' Database:";
    cout << string(terminalWidth/3, '=') << yellow + bold+underline + text + reset<< string(terminalWidth - terminalWidth/3 - text.length(), '=') << '\n';
    cout 
    << left << setw(8+ Id_length) << inverse+ "Id" + reset 
    << left << setw(8+ StudentId_length) <<inverse+ "Student's Id" +reset 
    << left << setw(8+ Name_length) <<inverse+ "Name" +reset 
    << left << setw(8+ Class_length) <<inverse+ "Class" +reset 
    << left << setw(8+Inuse_length) <<inverse+ "In use" +reset 
    << left << setw(8+Info_length) <<inverse+ "Book's info" +reset << "\n";
    int rc = sqlite3_exec(dataMain.db, sql, callback_printStudentData, (void*)this, &dataMain.zErrMsg);
    cout << string(terminalWidth, '=') << '\n';

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }
    //this->printLibraryMenu();
    return 1;
}

int callback_printTheLibrary(void *aClass, int argc, char **argv, char **azColName) {
    class menuHandler* menuHandler = static_cast<class menuHandler*>(aClass);
    
    
    for(int i = 0; i<argc; i++) {  
        if(strcmp(azColName[i], "Id") == 0){
            menuHandler->bookControl.Id = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Title") == 0){
            menuHandler->bookControl.Title = argv[i];
        }else if(strcmp(azColName[i], "Code") == 0){
            menuHandler->bookControl.Code = argv[i];
        }else if(strcmp(azColName[i], "Amount") == 0){
            menuHandler->bookControl.Amount = atoi(argv[i]);
        }else if(strcmp(azColName[i], "In_use") == 0){
            menuHandler->bookControl.In_use = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Users") == 0){
            menuHandler->bookControl.Users = argv[i];
        }
    }
    if (menuHandler->bookControl.Title.length() >= menuHandler->Title_length){
        menuHandler->bookControl.Title = menuHandler->bookControl.Title.substr(0,menuHandler->Title_length-4) + "...";
    }
    if (menuHandler->bookControl.Code.length() >= menuHandler->Code_length){
        menuHandler->bookControl.Code = menuHandler->bookControl.Code.substr(0,menuHandler->Code_length-4) + "...";
    }
    if (menuHandler->bookControl.Users.length() >= menuHandler->Users_length){
        menuHandler->bookControl.Users = menuHandler->bookControl.Users.substr(0,menuHandler->Users_length-4) + "...";
    }
    cout
    << left << setw(menuHandler->Id_length) << menuHandler->bookControl.Id 
    << left << setw(menuHandler->Title_length) << menuHandler->bookControl.Title
    << left << setw(menuHandler->Code_length) << menuHandler->bookControl.Code 
    << left << setw(menuHandler->Inuse_Amount_length) <<  std::to_string(menuHandler->bookControl.In_use)+"/"+std::to_string(menuHandler->bookControl.Amount) 
    << left << setw(menuHandler->Users_length) << menuHandler->bookControl.Users << "\n";
    return 0;
}

int menuHandler::printTheLibrary(){
    cout << "\033[2J\033[1;1H";
    char *sql = (char*) "SELECT * from thelibrary";


    string text = "The Library All Items:";
    cout << string(terminalWidth/3, '=') << yellow + bold+underline + text + reset<< string(terminalWidth - terminalWidth/3 - text.length(), '=') << '\n';
    cout 
    << left << setw(8 + Id_length) << inverse+ "Id" + reset << left << setw(8+ Title_length) <<inverse+ "Title" +reset 
    << left << setw(8+Code_length) <<inverse+ "Code" +reset << left << setw(8+Inuse_Amount_length) <<inverse+ "Amount" +reset << left << setw(8+Users_length) <<inverse+ "Users" +reset << "\n";
    int rc = sqlite3_exec(dataMain.db, sql, callback_printTheLibrary, (void*)this, &dataMain.zErrMsg);
    cout << string(terminalWidth, '=') << '\n';

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }
    this->printLibraryMenu();
    return 1;
}

int menuHandler::getLibraryInputOption(){
    cout << inverse + "Choose your option:" + reset;
    int option;
    cin >> option; cout << endl;
    switch (option)
    {
    case 0:
        cout << "\033[2J\033[1;1H";
        printMenu();
        break;
    case 1:
        this->libraryMenuUtils.addBookUI();
        this->printTheLibrary();
        this->printMenu();
        break;
    case 2: //remove book
        this->libraryMenuUtils.removeBook();
        this->printTheLibrary();
        this->printMenu();
        break;
    case 3: //add user
        this->libraryMenuUtils.addUser();
        this->printTheLibrary();
        this->printMenu();
        break;
    case 4: //remove user
        this->libraryMenuUtils.removeUser();
        this->printTheLibrary();
        this->printMenu();
        break;
    case 5: //edit quantity
        this->libraryMenuUtils.editQuantity();
        this->printTheLibrary();
        this->printMenu();
        break;
    default:
        cout << red + "Option not found, please re-enter.\n"+reset ;
        getLibraryInputOption();
        break;
    }

    return 1;
}

int menuHandler::printLibraryMenu(){
    string text1 = "Library";
    string text2 = "'s Menu";
    cout << string(terminalWidth/3, '=') << bold+underline+yellow+text1+red+text2+reset<< string(terminalWidth - terminalWidth/3 - text1.length() - text2.length(), '=') << '\n';
    cout << yellow + "0. Get back to "+red+"Main Menu\n"+reset;
    cout << "1. Add Book\n";
    cout << "2. Remove Book\n";
    cout << "3. Add User\n";
    cout << "4. Remove User\n";
    cout << "5. Edit book's quantity\n";
    cout << string(terminalWidth, '=') << '\n';
    getLibraryInputOption();
    return 1;
}

int menuHandler::processingAnimation(){
    cout << "\033[2J\033[1;1H";
    int param = 60000;
    int param2 = 400000;
    cout << "P"<< flush; usleep(param);cout << "r"<< flush; usleep(param);cout << "o"<< flush; usleep(param);cout << "g"<< flush; usleep(param);cout << "r"<< flush; usleep(param);cout << "a"<< flush; usleep(param);cout << "m"<< flush; usleep(param);cout << " "<< flush; usleep(param);
    cout << "i"<< flush; usleep(param);cout << "s"<< flush; usleep(param);cout << " "<< flush; usleep(param);
    cout << "r"<< flush; usleep(param);cout << "u"<< flush; usleep(param);cout << "n"<< flush; usleep(param);cout << "n"<< flush; usleep(param);cout << "i"<< flush; usleep(param);cout << "n"<< flush; usleep(param);cout << "g"<< flush; usleep(param);
    cout << ", "<< flush; usleep(param);cout << red+"p"<< flush; usleep(param);cout << "l"<< flush; usleep(param);cout << "e"<< flush; usleep(param);cout << "a"<< flush; usleep(param);cout << yellow+ "s"<< flush; usleep(param);cout << "e"<< flush; usleep(param);cout << " "<< flush;
    cout << "w"<< flush; usleep(param);cout << green+ "a"<< flush; usleep(param);cout << "i"<< flush; usleep(param);cout << "t"<< flush; usleep(param);
    usleep(param2);cout << "."<< flush; usleep(param2);cout << "."<< flush; usleep(param2);cout << "." + reset << flush; usleep(param2);
    cout << "\n";
    return 1;
}