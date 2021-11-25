extern char text[];

void foo()
{
    extern int i;   //makes the i declared in main.c external
    i = 100;
}

int number()
{
    return 3;
}