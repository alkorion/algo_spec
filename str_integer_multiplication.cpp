#include<iostream>
#include<math.h>

std::string front(std::string s) {
    /*
    psuedo
    find string length
    if len is odd += 1
    return substring of front
    */

    int len = s.length();

    if (len % 2 != 0) 
    {
        len += 1;           // make sure length is "even"
        s.insert(0,"0");    // append leading zero to make length correct
    }
    std::string front_str = s.substr(0,len/2);

    return front_str;
}

std::string back(std::string s) {
    /*
    psuedo
    find string length
    if len is odd += 1
    return substring of front
    */

    int len = s.length();

    if (len % 2 != 0) 
    {
        len += 1;           // make sure length is "even"
        s.insert(0,"0");    // append leading zero to make length correct
    }
    std::string back_str = s.substr(len/2,len);

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


// std::string int_diff(std::string a, std::string b) { // assumes both inputs are positive
//     /* 
//     psuedo
//     find out which is bigger (using length or largest first digit)
//     from right to left, take large - small number (carry the one, etc)
//     if b > a, add a negative sign
//     return difference
//     */

//     std::string bigger;
//     std::string smaller;

//     bool is_neg { false };

//     if (a.length() > b.length()) // positive difference case 
//     {
//         bigger = a;
//         smaller = b;
//     }
//     else if (b.length() > a.length()) // negative case
//     {
//         bigger = b;
//         smaller = a;
//         is_neg = true;
//     }
//     else // a and b are equal length

//         for (int i{a.length()-1}; i >= 0; --i)
//             // if a_lead > b_lead
        
//         if (a > b)
//         {
//             bigger = a;
//             smaller = b;
//         }


//     std::string diff_string;
//     int carry_1 {0}; // intitalize the carry var to 0 for first sum

//     for (int i{a.length()-1}; i >= 0; --i) {
//         int x_int = std::stoi(x.substr(i,1));
//         int y_int = std::stoi(y.substr(i,1));
//         int sum = x_int + y_int + carry_1;

//         carry_1 = sum / 10;
//         // append the remainder to the total sum string
//         sum_string.insert(0, std::to_string(sum % 10));
//     }

//     if (carry_1) // case where final sum was > 10
//         sum_string.insert(0, "1");

//     return diff_string;
// }

std::string r(std::string x, std::string y) {
    // // base case: if x and y are 1-digit
    // if (x.length() == 1 && y.length() == 1)
    // {
    //     int product = std::stoi(x) * std::stoi(y);
    //     return std::to_string(product);
    // }

    // else 
    // {
        
    //     int n = std::max(x.length(), y.length());

    //     if (n % 2 != 0) 
    //         n += 1;

    //     std::string a = front(x);
    //     std::string b = back(x);
    //     std::string c = front(y);
    //     std::string d = back(y);

    //     std::string step_1 = r(a, c);
    //     std::string step_2 = r(b, d);
        
    //     std::string step_3 = r(int_sum(a,b), int_sum(c,d));

    //     std::string mid_term = step_3 - int_sum;(step_1, step_2);

    //     // unsigned long long final_product = 10.power(n)*step_1 + 10.power(n/2)*mid_term + step_2;
    //     unsigned long long final_product = pow(10, n)*step_1 + pow(10, n/2)*mid_term + step_2;
    //     return final_product;
    

    // }

    // debug return case
    return 0;
}


int main() {

    // unsigned long long front(unsigned long long x);

    std::string x;
    std::string y;

    std::cout << "Enter a positive integer: ";
    std::cin >> x;
    std::cout << "Enter another positive integer: ";
    std::cin >> y;

    std::cout << "front of num: " << front(x) << "\n";
    std::cout << "back of num: " << back(x) << "\n";

    // std::cout << "Product of " << x << " x " << y << " = " << r(x,y) << "\n";

    std::cout << "Sum of " << x << " + " << y << " = " << int_sum(x,y) << "\n";

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