#include <stdio.h>
#include <ctype.h>

int contar_vogais(char *str) {
    int count = 0;
    while(*str) {
        char c = tolower(*str);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    gets(str);

    int num_vogais = contar_vogais(str);
    printf("O número de vogais na string é: %d\n", num_vogais);
    return 0;
}
