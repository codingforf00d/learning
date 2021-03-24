#include <stdio.h>


int main() {
    char a[100];
    int i;
    for (i = 0; i<5; i++) {
        a[i] = 'a';
        printf("%s", a);
    }
}