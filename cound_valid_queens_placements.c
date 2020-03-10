/*
** EPITECH PROJECT, 2019
** count_valid_queens_placements
** File description:
** count valid queens placements
*/

#include <stdio.h>
#include <stdlib.h>

int check_pos_queen(char *str, int line, int size)
{
    int pos = line * size;

    for (; str[pos] != 'Q'; pos++);
    printf("pos = %d\n", pos);
    for (int i = 1; pos - (i * (size + 1)) >= 0 && pos != 0
            && str[pos - (i * (size + 1))] != 'B' && (pos + 1) % size != 0; i++)
        if (str[pos - (i * (size + 1))] == 'Q') {
            printf("test1\n");
            return (0);
        }
    for (int i = 1; pos - (i * (size - 1)) >= 0 && pos != 0
             && str[pos - (i * (size + 1))] != 'B' && pos % size != 0; i++)
        if (str[pos - (i * (size - 1))] == 'Q') {
            printf("test2\n");
            return (0);
        }
    for (int i = 1; pos - (i * size) >= 0; i++)
        if (str[pos - (i * size)] == 'Q') {
            printf("test3\n");
            return (0);
        }
    if (line + 1 == size)
        return (2);
    return (1);
}

char *my_add_queen(char *str, int *line, int size, int *check)
{
    int place = 0;
    int i = *line * size;

    for (; i < (*line + 1) * size && str[i] != 'Q'; i++);
    if (str[i] == 'Q' && i == (*line + 1) * size - 1) {
        str[i] = 'B';
        *check = -1;
        return (str);
    }
    if (str[i] == 'Q' && i != (*line + 1) * size - 1) {
        if (i % size == 0)
            str[i] = 'B';
        if (i % size != 0)
            str[i] = 'A';
        str[i + 1] = 'Q';
    }
    if (str[i] != 'Q' && i == (*line + 1) * size) {
        str[*line * size] = 'Q';
    }
    *check = 0;
    return (str);
}

int my_inter(char *str, int line, int size, int count)
{
    int clear = 0;
    int check = 0;

    for (; line != -1; ) {
        str = my_add_queen(str, &line, size, &check);
        printf("line = %d\n", line);
        printf("%s\n", str);
        if (line == -1)
            break;
        if (check == 0)
            clear = check_pos_queen(str, line, size);
        printf("clear = %d\n", clear);
        if (check == -1)
            line--;
        if (clear == 2)
            count++;
        if (clear == 1)
            line++;
        check = 0;
        clear = 0;
    }
    return (count);
}

int count_valid_queens_placements(int n)
{
    int size = n * n;
    int count = 0;
    char str[size];

    for (int i = 0; i < size; i++) {
        if (i % n == 0 || (i + 1) % n == 0)
            str[i] = 'B';
        else
            str[i] = 'A';
    }
    str[size] = '\0';
    count = my_inter(str, 0, n, count);
    printf("count = %d\n", count);
    return (count);
}

int main(int ac, char **av)
{
    count_valid_queens_placements(atoi(av[1]));
    return (0);
}
