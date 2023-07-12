
#ifndef BASESYNTAX_H
#define BASESYNTAX_H
#include "../Base.h"

class BaseSyntax:public Base
{
private:
    /* data */
public:
    BaseSyntax(/* args */);
    ~BaseSyntax();
    virtual void run() override;
};

BaseSyntax::BaseSyntax(/* args */)
{
}

BaseSyntax::~BaseSyntax()
{
}

void BaseSyntax::run(){ 
    
}
#endif



