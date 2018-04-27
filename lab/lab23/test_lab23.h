//
// Лабораторная работа №2. Деревья
// test_tree.h
//
#pragma once
#include "lab23.h"

typedef tree *array_tree;

array_tree test_tree(const std::initializer_list<tree::datatype> &list);

bool is_equal_tree(const tree *root1, const tree *root2);

bool test_leaves_count();

bool test_depth(void *func = nullptr);

bool test_width_at_level(void *func = nullptr);

bool test_width(void *func = nullptr);

bool test_copy_tree(void *func = nullptr);

bool test_remove_leaves(void *func = nullptr);

bool test_full_lab23();