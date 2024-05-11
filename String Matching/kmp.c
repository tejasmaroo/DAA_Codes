#include <stdio.h>
#include<string.h>

void computeLPS(char *p, int m, int *lps)
{
    int i = 1;
    int j = 0;
    lps[0] = 0;

    while(i < m)
    {
        if(p[i] == p[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0)
                j = lps[j - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(char *p, char *t)
{
    int m = strlen(p);
    int n = strlen(t);

    int lps[m];
    computeLPS(p, m, lps);

    int i = 0, j = 0;

    while(i < n)
    {
        if(p[j] == t[i])
        {
            j++;
            i++;
        }

        if(j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if(p[j] != t[i])
        {
            if(j != 0)
                j = lps[j - 1];
            else    
                i++;
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABABABABCABAB";
    char pattern[] = "ABABCABAB";
    kmp_search(pattern, text);
    return 0;   
}