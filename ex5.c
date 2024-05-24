#include <stdio.h>
#include <ctype.h>

void str_to_upper(char *str) {
    while(*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    gets(str);

    str_to_upper(str);
    printf("String em maiúsculas: %s\n", str);
    return 0;
}
