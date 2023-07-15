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
    ~binaryTree();
};

template <typename T> binaryTree<T>::binaryTree(/* args */)
{
    root=nullptr;
    nodeNum=0;
}

template <typename T> binaryTree<T>::~binaryTree()
{
}
template <typename T> bool binaryTree<T>::isEmpty()
{
    return false;
}
template <typename T> void binaryTree<T>::preOrderTraversal()
{

}
template <typename T> void binaryTree<T>::middleOrderTraversal()
{
}
template <typename T> void binaryTree<T>::postOrderTraversal()
{
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
#endif