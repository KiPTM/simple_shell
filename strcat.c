#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: the first string
 * @src: the second string
 *
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
    int dest_len = 0, i = 0;

    /* Calculate the length of the destination string */
    while (dest[dest_len] != '\0')
    {
        dest_len++;
    }

    /* Append the source string to the destination string */
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    /* Add null terminator to mark the end of the concatenated string */
    dest[dest_len + i] = '\0';

    return dest;
}
