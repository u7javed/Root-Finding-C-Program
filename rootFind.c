#include <stdio.h>

/*the polynomial representation of the given number
*/
double f(double x, double c) {
    return (x*x) - c;
}

/*derivative of polynomial function
*/
double fderivative(double x) {
    return 2*x;
}

/*newton's method for set number of iterations
*/
double newtonsMethod(double x, int iter, double (*f)(double, double), double (*fd)(double)) {
    //create a variable holder for the initial entered value of x to feed into the polynomail function
    double xc = x;
    for(int i = 0; i < iter; i++) {
        x = x - (f(x, xc)/fd(x));
    }
    return x;
}

int main()
{
    double root;
    //loop until user enters a character
    do {
        printf("Input a number you want to calculate the 2nd root of: (ENTER A CHARACTER TO END PROGRAM)\n");
        //checks if input is a double
        if(scanf("%lf", &root)) {
            //place holder for input value in order to print its representation.
            double rootPrint = root;
            root = newtonsMethod(root, 100, f, fderivative);
            printf("the 2nd root of %.4lf is: %.20lf\n", rootPrint, root);
        //if input is a character, break loop
        } else if(scanf("%c", &root)) {
            break;
        }
    } while(1);
    printf("PROGRAM TERMINATED");
    return 0;
}
