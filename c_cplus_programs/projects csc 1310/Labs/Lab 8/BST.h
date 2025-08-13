/*
	File Name: BST.h
	Author: Tate Finley
	Date: 10/30/22
	Purpose: This header file defines the class definition of a Binary Standard Tree
*/

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

/*
	Class name: BST
	Class purpose: this class behaves like a Binary Standard Tree
	Attributes: see definitions
	Member functions: see function definitions
*/
class BST
{
	private:
		/*
			Struct Name: treeNode
			Struct Purpose: acts like a node in a tree
		*/
		struct treeNode
		{
			int value;// value being stored
			treeNode* left;//left child node
			treeNode* right;//right child node
		};
		treeNode* root;//root of the tree

		/*
			Function Name: copy()
			Function Purpose: copies nodes from one tree to another (preorder traversal)
			Parameters: 2 treeNode pointers, root of the new tree and address of tree being copied
			Returns: None
		*/
		void copy(treeNode*&nodePtr, treeNode*treeCopy)
		{	
			//check if a node still exists in the original tree
			if(treeCopy)
			{
				treeNode* newNode;//new node

				//process of creating a new node
				newNode = new treeNode;
				newNode->value = treeCopy->value;
				newNode->left = NULL;
				newNode->right = NULL;

				//insert the node
				insert(nodePtr, newNode);

				//copy left of node if available
				if(treeCopy->left)
				{
					copy(nodePtr->left, treeCopy->left);
				}
				//copy right of node if available
				if(treeCopy->right)
				{
					copy(nodePtr->right, treeCopy->right);
				}
			
			}
		}
		/*
			Function Name: insert()
			Function Purpose: inserts a node into the appropriate part of the tree
			Parameters: 2 treeNode pointers
			Returns: None
		*/
		void insert(treeNode*&nodePtr, treeNode*newNode)
		{
			//if leaf node, insert node
			if(nodePtr == NULL)
			{
				nodePtr = newNode;
			}
			//if value is less than, traverse left
			else if(newNode->value < nodePtr->value)
			{
				insert(nodePtr->left, newNode);
			}
			//if not, traverse right
			else
			{
				insert(nodePtr->right, newNode);
			}
		}
		/*
			Function Name: displayInOrder()
			Function Purpose: displays the nodes in the tree in order (inorder traversal)
			Parameters: a treeNode pointer
			Returns: None
		*/
		void displayInOrder(treeNode* treeNodePtr) const
		{
			if(treeNodePtr)
			{
				//call any to the left of the current node
				displayInOrder(treeNodePtr->left);

				//output value of node
				cout << treeNodePtr->value << " ";

				//call any to the right of the current node
				displayInOrder(treeNodePtr->right);
			}
		}
		/*
			Function Name: destroySubTree()
			Function Purpose: deletes an entire tree
			Parameters: a treeNode pointer
			Returns: None
		*/
		void destroySubTree(treeNode* deleteNodePtr)
		{
			if(deleteNodePtr)
			{
				//delete any child nodes left of current node
				if(deleteNodePtr->left)
				{
					destroySubTree(deleteNodePtr->left);
				}
				//delete any child nodes right of current node
				if(deleteNodePtr->right)
				{
					destroySubTree(deleteNodePtr->right);
				}
				//delete current node
				delete deleteNodePtr;
			}
		}

	public:
		BST() //default constructor
		{
			root = NULL;
		}			
		BST(const BST &tree) //copy constructor
		{
			root = NULL;
			copy(root, tree.root);
		}
		~BST() //destuctor
		{
			destroySubTree(root);
		}
		/*
			Function Name: insertNode()
			Function Purpose: create a new node, store value, then insert into tree
			Parameters: a integer containing the value to be stored
			Returns: None
		*/
		void insertNode(int num)
		{
			treeNode* newNode = NULL;//new node

			newNode = new treeNode;
			newNode->value = num;
			newNode->left = NULL;
			newNode->right = NULL;

			insert(root, newNode);
		}
		/*
			Function Name: display()
			Function Purpose: public function to display order
			Parameters: None
			Returns: None
		*/
		void display()
		{
			displayInOrder(root);
		}
};

#endif