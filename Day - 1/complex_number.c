// Add two complex numbers
#include <stdio.h>
int main(void) {
    float real1, real2, imag1, imag2;
    printf("Enter the real and imaginary part of the first complex number: ");
    scanf("%f %f", &real1, &imag1);
    printf("Enter the real and imaginary part of the second complex number: ");
    scanf("%f %f", &real2, &imag2);
    printf("The sum of the two complex numbers is: %.2f + %.2fi", real1 + real2, imag1 + imag2);
    return 0;
}