int a, b, c;
float values[5];

int func(int x, float rate)
{
    int t;
    t = 0;

    if (x == 1)
    {
        int a;
        a = 0;
        t = 1;
    }

    return t;
}

int main()
{
    int x;
    x = 2;
    func(x, 1.5);
    return 0;
}
