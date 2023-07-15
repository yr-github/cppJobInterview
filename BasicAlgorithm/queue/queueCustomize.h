#ifndef QUEUECUSTOMIZE_H
#define QUEUECUSTOMIZE_H
template <typename T> class queueCustomize
{
private:
    /* data */
    unsigned int length;
    unsigned int capacity;
    unsigned int begin;
    unsigned int end;
    T* container;
public:
    queueCustomize(unsigned int len);
    ~queueCustomize();
    bool isEmpty();    
    bool push(const T& node);
    T& pop();

};

template <typename T> queueCustomize<T>::queueCustomize(unsigned int len)
{
    end=0;
    begin=0;
    length=0;
    capacity=len;    
    container=new T[len];
}

template <typename T> queueCustomize<T>::~queueCustomize(){
    delete []container;
}

template <typename T> bool queueCustomize<T>::isEmpty(){
    return length==0;
}

template <typename T> bool queueCustomize<T>::push(const T& node){
    if (length==capacity)
    {
       return false;
    }
    this->container[this->end%this->capacity]=node;
    this->end%=this->capacity;
    this->end++;
    this->length++;
    return true;
}

template <typename T> T& queueCustomize<T>::pop(){
    T& result = this->container[this->begin%this->capacity];
    this->begin%=this->capacity;
    this->begin++;
    this->length--;
    return result;
}

#endif