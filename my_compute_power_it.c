/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** compute power
*/

int my_compute_power_it(int nb, int p)
{
    long check = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (int pow = nb; p > 1; p--) {
        nb = nb * pow;
        check = check * pow;
        if (check != nb)
            return (0);
    }
    return (nb);
}
