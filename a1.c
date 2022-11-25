#include <stdio.h>
         
int main(){
  
    int n1, n2;;
    char choice;

    printf("Enter +,-,*,/ to perform the required operation :\n");
    scanf("%c", &choice);

//          Taking input of  numbers.
     printf("Enter the two no.s to perform the operation:");
     scanf("%d %d", &n1, &n2);
      
      
     switch(choice){
      case '+':
      printf("Addition of n1 and n2 is %d", n1+n2);\
      break;

      case '-':
      printf("Subtraction of n1 and n2 is %d", n1-n2);
      break;

      case '*':
      printf("Multiplication of n1 and n2 is %d", n1*n2);
      break;

      case '/':
      printf("Division of n1 and n2 is %f", (n1/(float)n2)); 
      break;
    }
return 0;
}
