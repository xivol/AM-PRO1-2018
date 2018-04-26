//
// Лабораторная работа №2. Деревья
// test_tree.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "test_lab23.h"

array_tree test_tree(const tree::datatype *array, const size_t length)
{
    array_tree root = new tree[length];
    for (int i = 0; i < length; i++) {
        root[i].data = array[i];
        size_t r = 2 * i + 1;
        size_t l = 2 * i + 2;
        if (r<length) 
            root[i].right = root + r;
        else root[i].right = nullptr;
        if (l < length)
            root[i].left = root + l;
        else root[i].left = nullptr;
    }
    return root;
}

bool test_get_array_tree()
{
    int n = 5;
    tree::datatype *array = new tree::datatype[n];
    for (int i = 0; i<n; i++) {
        array[i] = rand();
    }
    tree *root = test_tree(array, n);
    assert(test_array_tree_rec(array, n, 0, root));
    delete[] root;
    delete[] array;
#ifdef _DEBUG
    std::cerr << "test get_array_tree: OK" << std::endl;
#endif
    return true;
}

bool test_array_tree_rec(const tree::datatype *array, const size_t length, const size_t index, const tree *root)
{
    if (root == nullptr) return index >= length;
    if (root->data != array[index]) return false;
    size_t right = 2 * index + 1;
    size_t left = 2 * index + 2;
    return test_array_tree_rec(array, length, right, root->right) && test_array_tree_rec(array, length, left, root->left);
}