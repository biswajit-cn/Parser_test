#include <stdio.h>
extern char* go_parse(char* sql_string) __asm__ ("parse_test.main.Parse");
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
            char* ans_string = go_parse(string);
            printf("PARSED QUERY : \n %s \n", ans_string);
        }
        else
        {
            printf("ERROR IN PARSING QUERY\n");
        }
    }
}