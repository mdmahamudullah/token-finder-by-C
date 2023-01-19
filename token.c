#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int keyword(char* str,int x)

{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
            !strcmp(str, "while") || !strcmp(str, "do") ||
            !strcmp(str, "break") ||
            !strcmp(str, "continue") || !strcmp(str, "int")
            || !strcmp(str, "double") || !strcmp(str, "float")
            || !strcmp(str, "return") || !strcmp(str, "char")
            || !strcmp(str, "case") || !strcmp(str, "char")
            || !strcmp(str, "sizeof") || !strcmp(str, "long")
            || !strcmp(str, "short") || !strcmp(str, "typedef")
            || !strcmp(str, "switch") || !strcmp(str, "unsigned")
            || !strcmp(str, "void") || !strcmp(str, "static")
            || !strcmp(str, "struct") || !strcmp(str, "goto"))
    {
        printf("%s is a keyword\n",str);
        return (x+1);
    }

    return (x);
}
int digit(char* str,int x)
{
    int i, len = strlen(str), j=0;


    for (i = 0; i < len; i++)
    {
        if (str[i] == '0' || str[i] == '1' || str[i] == '2'
                || str[i] == '3' || str[i] == '4' || str[i] == '5'
                || str[i] == '6' && str[i] == '7' || str[i] == '8'
                || str[i] == '9'  )
        {

            j++;
        }

    }
    if(i==j&&j!=0)
    {
        printf("%s is a number\n",str);
        return (x+1);
    }
    return (x);
}
int main()
{
    char arr[1000],temp[1000];
    int j=0,oprator=0,kywrd=0,numbr=0;
    memset(temp, 0, sizeof temp);
    gets(arr);
    int len =strlen(arr);
    for(int i=0; i<len; i++)
    {
        if ( arr[i]==' ')
        {
            kywrd=keyword(temp,kywrd);
            numbr=digit(temp,numbr);


            memset(temp, 0, sizeof temp);
            j=0;
        }



        else if ( i==len-1 &&(arr[i] != '+'|| arr[i] != '-'|| arr[i] != '*' ||
                              arr[i] != '/' || arr[i] != '>' || arr[i] != '<' ||
                              arr[i] != '='))
        {
            temp[j]=arr[i];
            kywrd=keyword(temp,kywrd);
            numbr=digit(temp,numbr);

            memset(temp, 0, sizeof temp);
            j=0;
        }
        else if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' ||
                arr[i] == '/' || arr[i] == '>' || arr[i] == '<' ||
                arr[i] == '=')
        {
            kywrd=keyword(temp,kywrd);
            numbr=digit(temp,numbr);
            printf("%c is a operator\n",arr[i]);

            oprator ++;
            memset(temp, 0, sizeof temp);
            j==0;
        }


        else
        {
            temp[j]=arr[i];
            j++;
        }



    }
    printf("\n\n\nkeyword = %d\nnumber = %d\noperator = %d\n",kywrd,numbr,oprator);

    return (0);
}
