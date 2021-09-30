// Program 2: Number Guessing Game

/* 
   - create switch statement for menu selection
   - enclose switch statement in do while loop so user can revisit the menu
   - option one allows user to play with default 1-10 number generation
   - option two allows user to specify a upper bound for the number generation 
     that is not greater than the max value
   - option three exits the game
**/   

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   const int MAX_VALUE = RAND_MAX;
   int choice, answer, newMaxValue = 10;

   time_t t;
   srand((unsigned) time(&t)); 

   do
   {
      printf("----------------------------------\n");
      printf("Press 1 to play a game.\n");
      printf("Press 2 to change the max number\n");
      printf("Press 3 to quit.\n");
      printf("----------------------------------\n");

      scanf("%d", &choice);
      fflush(stdin);

      switch (choice)
         {
            case 1:
            {
               char userAnswer[3];
               answer = rand() % newMaxValue + 1;
               long int userNum;
               do
               {
                     printf("Enter a number between 1 - %d: ", newMaxValue);
                     fgets(userAnswer, 4, stdin);
                     fflush(stdin);
                     
                     if (userAnswer[0] == 'q' || userAnswer[0] == 'Q')
                     {
                        break;
                     }

                     char *end;
                     userNum = strtol(userAnswer, &end, 10);

                     if (userNum < answer)
                     {
                        printf("to low, try again\n\n");
                     }
                     else if (userNum > answer)
                     {
                        printf("to high, try again\n\n");
                     }
                     else
                     {
                        printf("Correct, you win!\n\n");
                     }
               } while(userNum != answer);
               

               break;
            }
            case 2:
            {
               int flag = 0;
               do
               {
                  printf("Enter a new max value below %d: ", MAX_VALUE);
                  scanf("%d", &newMaxValue);

                  if (newMaxValue <= 0)
                  {
                     printf("max value cannot be less than or equal to 0\n");
                  }
                  else if (newMaxValue > MAX_VALUE)
                  {
                     printf("max value cannot be greater than %d\n", MAX_VALUE);
                  }
                  else
                  {
                     printf("new max value set to %d\n", newMaxValue);
                     flag = 1;
                  }
               } while (flag != 1);
               
               break;
            }
            case 3:
            {
               break;
            }
            default:
            {
               printf("Invalid choice, please select 1, 2, or 3!\n");
            }
      }
   } while(choice != 3);
   

   return 0;
}