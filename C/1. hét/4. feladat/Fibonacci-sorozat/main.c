#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fst, snd, max, next, i;
  printf("Elso ertek: ");
  scanf("%d", &fst);
  printf("Masodik ertek: ");
  scanf("%d", &snd);
  printf("Meddig: ");
  scanf("%d", &max);
  printf("%d ", fst);
  printf("%d ", snd);
  for(i = 3; i <= max; i++)
  {
    next = fst + snd;
    printf("%d ", next);
    fst = snd;
    snd = next;
  }
}
