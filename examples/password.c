#include <stdio.h>
#include <string.h>

int main(void)

{

char password[9];

printf("Please enter the password: \n");
scanf("%s", password);

 if (strcmp(password, "deadbeef01") == 0)
 {
 printf("Access Granted: Code 1A2B3C4D\n");
 }
 else
 {
 printf("Access Denied\n");
 }

}
