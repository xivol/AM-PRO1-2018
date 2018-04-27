//
// Лабораторная рвбота №2. Деревья
// tree.cpp
//
#include <stdlib.h>
#include <iostream>
#include "crtdynmem.h"
#include "lab23.h"

tree *read_tree(uint count)
{
    tree *root = nullptr;
    tree::datatype x;
    while (count > 0 && std::cin >> x) 
	{
        insert(root, x);
        count -= 1;
    }
    return root;
}

void insert(tree *&root, tree::datatype x)
{
    if (root == nullptr) {
        root = new tree;
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (rand() % 2 == 0)  // вставляем элемент в случайное поддерево
            insert(root->left, x);
        else
            insert(root->right, x);
    }
}

void delete_tree(tree *&root)
{
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = nullptr;
}

void print_tree(const tree *root, uint space)
{
    if (root == nullptr) return;
    print_tree(root->left, space+1);
    for (int i = 0; i < space; i++) 
		std::cout << '\t';
    std::cout << root->data << std::endl;
    print_tree(root->right, space+1);
}

uint leaves_count(const tree *root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) 
        return 1;
    return leaves_count(root->left) + leaves_count(root->right);
}