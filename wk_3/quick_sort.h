#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void print_array(int* start, int* end);

void quick_sort(int* left, int* right);
int* partition(int* pivot, int* left, int* right);


#endif