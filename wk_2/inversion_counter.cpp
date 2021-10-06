#include <iostream>
#include <vector>
#include <algorithm>

#include "inversion_counter.h"

/*

vector input load_vector_from_path(string file_path);

(vector, int) sort_and_count_invs(vector a, int n) {
    if (n == 1)
        return a, 0;
    else {
        int x,y,z;
        vector a,b;
        b, x = count_invs(v[0:n/2], n/2);
        c, y = count_invs(v[n/2+1:n], n/2);
        d, z = count_split_invs(b, c, n);

        int invs = x + y + z;

        return d, invs;

    }
}

(vector, int) merge_and_count_split_invs(vector a, vector b , int n) {
    vector d;       // output vector
    int i, j = 1;   // bad form for initialization
    int inv_count = 0;

    for (int k = 1; k <= n; k++) {
        if (b[i] < c[j]) {
            d[k] = b[i];
            i++;
        }
        else {
            d[k] = c[j];
            j++;
            inv_count += len(b[i:last]) // count remaining elements in B when C is copied over
        }

    }

    return d, inv_count;
}

*/

using vector = std::vector<int>;

void print_vector(vector m) {
    std::cout << "[ ";
    for (int i : m) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";
}

vector merge(const vector& a, const vector& b) {
    vector m;
    m.resize(a.size() + b.size());

    int i = 0;
    int j = 0;


    for (int k = 0; k < static_cast<int>(m.size()); ++k) {
        std::cout << "k=" << k << "; comparing " << a[i] << " & " << b[j] << '\n';
        // edge case if i/j have reached max index
        if (i == static_cast<int>(a.size())) {
            m[k] = b[j];
            break;
        }
        else if (j == static_cast<int>(b.size())) {
            m[k] = a[i];
            break;
        }
        else if (a[i] <= b[j]) {
            m[k] = a[i];
            ++i;
        }
        else {
            m[k] = b[j];
            ++j;
        }
    }

    return m;
}

// wip
vector merge_sort(vector& a) {
    // split the array in 2
    // feed half-arrays into recursive calls
    // feed the result of those into merge alg


    int n = static_cast<int>(a.size());
    
    // base case
    if (n == 1)
        return a;

    vector front = a;
    vector back = a;

    std::cout << "front before: "; print_vector(front);
    front.resize(n/2);
    std::cout << "front after: "; print_vector(front);
    std::cout << "back before: "; print_vector(back);
    back.erase(back.begin(), (back.begin() + n/2));
    std::cout << "back after: "; print_vector(back);

    vector sorted;

    front = merge_sort(front);
    back = merge_sort(back);

    sorted = merge(front, back);

    // temp return
    return sorted;
}



int main() {
    vector a {1,3,5,7};
    vector b {2,4,6,8};
    print_vector(a);
    print_vector(b);

    vector m = merge(a, b);

    print_vector(m);

    m = merge_sort(m);

    std::cout << "final sorted: "; print_vector(m);

    return 0;
}