int my_round(float n)
{
    int m = n;
    if (n > 0)
    {
        if (n - m >= 0.5)
            m = n + 1;
    }
    else
    {
        if (n - m <= -0.5)
            m = n - 1;
    }
    return m;
}
