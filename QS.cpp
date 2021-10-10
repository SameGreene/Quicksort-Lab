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
    // The below is activated when testing. FIX
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
    cout << "sorting..." << endl;
}

int QS::medianOfThree(int left, int right){
    return 1;
}

int QS::partition(int left, int right, int pivotIndex){
    return 1;
}