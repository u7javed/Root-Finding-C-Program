#include <stdio.h>

double f(double x, double c) {
    return (x*x) - c;
}

double fderivative(double x) {
    return 2*x;
}

double newtonsMethod(double x, int iter, double (*f)(double, double), double (*fd)(double)) {
    double xc = x;
    for(int i = 0; i < iter; i++) {
        x = x - (f(x, xc)/fd(x));
    }
    return x;
}

int main()
{
    double root;
    do {
        printf("Input a number you want to calculate the 2nd root of: (ENTER A CHARACTER TO END PROGRAM)\n");
        if(scanf("%lf", &root)) {
            double rootPrint = root;
            root = newtonsMethod(root, 100, f, fderivative);
            printf("the 2nd root of %.4lf is: %.20lf\n", rootPrint, root);
        } else if(scanf("%c", &root)) {
            break;
        }
    } while(1);
    printf("PROGRAM TERMINATED");
    return 0;
}
