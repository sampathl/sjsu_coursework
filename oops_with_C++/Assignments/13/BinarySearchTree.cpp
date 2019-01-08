#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

BinaryNode *BinarySearchTree::getRoot() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    /***** Complete this function. *****/
}

long BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMin(root)->data;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *ptr) const
{
    /***** Complete this function. *****/
}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
    /***** Complete this function. *****/
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
    /***** Complete this function. *****/
}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const long data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const long data, BinaryNode *ptr) const
{
    /***** Complete this function. *****/
}

void BinarySearchTree::insert(const long data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const long data, BinaryNode* &ptr)
{
//    cout << "=== Insert called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

    /***** Complete this function. *****/
}

void BinarySearchTree::remove(const long data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const long data, BinaryNode* &ptr)
{
//    cout << "=== Remove called on "
//         << (ptr != nullptr ? to_string(ptr->data) : "null")
//         << endl;

    /***** Complete this function. *****/
}
