//
// Лабораторная работа №2. Деревья
// test_tree.h
//
#pragma once
#include "lab23.h"

typedef tree *array_tree;

array_tree test_tree(const tree::datatype *array, const size_t length);

bool test_get_array_tree();

bool test_array_tree_rec(const tree::datatype *array, const size_t length, const size_t index, const tree *root);