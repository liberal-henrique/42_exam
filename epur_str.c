// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.

// Example:

// $> ./epur_str "See? It's easy to print the same thing" | cat -e
// See? It's easy to print the same thing$
// $> ./epur_str " this        time it      will     be    more complex  . " | cat -e
// this time it will be more complex .$
// $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>
//"   abc    def   "

#include <unistd.h>
int main(int argc, char *argv[])
{
    int i;
    int flag;
    char    c;

    i = 0;
    flag = 0;
    if (argc != 2)
    {
        write(1, "Too much arguments", 18);
        return (0);
    }
    else
    {
        while (argv[1][i])
        {
            while ((argv[1][i] == 32 || argv[1][i] >= 9 && argv[1][i] <= 13))
            {    
                i++;
                flag = 1;
            }
            if (flag == 1)
            {
                c = 32;
                write(1, &c, 1);
                flag = 0;
            }
            if (argv[1][i])
            {
                c = argv[1][i];
                write(1, &c, 1);  
                i++;
            }
        }
        c = 10;
        write(1, &c, 1);
    }
    return (0);
}
