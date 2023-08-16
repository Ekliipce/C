#include <stdio.h>

int top_of_the_hill(int tab[], size_t len);

int main(void)
{
    int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, 0 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab1, 10));
    int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab2, 10));
    int tab3[] = { 1, 2, 3, 4, 6, 6, 4, 5, 0, 0 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab3, 10));
    printf("%d\n", top_of_the_hill(tab3, 0));
    int tab4[] = { 1 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab4, 1));
    int tab5[] = { 6, 4, 3, 0, 0 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab5, 5));
    int tab6[] = { 1, 2, 3, 4, 5, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab6, 6));

    return 0;
}
