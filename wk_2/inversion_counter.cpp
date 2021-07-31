#include <iostream>
#include <vector>

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

int main() {

    return 0;
}