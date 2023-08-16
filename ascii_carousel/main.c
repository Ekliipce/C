#include <stdio.h>

void rot_x(char *s, int x);

static void print_rotx(char *str, int nb)
{
    printf("rotx %s = ", str);
    rot_x(str, nb);
    printf("%s\n", str);    
}
int main(void)
{
    print_rotx("aBcD", 13);
    print_rotx("zWyX", 13);
   // print_rotx("abcD", -4);
   // print_rotx("zwxt", -26);
    return 0;
}
