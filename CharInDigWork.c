#include <stdio.h> 
#include <stdlib.h> 
double powmy(double digtopow, int degree)
{
    double power = digtopow;
    if (degree!=0){
        for (double i = 1; i < degree; i++)
        {
            digtopow = digtopow * power;
        }
        return digtopow;
    }
    else
    {
        return 1;
    }

}

int main()
{
    int size = 1000;
    char* inptstr = (char*)malloc(sizeof(char) * size);
    char smbl = ' ';
    int strln = 0, posstr = 0;
    while (((smbl = getchar()) != '.') and (smbl != ','))
    {
        inptstr[strln] = smbl;
        strln++;
        posstr++;
    }
    inptstr[strln++] = '.';
    int negstr = 0;
    while ((smbl = getchar()) != '\n')
    {
        inptstr[strln] = smbl;
        strln++;
        negstr++;
    }
    double num = 0.0;
    int digit = 0;
    for (int i = strln-1; i > posstr; i--)
    {
        digit = (int)inptstr[i] - 48;
        num = num + digit * (1 / powmy(4, negstr));
        negstr -= 1;
        printf("%f \n", num);
    }
    int posdeg = 0;
    for (int i = posstr-1; i >= 0; i--)
    {
        digit = (int)inptstr[i] - 48;
        num = num + digit * powmy(4, posdeg);
        posdeg++;
        printf("%f \n", num);
    }

    printf(" % d \t % d \t % f", posstr, negstr, num);
    return 0;
}