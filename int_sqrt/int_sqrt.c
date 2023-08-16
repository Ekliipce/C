int int_sqrt(int n)
{
    if (n < 0)
        return -1;

    int root = 1;
    int i = 1;

    while (root <= n)
    {
        i++;
        root = i * i;
    }

    return i - 1;
}
