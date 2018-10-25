/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:07:15 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/04 12:26:43 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>

void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strncpy(char *dst, const char *src, size_t len);
char    *ft_strcat(char *s1, const char *s2);
char    *ft_strncat(char *s1, const char *s2, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strstr(const char *big, const char *little);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_atoi(const char *str);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
void    *ft_memalloc(size_t size);
void    ft_memdel(void **ap);
char    *ft_strnew(size_t size);
void    ft_strdel(char **as);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
char    *ft_strmap(char const *s, char (*f)(char));
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int     ft_strequ(char const *s1, char const *s2);
int     ft_strnequ(char const *s1, char const *s2, size_t n);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s);
char    **ft_strsplit(char const *s, char c);
char    *ft_itoa(int n);
void    ft_putchar(char c);
void    ft_putstr(char const *s);
void    ft_putendl(char const *s);
void    ft_putnbr(int n);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char const *s, int fd);
void    ft_putendl_fd(char const *s, int fd);
void    ft_putnbr_fd(int n, int fd);
t_list  *ft_lstnew(void const *content, size_t content_size);
void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void    ft_lstadd(t_list **alst, t_list *new);
void    ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list  *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void    test_ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        write(1, &(*(s + i)), 1);
        i++;
    }
}

void test_striteri(unsigned int j, char *s1)
{
    unsigned int i;

    i = 0;
    while (i < j)
    {
        write(1, &(*(s1 + i)), 1);
        i++;
    }
}

char test_strmap(char c1)
{
    c1 += 1;
    return (c1);
}

char test_strmapi(unsigned int i, char c2)
{
    c2 += i;
    return (c2);
}

/*void del(void *del_str, size_t del_size)
{
 
    if (del_str)
    {
        free(del_str);
        del_str = NULL;
    }
}*/

t_list  *test_lstnew(t_list *list, void const *content, size_t content_size)
{
    t_list *new_list;

    new_list = malloc(sizeof(t_list));
    if (new_list && content)
    {
        new_list->content = malloc(content_size);
        if(!(new_list->content = (char *)content))
            {
                free (new_list);
                return (NULL);
            }
        new_list->content_size = content_size;
        new_list->next = list;
        return (new_list);
    }
    if (content == NULL)
    {
        new_list->content = NULL;
        new_list->content_size = 0;
    }
    return (NULL);
}

void test_lstiter(t_list *elem)
{
    t_list *tmp4;
    tmp4 = NULL;
    tmp4 = test_lstnew(tmp4, "Result", 10);
    elem = tmp4;
}

t_list *test_lstmap(t_list *elem)
{
    t_list *tmp6;
    tmp6 = NULL;
    tmp6 = test_lstnew(tmp6, "Result", 10);
    elem = tmp6;
    return (elem);
}

int main(void)
{
    printf("%s", "LIBRARY FUNCTIONS\n\n");

	printf("%s", "MEMSET FUNCTION\n\n");
	unsigned char src[] = "1234567890dfsfdgfdgfghf";
	printf("%s", "Original MEMSET output\n");
	printf("%s%s\n", "Original string is ", src);
	printf("%s%s\n", "Set symbol 1 to 10 bytes ", memset(src, '1', 10));
	printf("%s%s\n", "Set symbol 2 to 5 bytes ", memset(src, '2', 5));
	printf("%s%s\n", "Set symbol 3 to 1 byte ", memset(src, '3', 1));
    printf("%s%d\n", "If len is 0 pointer adress should be: ", (int)memset(src, '3', 0));
    printf("%s%s\n", "If char has non asii code: ", memset(src, 999, 5));
	printf("%s", "\nCustom MEMSET output\n");
	unsigned char src1[] = "1234567890dfsfdgfdgfghf";
	printf("%s\n", src1);
    printf("%s%s\n", "Set symbol 1 to 10 bytes ", ft_memset(src1, '1', 10));
	printf("%s%s\n", "Set symbol 2 to 5 bytes ", ft_memset(src1, '2', 5));
	printf("%s%s\n", "Set symbol 3 to 1 byte ", ft_memset(src1, '3', 1));
    printf("%s%d\n", "If len is 0 pointer adress should be: ", (int)ft_memset(src, '3', 0));
    printf("%s%s\n\n", "If char has non asii code: ", ft_memset(src, 999, 5));

	printf("%s", "BZERO FUNCTION\n\n");
	int src25[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%s", "Original BZERO output\n");
	printf("%s%d\n", "Original string is ", *src25);
    bzero(src25, 0);
    printf("%s%d\n", "bzero with 0 bytes ", *src25);
	bzero(src25, 1);
	printf("%s%d\n", "bzero with 1 byte ", *src25);
	bzero(src25, 8);
	printf("%s%d\n", "bzero with 8 bytes ", *(src25 + 2));
	bzero(src25, 16);
	printf("%s%d\n", "bzero with 16 bytes ", *(src25 + 3));
    printf("%s", "\nCustom BZERO output\n");
	int src26[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%s%d\n", "Original string is ", *src26);
    ft_bzero(src26, 0);
    printf("%s%d\n", "bzero with 0 byte ", *src26);
	ft_bzero(src26, 1);
	printf("%s%d\n", "bzero with 1 byte ", *src26);
	ft_bzero(src26, 8);
	printf("%s%d\n", "bzero with 8 bytes ", *(src26 + 2));
	ft_bzero(src26, 16);
	printf("%s%d\n\n", "bzero with 16 bytes ", *(src26 + 3));
    
	unsigned char src2[] = "Hello";
	unsigned char dest2[] = "ABCD";
	printf("%s", "MEMCPY FUNCTION\n\n");
	printf("%s", "Original MEMCPY output\n");
	printf("%s%s\n", "0 bytes: ", memcpy(dest2, src2, 0));
	printf("%s%s\n", "2 bytes: ", memcpy(dest2, src2, 2));
	printf("%s", "\nCustom MEMCPY output\n");
	unsigned char src3[] = "Hello";
    unsigned char dest3[] = "ABCD";
	printf("%s%s\n", "0 bytes: ", ft_memcpy(dest3, src3, 0));
    printf("%s%s\n\n", "2 bytes: ", ft_memcpy(dest3, src3, 2));

	char src27[] = "1234567890";
    char dest4[10];
    printf("%s", "MEMCCPY FUNCTION\nOriginal MEMCCPY output");
    printf("%s%s", "\nOriginal string is ", src27);
	printf("%s%u", "\nReturned value is ", (unsigned int)memccpy(dest4, src27, 49, 3));
	printf("%s%s", "\nDestination string with found c symbol is ", dest4);
	printf("%s%d", "\nReturned value is ", (int)memccpy(dest4, src27, 30, 5));
	printf("%s%s", "\nDestination string with not found c symbol is ", dest4);
    printf("%s%d", "\nReturned value is ", (int)memccpy(dest4, src27, 999, 5));
    printf("%s%s", "\nDestination string if c is non ascii is ", dest4);
    printf("%s%d", "\nReturned value is ", (int)memccpy(dest4, src27, 30, 0));
    printf("%s%s", "\nDestination string with size is 0: ", dest4);
	char src4[] = "1234567890";
    char dest5[10];
	printf("%s%s", "\n\nCustom MEMCCPY output\nSRC string is ", src4);
    printf("%s%s", "\nOriginal string is ", src4);
    printf("%s%u", "\nReturned value is ", (unsigned int)ft_memccpy(dest5, src4, 49, 3));
    printf("%s%s", "\nDestination string with found c symbol is ", dest5);
    printf("%s%d", "\nReturned value is ", (int)ft_memccpy(dest5, src4, 30, 5));
    printf("%s%s", "\nDestination string with not found c symbol is ", dest5);
    printf("%s%d", "\nReturned value is ", (int)ft_memccpy(dest5, src4, 999, 5));
    printf("%s%s", "\nDestination string if c is non ascii is ", dest5);
    printf("%s%d", "\nReturned value is ", (int)ft_memccpy(dest5, src4, 30, 0));
    printf("%s%s\n\n", "\nDestination string with size is 0: ", dest5);
    
    printf("%s", "MEMMOVE FUNCTION\n\nOriginal MEMMOVE output\n");
    char src22[] = "1234567890";
    char dest22[] = "abcdefghijk";
    printf("%s%s", "\nOriginal string is ", dest22);
    printf("%s%s", "\nDestination string with 3 bytes from src 1 to dest 5", (char *)memmove(&dest22[1], &src22[5], 3));
    printf("%s%s", "\nDestination string with 3 bytes from src 5 to dest 1", (char *)memmove(&dest22[5], &src22[1], 3));
    printf("%s%s", "\nDestination string with 7 bytes from src 1 to dest 5", (char *)memmove(&dest22[1], &src22[5], 7));
    printf("%s%s", "\nDestination string with 7 bytes from src 5 to dest 1", (char *)memmove(&dest22[5], &src22[1], 7));
    printf("%s%s", "\nDestination string with 0 bytes from src 1 to dest 5", (char *)memmove(&dest22[1], &src22[5], 0));
    char src23[] = "1234567890";
    char dest23[] = "abcdefghijk";
    printf("%s%s", "\n\nCustom MEMMOVE output\nSRC string is ", dest23);
    printf("%s%s", "\nDestination string with 3 bytes from src 1 to dest 5", (char *)ft_memmove(&dest23[1], &src23[5], 3));
    printf("%s%s", "\nDestination string with 3 bytes from src 5 to dest 1", (char *)ft_memmove(&dest23[5], &src23[1], 3));
    printf("%s%s", "\nDestination string with 7 bytes from src 1 to dest 5", (char *)ft_memmove(&dest23[1], &src23[5], 7));
    printf("%s%s", "\nDestination string with 7 bytes from src 1 to dest 1", (char *)ft_memmove(&dest23[5], &src23[1], 7));
    printf("%s%s\n\n", "\nDestination string with 0 bytes from src 1 to dest 5", (char *)ft_memmove(&dest23[1], &src23[5], 0));

    printf("%s", "MEMCHR FUNCTION\n\nOriginal MEMCHR output\n");
    char src24[] = "1234567890";
    printf("%s%s", "Original string is ", src24);
    printf("%s%s", "\nFind 9 in first 5 bytes ", memchr(src24, '9', 5));
    printf("%s%s", "\nFind 9 in first 10 bytes ", memchr(src24, '9', 10));
    printf("%s%s", "\nFind non ascii in first 6 bytes ", memchr("abcdef", 999, 6));
    printf("%s%d", "\nFind non ascii in first 6 bytes ", (int)memchr("abcdef", 999, 6));
    printf("%s%s", "\nFind c in first 0 bytes ", memchr("abcdef", 47, 0));
    printf("%s%s", "\n\nCustom MEMCHR output\nOriginal string is ", src24);
    printf("%s%s", "\nFind 9 in first 5 bytes ", ft_memchr(src24, '9', 5));
    printf("%s%s", "\nFind 9 in first 10 bytes ", ft_memchr(src24,'9', 10));
    printf("%s%s", "\nFind non ascii in first 6 bytes ", ft_memchr("abcdef", 999, 6));
    printf("%s%d", "\nFind non ascii in first 6 bytes ", (int)ft_memchr("abcdef", 999, 6));
    printf("%s%s\n\n", "\nFind c in first 0 bytes ", ft_memchr("abcdef", 47, 0));

    printf("%s", "MEMCMP FUNCTION\n\nOriginal MEMCMP output\n");
    printf("%s%d\n", "If strings are the same result is ", memcmp("hello", "hello", 3));
    printf("%s%d\n", "If first string shorter result is ", memcmp("hell", "hello", 5));
    printf("%s%d\n", "If first string longer result is ", memcmp("hello", "hell", 5));
    printf("%s%d\n", "If first string has bigger byte result is ", memcmp("hello", "aello", 3));
    printf("%s%d\n", "If first string has less byte result is ", memcmp("aello", "hello", 3));
    printf("%s%d\n", "If len is 0: ", memcmp("hello", "hello", 0));
    printf("%s%d\n", "If first string is empty: ", memcmp("", "aello", 3));
    printf("%s%d\n", "If second string is empty: ", memcmp("aello", "", 3));
    printf("\n%s\n", "CUSTOM MEMCMP output");
    printf("%s%d\n", "If strings are the same result is ", ft_memcmp("hello", "hello", 3));
    printf("%s%d\n", "If first string shorter result is ", ft_memcmp("hell", "hello", 5));
    printf("%s%d\n", "If first string longer result is ", ft_memcmp("hello", "hell", 5));
    printf("%s%d\n", "If first string has bigger byte result is ", ft_memcmp("hello", "aello", 3));
    printf("%s%d\n", "If first string has less byte result is ", ft_memcmp("aello", "hello", 3));
    printf("%s%d\n", "If len is 0: ", ft_memcmp("hello", "hello", 0));
    printf("%s%d\n", "If first string is empty: ", ft_memcmp("", "aello", 3));
    printf("%s%d\n\n", "If second string is empty: ", ft_memcmp("aello", "", 3));

	printf("%s", "STRLEN FUNCTION\n\nORIGINAL STRLEN output");
	printf("%s%lu", "\nThe length of \"Hello\" is ", strlen("Hello"));
	printf("%s%lu", "\nThe length of empty string is is ", strlen(""));
	printf("%s", "\n\nCUSTOM STRLEN output");
    printf("%s%lu", "\nThe length of \"Hello\" is ", ft_strlen("Hello"));
    printf("%s%lu\n\n", "\nThe length of empty string is is ", ft_strlen(""));
  
	printf("%s", "STRDUP FUNCTION\n\nORIGINAL STRDUP output");
	printf("%s%s", "\nOutput of \"Hello\" string is ", strdup("Hello"));
    printf("%s%d", "\nOutput of \"\" string is ", (int)strdup(""));
	printf("%s", "\n\nCUSTOM STRDUP output");
	printf("%s%s", "\nOutput of \"Hello\" string is ", ft_strdup("Hello"));
    printf("%s%d\n\n", "\nOutput of \"\" string is ", (int)ft_strdup(""));
	
	printf("%s", "STRCPY FUNCTION\n\nORIGINAL STRCPY output\n");
	char src5[] = "123456789";
    char dest6[10];
    printf("%s%s\n", "Original string is ", src5);
	printf("%s%s\n", "Dest string is ", strcpy(dest6, src5));
	printf("\nCUSTOM STRCPY output\n");
	char src66[] = "123456789";
    char dest77[10];
    printf("%s%s\n", "Original string is ", src66);
	printf("%s%s\n\n", "Dest string is ", ft_strcpy(dest77, src66));
   
	printf("%s", "STRNCPY FUNCTION\n\nORIGINAL STRNCPY output\n");
	char src6[] = "12345678901";
    char dest7[10];
    printf("%s%s\n", "Original string is ", src6);
    printf("%s%s\n", "If src is longer than len dest string is ", strncpy(dest7, src6, 5));
    printf("%s%s\n", "If len is 0: ", strncpy(dest7, src6, 0));
    printf("%s%s\n", "If source is empty string: ", strncpy(dest7, "", 5));
   	printf("%s", "\nCUSTOM STRNCPY output\n");
    char src7[] = "12345678901";
    char dest8[10];
    printf("%s%s\n", "Original string is ", src7);
    printf("%s%s\n", "If src is longer than len dest string is ", ft_strncpy(dest8, src7, 5));
    printf("%s%s\n", "If len is 0: ", ft_strncpy(dest8, src7, 0));
    printf("%s%s\n\n", "If source is empty string: ", ft_strncpy(dest8, "", 5));

    printf("%s", "STRCAT FUNCTION\n\nORIGINAL STRCAT output");
	char src9[20] = "Hello, ";
    char dest10[10] = "World";
	printf("%s%s\n", "\nDest string is ", strcat(src9, dest10));
    printf("%s%s\n", "Dest string is ", strcat(src9, ""));
	printf("%s", "\n\nCUSTOM STRCAT output");
    char src10[20] = "Hello, ";
    char dest11[10] = "World";
	printf("%s%s\n", "\nDest string is ", ft_strcat(src10, dest11));
    printf("%s%s\n\n", "Dest string is ", ft_strcat(src10, ""));
	
	printf("%s", "STRNCAT FUNCTION\n\nORIGINAL STRNCAT output");
    char src12[20] = "Hello, ";
    char dest13[10] = "World";
    printf("%s%s\n", "\nIf len less than s2 dest string is ", strncat(src12, dest13, 3));
   	char src13[20] = "Hello, ";
    char dest14[10] = "World";
	printf("%s%s\n", "If len longer than s2 dest string is ", strncat(src13, dest14, 10));
    printf("%s%s\n", "If len is 0 ", strncat(src13, dest14, 0));
    printf("%s%s\n", "If source is empty string ", ft_strncat(src13, "", 10));
  	printf("%s", "\nCUSTOM STRNCAT output");
    char src14[20] = "Hello, ";
    char dest15[10] = "World";
	printf("%s%s\n", "\nIf len less than s2 dest string is ", ft_strncat(src14, dest15, 3));
	char src15[20] = "Hello, ";
    char dest16[10] = "World";
	printf("%s%s\n", "If len longer than s2 dest string is ", ft_strncat(src15, dest16, 10));
    printf("%s%s\n", "If len is 0 ", ft_strncat(src15, dest16, 0));
    printf("%s%s\n\n", "If source is empty string ", ft_strncat(src15, "", 10));

	printf("%s", "STRLCAT FUNCTION\nORIGINAL STRLCAT output");
    printf("%s%lu\n", "If len is 5 and less than dest result is ", strlcat("1234567890", "567890", 5));
    printf("%s%lu\n", "If len is 10 and equal with dest result is ", strlcat("1234567890", "567890", 10));
    printf("%s%lu\n", "If len is 3 and dest longer source is ", strlcat("1234567890", "567890", 3));
    printf("%s%lu\n", "If len is 3 and source longer dest is ", strlcat("567890", "1234567890", 3));
    printf("%s%lu\n", "If len is 0 and less than dest result is ", strlcat("1234567890", "567890", 0));
    printf("%s%lu\n", "If len is 0 and less than dest result is ", strlcat("567890", "1234567890", 0));
    printf("%s%lu\n", "If source is empty ", strlcat("1234567890", "", 5));
    printf("\n%s\n", "CUSTOM STRLCAT output");
    //printf("%s%lu\n", "If len is 5 and less than dest result is ", ft_strlcat("1234567890", "567890", 5));
    printf("%s%lu\n", "If len is 10 and equal with dest result is ", ft_strlcat("1234567890", "567890", 10));
    printf("%s%lu\n", "If len is 3 and dest longer source is ", ft_strlcat("1234567890", "567890", 3));
    printf("%s%lu\n", "If len is 3 and source longer dest is ", ft_strlcat("567890", "1234567890", 3));
    printf("%s%lu\n", "If len is 0 and less than dest result is ", ft_strlcat("1234567890", "567890", 0));
    printf("%s%lu\n", "If len is 0 and less than dest result is ", ft_strlcat("567890", "1234567890", 0));
    printf("%s%lu\n\n", "If source is empty ", ft_strlcat("1234567890", "", 5));
   
	printf("%s", "STRCHR FUNCTION\n\nORIGINAL strchr output\n");
	char src20[] = "1234567890sfdsgfhfghgfh";
	printf("%s%s\n", "Original string is ", src20);
	printf("%s%s\n", "4 symbol found ", strchr(src20, '4'));
	printf("%s%s", "Symbol a not found ", strchr(src20, 'a'));
	printf("\n%s%d", "Symbol is 0 ", (int)*strchr(src20, 0));
    printf("%s%s", "Non ascii symbol ", strchr(src20, 999));
	printf("\n\n%s", "CUSTOM strchr output\n");
    printf("%s%s\n", "Original string is ", src20);
	printf("%s%s\n", "4 symbol found ", ft_strchr(src20, '4'));
	printf("%s%s", "Symbol a not found ", ft_strchr(src20, 'a'));
	printf("\n%s%d", "Symbol is 0 ", (int)*ft_strchr(src20, 0));
    printf("%s%s\n\n", "Non ascii symbol ", ft_strchr(src20, 999));

	printf("%s", "STRRCHR FUNCTION\n\nORIGINAL strrchr output\n");
	char src30[] = "1234567890sfdsgfhfghgfh";
	printf("%s%s\n", "Original string is ", src30);
	printf("%s%s\n", "f symbol found ", strrchr(src30, 'f'));
	printf("%s%s\n", "Symbol not found ", strrchr(src30, 'a'));
	printf("\n%s%d", "Symbol is 0 ", (int)*strrchr(src30, 0));
	printf("\n\n%s\n", "CUSTOM strrchr output");
    printf("%s%s\n", "Original string is ", src30);
	printf("%s%s\n", "f symbol found ", ft_strrchr(src30, 'f'));
	printf("%s%s\n", "Symbol not found ", ft_strrchr(src30, 'a'));
	printf("\n%s%d\n\n", "Symbol is 0 ", (int)*ft_strrchr(src30, 0));

	printf("%s", "STRSTR FUNCTION\nORIGINAL strstr output\n");
    char src21[] = "1234567890";
    char dest21[] = "34567";
    printf("%s%s\n", "Original string is ", src21);
    printf("%s%s\n", "We find string ", dest21);
    printf("%s%s\n", "String is found ", strstr(src21, dest21));
    printf("%s%s\n", "String not found ", strstr(src21, "dfgd"));
    printf("%s%s\n", "String is found ", strstr("", dest21));
    printf("\n%s%s", "String 2 has 0 length ", strstr(src21, ""));
    printf("\n\n%s\n", "CUSTOM strstr output");
    char src34[] = "1234567890";
    char dest34[] = "34567";
    printf("%s%s\n", "Original string is ", src34);
    printf("%s%s\n", "We find string ", dest34);
    printf("%s%s\n", "String is found ", ft_strstr(src34, dest34));
    printf("%s%s\n", "String not found ", ft_strstr(src34, "dfgd"));
    printf("%s%s\n", "String not found ", ft_strstr("", dest34));
    printf("\n%s%s\n\n", "String 2 has 0 length ", ft_strstr(src34, ""));

    printf("%s", "STRNSTR FUNCTION\nORIGINAL strnstr output\n");
    char src35[] = "1234567890";
    char dest35[] = "34567";
    printf("%s%s\n", "Original string is ", src35);
    printf("%s%s\n", "We find string ", dest35);
    printf("%s%s\n", "String is found ", strnstr(src35, dest35, 10));
    printf("%s%s\n", "String not found ", strnstr(src35, "dfgd", 3));
    printf("%s%s\n", "String 2 has 0 length ", strnstr(src35, "", 3));
    printf("%s%s\n", "If length is 0 ", strnstr(src35, dest35, 0));
    char src36[] = "1234567890";
    char dest36[] = "34567";
    printf("\n\n%s\n", "CUSTOM strnstr output");
    printf("%s%s\n", "Original string is ", src36);
    printf("%s%s\n", "We find string ", dest36);
    printf("%s%s\n", "String is found ", ft_strnstr(src36, dest36, 10));
    printf("%s%s\n", "String not found ", ft_strnstr(src36, "dfgd", 3));
    printf("%s%s\n", "String 2 has 0 length ", ft_strnstr(src36 , "", 3));
    printf("%s%s\n\n", "If length is 0 ", ft_strnstr(src36, dest36, 0));


    printf("%s", "STRCMP FUNCTION\n\nORIGINAL STRCMP output\n");
    printf("%s%d\n", "If strings are the same result is ", strcmp("hello", "hello"));
    printf("%s%d\n", "If first string shorter result is ", strcmp("hell", "hello"));
    printf("%s%d\n", "If first string longer result is ", strcmp("hello", "hell"));
    printf("%s%d\n", "If first string has bigger byte result is ", strcmp("hello", "aello"));
    printf("%s%d\n", "If first string has less byte result is ", strcmp("aello", "hello"));
    printf("%s%d\n", "If first string is empty ", strcmp("", "hello"));
    printf("%s%d\n", "If second string is empty ", strcmp("aello", ""));
    printf("\n%s\n", "CUSTOM STRCMP output");
    printf("%s%d\n", "If strings are the same result is ", ft_strcmp("hello", "hello"));
    printf("%s%d\n", "If first string shorter result is ", ft_strcmp("hell", "hello"));
    printf("%s%d\n", "If first string longer result is ", ft_strcmp("hello", "hell"));
    printf("%s%d\n", "If first string has bigger byte result is ", ft_strcmp("hello", "aello"));
    printf("%s%d\n", "If first string has less byte result is ", ft_strcmp("aello", "hello"));
    printf("%s%d\n", "If first string is empty ", ft_strcmp("", "hello"));
    printf("%s%d\n\n", "If second string is empty ", ft_strcmp("aello", ""));

	printf("%s", "STRNCMP FUNCTION\n\nORIGINAL STRNCMP output\n");
    printf("%s%d\n", "If strings are the same result is ", strncmp("hello", "hellojkl", 5));
    printf("%s%d\n", "If first string shorter result is ", strncmp("hell", "hellosfsfdsf", 5));
    printf("%s%d\n", "If first string longer result is ", strncmp("hello", "hell", 5));
    printf("%s%d\n", "If first string has bigger byte result is ", strncmp("hello123", "aello456", 3));
    printf("%s%d\n", "If first string has less byte result is ", strncmp("aello123", "hello456", 2));
    printf("%s%d\n", "If first string has less byte result is ", strncmp("aello123", "hello456", 0));
    printf("%s%d\n", "If first string has less byte result is ", strncmp("", "hello456", 2));
    printf("%s%d\n", "If first string has less byte result is ", strncmp("aello123", "", 2));
    printf("\n%s\n", "CUSTOM STRNCMP output");
    printf("%s%d\n", "If strings are the same result is ", ft_strncmp("hello", "hellojkl", 5));
    printf("%s%d\n", "If first string shorter result is ", ft_strncmp("hell", "hellosfsfdsf", 5));
    printf("%s%d\n", "If first string longer result is ", ft_strncmp("hello", "hell", 5));
    printf("%s%d\n", "If first string has bigger byte result is ", ft_strncmp("hello123", "aello456", 3));
    printf("%s%d\n", "If first string has less byte result is ", ft_strncmp("aello123", "hello456", 2));
    printf("%s%d\n", "If first string has less byte result is ", ft_strncmp("aello123", "hello456", 0));
    printf("%s%d\n", "If first string has less byte result is ", ft_strncmp("", "hello456", 2));
    printf("%s%d\n\n", "If first string has less byte result is ", ft_strncmp("aello123", "", 2));

	printf("\n%s", "ATOI FUNCTION\nORIGINAL ATOI output\n");
    printf("%s%d\n", "If string with literals result is ", atoi("dfdf5"));
    printf("%s%d\n", "If string with gaps rewult is ", atoi("   456"));
    printf("%s%d\n", "If string with + and gaps result is ", atoi("+   456df  "));
    printf("%s%d\n", "If string with plus result is ", atoi("+456df  "));
    printf("%s%d\n", "If string with gaps and - result is ", atoi("   -456"));
    printf("%s%d\n", "If string with slash n result is ", atoi("\n\n\n\n+456"));
    printf("%s%d\n", "If string with slash t result is ", atoi("\t-54646"));
    printf("%s%d\n", "If string with slash v result is ", atoi("\v596"));
    printf("%s%d\n", "If string with slash f result is ", atoi("\f596"));
    printf("%s%d\n", "If string with slash r result is ", atoi("\r596"));
    printf("%s%d\n", "If string with extreme negative int result is ", atoi("-2147483648"));
    printf("%s%d\n", "If string with extreme positive int result is ", atoi("+2147483647"));
    printf("%s%d\n", "If string with less then extreme negative int result is ", atoi("-21474836481686"));
    printf("%s%d\n", "If string with more then extreme positive int result is ", atoi("+21474836471686"));
    printf("%s%d\n", "If string with less then extreme negative long long result is ", atoi("-99999999999999999999999999"));
    printf("%s%d\n", "If string with more then extreme positive long long result is ", atoi("99999999999999999999999999"));
    printf("\n%s\n", "CUSTOM ATOI output");
    printf("%s%d\n", "If string with literals result is ", ft_atoi("dfdf5"));
    printf("%s%d\n", "If string with gaps rewult is ", ft_atoi("   456"));
    printf("%s%d\n", "If string with + and gaps result is ", ft_atoi("+   456df  "));
    printf("%s%d\n", "If string with plus result is ", ft_atoi("+456df  "));
    printf("%s%d\n", "If string with gaps and - result is ", ft_atoi("   -456"));
    printf("%s%d\n", "If string with slash n result is ", ft_atoi("\n\n\n\n+456"));
    printf("%s%d\n", "If string with slash t result is ", ft_atoi("\t-54646"));
    printf("%s%d\n", "If string with slash v result is ", ft_atoi("\v596"));
    printf("%s%d\n", "If string with slash f result is ", ft_atoi("\f596"));
    printf("%s%d\n", "If string with slash r result is ", ft_atoi("\r596"));
    printf("%s%d\n", "If string with extreme negative int result is ", ft_atoi("-2147483648"));
    printf("%s%d\n", "If string with extreme positive int result is ", ft_atoi("+2147483647"));
    printf("%s%d\n", "If string with less then extreme negative int result is ", ft_atoi("-21474836481686"));
    printf("%s%d\n", "If string with more then extreme positive int result is ", ft_atoi("+21474836471234"));
    printf("%s%d\n", "If string with less then extreme negative long long result is ", ft_atoi("-99999999999999999999999999"));
    printf("%s%d\n\n", "If string with more then extreme positive long long result is ", ft_atoi("99999999999999999999999999"));

    printf("\n%s", "ISALPHA FUNCTION\n\nORIGINAL ISALPHA output\n");
    printf("%s%d\n", "Is alpha a ", isalpha('a'));
    printf("%s%d\n", "Is alpha k ", isalpha('k'));
    printf("%s%d\n", "Is alpha z ", isalpha('z'));
    printf("%s%d\n", "Is alpha A ", isalpha('A'));
    printf("%s%d\n", "Is alpha K ", isalpha('K'));
    printf("%s%d\n", "Is alpha Z ", isalpha('Z'));
    printf("%s%d\n", "Is alpha gap ", isalpha(' '));
    printf("%s%d\n", "Is alpha * ", isalpha('*'));
    printf("\n%s\n", "CUSTOM ISALPHA output");
    printf("%s%d\n", "Is alpha a ", ft_isalpha('a'));
    printf("%s%d\n", "Is alpha k ", ft_isalpha('k'));
    printf("%s%d\n", "Is alpha z ", ft_isalpha('z'));
    printf("%s%d\n", "Is alpha A ", ft_isalpha('A'));
    printf("%s%d\n", "Is alpha K ", ft_isalpha('K'));
    printf("%s%d\n", "Is alpha Z ", ft_isalpha('Z'));
    printf("%s%d\n", "Is alpha gap ", ft_isalpha(' '));
    printf("%s%d\n\n", "Is alpha * ", ft_isalpha('*'));

    printf("%s", "ISDIGIT FUNCTION\n\nORIGINAL ISDIGIT output\n");
    printf("%s%d\n", "Is alpha 3 with code 50 ", isdigit(50));
    printf("%s%d\n", "Is alpha 7 ", isdigit('7'));
    printf("%s%d\n", "Is alpha z ", isdigit('z'));
    printf("\n%s\n", "CUSTOM ISDIGIT output");
    printf("%s%d\n", "Is alpha 3 with code 50 ", ft_isdigit(50));
    printf("%s%d\n", "Is alpha 7 ", ft_isdigit('7'));
    printf("%s%d\n\n", "Is alpha z ", ft_isdigit('z'));

    printf("%s", "ISALNUM FUNCTION\n\nORIGINAL ISALNUM output\n");
    printf("%s%d\n", "Is alpha * ", isalnum('*'));
    printf("%s%d\n", "Is alpha 7 ", isalnum('7'));
    printf("%s%d\n", "Is alpha z ", isalnum('z'));
    printf("\n%s\n", "CUSTOM ISALNUM output");
    printf("%s%d\n", "Is alpha * ", ft_isalnum('*'));
    printf("%s%d\n", "Is alpha 7 ", ft_isalnum('7'));
    printf("%s%d\n\n", "Is alpha z ", ft_isalnum('z'));

    printf("%s", "ISASCII FUNCTION\n\nORIGINAL ISASCII output\n");
    printf("%s%d\n", "Is alpha * ", isascii('*'));
    printf("%s%d\n", "Is alpha 7 ", isascii('7'));
    printf("%s%d\n", "Is alpha z ", isascii('z'));
    printf("\n%s\n", "CUSTOM ISASCII output");
    printf("%s%d\n", "Is alpha * ", ft_isascii('*'));
    printf("%s%d\n", "Is alpha 7 ", ft_isascii('7'));
    printf("%s%d\n\n", "Is alpha z ", ft_isascii('z'));

    printf("%s", "ISPRINT FUNCTION\n\nORIGINAL ISPRINT output\n");
    printf("%s%d\n", "Is alpha * ", isprint('*'));
    printf("%s%d\n", "Is alpha 7 ", isprint('7'));
    printf("%s%d\n", "Is alpha z ", isprint('z'));
    printf("\n%s\n", "CUSTOM ISPRINT output");
    printf("%s%d\n", "Is alpha * ", ft_isprint('*'));
    printf("%s%d\n", "Is alpha 7 ", ft_isprint('7'));
    printf("%s%d\n\n", "Is alpha z ", ft_isprint('z'));

    printf("%s", "TOUPPER FUNCTION\n\nORIGINAL TOUPPER output\n");
    printf("%s%d\n", "Is alpha a ", toupper('a'));
    printf("%s%d\n", "Is alpha 7 ", toupper('7'));
    printf("%s%d\n", "Is alpha z ", toupper('z'));
    printf("\n%s\n", "CUSTOM TOUPPER output");
    printf("%s%d\n", "Is alpha a ", ft_toupper('a'));
    printf("%s%d\n", "Is alpha 7 ", ft_toupper('7'));
    printf("%s%d\n\n", "Is alpha z ", ft_toupper('z'));

    printf("%s", "TOLOWER FUNCTION\n\nORIGINAL TOLOWER output\n");
    printf("%s%d\n", "Is alpha A ", tolower('A'));
    printf("%s%d\n", "Is alpha 7 ", tolower('7'));
    printf("%s%d\n", "Is alpha Z ", tolower('Z'));
    printf("\n%s\n", "CUSTOM TOLOWER output");
    printf("%s%d\n", "Is alpha A ", ft_tolower('A'));
    printf("%s%d\n", "Is alpha 7 ", ft_tolower('7'));
    printf("%s%d\n\n", "Is alpha Z ", ft_tolower('Z'));

    printf("%s", "\nADDITIONAL FUNCTIONS\n\n");

    printf("%s", "FT_PUTCHAR ouput\n");
    printf("\n%s\n", "Print a symbol: ");
    ft_putchar('a');
    printf("\n%s\n", "Print a symbol: ");
    ft_putchar(57);

    printf("%s", "\n\nFT_PUTSTR ouput\n");
    printf("\n%s", "Print Hello");
    ft_putstr("Hello");

    printf("%s", "\n\nFT_PUTENDL ouput\n");
    printf("\n%s", "Print Hello");
    ft_putendl("Hello");

    printf("%s", "\n\nFT_STRITER ouput\n");
    printf("%s\n", "Call ft_striter with Hello string and putchar function: ");
    ft_striter("Hello", &test_ft_putstr);

    printf("%s", "\n\nFT_STRITERI ouput\n");
    printf("%s\n", "Call ft_striteri with Hello string and putchar function: ");
    ft_striteri("Hello", &test_striteri);

    /*printf("%s", "\n\nFT_MEMALLOC ouput\n");       
    printf("%s%d\n", "The memory allocated is initialized to 0: ", (int)ft_memalloc(3));
    printf("%s%d\n", "The memory allocated is initialized to 0: ", (int)ft_memalloc(0));

    printf("%s", "\n\nFT_STRNEW ouput\n");
    printf("%s%d", "The string allocated and initialized to 0: ", (int)ft_strnew(3));*/

    /*printf("%s", "FT_STRCLR ouput\n");
    char *src29 = "Hello";
    printf("%s%s\n", "Original string is ", src29);
    ft_strclr(src29);
    printf("%s%d\n", "Clear Hello string result: ", (int)src29[0]);*/

    printf("\n\n%s", "FT_STRMAP ouput\n");
    char *src31 = "Hello";
    printf("%s%s\n", "Original string is ", src31);
    printf("%s%s", "Returned string is ", ft_strmap(src31, &test_strmap));

    printf("\n\n%s", "FT_STRMAPI ouput\n");
    char *src32 = "Hello";
    printf("%s%s\n", "Original string is ", src32);
    printf("%s%s", "Returned string is ", ft_strmapi(src32, &test_strmapi));

    printf("%s", "\n\nFT_PUTNBR output\n");
    printf("%s\n", "Ouput of 1 is ");
    ft_putnbr(1);
    printf("\n%s\n", "Ouput of 0 is ");
    ft_putnbr(0);
    printf("\n%s\n", "Ouput of 9 is ");
    ft_putnbr(9);
    printf("\n%s\n", "Output of 12345 is ");
    ft_putnbr(12345);
    printf("%s\n", "Ouput of -1 is ");
    ft_putnbr(-1);
    printf("\n%s\n", "Output of -12345 is ");
    ft_putnbr(-12345);
    printf("\n%s\n", "Output of 2147483647 is ");
    ft_putnbr(2147483647);
    printf("\n%s\n", "Output of -2147483648 is ");
    ft_putnbr(-2147483648);

    printf("\n\n%s", "FT_STREQU FUNCTION\n");
    printf("%s%d\n", "If the same empty strings result is ", ft_strequ("", ""));
    printf("%s%d\n", "If the same empty strings result is ", ft_strequ("hello", "hello"));
    printf("%s%d\n", "Different length ", ft_strequ("h", "h "));
    printf("%s%d\n\n", "Different symbols ", ft_strequ("hello", "hellc"));
    
    printf("%s", "FT_STRNEQU FUNCTION\n");
    printf("%s%d\n", "If the same empty strings result is ", ft_strnequ("", "", 2));
    printf("%s%d\n", "If the same strings result is ", ft_strnequ("hello", "hello", 3));
    printf("%s%d\n", "Different length ", ft_strnequ("h", "h ", 3));
    printf("%s%d\n\n", "Different symbols ", ft_strnequ("hello", "hellc", 6));

    printf("%s", "FT_STRSUB FUNCTION\n");
    char const *src51 = "someHellosome";
    printf("%s%s\n", "Original string is ", src51);
    printf("%s%s\n", "Substring from index 4 and 5 symbols is: ", ft_strsub(src51, 4, 5));
    printf("%s%s\n", "Substring from index 10 and 5 symbols is: ", ft_strsub(src51, 10, 5));
    printf("%s%s\n", "Substring from index 4 and 10 symbols is: ", ft_strsub(src51, 4, 10));
    printf("%s%s\n", "Substring from index 4 and 0 symbols is: ", ft_strsub(src51, 4, 0));

    printf("%s", "\nFT_STRJOIN FUNCTION\n");
    char const *src52 = "Hello, ";
    char const *src53 = "World!";
    printf("%s%s\n", "Should be Hello, World! string: ", ft_strjoin(src52, src53));
    printf("%s%s\n", "Should be Hello, World! string: ", ft_strjoin("", src53));
    printf("%s%s\n", "Should be Hello, World! string: ", ft_strjoin(src52, ""));
    
    printf("%s", "\nFT_STRTRIM FUNCTION\n");
    char const *src54 = "Hello";
    char const *src55 = " \n\tHello\t\t \n     ";
    printf("%s%s\n", "Result of Hello string without whitespaces: ", ft_strtrim(src54));
    printf("%s%s\n", "Result of Hello string with whitespaces at the start and and: ", ft_strtrim(src55));
    printf("%s%d\n\n", "Result of Hello string with whitespaces at the start and and: ", (int)*ft_strtrim(""));

   	/*printf("%s", "\n\nFT_MEMDEL FUNCTION\n");
    char *src37;
    src37 = malloc(sizeof(char) * 10);
    src37 = "Hello";
    printf("%s%s", "Original string is ", src37);
    ft_memdel((void **)&src37);
    printf("%s%s", "String after free calling is ", src37);*/

    /*printf("%s", "\n\nFT_STRDEL FUNCTION\n");
    char *src38;
    src38 = malloc(sizeof(char) * 10);
    src38 = "Hello";
    printf("%s%s", "Original string is ", src38);
    ft_strdel(&src38);
    printf("%s%d", "String after free calling is ", (int)src38);*/

    printf("%s", "FT_STRSPLIT FUNCTION\n");
    int i_spl = 0;
    char const *src39 = "*hello*fellow***students*";
    printf("%s%s\n", "Original string is: ", src39);
    char **dest39 = ft_strsplit(src39, '*');
    while (dest39[i_spl] != NULL)
    {
        printf("%s%d%s\n", "Element of aray with index ", i_spl, dest39[i_spl]);
        i_spl++;
    }
    int i_spl1 = 0;
    char const *src40 = "*hello*";
    printf("%s%s\n", "Original string is: ", src40);
    char **dest40 = ft_strsplit(src40, '*');
    while (dest40[i_spl1] != NULL)
    {
        printf("%s%d%s\n", "Element of aray with index ", i_spl1, dest40[i_spl1]);
        i_spl1++;
    }
    int i_spl2 = 0;
    int i = 0;
    char const *src41 = "       olol";
    printf("%s%s\n", "Original string is: ", src41);
    char **dest41 = ft_strsplit(src41, ' ');
    while (dest41[i_spl2] != NULL)
    {
        printf("%s%d%s\n", "Element of aray with index ", i_spl2, dest41[i_spl2]);
        i_spl2++;
    }
    while (dest41[0][i] != 0)
        i++;
    printf("%d", i);
    
    printf("%s", "\n\nFT_ITOA FUNCTION\n");
    printf("%s%d\n", "Original number is ", 0);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(0));
    printf("%s%d\n", "Original number is ", 5);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(5));
    printf("%s%d\n", "Original number is ", 123);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(123));
    printf("%s%d\n", "Original number is ", 356146876);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(356146876));
    printf("%s%d\n", "Original number is ", -5);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(-5));
    printf("%s%d\n", "Original number is ", -123);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(-123));
    printf("%s%d\n", "Original number is ", -356146876);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(-356146876));
    printf("%s%d\n", "Original number is ", 2147483647);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(2147483647));
    printf("%s%ld\n", "Original number is ", -2147483648);
    printf("%s%s\n", "Result of itoa is ", ft_itoa(-2147483648));

    printf("%s", "\n\nBONUS PART\n");

    printf("%s", "\nFT_LSTNEW FUNCTION\n");
    t_list *tmp1;
    tmp1 = ft_lstnew("Hello", 10);
    while (tmp1)
    {
        printf("%s\n", (char *)tmp1->content);
        printf("%d\n", (int)tmp1->content_size);
        printf("%s\n\n", (char *)tmp1->next);
        tmp1 = tmp1->next;
    }
    
    printf("%s", "\nFT_LSTADD FUNCTION\n");
    t_list *tmp2;
    tmp2 = NULL;
    tmp2 = test_lstnew(tmp2, "Hello", 10);
    tmp2 = test_lstnew(tmp2, "my", 8);
    tmp2 = test_lstnew(tmp2, "world", 7);
    t_list *tmp3;
    tmp3 = NULL;
    tmp3 = test_lstnew(tmp3, "test", 7);
    ft_lstadd(&tmp2, tmp3);
    while (tmp3)
    {
        printf("%s\n", (char *)tmp3->content);
        printf("%d\n", (int)tmp3->content_size);
        printf("%s\n\n", (char *)tmp3->next);
        tmp3 = tmp3->next;
    }

    printf("%s", "\nFT_LSTITER FUNCTION\n");
    t_list *tmp5;
    tmp5 = NULL;
    tmp5 = test_lstnew(tmp5, "Hello", 10);
    tmp5 = test_lstnew(tmp5, "my", 8);
    tmp5 = test_lstnew(tmp5, "world", 7);
    ft_lstiter(tmp5, &test_lstiter);
    while (tmp5)
    {
        printf("%s\n", (char *)tmp5->content);
        tmp5 = tmp5->next;
    }

    /*printf("%s", "\nFT_LSTDELONE FUNCTION\n");
    t_list *tmp7;
    tmp7 = test_lstnew(tmp7, "Hello", 10);
    printf("%s\n", (char *)tmp7->content);
    printf("%d\n", (int)tmp7->content_size);
    printf("%s\n\n", (char *)tmp7->next);
    ft_lstdelone(&tmp7, del);*/

    /*printf("%s", "\nFT_LSTMAP FUNCTION\n");
    t_list *tmp7;
    tmp7 = ft_lstmap(tmp3, &test_lstmap);
    while (tmp7)
    {
        printf("%s\n", (char *)tmp7->content);
        printf("%d\n", (int)tmp7->content_size);
        printf("%s\n\n", (char *)tmp7->next);
        tmp7 = tmp7->next;
    }*/
}
