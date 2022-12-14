#include <iostream>
#include <string>
#include "libraryMenuUtils.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "ANSI_colorCode.h"

#include <vector>
#include <sstream>

using namespace std;

libraryMenuUtils::libraryMenuUtils(){

}

libraryMenuUtils::~libraryMenuUtils(){

}


vector<string> splitString(string str){
    stringstream ss(str);
    vector<string> result;

    while( ss.good() )
    {      
        string substr;
        getline( ss, substr, '|' );
        result.push_back( substr );
    }
    return result;
}

int libraryMenuUtils::addBookUI(){
    cout << inverse + "Type your input with this form \""+italy+red+"<Title>"+reset+inverse+"|"+italy+ red+"<Book's Code>"+reset+inverse+"|"+italy+ red +"<Amount>"+reset+inverse+"\"" + reset;
    cout << inverse + " or type "+red+"back"+reset+inverse+" to return: "+reset;
    
    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    if(str == std::string("back")){
        return 0;
    }

    vector<string> param = splitString(str);

    if(param.size() != 3){
        cout << red + "\nWrong input type, please re-enter!.\n" + reset;
        this->addBookUI();
        return 1;
    }
    cout << endl;
    this->bookControl.addBook(param[0],param[1],atoi(param[2].c_str()));

    int num = 400000;
    cout << green + "\nSuccessfully add another record, redirect in 3" << flush;
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "2" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);    
    cout << "1" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << reset;
    return 1;
}

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int libraryMenuUtils::removeBook(){
    cout << inverse + "Type the "+red+"book's ID"+reset+inverse+" you wish removing";
    cout << inverse + " or type "+red+"back"+reset+inverse+" to return: "+reset;
    
    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }

    
    if(str == std::string("back")){
        return 0;
    }

    if(!isNumber(str)){
        cout << red + "\nInput need to be a number! Please re-enter.\n" + reset;
        this->removeBook();
        return 1;
    }

    cout << endl;
    this->bookControl.removeBookByID(str);

    int num = 400000;
    cout << green + "\nOperation done successfully, redirect in 3" << flush;
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "2" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);    
    cout << "1" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << reset;
    return 1;
}

int libraryMenuUtils::addUser(){
    cout << inverse + "Type your input with this form \""+italy+red+"<Book's Id>"+reset+inverse+"|"+italy+ red+"<Student's Code>"+reset+inverse+"\" to add" + reset;
    cout << inverse + " or type "+red+"back"+reset+inverse+" to return: "+reset;
    
    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }
    
    if(str == std::string("back")){
        return 0;
    }

    vector<string> param = splitString(str);

    if(param.size() != 2){
        cout << red + "\nWrong input type, please re-enter!.\n" + reset;
        this->addUser();
        return 1;
    }

    cout << endl;
    this->bookControl.addNewUser(param[1],param[0]);

    int num = 400000;
    cout << green + "\nOperation done successfully, redirect in 3" << flush;
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "2" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);    
    cout << "1" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << reset;
    return 1;
}

int libraryMenuUtils::removeUser(){
    cout << inverse + "Type your input with this form \""+italy+red+"<Book's Id>"+reset+inverse+"|"+italy+ red+"<Student's Code>"+reset+inverse+"\" to remove" + reset;
    cout << inverse + " or type "+red+"back"+reset+inverse+" to return: "+reset;
    
    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }
    
    if(str == std::string("back")){
        return 0;
    }

    vector<string> param = splitString(str);

    if(param.size() != 2){
        cout << red + "\nWrong input type, please re-enter!.\n" + reset;
        this->removeUser();
        return 1;
    }

    cout << endl;
    this->bookControl.removeUser(param[1],param[0]);

    int num = 400000;
    cout << green + "\nOperation done successfully, redirect in 3" << flush;
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "2" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "1" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << reset;
    return 1;
}

int libraryMenuUtils::editQuantity(){
    cout << inverse + "Type your input with this form \""+italy+red+"<Book's Id>"+reset+inverse+"|"+italy+ red+"<New Quantity>"+reset+inverse+"\" to edit" + reset;
    cout << inverse + " or type "+red+"back"+reset+inverse+" to return: "+reset;
    
    cin.clear();
    fflush(stdin);

    string str;
    getline(cin, str);
    
    if(str.empty()){
        getline(cin, str);
    }
    
    if(str == std::string("back")){
        return 0;
    }

    vector<string> param = splitString(str);

    if(param.size() != 2){
        cout << red + "\nWrong input type, please re-enter!.\n" + reset;
        this->removeUser();
        return 1;
    }

    cout << endl;
    
    this->bookControl.editQuantity(param[0],param[1]);

    int num = 400000;
    cout << green + "\nOperation done successfully, redirect in 3" << flush;
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "2" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "1" << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << "." << flush;usleep(num);
    cout << reset;
    return 1;
}

