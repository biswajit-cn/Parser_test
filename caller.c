#include <stdio.h>
#include <stdlib.h>
extern void go_parse(char* sql_string) __asm__ ("parse_test.Parse");
int main() 
{
    int times=1;
    while(times--)
    {
        int bytes_read;
        int size = 10;
        char *string;
        string = (char *) malloc (size);
        bytes_read = getline (&string, &size, stdin);
        if(bytes_read!=-1)
        {
            printf("PARSED QUERY : ");
            go_parse(string);
            printf("\n");
        }
        else
        {
            printf("ERROR IN PARSING QUERY\n");
        }
    }
}