template <typename T>
T factorial (T nuber)
{  // check that not double
    if (nuber <= 1)
    {
        return 1;
    }
    return nuber * factorial (nuber - 1);
}
