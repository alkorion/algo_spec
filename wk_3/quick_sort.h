#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void print_array(int* start, int* end);

long long int quick_sort(int* left, int* right);
int* partition(int* pivot, int* left, int* right);

int* select_median_pivot(int* left, int* right);

#endif