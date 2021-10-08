#ifndef QS_H
#define QS_H
#include "QSInterface.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class QS: public QSInterface {
private:
    int capacity;
    int* arrPtr;
    int elements;

public:
    QS();
    ~QS();
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray();
    int getSize();
    bool addToArray(int value);
    bool createArray(int capacity);
    void clear();
};

#endif