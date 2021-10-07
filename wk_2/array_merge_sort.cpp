#include <iostream>
#include <array>

constexpr int array_size = 8;

using array = std::array<int,array_size>;

void print_array(int* start, int* end) {
    std::cout << "[ ";
    for(int* iter = start; iter != end; ++iter) {
        std::cout << *iter << ", ";
    }
    std::cout << "]\n";
}

void merge(array a, int* left_start, int* left_end, int* right_start, int* right_end) {
    // temp return array
    array return_array;
    print_array(return_array.begin(), return_array.end()); // debug purposes
    int a_size = static_cast<int>(a.size());

    for (int k = 0; k < a_size; k++) {
        // end cases check
        if (left_start == left_end) {
            // append the rest of right to return_array, then break
            while (right_start != right_end) {
                return_array[k] = *right_start;
                ++right_start;
                ++k;
            }
            break;
        }
        else if (right_start == right_end) {
            // append the rest of left to return_array, then break
            while (left_start != left_end) {
                return_array[k] = *left_start;
                ++left_start;
                ++k;
            }
            break;
        }
        
        if (*left_start < *right_start) {
            return_array[k] = *left_start;
            ++left_start;
        }
        else { // assuming no equal values in array
            return_array[k] = *right_start;
            ++right_start;
        }
    }

    print_array(return_array.begin(), return_array.end());

}


int main() {
    
    array a = { 1, 3, 5, 7, 2, 4, 6, 8 };
    print_array(a.begin(), a.end());

    merge(a, a.begin(), a.begin()+4, a.begin()+4, a.end());

    return 0;
}