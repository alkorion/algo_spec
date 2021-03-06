#include<iostream>
#include<string>
#include<math.h>

std::string remove_lead_zeros(std::string s) {
    int len = s.length();
    for (int i{0}; i < len-1; ++i)
    {
        if (s.at(0) == '0')
            s.erase(0,1); // remove 1st character (leading zero)
        else
            break;
    }

    return s;
}

// assumes the n is even & positive int
std::string front(std::string s, int n) {
    /*
    if len < n
        add zeros until len = n
        return substring
    else // len=n
        return substring
    
    */

    int len = s.length();

    if (len < n)
    {
        for (int i{0}; i < (n-len); ++i)
            s.insert(0, "0");    // append leading zero to make length correct
    }   
    std::string front_str = s.substr(0,n/2);
    front_str = remove_lead_zeros(front_str);

    return front_str;
}

std::string back(std::string s, int n) {
    /*
    if len < n
        add zeros until len = n
        return substring
    else // len=n
        return substring
    
    */

    int len = s.length();

    if (len < n)
    {
        for (int i{0}; i < (n-len); ++i)
            s.insert(0, "0");    // append leading zero to make length correct
    }   
    std::string back_str = s.substr(n/2,n);
    back_str = remove_lead_zeros(back_str);

    return back_str;
}

std::string int_sum(std::string x, std::string y) {
    /* 
    psuedo
    from right to left, sum the digits, if they are more than 10, carry the 1
    */

    int n{0};

    int x_len = x.length();
    int y_len = y.length();

    if (x_len != y_len)
    {
        n = std::max(x_len, y_len);
        if (x_len > y_len)
        {
            // pad out y to be same length as x
            for (int i{ x_len - y_len }; i>0; i--)
            {
                y.insert(0,"0");
            }
        }
        else // y is longer than x
        {
            // pad out x to be same length as y
            for (int i{y_len - x_len}; i>0; i--)
            {
                x.insert(0,"0");
            }
        }

    }
    else // if both are same length, just take length of x
        n = x.length();

    std::string sum_string;
    int carry_1 {0}; // intitalize the carry var to 0 for first sum

    for (int i{n-1}; i >= 0; --i) {
        int x_int = std::stoi(x.substr(i,1));
        int y_int = std::stoi(y.substr(i,1));
        int sum = x_int + y_int + carry_1;

        carry_1 = sum / 10;
        // append the remainder to the total sum string
        sum_string.insert(0, std::to_string(sum % 10));
    }

    if (carry_1) // case where final sum was > 10
        sum_string.insert(0, "1");

    return sum_string;
}

std::string find_larger(std::string a, std::string b) {
    // assumes strings are same length, and positive integers
    int n = a.length();

    for (int i{0}; i<n; ++i) 
    {
        int a_int = std::stoi(a.substr(i,1));
        int b_int = std::stoi(b.substr(i,1));

        if (a_int > b_int)
            return a;
        else if (b_int > a_int)
            return b;
    }

    // if no digit is ever larger, return a as arbitrary "larger"
    return a;
}

std::string int_diff(std::string a, std::string b) { // assumes both inputs are positive
    /* 
    psuedo
    find out which is bigger (using length or largest first digit)
    from right to left, take large - small number (carry the one, etc)
    if b > a, add a negative sign
    return difference
    */

    std::string bigger;
    std::string smaller;


    int a_len = a.length();
    int b_len = b.length();

    bool is_neg { false };

    if (a_len > b_len) // positive difference case 
    {
        bigger = a;
        smaller = b;
        
        // pad out b to be same length as a
        for (int i{ (a_len - b_len) }; i>0; i--)
            smaller.insert(0, "0");
    }
    else if (b_len > a_len) // negative case
    {
        bigger = b;
        smaller = a;
        is_neg = true;
        
        // pad out b to be same length as a
        for (int i{ b_len - a_len }; i>0; i--)
            smaller.insert(0,"0");

    }
    else // a and b are equal length
    {
        bigger = find_larger(a,b);
        if (bigger == a)
            smaller = b;
        else
        {
            smaller = a;
            is_neg = true;
        }
    }

    std::string diff_string;

    int dec_1 {0};

    int big_len = bigger.length();

    for (int i{big_len-1}; i >= 0; --i) {
        
        int big_int = std::stoi(bigger.substr(i,1)) + dec_1;
        int small_int = std::stoi(smaller.substr(i,1));

        int diff;
        
        // if diff < 0, pad w/ 10 and decriment the next diff
        if (big_int < small_int)
        {
            diff = (big_int+10) - small_int;
            dec_1 = -1;
        }
        else // diff is > 0, carry on
        {
            diff = big_int - small_int;
            dec_1 = 0;
        }

        // append the remainder to the total sum string
        diff_string.insert(0, std::to_string(diff));
    }

    // remove leading zeros
    diff_string = remove_lead_zeros(diff_string);

    // add negative
    if (is_neg)
        diff_string.insert(0,"-");

    return diff_string;
}

// assumes positive integers
std::string r(std::string x, std::string y) {
    // base case: if x and y are 1-digit
    if (x.length() == 1 && y.length() == 1)
    {
        int product = std::stoi(x) * std::stoi(y);
        return std::to_string(product);
    }

    else 
    {
        
        int n = std::max(x.length(), y.length());

        if (n % 2 != 0) 
            n += 1;

        std::string a = front(x, n);
        std::string b = back(x, n);
        std::string c = front(y, n);
        std::string d = back(y, n);

        std::string step_1 = r(a, c);
        std::string step_2 = r(b, d);
        
        std::string step_3 = r(int_sum(a,b), int_sum(c,d));

        std::string mid_term = int_diff(step_3, int_sum(step_1, step_2));

        // final_product = pow(10, n)*step_1 + pow(10, n/2)*mid_term + step_2;
        std::string term_1;

        // multiply front term by 10^n
        for (int i=0; i<n; ++i) {
            step_1.append("0");
        }

        // multiply front term by 10^n
        for (int i=0; i<n/2; ++i) {
            mid_term.append("0");
        }

        std::string final_product = int_sum(int_sum(step_1, mid_term), step_2);

        final_product = remove_lead_zeros(final_product);

        return final_product;
    

    }

}


int main() {

    // unsigned long long front(unsigned long long x);

    std::string x;
    std::string y;

    std::cout << "Enter a positive integer: ";
    std::cin >> x;
    std::cout << "Enter another positive integer: ";
    std::cin >> y;

    // int n = std::max(x.length(), y.length());
    // if (n % 2 != 0) {n += 1;}
    // std::cout << "Front(x) is " << front(x, 8) << " and Back(x) is " << back(x, 8) << "\n";

    // std::cout << x << " with leading zeros removed is: " << remove_lead_zeros(x) << "\n";

    // std::cout << "Between " << x << " and " << y << ", " << find_larger(x,y) << " is larger!\n";
    // std::cout << "Diff of " << x << " - " << y << " = " << int_diff(x,y) << "\n";

    std::cout << "Product of " << x << " x " << y << " = " << r(x,y) << "\n";

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