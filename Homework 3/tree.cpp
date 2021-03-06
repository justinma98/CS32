int countIncludes(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 < 1)
        return 1;
    if (n1 < 1)
        return 0;
    int count = 0;
    if (n1 >= n2)
    {
        if (a1[0] == a2[0])
            count += (countIncludes(a1+1, n1-1, a2, n2) + countIncludes(a1+1, n1-1, a2+1, n2-1));
        else
            count += countIncludes(a1+1, n1-1, a2, n2);
    }
    return count;
        
}

void exchange(string& x, string& y)
{
    string t = x;
    x = y;
    y = t;
}

void separate(string a[], int n, string separator,
              int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > separator)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < separator)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

void order(string a[], int n)
{
    if (n <= 1) return;
    int first;
    int second;
    separate(a, n, a[n-1], first, second);
    if (second == n)
        order(a,n-1);
    else
        order(a, n);
}
