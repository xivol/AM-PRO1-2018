
int shiftsdg_right(int *a, const size_t n)
{
    if (n == 1) 
        return *a;

    int an = shiftsdg_right(a + 1, n - 1);
    *(a + 1) = *a;
    *a = an;
    return an;    
}