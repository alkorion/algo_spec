#include <iostream>
#include <array>
#include <fstream>

#include "quick_sort.h"

// constexpr int ARRAY_SIZE = 8;
constexpr int ARRAY_SIZE = 10000;
using array = std::array<int,ARRAY_SIZE>;

void print_array(int* start, int* end) {
    std::cout << "[ ";
    for(int* iter = start; iter != end; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]\n";
}

int* select_median_pivot(int* left, int* right) {
    int n = right - left;
    int* eff_right = right - 1;
    int* middle;
    
    if (n % 2 == 0) { // if even amount
         middle = (left + n/2) - 1;  // choose the "left middle" value as the center
    }
    else { // n is odd, just pick the middle value
        middle = left + n/2;
    }

    // annoying and probably ineffecient switch cases:
    if (*middle < *left && *eff_right < *left) { // left is largest
        if (*middle < *eff_right) { return eff_right; }
        else { return middle; }
    }
    if (*middle < *eff_right && *left < *eff_right) { // right is largest
        if (*middle < *left) { return left; }
        else { return middle; }
    }
    if (*eff_right < *middle && *left < *middle) { // middle is largest
        if (*eff_right < *left) { return left; }
        else { return eff_right; }
    }

    // this should never be reached since there are no equal values, but adding to silence warnings... (facepalm)
    return middle;

}

long long int quick_sort(int* left, int* right) {
    static long long int comparisons;

    int n = right - left;

    if (n <= 1) {
        return comparisons;
    }
    else {
        // int* pivot = left;                                   // section 1: select 1st item as pivot          Answer: 162085
        // int* pivot = right-1;                                // section 2: select last item as pivot         Answer: 164123
        int* pivot = select_median_pivot(left, right);          // section 3: select median-of-three  as pivot  Answer: 138382

        int* pivot_location = partition(pivot, left, right);

        // // recursively call quick_sort on both sides of pivot
        quick_sort(left, pivot_location); // left side
        quick_sort(pivot_location+1, right); // right side
        
        // // count the comparisons in the recursive calls
        int m_left = (pivot_location - left) - 1;
        int m_right = (right - pivot_location + 1) - 1;
        comparisons += (m_left + m_right);

    }

    return comparisons;
    
}

// partition elements between pointers and return partition-element location
int* partition(int* pivot, int* left, int* right) {

    int temp = *pivot;
    *pivot = *left;
    *left = temp;
    // tell the pivot to correctly point at the start now
    pivot = left;

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
    temp = *pivot;
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

    // std::array<int,7> a = {1,2,3,4,5,6,7}; 

    // print_array(a.begin(), a.end());
    // int* temp = select_median_pivot(a.begin(), a.end());
    // std::cout << "The median-of-three = " << *temp << '\n';

    long long int comparisons = quick_sort(a.begin(), a.end());
    // print_array(a.begin(), a.end());
    std::cout << "Comparisons made: " << comparisons << '\n';


    return 0;
}