#include <stdio.h>
#include <math.h>

int num_len(double n) {
    if (n < 0) n = -n;
    if (n == 0) return 1; 
    return (int)log10(n) + 1;
}

// karatsuba function
double karatsuba(double x, double y) {
    
    if (x < 10 && y < 10) {
        return x * y;
    }

    int n1 = num_len(x);
    int n2 = num_len(y);

    int n = (n1 > n2) ? n1 : n2;
    int n_half = n / 2;

    double a = floor(x / pow(10, n_half));
    double b = fmod(x, pow(10, n_half));
    double c = floor(y / pow(10, n_half));
    double d = fmod(y, pow(10, n_half));

    double ac = karatsuba(a, c);
    double bd = karatsuba(b, d);
    double ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

    double result = ac * pow(10, 2 * n_half) + ad_plus_bc * pow(10, n_half) + bd;

    return result;
}

int main(void) {
    double n1, n2;
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &n1, &n2);

    double result = karatsuba(n1, n2);

    printf("The result of multiplication is: %.2lf\n", result);

    return 0;
}
