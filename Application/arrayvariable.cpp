#include "arrayvariable.h"

ArrayVariable::ArrayVariable(QString str, int s) : Identifier(str), MAX_SIZE(s) {
    array = new int[MAX_SIZE];
}

ArrayVariable::~ArrayVariable()
{
}

void ArrayVariable::set(int index, int value){
    if(index > size()-1){
        //index out of bounds
    }
    array[index] = value;
}

int ArrayVariable::size(){
    return (sizeof(*array)/sizeof(*array));
}
