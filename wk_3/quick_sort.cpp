#include <iostream>
#include <array>

#include "quick_sort.h"

constexpr int ARRAY_SIZE = 8;
using array = std::array<int,ARRAY_SIZE>;

void print_array(int* start, int* end) {
    std::cout << "[ ";
    for(int* iter = start; iter != end; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]\n";
}

void quick_sort(int* left, int* right) {
    int n = right - left;

    if (n <= 1) {
        return;
    }
    else {
        int* pivot = left;
        int* pivot_location = partition(pivot, left, right);

        // recursively call quick_sort on both sides of pivot
        quick_sort(left, pivot_location); // left side
        quick_sort(pivot_location, right);

    }
    
}

// partition elements between pointers and return partition-element location
int* partition(int* pivot, int* left, int* right) {

    int* i = left+1; // initialize j to the same in the for loop
    
    for (int* j = left+1; j != right; ++j) {

        if (*j < *pivot) { // if new element is >p we don't do anything
            // swap a[j] and a[i]
            int temp = *j;
            *j = *i;
            *i = temp;

            ++i; // increment boundary of less/greater than pivot
        }

    }

    // once j falls off the array, move the pivot into place (swap w/ i-1)
    *pivot = *(i-1);
    *(i-1) = *left;

    return (i-1); // return location of p

}

int main() {

    array a = {3, 8, 6, 7, 5, 1, 2, 4};
    print_array(a.begin(), a.end());

    quick_sort(a.begin(), a.end());
    print_array(a.begin(), a.end());


    return 0;
}