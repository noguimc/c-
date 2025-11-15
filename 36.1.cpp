#include <iostream>
using namespace std;


int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}


int count_nonnegative_solutions(int a, int b, int c) {
    
    if (a == 0 && b == 0) {
        if (c == 0) return -1; 
        else return 0;
    }
    if (c < 0) return 0;
    
    int x0, y0;
    int gcd = extended_gcd(a, b, x0, y0);
    
    
    if (c % gcd != 0) return 0;
    
    
    int factor = c / gcd;
    x0 *= factor;
    y0 *= factor;
    
    
    int t_lower, t_upper;
    
    
    
    double lower_bound = -(double)x0 * gcd / b;
    double upper_bound = (double)y0 * gcd / a;
    
    t_lower = ceil(lower_bound);
    t_upper = floor(upper_bound);
    
    
    if (t_lower <= t_upper) {
        return t_upper - t_lower + 1;
    } else {
        return 0;
    }
}

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int count = count_nonnegative_solutions(a, b, c);
    
    if (count == -1) {
        cout << "None" << endl;
    } else {
        cout <<count << endl;
    }
    
    return 0;
}