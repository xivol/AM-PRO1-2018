//
// Лабораторная работа №2. Деревья
// test_tree.cpp
//
#include <cassert>
#include <iostream>
#include <initializer_list>
#include "crtdynmem.h"
#include "test_lab23.h"

using namespace std;

array_tree test_tree(const initializer_list<tree::datatype> &list)
{
    array_tree root = new tree[list.size()];
    uint i = 0;
    for (auto it = list.begin(); it != list.end(); ++it) 
    {
        root[i].data = *it;
        uint r = 2 * i + 1;
        uint l = 2 * i + 2;
        
        if (r < list.size())
            root[i].right = root + r;
        else root[i].right = nullptr;

        if (l < list.size())
            root[i].left = root + l;
        else root[i].left = nullptr;
        
        i += 1;
    }
    return root;
}

bool is_equal_tree(const tree *root1, const tree *root2)
{
    if (root1 == root2) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->data != root2->data) return false;
    return is_equal_tree(root1->left, root2->left) && is_equal_tree(root1->right, root2->right);
}

bool test_leaves_count()
{
    assert(leaves_count(nullptr) == 0);

    array_tree root = test_tree({ 1 });
    assert(leaves_count(root) == 1);
    delete root;

    root = test_tree({ 1,2 });
    assert(leaves_count(root) == 1);
    delete root;

    root = test_tree({ 1,2,3 });
    assert(leaves_count(root) == 2);
    delete root;

    root = test_tree({ 1,2,3,4 });
    assert(leaves_count(root) == 2);
    delete root;

    root = test_tree({ 1,2,3,4,5 });
    assert(leaves_count(root) == 3);
    delete root;

    root = test_tree({ 1,2,3,4,5,6 });
    assert(leaves_count(root) == 3);
    delete root;

    root = test_tree({ 1,2,3,4,5,6,7 });
    assert(leaves_count(root) == 4);
    delete root;

    cerr << "test leaves_count: OK" << endl;
    return true;
}

bool test_depth(void *func)
{
    cerr << "test depth: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint(*depth)(const tree *) = (uint(*)(const tree *)) func;

    assert(depth(nullptr) == 0);

    array_tree root = test_tree({ 1 });
    assert(depth(root) == 1);
    delete root;

    root = test_tree({ 1,2 });
    assert(depth(root) == 2);
    delete root;

    root = test_tree({ 1,2,3,4 });
    assert(depth(root) == 3);
    delete root;

    cerr << "OK" << endl;
    return true;
}

bool test_width_at_level(void *func)
{
    cerr << "test width_at_level: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint(*width_at_level)(const tree *, uint) = (uint(*)(const tree *, uint)) func;
    
    assert(width_at_level(nullptr, 0) == 0);

    array_tree root = test_tree({ 1 });
    assert(width_at_level(root, 0) == 1);
    delete root;

    root = test_tree({ 1,2 });
    assert(width_at_level(root, 0) == 1);
    assert(width_at_level(root, 1) == 1);
    delete root;

    root = test_tree({ 1,2,3,4 });
    assert(width_at_level(root, 0) == 1);
    assert(width_at_level(root, 1) == 2);
    assert(width_at_level(root, 2) == 1);
    delete root;

    root = test_tree({ 1,2,3,4,5,6,7 });
    assert(width_at_level(root, 0) == 1);
    assert(width_at_level(root, 1) == 2);
    assert(width_at_level(root, 2) == 4);
    delete root;

    cerr << "OK" << endl;
    return true;
}

bool test_width(void *func)
{
    cerr << "test width: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint (*width)(const tree *) = (uint (*)(const tree *)) func;

    assert(width(nullptr) == 0);

    array_tree root = test_tree({ 1 });
    assert(width(root) == 1);
    delete root;
    
    root = test_tree({ 1,2,3 });
    assert(width(root) == 2);
    delete root;

    root = test_tree({ 1,2,3,4 });
    assert(width(root) == 2);
    delete root;

    root = test_tree({ 1,2,3,4,5,6 });
    assert(width(root) == 3);
    delete root;

    root = test_tree({ 1,2,3,4,5,6,7 });
    assert(width(root) == 4);
    delete root;

    cerr << "OK" << endl;
    return true;
}

bool test_copy_tree(void *func)
{
    cerr << "test copy_tree: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    tree *(*copy_tree)(const tree *) = (tree *(*)(const tree *)) func;

    array_tree root = test_tree({ 1,2,3,4,5,6,7 });
    tree *result = copy_tree(root);
    assert(is_equal_tree(root, result));

    delete[]root;
    delete_tree(result);

    cerr << "OK" << endl;
    return true;
}

bool test_remove_leaves(void *func)
{
    cerr << "test remove_leaves: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*remove_leaves)(tree *&, tree::datatype) = (void (*)(tree *&, tree::datatype))func;

    tree::datatype x = 1;
    tree *root = new tree{ x, nullptr, nullptr};
    
    remove_leaves(root, x);
    assert(root == nullptr);
        
    root = new tree{ x, nullptr, nullptr };
    root->left = new tree{ x, nullptr, nullptr };
    root->right = new tree{ x, nullptr, nullptr };

    remove_leaves(root, x);
    assert(root != nullptr);
    assert(root->left == nullptr);
    assert(root->right == nullptr);

    delete_tree(root);

    cerr << "OK" << endl;
    return true;
}

bool test_full_lab23()
{
#ifdef _DEBUG
    return test_leaves_count() &&
        test_depth(/*ваша реализация здесь*/) &&
        test_width_at_level(/*ваша реализация здесь*/) &&
        test_width(/*ваша реализация здесь*/) &&
        test_copy_tree(/*ваша реализация здесь*/) &&
        test_remove_leaves(/*ваша реализация здесь*/);
#endif
}
