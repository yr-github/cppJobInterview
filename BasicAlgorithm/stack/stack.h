#ifndef STACK_H
#define STACK_H
//array implement
template <typename T> class stackCustomer
{
private:
    /* data */
    unsigned int length;
    unsigned int capacity;
    T *container;
    stackCustomer(/* args */);
public:
    
    stackCustomer(unsigned int len);//初始化长度为len的空栈
    ~stackCustomer();
    bool push(const T& node);
    bool isEmpty();
    //bool push(T node);
    unsigned int size();
    T& pop();
};

template <typename T> stackCustomer<T>::stackCustomer(/* args */)
{
}
template <typename T> stackCustomer<T>::stackCustomer(unsigned int len)
{
    this->capacity=len;
    this->length=0;
    this->container=new T[len];
}
template <typename T> stackCustomer<T>::~stackCustomer()
{
    delete[] this->container;
}

template <typename T> unsigned int stackCustomer<T>::size(){
    return this->length;
}

template <typename T> bool stackCustomer<T>::push(const T& node){
    if (this->length==this->capacity)//栈满了
    {
        return false;
    }
    this->container[length]=node;
    this->length++;
    return true;
}

template <typename T> T& stackCustomer<T>::pop(){
    static T default_value;
    if (isEmpty())
    {
        return default_value;
    }    
    T& result = this->container[length-1];
    this->length--;
    return result;
}

template <typename T> bool stackCustomer<T>::isEmpty(){
    return length==0;
}

#endif