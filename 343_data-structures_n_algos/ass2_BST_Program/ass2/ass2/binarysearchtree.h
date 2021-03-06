// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

/* modified by Ryan Peters
 * 19 Jan 2018
 * 
 * for assignment 2: Binary Search Tree
 *
 *
 *
 *
 *
 *  
 * 
 * 
 *  
 *        
 *        
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream> 
#include <functional>
#include <stack>
#include <queue> 
#include "binarynode.h"

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
	// constructor, empty tree
	BinarySearchTree();

	// constructor, tree with root
	BinarySearchTree(const ItemType& rootItem);

	// copy consturctor
	BinarySearchTree(const BinarySearchTree<ItemType>& bst);

	// destructor
	virtual ~BinarySearchTree();

	// true if no nodes
	bool isEmpty() const;

	// 0 if empty, 1 if only root, otherwise
	// max height of subtrees + 1
	int getHeight() const;

	// number of nodes and data in tree
	int getNumberOfNodes() const;

	// add a new item
	// return true if succesasfull
	// false if item already in tree or some other reason to fail
	bool add(const ItemType& item);

	// true if item is in tree
	bool contains(const ItemType& item) const;

	// inorder traversal: left-root-right
	// takes a function that takes a single parameter of ItemType
	// the function can modify the data in tree, but the
	// tree structure is not changed
	void inorderTraverse(void visit(const ItemType&)) const;

	// create dynamic array, copy all the items to the array
	// and then read the array to re-create this tree
	void rebalance();

	// delete all nodes in tree and set root to nullptr
	void clear();

	// given an array of length n
	// create this tree to have all items in that array
	// with the minimum height
	bool readTree(ItemType arr[], const int& n);

	// trees are equal if they have the same structure
	// AND the same item values at all the nodes
	bool operator==(const BinarySearchTree<ItemType> &other) const;
	bool operator==(const BinarySearchTree<ItemType>* other) const;
	// not == to each other
	bool operator!=(const BinarySearchTree<ItemType> &other) const;
	bool operator!=(const BinarySearchTree<ItemType>* other) const;

	// dispaly a sideways ascii representation of tree
	void displaySideways() const;
private:

	// root of the tree
	BinaryNode<ItemType>* rootPtr/*{ nullptr }*/;

	// member variables for tracking element count and tree height
	int treeHeight, numElems;

	// a private version of inorderTraverse that accepts lambdas
	void inorderTraverse(std::function<void(const ItemType& itm)> func) const;

	// add a new node, helper function for add
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

	// find the node with given vale, helper function for contains
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const;

	// helper function for displaySideways to work recursively
	void sideways(BinaryNode<ItemType>* current, int level) const;
	
	// bool BinarySearchTree<ItemType>::matchyFunk(BinaryNode<ItemType>* local, BinaryNode<ItemType>* remote)
	// 
	// Helper function the performs tail-recursion in search for dissimilarities between this and the
	// other parameter that was passed into the operator== overload.
	bool matchyFunk(BinaryNode<ItemType>* local, BinaryNode<ItemType>* remote) const;

	void buildBalancedTree(const int &l, const int& mid, const int &r, const ItemType arr[]);
};

#include "binarysearchtree.cpp"

#endif // BINARYSEARCHTREE_H

