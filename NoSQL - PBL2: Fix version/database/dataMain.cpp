#include <iostream>
#include <string>
#include <cstring>
#include "dataMain.h"
using namespace std;

dataMain::dataMain(){
}

dataMain::~dataMain(){
    saveOutputFile();
}

int dataMain::saveOutputFile(){
    ofstream fileout;
	fileout.open("input.txt", ios::out);
    fileout << data.size() << endl;

    for (int i = 0; i < data.size(); i++)
    {
        fileout << std::to_string(i) <<"|"<< data[i].Title <<"|"<< data[i].Code <<"|"
        << std::to_string(data[i].Amount) <<"|"<< std::to_string(data[i].In_use) <<"|"<< data[i].Users << endl;
    }
    fileout.close();
    return 1;
}

int dataMain::readInputFile(){
    ifstream filein;
	filein.open("input.txt", ios::in);
    
	int inputAmount = 0;
	filein >> inputAmount;

    if(inputAmount == 0){
        return 1;
    }

	vector<string> ThuocTinh[1000];							
	char delim = '|';


    int i = 0;
    string line;
	while (filein){
	    getline(filein, line);
	    stringstream ss(line);
	    string word;

	    while (getline(ss, word, delim)){
			ThuocTinh[i].push_back(word);
		}
		++i;
	}

    Book tempbook;
	for(int i = 1; i <= inputAmount; i++){    
        tempbook.Id = stoi(ThuocTinh[i][0]);
        tempbook.Title = ThuocTinh[i][1];
        tempbook.Code = ThuocTinh[i][2];
        tempbook.Amount = stoi(ThuocTinh[i][3]);
        tempbook.In_use = stoi(ThuocTinh[i][4]);
        tempbook.Users = ThuocTinh[i][5];
		data.push_back(tempbook);
	}
	filein.close();
    return 1;
}

int dataMain::outputStudentData(){
    ofstream fileout;
	fileout.open("./database/studentData.txt", ios::out);
    fileout << studentData.size() << endl;

    for (int i = 0; i < studentData.size(); i++)
    {
        fileout << studentData[i].StudentId <<"|"<< studentData[i].Name <<"|"<< studentData[i].Class << endl;
    }
    fileout.close();
    return 1;
}

int dataMain::readStudentData(){
    ifstream filein;
	filein.open("./database/studentData.txt", ios::in);
    
	int inputAmount = 0;
	filein >> inputAmount;

    if(inputAmount == 0){
        return 1;
    }

	vector<string> ThuocTinh[1000];
	char delim = '|';


    int i = 0;
    string line;
	while (filein){
	    getline(filein, line);
	    stringstream ss(line);
	    string word;

	    while (getline(ss, word, delim)){
			ThuocTinh[i].push_back(word);
		}
		++i;
	}

    Student student;
	for(int i = 1; i <= inputAmount; i++){    
        for (int i = 0; i < data.size(); i++)
        {
            if(true){
                //todo check json of data.user then add the book to student info
            }
        }
        
        student.StudentId = ThuocTinh[i][0];
        student.Name = ThuocTinh[i][1];
        student.Class = ThuocTinh[i][2];
		studentData.push_back(student);
	}
	filein.close();
    return 1;
}