/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** compute factorial rec
*/

int my_compute_factorial_rec(int nb)
{
    int total;

    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0)
        return (1);
    if (nb > 0)
        total = nb * my_compute_factorial_rec(nb - 1);
    return (total);
}
