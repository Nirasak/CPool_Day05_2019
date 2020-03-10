/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** compute factorial
*/

int my_compute_factorial_it(int nb)
{
    int total = 1;

    if (nb < 0 || nb > 12)
        return (0);
    for (; nb > 0; nb--)
        total = total * nb;
    return (total);
}
