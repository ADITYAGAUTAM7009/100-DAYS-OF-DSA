/*
Name: Aditya Gautam
Problem: Evaluate String Expression (Basic Calculator II)
*/

#include <stdio.h>
#include <ctype.h>

int calculate(char *s)
{
    long num = 0, last = 0, result = 0;
    char op = '+';

    for (int i = 0; ; i++)
    {
        char c = s[i];

        if (isdigit(c))
            num = num * 10 + (c - '0');

        if ((!isdigit(c) && c != ' ') || c == '\0')
        {
            if (op == '+') { result += last; last = num; }
            else if (op == '-') { result += last; last = -num; }
            else if (op == '*') last = last * num;
            else if (op == '/') last = last / num;

            if (c == '\0')
                break;

            op = c;
            num = 0;
        }
    }

    return result + last;
}

int main()
{
    char s[300001];

    fgets(s, sizeof(s), stdin);

    printf("%d\n", calculate(s));

    return 0;
}
