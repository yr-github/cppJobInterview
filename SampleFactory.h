#ifndef SAMPLEFACTORY_H
#define SAMPLEFACTORY_H
#include"Basesyntax/BaseSyntax.h"

class SampleFactory
{
private:
    /* data */
public:
    SampleFactory(/* args */);
    ~SampleFactory();
    static Base* creatProduct(ClassEnum value){        
        switch (value)
        {
        case ClassEnum::ENUM_BASESYNTAX:
            return new BaseSyntax();
            break;        
        default:
            return new Base();
            break;
        }
    }
};

SampleFactory::SampleFactory(/* args */)
{
}

SampleFactory::~SampleFactory()
{
}
#endif
