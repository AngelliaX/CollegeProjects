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
    cout << inverse + "Type your input with this form \""+italy+yellow+"<Title>"+reset+inverse+"|"+italy+ yellow+"<Book's Code>"+reset+inverse+"|"+italy+ yellow +"<Amount>"+reset+inverse+"\"" + reset;
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