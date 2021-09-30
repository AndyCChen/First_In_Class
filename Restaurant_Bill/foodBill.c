// Program 1: Restautrant Bill

/*
   - ask user inputs for tax and tip as percent
   - random number generator to choose which four meals to use
   - Total = mealPrice + tax + tip
   - output the meal cost, tax, tip, and total bill

**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   time_t t;
   srand((unsigned) time(&t));

   double taxPercent, tipPercent, taxAmount, tipAmount, total;

   int mealNumber = rand() % 4;

   const char *meal[] = {"Salad", "Soup", "Sandwich", "Pizza"};
   double mealPrice[] = {9.95, 4.55, 13.25, 22.35};

   double mealCost = mealPrice[mealNumber];

   printf(meal[mealNumber]);
   printf(" : $%.2lf\n", mealPrice[mealNumber]);
   printf("-----------------------------\n");

   printf("Please enter tax percent: ");
   scanf("%lf", &taxPercent);

   printf("Please enter tip percent: ");
   scanf("%lf", &tipPercent);

   printf("-----------------------------\n\n");

   taxAmount =  mealCost * (taxPercent / 100);
   tipAmount =  mealCost * (tipPercent / 100);
   total = mealCost + taxAmount + tipAmount;

   printf("Tax amount: $%.2lf\n", taxAmount);
   printf("Tip amount $%.2lf\n", tipAmount);
   printf("Total bill: $%.2lf\n", total);

   return 0;
}