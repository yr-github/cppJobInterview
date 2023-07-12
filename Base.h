#ifndef BASE_H
#define BASE_H
#include"iostream"


template <typename T>
void output(std::ostream& os,T value){
    os<<value<<std::endl;
}


template <typename T,typename... TYPES>
void output(std::ostream& os,T value,TYPES... package ){
    os<<value<<" , ";
    output(os,package...);

}


enum ClassEnum{
    ENUM_BASESYNTAX=0,
    MAX
};


class Base
{
private:
    /* data */
public:
    Base(/* args */);
    ~Base();
    virtual void run(){
        output(std::cout,"No Derived Class existed, may be use wrong ClassEnum,please check");
    }
};

Base::Base(/* args */)
{
}

Base::~Base()
{
}
#endif


