#include <iostream>
#include "List.h"

using namespace std;

List::List(){
   
}

List::~List(){

}


int swap(Nhanvien *Nv1, Nhanvien *Nv2){
    Nhanvien tmp = *Nv1;
    *Nv1 = *Nv2;
    *Nv2 = tmp;
    return 1;
}

int List::quickSortBySalary(int left, int right, bool(*mode)( double, double)){
    int key = (left + right) / 2;
	int i = left, j = right;
	while (i <= j) {
		while (mode(array[i].Salary, array[key].Salary)) i++;
		while (mode(array[key].Salary, array[j].Salary)) j--;
		if (i <= j) {
			if (i < j)
				swap(array[i], array[j]);
			i++; j--;
		}
	}
	if (left < j)
		quickSortBySalary(left, i, mode);
	if (i < right)
		quickSortBySalary(i, right, mode);
    return 1;
}

int List::checkCapicity(){
    if(currentEmptyPos >= size -5){
	    int newSize = size + 10;
        
	    // cấp phát động mảng mới 6 phần tử
	    Nhanvien *resize = new Nhanvien[newSize];

	    // sao chép phần tử
	    for (int i = 0; i < size; i++)
	    {
    		resize[i] = array[i];
	    }

	    delete[] array; // Xóa mảng hiện tại
	    array = resize; // Trỏ sang mảng đã resize
        size = newSize;
    }
    return 1;
}

int List::updateObject(int Pos){
    Pos -= 1;
    Nhanvien Nv;
    cin >> Nv;
    array[Pos] = Nv;

    return 1;
}

int List::deleteObject(int Pos){
    int n = currentEmptyPos-1;
    currentEmptyPos -= 1;
    Pos -= 1;

    for (int i = 0; i < Pos; ++i)
        *(array + i) = *(array + i);
    for (int i = Pos + 1; i < n + 1; ++i)
        *(array + i - 1) = *(array + i);
    
    return 1;
}

int List::addNewObject(Nhanvien Nv, int Pos){
    int n = currentEmptyPos+1;
    currentEmptyPos += 1;
    Pos -= 1;

    Nhanvien *newp = new Nhanvien[n];
    for (int i = 0; i < Pos; ++i)
        *(newp + i) = *(array + i);

    *(newp + Pos) = Nv;
    for (int i = Pos + 1; i < n; ++i)
        *(newp + i) = *(array + i - 1);

    delete[] array;
    array = newp;
     
    checkCapicity();
    return 1;
}