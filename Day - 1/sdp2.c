#include<stdio.h>
int main(){
    float hour;
    printf("Enter the number of hours: ");
    scanf("%f",&hour);
    int price=0;
    if(hour<=2){
        price = price + 20;
    }
    else{
        price=20 + (hour-2)*10;
    }
    printf("The price is: %d",price);
    return 0;
}

