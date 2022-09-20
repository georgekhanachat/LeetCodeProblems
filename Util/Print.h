//
// Created by gkhan on 9/20/2022.
//

#ifndef LEETCODESANDBOX_PRINT_H
#define LEETCODESANDBOX_PRINT_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void print(const vector<vector<T>>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T>& v) {
    for (size_t j = 0; j < v.size(); ++j) {
        cout << v[j] << " ";
    }
}

#endif //LEETCODESANDBOX_PRINT_H
