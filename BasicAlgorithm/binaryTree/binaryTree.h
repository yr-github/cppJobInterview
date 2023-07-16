#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include"../queue/queueCustomize.h"
template <typename T> class binaryTree
{
private:
    /* data */
    struct binaryTreeNode
    {
        T Data;
        binaryTreeNode* left=nullptr;
        binaryTreeNode* right=nullptr;
        ~binaryTreeNode(){
            left=nullptr;
            right=nullptr;            
        }
    };
    binaryTreeNode* root;
    unsigned int nodeNum;
public:
    binaryTree(/* args */);
    
    bool isEmpty();
    void preOrderTraversal();//前序
    void middleOrderTraversal();//中序
    void postOrderTraversal();//后序
    void levelOrderTraversal();//层序
    unsigned int leafNodesNum();
    void insterNode(const T& node);
    binaryTreeNode* find(const T& target);
    binaryTreeNode* findMin(binaryTreeNode* node);
    binaryTreeNode* findMax(binaryTreeNode* node);

    binaryTreeNode* deleteFindMin(binaryTreeNode* node);
    binaryTreeNode* deleteFindMax(binaryTreeNode* node);
    bool deleteNode(const T& target);
    ~binaryTree();
};

template <typename T> binaryTree<T>::binaryTree(/* args */)
{
    root=nullptr;
    nodeNum=0;
}

template <typename T> binaryTree<T>::~binaryTree()
{
    queueCustomize<binaryTreeNode*> queue(leafNodesNum());
    queue.push(this->root);
    while (!queue.isEmpty())
    {
        binaryTreeNode* temp = queue.pop();        
        if (temp->left)
        {
            queue.push(temp->left);
        }
        if(temp->right)
        {
            queue.push(temp->right);
        }
        delete temp;
    }
}
template <typename T> bool binaryTree<T>::isEmpty()
{
    return false;
}
template <typename T> void binaryTree<T>::preOrderTraversal()
{
    stackCustomer<binaryTreeNode*> stack(leafNodesNum());
    stack.push(root);
    binaryTreeNode* temp;
    while (!stack.isEmpty())
    {
        temp = stack.pop();
        std::cout<<temp->Data;        
        if(temp->right){
            stack.push(temp->right);
        }
        if(temp->left){
            stack.push(temp->left);
        }         
    }    
}
template <typename T> void binaryTree<T>::middleOrderTraversal()
{
    stackCustomer<binaryTreeNode*> stack(leafNodesNum());
    stack.push(root);
    binaryTreeNode* temp=root;
    while (temp || !stack.isEmpty())
    {        
        while (temp)
        {
            stack.push(temp->left);
            temp=temp->left;
        }
        temp=stack.pop();
        if (temp)
        {
            std::cout<<temp->Data;
        }                
        if (temp&&temp->right)
        {
            stack.push(temp->right);
            temp=temp->right;
        }else
        {
            temp=nullptr;//important
        }
    }
}
template <typename T> void binaryTree<T>::postOrderTraversal()
{
    stackCustomer<binaryTreeNode*> stack(leafNodesNum());
    stack.push(root);
    binaryTreeNode* temp=root;
    binaryTreeNode* pre=nullptr;
    while (temp || !stack.isEmpty())
    {        
        while (temp)
        {
            stack.push(temp->left);
            temp=temp->left;
        }
        temp=stack.pop();       
        if (temp)
        {            
            if(temp->right&&temp->right!=pre){          
                stack.push(temp);
                stack.push(temp->right);
                temp=temp->right;
            }else{                                
                std::cout<<temp->Data;
                pre=temp;
                temp=nullptr;
            }
        }
    }
}

template <typename T> unsigned int binaryTree<T>::leafNodesNum()
{
    return nodeNum;//TODO
}

template <typename T> void binaryTree<T>::levelOrderTraversal()
{
    queueCustomize<binaryTreeNode*> queue(leafNodesNum());
    queue.push(this->root);
    while (!queue.isEmpty())
    {
        binaryTreeNode* temp = queue.pop();
        std::cout<<temp->Data;
        if (temp->left)
        {
            queue.push(temp->left);
        }
        if(temp->right)
        {
            queue.push(temp->right);
        }
    }
}

template<typename T> void binaryTree<T>::insterNode(const T& node){
    nodeNum++;
    if (root)
    {
        binaryTreeNode* temp=root;
        while (temp)
        {
            if (temp->Data > node)
            {
                if (temp->left)
                {
                    temp=temp->left;
                }else{
                    temp->left=new binaryTreeNode();
                    temp->left->Data=node;
                    temp=nullptr;
                }                                
            }else
            {
                if (temp->right)
                {
                    temp=temp->right;
                }else{
                    temp->right=new binaryTreeNode();
                    temp->right->Data=node;
                    temp=nullptr;
                }                
            }                        
        }                
    }else
    {
        root=new binaryTreeNode();
        root->Data=node;
    }        
}

template<typename T> typename binaryTree<T>::binaryTreeNode* binaryTree<T>::find(const T& target){//this define
    binaryTreeNode* temp=root;
    binaryTreeNode* result=nullptr;
    while (temp)
    {
        if (target<temp->Data)
        {
            temp=temp->left;
        }else if (target>temp->Data)
        {
            temp=temp->right;
        }else
        {
            result=temp;
            temp=nullptr;
        }                        
    }
    return result;
}

template<typename T> typename binaryTree<T>::binaryTreeNode* binaryTree<T>::findMax(binaryTree<T>::binaryTreeNode* node){
    while (node->right!=nullptr)
    {
        node=node->right;
    }
    return node;
}
template<typename T> typename binaryTree<T>::binaryTreeNode* binaryTree<T>::findMin(binaryTree<T>::binaryTreeNode* node){
    while (node->left!=nullptr)
    {
        node=node->left;
    }
    return node;
}


template<typename T> typename binaryTree<T>::binaryTreeNode* binaryTree<T>::deleteFindMax(binaryTree<T>::binaryTreeNode* node){
    binaryTreeNode* pre;
    binaryTreeNode* result=nullptr;
    while (node->right!=nullptr)
    {
        pre=node;
        node=node->right;
    }
    if (node->left)
    {
        node->left->right=node;
        node->left->left=pre->left;
        result=node->left;
        node->left=nullptr;
        
    }else
    {
        result=node;
        pre->right=nullptr;
    }    
    return result;
}
template<typename T> typename binaryTree<T>::binaryTreeNode* binaryTree<T>::deleteFindMin(binaryTree<T>::binaryTreeNode* node){
    binaryTreeNode* pre;
    binaryTreeNode* result=nullptr;
    while (node->left!=nullptr)
    {
        pre=node;
        node=node->left;
    }
    if (node->right)
    {
        node->right->left=node;
        node->right->right=pre->right;
        result=node->right;
        node->right=nullptr;
    }else
    {
        result=node;
        pre->left=nullptr;
    }    
    return result;
}

template<typename T> bool binaryTree<T>::deleteNode(const T& target){
    binaryTreeNode* temp=root;
    binaryTreeNode* pre=nullptr;
    while (temp)
    {
        if (target<temp->Data)
        {
            pre=temp;
            temp=temp->left;
        }else if (target>temp->Data)
        {
            pre=temp;
            temp=temp->right;
        }else
        {
            break;
        }                        
    }
    if (temp->left==nullptr&&temp->right==nullptr)
    {
        pre->left==temp?pre->left=nullptr:pre->right=nullptr;
        delete temp;
        return true;
    }else if (temp->right==nullptr&&temp->left!=nullptr)
    {
        pre->left==temp?pre->left=temp->left:pre->right=temp->left;
        delete temp;
        return true;
    }else if (temp->right!=nullptr&&temp->left==nullptr)
    {
        pre->left==temp?pre->left=temp->right:pre->right=temp->right;
        delete temp;
        return true;
    }else if(temp->right!=nullptr&&temp->left!=nullptr)
    {
        if (pre!=nullptr)
        {   
            if (pre->left==temp)
            {
                pre->left=deleteFindMax(temp);       
            }else
            {
                pre->right=deleteFindMin(temp);                
            }                                                
            delete temp;
        }else{
            //TODO
            temp=findMax(temp->left);
            T tempData=temp->Data;
            deleteNode(temp->Data);
            root->Data=tempData;
        }
        return true;        
    }            
}
#endif