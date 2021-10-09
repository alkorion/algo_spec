#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

constexpr int array_size = 100000;

using array = std::array<int,array_size>;
using vector = std::vector<int>;

void print_array(int* start, int* end) {
    std::cout << "[ ";
    for(int* iter = start; iter != end; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]\n";
}

void merge_and_count_split_inv(long long& count, array& a, int* left_start, int* left_end, int* right_start, int* right_end) {
    // temp return vector
    vector return_array;
    int k_size = right_end - left_start;
    return_array.resize(k_size);

    int* left_iter = left_start;
    int* right_iter = right_start;

    for (int k = 0; k < k_size; k++) {
        // end cases check for when either array is empty
        if (left_iter == left_end) {
            // append the rest of right to return_array, then break
            while (right_iter != right_end) {
                return_array[k] = *right_iter;
                ++right_iter;
                ++k;
            }
            break;
        }
        else if (right_iter == right_end) {
            // append the rest of left to return_array, then break
            while (left_iter != left_end) {
                return_array[k] = *left_iter;
                ++left_iter;
                ++k;
                // ++count; //count += remaining left_array vals;
            }
            break;
        }

        // standard comparison between both arrays
        if (*left_iter < *right_iter) {
            return_array[k] = *left_iter;
            ++left_iter;
        }
        else { // assuming no equal values in array
            return_array[k] = *right_iter;
            ++right_iter;

            // count += remaining left_array vals
            for (int* temp_left_iter = left_iter; temp_left_iter != left_end; ++temp_left_iter) {
                ++count;
            }
        }
    }
    
    // std::cout << "Return array: "; print_array(&return_array[0], &return_array[k_size-1]);

    int* a_iter = left_start;
    // copy over return array into original array
    for(int i = 0; i < k_size; ++i) {
        *a_iter = return_array[i];
        ++a_iter;
    }

}

void sort_and_count(long long& count, array& a, int* start, int* end) {
    int n = end - start;

    // base case, no re-arranging needed
    if (n == 1) {
        return; 
    }

    int* left_start = start;
    int* left_end = left_start + n/2;

    int* right_start = left_end;
    int* right_end = end;

    // sort each half of the original array in place
    sort_and_count(count, a, left_start, left_end);
    sort_and_count(count, a, right_start, right_end);

    // merge together the two sub-arrays in place
    merge_and_count_split_inv(count, a, left_start, left_end, right_start, right_end);

}

int main() {
    

    array a;

    // std::string file_name {"test_array.txt"};
    std::string file_name {"IntegerArray.txt"};


    std::ifstream in_file {file_name};

    int* iter = a.begin();

    while (in_file) {
        // read stuff from the file into a string and print it
        int num;
        in_file >> num;
        *iter = num;
        ++iter;
    }

    // array a = { 1, 3, 5, 7, 2, 4, 6, 8 };
    // array a = { 8, 7, 6, 5, 4, 3, 2, 1 };

    // array a = { 3, 1, 5, 7, 2, 4, 6, 8 };

    long long count = 0;

    // print_array(a.begin(), a.end());

    sort_and_count(count, a, a.begin(), a.end());

    // print_array(a.begin(), a.end());

    std::cout << "Total inversions: " << count << '\n';

    return 0;
}