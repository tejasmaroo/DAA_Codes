#include<stdio.h>
#include<string.h>

#define d 26
#define q 13

void search(char *pat, char * txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int i, j;
    int p = 0, t = 0, h = 1 , spurhit = 0 ;

    for(i = 0; i < m - 1; i ++)
    {
        h = (h * d) % q;
    }

    for(i = 0; i < m; i++)
    {
        p = (d * p + (pat[i] - 'A')) % q;
        t = (d * t + (txt[i] - 'A')) % q;
    }

    for(i = 0; i <= n - m; i++)
    {
        if(p == t){
            for(j = 0; j < m; j++)
            {
                if(txt[i + j] != pat[j])
                    break;
            }
            if(j == m)
                printf("Pattern found at index %d\n", i);
            else
                spurhit += 1;
        }

        if(i < n - m)
        {
            t = (d * (t - (txt[i] - 'A') * h) + (txt[i + m] - 'A')) % q;
            if(t < 0)
                t = t + q;
        }
    }
}

int main()
{
    char t[] = "ABCJEAFHFAEFBAFGABC";
    char p[] = "ABC";
    search(p, t);
    return 0;
}