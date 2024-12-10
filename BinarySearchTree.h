#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Queue.h"

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
        if ( root == nullptr)
        {
            return false;
        }
        if ( key == root->data)
        {
            return true;
        }
        else if ( key < root->data)
        {
            return search(root->left, key);
        }
        else 
        {
            return search(root->right, key);
        }
    }
    void insert(Node* root, int newValue) {
        //your code here
        if ( newValue == root->data)
        {
            return;
        }
        else if ( newValue < root->data)
        {
            if ( root->left == nullptr)
            {
                root->left = new Node(newValue);
            }
            else 
            {
                insert(root->left, newValue);
            }
        }
        else {
            if ( root->right == nullptr)
            {
                root->right = new Node(newValue);
            }
            else 
            {
                insert(root->right, newValue);
            }
        }
        
    }
    void deleteNode(Node* root, int value){
        //your code here
        if ( root == nullptr)
        {
            return;
        }
        Node* temp;
        if ( value == root->data)
        {
            if ( root->left == nullptr)
            {
                temp = root->right;
                delete root;
                root = temp;
            }
            else if ( root->right == nullptr)
            {
                temp = root->left;
                delete	root;
                root = temp;
            }
            else 
            {
                temp = root->right;
                while ( temp != nullptr && temp->left != nullptr)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                deleteNode(root->right, temp->data);
            }
        }
    }
    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    //exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        Queue q;
        q.enqueue(root->data);
        while ( !q.isEmpty())
        {
            Node* temp = root; 
            temp->data  = q.peek();
            q.dequeue();
            result += std::to_string(temp->data) + " ";
            if ( temp->left != nullptr)
            {
                q.enqueue(temp->left->data);
            }
            if (temp->right != nullptr)
            {
                q.enqueue(temp->right->data);
            }
        }
        //Important note: you are allowed to use the std::queue class to implement this function
        return result;
    }
    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
    void inOrder(Node* node, std::string& result) {
        if ( node == nullptr)
        {
            return;
        } 
        inOrder(node->left, result);
        result += std::to_string(node->data) + " ";
        inOrder(node->right, result);
    }
};

#endif // BINARYTREE_H