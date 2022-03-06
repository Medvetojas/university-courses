#include<stdio.h>
int main(void)
{
char karakterek[] = { 'r', 'i', 'a', 'o', 'd' };
for (int i = 0; i < 5; i++)
{
printf("%c", karakterek[i * 2 % 6]);
}
return 0;
}
