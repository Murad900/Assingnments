#include <stdio.h>


void function(char *source, char *integers, char *nonIntegers){
    int i = 0, intIndex = 0, nonIntIndex = 0;
    for(;source[i] != '\0'; i++){
        if (source[i] >= 48 && source[i] <= 57){
            integers[intIndex] = source[i];
            intIndex++;
        }
        else{
            nonIntegers[nonIntIndex] = source[i];
            nonIntIndex++;
        }
        integers[intIndex] = '\0';
        nonIntegers[nonIntIndex] = '\0';

    }
}

int main() {

    char source[] = "asdjkfbahfb12341234!@#$%";
    char integers[256];
    char nonIntegers[256];

    function(source, integers, nonIntegers);

    printf("source: %s\n", source);
    printf("integers: %s\n", integers);
    printf("nonIntegers: %s\n", nonIntegers);

    return 0;
}

