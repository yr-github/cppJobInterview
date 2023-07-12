
#include"SampleFactory.h"
#include<memory>

int main(){
    // std::shared_ptr<Base> ptr=std::make_shared<Base>(std::move(*SampleFactory::creatProduct(ClassEnum::ENUM_BASESYNTAX)));
    
    // ptr.get()->run();
    Base* ptr1=SampleFactory::creatProduct(ClassEnum::ENUM_BASESYNTAX);
    ptr1->run();
}