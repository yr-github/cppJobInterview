
#include"SampleFactory.h"
#include<memory>
#include"BasicAlgorithm/stack/stack.h"
#include"BasicAlgorithm/queue/queueCustomize.h"
#include"BasicAlgorithm/binaryTree/binaryTree.h"

int main(){
    // std::shared_ptr<Base> ptr=std::make_shared<Base>(std::move(*SampleFactory::creatProduct(ClassEnum::ENUM_BASESYNTAX)));
    
    // ptr.get()->run();
    Base* ptr1=SampleFactory::creatProduct(ClassEnum::ENUM_BASESYNTAX);
    ptr1->run();
    queueCustomize<int> a(10);
    //stackCustomer<int> a(10);
    for (auto i = 0;i<=100;i++)
    {
        if(!a.push(i))
            std::cout<<"error: "<<i<<std::endl;
    }
    while(!a.isEmpty())
        std::cout<<a.pop()<<std::endl;
    binaryTree<int> b;
    // b.insterNode(5);
    // b.insterNode(2);
    // b.insterNode(7);
    // b.insterNode(3);
    // b.insterNode(6);
    // b.insterNode(1);
    // b.insterNode(8);

    b.insterNode(6);
    b.insterNode(3);
    b.insterNode(5);
    b.insterNode(4);
    b.insterNode(2);

    b.insterNode(10);
    b.insterNode(7);
    b.insterNode(8);
    b.insterNode(11);

    b.levelOrderTraversal();//correct
    std::cout<<std::endl;
    b.preOrderTraversal();//correct
    std::cout<<std::endl;
    b.middleOrderTraversal();
    std::cout<<std::endl;
    b.postOrderTraversal();
    std::cout<<std::endl;        
}