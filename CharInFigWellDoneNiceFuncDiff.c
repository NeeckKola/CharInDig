#include <stdio.h> 
#include <stdlib.h> 
double powmy(double digtopow, int degree)
{
    double power = digtopow;
    if (degree != 0) {
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
void addstrln(int* strln) {
    (*strln)++;
}
void finddotpose(int* dotpos) {
    (*dotpos)++;
}
void dotincomm(char* mass, int* dotpos) { // Превращает запятую в точку, добавляет длину строке
    mass[*dotpos] = '.';
    finddotpose(dotpos);
}
void checkisincorrectsystem(char* smbl, int* flag) {
    if ((*smbl) - 48 >= 4) {
        (*flag)++;
    }
}
void fillmassive(int* strln, char* smbl, char* mass) {
    mass[*strln] = *smbl;
}
void intpartborder(char* smbl, int* flag, char* mass, int* strln, int* dotpos) { //узнает длину целой части числа, изменяет длину строки, находит местоположение точки
    checkisincorrectsystem(smbl, flag);
    fillmassive(strln, smbl, mass);
    addstrln(strln);
    finddotpose(dotpos);
}
void floatpartborder(char* smbl, int* flag, char* mass, int* strln) {
    checkisincorrectsystem(smbl, flag);
    fillmassive(strln, smbl, mass);;
    addstrln(strln);
}
void transintnotation(int* strln, int* dotpos, char* inptstr, double* num) {
    int digit = 0;
    int negdeg = (*strln) - (*dotpos) - 1;
    for (int i = (*strln) - 1; i > (*dotpos); i--)
    {
        digit = (int)inptstr[i] - 48;
        (*num) = (*num) + digit * (1 / powmy(4, negdeg));
        negdeg -= 1;
    }
}
void transfloatnotation(int* dotpos, char* inptstr, double* num) {
    int posdeg = 0;
    int digit = 0;
    for (int i = *dotpos - 1; i >= 0; i--)
    {
        digit = (int)inptstr[i] - 48;
        (*num) = (*num) + digit * powmy(4, posdeg);
        posdeg++;
    }
}
int main()
{
    printf("Please enter a number in the quaternary system\n");
    int size = 1000;
    char* inptstr = (char*)malloc(sizeof(char) * size);
    char smbl = ' ';
    int strln = 0, dotpos = 0;
    int flag = 0;
    while (((smbl = getchar()) != '.') and (smbl != ','))
    {
        intpartborder(&smbl, &flag, inptstr, &strln, &dotpos);
    }
    dotincomm(inptstr, &strln);
    while ((smbl = getchar()) != '\n')
    {
        floatpartborder(&smbl, &flag, inptstr, &strln);
    }
    double num = 0.0;
    int digit = 0;
    if (flag == 0)
    {
        transintnotation(&strln, &dotpos, inptstr, &num);
        transfloatnotation(&dotpos, inptstr, &num);
        printf("%f", num);
    }
    else
    {
        printf("There is no such number in the quaternary number system!");
    }
    return 0;
}
