#include "QS.h"
#include <sstream>
#include <string>

QS::QS(){}
QS::~QS(){
    delete [] arrPtr;
}

bool QS::createArray(int cap){
    elements = -1;

    if(capacity < 0){
        return false;
    }

    else{
        if(elements > 0){
            delete [] arrPtr;
        }
        capacity = cap;
        arrPtr = new int[capacity];
        elements = 0;

        return true;
    }
}

bool QS::addToArray(int value){
    if(elements == capacity){
        return false;
    }
    
    else{
        arrPtr[elements] = value;
        elements++;
        return true;
    }
}

string QS::getArray() const{
    stringstream ss;
    
    if(elements <= 0){
        ss << "";
    }

    else{
        for(int i = 0; i < elements; i++){
            if(i == elements - 1){
                ss << arrPtr[i];
            }
        
            else{
                ss << arrPtr[i] << ",";
            }
        }
    }
    
    return ss.str();
}

int QS::getSize() const{
    return elements;
}

void QS::clear(){
    elements = 0;
}

void QS::sortAll(){
    quickSort(0, elements - 1);
}

void QS::quickSort(int first, int last){
    if(last - first < 1){
        return;
    }

    int pivot = medianOfThree(first, last);
    pivot = partition(first, last, pivot);
    quickSort(first, pivot - 1);
    quickSort(pivot + 1, last);
}

int QS::medianOfThree(int left, int right){
    if(elements == 0){
        return -1;
    }
    if(left < 0){
        return -1;
    }
    if(right < 0){
        return -1;
    }
    if(left > elements - 1){
        return -1;
    }
    if(right > elements - 1){
        return -1;
    }
    if(right <= left){
        return -1;
    }
    
    int placeholder;
    int middle = (left + right) / 2;
    
    if(arrPtr[left] > arrPtr[middle]){
        placeholder = arrPtr[left];
        arrPtr[left] = arrPtr[middle];
        arrPtr[middle] = placeholder;
    }
    if(arrPtr[middle] > arrPtr[right]){
        placeholder = arrPtr[middle];
        arrPtr[middle] = arrPtr[right];
        arrPtr[right] = placeholder;
    }
    if(arrPtr[left] > arrPtr[middle]){
        placeholder = arrPtr[left];
        arrPtr[left] = arrPtr[middle];
        arrPtr[middle] = placeholder;
    }

    return middle;
}

int QS::partition(int left, int right, int pivotIndex){
    if(elements == 0){
        return -1;
    }
    if(left < 0){
        return -1;
    }
    if(right < 0){
        return -1;
    }
    if(left > elements - 1){
        return -1;
    }
    if(right > elements - 1){
        return -1;
    }
    if(left >= right){
        return -1;
    }
    if(pivotIndex < left || pivotIndex > right){
        return -1;
    }

    int placeholder;
    placeholder = arrPtr[pivotIndex];
    arrPtr[pivotIndex] = arrPtr[left];
    arrPtr[left] = placeholder;

    int up = left + 1;
    int down = right;

    do{
        while((arrPtr[up] <= arrPtr[left]) && (up < right)){
            up++;   
        }
        while((arrPtr[down] > arrPtr[left]) && (down > left)){
            down--;
        }
        if(up < down){
            placeholder = arrPtr[up];
            arrPtr[up] = arrPtr[down];
            arrPtr[down] = placeholder;
        }
    } while(up < down);

    placeholder = arrPtr[left];
    arrPtr[left] = arrPtr[down];
    arrPtr[down] = placeholder;

    return down;
}