#include <iostream>
#include <array>
#include <fstream>

#include "quick_sort.h"

constexpr int ARRAY_SIZE = 10000;
using array = std::array<int,ARRAY_SIZE>;

void print_array(int* start, int* end) {
    std::cout << "[ ";
    for(int* iter = start; iter != end; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]\n";
}

long long int quick_sort(int* left, int* right) {
    static long long int comparisons;

    int n = right - left;

    if (n <= 1) {
        return comparisons;
    }
    else {
        int* pivot = left;
        int* pivot_location = partition(pivot, left, right);

        // debug: show pivot results
        // print_array(left, right);
        // print_array(left, pivot_location);
        // print_array(pivot_location+1, right);

        // recursively call quick_sort on both sides of pivot
        quick_sort(left, pivot_location); // left side
        quick_sort(pivot_location+1, right); // right side
        
        // count the comparisons in the recursive calls
        int m_left = (pivot_location - left) - 1;
        int m_right = (right - pivot_location + 1) - 1;
        comparisons += (m_left + m_right);

    }

    return comparisons;
    
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
    int temp = *pivot;
    *pivot = *(i-1);
    *(i-1) = temp;

    return (i-1); // return location of p

}

int main() {

    array a;
    
    // std::string file_name {"test_array.txt"};
    std::string file_name {"assignment_input.txt"};

    std::ifstream in_file {file_name};

    int* iter = a.begin();

    while (in_file) {
        // read stuff from the file into a string and print it
        int num;
        in_file >> num;
        *iter = num;
        ++iter;
    }

    // print_array(a.begin(), a.end());

    long long int comparisons = quick_sort(a.begin(), a.end());
    // print_array(a.begin(), a.end());
    std::cout << "Comparisons made: " << comparisons << '\n';


    return 0;
}