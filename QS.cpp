#include "QS.h"
#include <sstream>
#include <string>

QS::QS(){}
QS::~QS(){}

bool QS::createArray(int capacity){
    elements = -1;
    
    if(capacity < 0){
        return false;
    }

    else{
    // if(capacity == elements){
    //     delete [] arrPtr;
    // }
    arrPtr = new int[capacity];
    elements = 0;

    return true;
    }
}

bool QS::addToArray(int value){
    //check if the array is full!
    if(elements == capacity){
        return false;
    }
    
    else if(arrPtr){
        arrPtr[elements] = value;
        elements++;
        return true;
    }

    else{
        return false;
    }
}

string QS::getArray(){
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

int QS::getSize(){
    return elements;
}

void QS::clear(){
    delete [] arrPtr;
}

void QS::sortAll(){

}

int QS::medianOfThree(int left, int right){

}

int QS::partition(int left, int right, int pivotIndex){

}