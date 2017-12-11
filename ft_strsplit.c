#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

static size_t coun(char const *p, char f)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (p[i] && p[i] == f)
        i++;
    while (p[i])
    {
        count++;
        while (p[i] && p[i] != f)
            i++;
        while (p[i] && p[i] == f)
            i++;
    }
    return (count);
}

static char *takeword(char const *s, char d)
{
    int i;
    int n;
    char *res;

    i = 0;
    while (s[i] != d)
        i++;
    if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
    n = i++;
    while (i--)
        res[n - i] = s[n - i];
    res[n] = '\0';
    return (res);
}

char **ft_strsplit(char const *s, char c)
{
    char **str;
    int i;
    int k;
    int word;

    i = 0;
    k = 0;
    word = coun(s, c);
    if (!s || word == 0)
        return (NULL);
    if (!(str = (char **)malloc(sizeof(char *) * (word + 1))))
        return (NULL);
    while (word--)
    {
        while (s[i] == c && s[i])
			i++;
		str[k++] = takeword(&s[i], c);
		while (s[i] && s[i] != c)
            i++;
    }
    str[k] = NULL;
    return (str);
}

int main()
{
    char *st1 = "*****0ewe**1eeee*2eeee*3ee*4*5eee*6eee*";
    char **res;
    char s = '*';

    res = ft_strsplit(st1, s);
    printf("%s", res[0]);
    return (0);
}
