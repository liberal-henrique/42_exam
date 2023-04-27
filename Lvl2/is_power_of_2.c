int     is_power_of_2(unsigned int n)
{
    unsigned int num = 1;
    int number;

    number = (int) n;
    if (number < 0)
        return (0);
    while (num <= n)
    {
        if (num == n)
            return (1);
        num = num * 2;
    }
    return (0);
}
