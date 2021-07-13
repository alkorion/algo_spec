#include<iostream>
#include<math.h>

int get_n(unsigned long long x) {
    // determine integer log power (truncate decimal, add 1 digit)
    int n = ((int) log10(x)) + 1;

    // catch edge-case of odd-num of digits
    if (n == 1)
        return n;

    if (n % 2 != 0)
        n += 1;

    return n;
}

unsigned long long front(unsigned long long x, int n) {
    // edge-case for single-digit number passed
    if (n <= 1)
        return 0;

    int n_over_2 = n/2; // use integer division for now, assume even-numbered powers

    unsigned long long front_nums = x/((int) pow(10, n_over_2));
    
    return front_nums;
}

unsigned long long back(unsigned long long x, int n) {
    if (n <= 1)
        return n;
    
    int n_over_2 = n/2; // use integer division for now, assume even-numbered powers

    unsigned long long back_nums = x%((int) pow(10, n_over_2));

    return back_nums;
}

unsigned long long r(unsigned long long x, unsigned long long y) {
    // base case: if x and y are 1-digit
    if (log10(x) < 1.0 && log10(y) < 1.0)
    {
        return x*y;
    }

    else 
    {
        int n = get_n(std::max(x,y));

        unsigned long long a = front(x,n);
        unsigned long long b = back(x,n);
        unsigned long long c = front(y,n);
        unsigned long long d = back(y,n);

        unsigned long long step_1 = r(a, c);
        unsigned long long step_2 = r(b, d);
        unsigned long long step_3 = r(a+b, c+d);

        unsigned long long mid_term = step_3 - step_1 - step_2;

        // unsigned long long final_product = 10.power(n)*step_1 + 10.power(n/2)*mid_term + step_2;
        unsigned long long final_product = pow(10, n)*step_1 + pow(10, n/2)*mid_term + step_2;
        return final_product;
    

    }

    // debug return case
    // return 0;
}





int main() {

    // unsigned long long front(unsigned long long x);

    unsigned long long x;
    unsigned long long y;

    std::cout << "Enter a positive integer: ";
    std::cin >> x;
    std::cout << "Enter another positive integer: ";
    std::cin >> y;

    std::cout << "r(x,y) = " << r(x,y) << "\n";

    return 0;
}


/*
Psuedo-code

x*y = 10^n*ac + 10^(n/2)(ad+bc) + bd

1. recursively compute ac
2. recursively compute bd
3. recursively compute (a+b)(c+d)=ac+ad+bc+bd
4. compute (3) - (1) - (2)
5. final product = 10^n*(step 1) + 10^(n/2)(step 4) + (step 2)

r(x,y)
    # base case
    if x and y are 1-digit
        return a*b
    else
        n = max(x.len,y.len)

        // return r(3) - recurvsive_call(2) - r(1)
        --> aka -->
        step_1: r(x.front) * r(y.front)
        step_2: r(x.back) * r(y.back)
        step_3: r(x.front+x.back, y.front+y.back)
        step_4: step_3 - step_1 - step_2

        final_product = 10^n*(1) + 10^(n/2)*(3-1-2) + (2)

front(int x)
    return x.sub_str[0:len/2]

back(int x)
    return x.sub_str[len/2:-1]

*/