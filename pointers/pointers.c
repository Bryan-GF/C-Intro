#include <stdio.h>
#include <string.h>
/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/



void swap(int* a, int* b)
{
    int hold = *b;
    *b = *a;
    *a = hold;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/

char *find_char(char *str, int c)
{
    printf("%i", c);
        printf("%d", *str);
    
    while(*str != '\0') {
        
        if(*str == c) {
            char *temp = str;
            return temp;
        }
        str++;
    }
    return NULL;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    int length = strlen(y);
    printf("%c\n", *y);
    printf("%c\n", *x);
    for(int i = 0; i < length; i ++) {
        *x = *y;
        printf("%c\n", *x);
        printf("%c\n", *y);
        x++;
        y++;   
    }
    *x = '\0';
    printf("%s", y);  
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/

int string_compare(char *m, char *n)
{
    while(*m == *n) {
        if(*m == '\0') {
            return 0;
        }
        m++;
        n++;
    }
    return *m - *n;

}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/

char *find_string(char *haystack, char *needle)
{   
    
    char *temp = needle;

    while(*haystack != '\0') {
        if(*haystack == *needle) {
            
            char *start = haystack;
            while(*needle == *haystack && *needle != '\0') {
                needle++;
                haystack++;
            }
            if(*needle == '\0') {
                return start;
            }
            needle = temp;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);
    
    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];
    
    
    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));
    
    char *found_char = find_char(hello, 'e');

    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);
    
    return 0;
}
#endif
