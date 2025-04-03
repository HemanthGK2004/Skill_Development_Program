#include<stdio.h>
int main(){
    int total_vehicle;
    printf("Enter the total number of vehicles: ");
    scanf("%d",&total_vehicle);
    int total_wheels;
    printf("Enter the total number of wheels: ");
    scanf("%d",&total_wheels);
    int two_wheeler=(total_wheels-total_vehicle*2)/2;
    int four_wheeler=(total_vehicle-two_wheeler);
    printf("The number of two wheeler vehicles are: %d",two_wheeler);
    printf("\nThe number of four wheeler vehicles are: %d",four_wheeler);
    return 0;
}