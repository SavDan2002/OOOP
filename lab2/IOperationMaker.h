#ifndef LAB2_IOPERATIONMAKER_H
#define LAB2_IOPERATIONMAKER_H

#include "IOperation.h"
#include <string>

class IOperationMaker {
public:
    virtual IOperation *create() = 0;
};
#endif
