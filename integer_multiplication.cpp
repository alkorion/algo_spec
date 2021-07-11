#include<iostream>
#include<math.h>

void int_multiplication(unsigned long long x, unsigned long long y) {
    std::cout << "integer multiplication method running\n";
} 

unsigned long long r(unsigned long long x, unsigned long long y) {
    # base case
    if x and y are 1-digit
        return a*b
    else
        n = max(x.len,y.len)

        a = x.front
        b = x.back
        c = y.front
        d = y.back

        # count number of digits in x and y
        n = max(x.log10,y.log10)

        // return r(3) - recurvsive_call(2) - r(1)
        --> aka -->
        step_1 = r(a, c)
        step_2 = r(b, d)
        step_3 = r(a+b, c+d)

        mid_term = step_3 - step_1 - step_2

        final_product = 10.power(n)*step_1 + 10.power(n/2)*mid_term + step_2
        return final_product
    // debug return case?
    return 0;
}

unsigned long long front(unsigned long long x) {
    unsigned long long n = log10(x);
    // determine integer log power (truncate decimal)
    // divide x (using integer division) by n to get first "n" digits and return them

    //return x.sub_str[0:n/2]
}

unsigned long long back(unsigned long long x) {
//     return x.sub_str[len/2:-1]
// same sudo code as front() but replace integer division w/ modulo
    return 0;
}



/*
Psuedo-code

x*y = 10^n*ac + 10^(n/2)(ad+bc) + bd

1. recursively compute ac
2. recursively compute bd
3. recursively compute (a+b)(c+d)=ac+ad+bc+bd
4. compute (3) - (1) - (2)

r(x,y)
    # base case
    if x and y are 1-digit
        return a*b
    else
        n = max(x.len,y.len)

        // return r(3) - recurvsive_call(2) - r(1)
        --> aka -->
        step_1: r(x.front) * r( y.front )
        step_2: r(x.back) * r( y.back )
        step_3: r(x.front)*r(y.front) + r(x.front)*r(y.back) + r(x.back)*r(y.front) + r(x.back)*r(y.back)

        // final_product = 10^n*ac + 10^(n/2)(ad+bc) + bd
        return 10^n*(1) + 10^(n/2)*(3-1-2) + (2)

front(int x)
    return x.sub_str[0:len/2]

back(int x)
    return x.sub_str[len/2:-1]

*/

int main() {

    unsigned long long front(int);

    unsigned long long x = 1234;
    unsigned long long y = 5678;

    std::cout << "x.front = " << front(x);
    // std::cout << "y.front = " << back(y);

    int_multiplication(x,y);

    return 0;
}