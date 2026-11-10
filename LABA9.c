#include <stdio.h>
#include <locale.h>

#define ROW 9
#define COL 9

//Задание 1
void task1_full(void)
{
    for (int row = 1; row <= ROW; ++row)
    {
        for (int col = 1; col <= COL; ++col)
            printf("%5d", col * row);
        printf("\n");
    }
}

void task1_triangle(void)
{
    for (int row = 1; row <= ROW; ++row)
    {
        for (int col = 1; col <= row; ++col)  
            printf("%5d", col * row);
        printf("\n");
    }
}

void task1_variant11(void)
{
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d", 6 + i);
        for (int j = 5 - i; j >= 2; j--)
            printf(" %d", j);
        printf("\n");
    }
}

//Задание 2

void task2_digits(void)
{
    long long num;
    int digits[20];
    int n, sum1, sum2, half;

    printf("\nВведите целое число: ");
    scanf("%lld", &num);

    if (num < 0)
        num = -num;           

    n = 0;
    if (num == 0)
        digits[n++] = 0;       

    long long tmp = num;
    while (tmp > 0)
    {
        digits[n++] = tmp % 10;
        tmp /= 10;
    }

    half = n / 2;
    sum1 = 0;
    sum2 = 0;

    for (int i = 0; i < half; i++)
        sum1 += digits[n - 1 - i];  
    for (int i = 0; i < half; i++)
        sum2 += digits[i];           

    printf("Сумма первой половины цифр:  %d\n", sum1);
    printf("Сумма второй половины цифр:  %d\n", sum2);

    if (sum1 == sum2)
        printf("Суммы половин цифр РАВНЫ\n");
    else
        printf("Суммы половин цифр НЕ равны\n");
}

//Задание 3
void task3_trapezoid(void)
{
    int b, h, c;
    char sym;

    printf("Фигура: равнобедренная трапеция (только контур)\n");

    printf("Введите символ для рисования: ");
    scanf(" %c", &sym);

    do {
        printf("Введите ширину верхнего основания b (>=2): ");
        scanf("%d", &b);
    } while (b < 2);

    do {
        printf("Введите высоту h (>=2): ");
        scanf("%d", &h);
    } while (h < 2);

    do {
        printf("Введите ширину нижнего основания c (>= %d): ", b);
        scanf("%d", &c);
    } while (c < b);

    printf("\n");

    for (int i = 0; i < h; i++)
    {
        int width = b + (c - b) * i / (h - 1);
        int left = (c - width) / 2;            

        for (int j = 0; j < left; j++)
            putchar(' ');

        if (i == 0 || i == h - 1)
        {
            for (int j = 0; j < width; j++)
                putchar(sym);
        }
        else
        {
            putchar(sym);
            for (int j = 0; j < width - 2; j++)
                putchar(' ');
            putchar(sym);
        }
        printf("\n");
    }
}

//МЕНЮ

int main(void)
{
    int choice;

    setlocale(LC_ALL, "ru_RU.UTF-8");

    do
    {
        printf("\n МЕНЮ\n");
        printf("1 - таблица Пифагора (задание 1.1)\n");
        printf("2 - левый нижний треугольник (задание 1.2)\n");
        printf("3 - печать чисел, вариант 11 (задание 1.3)\n");
        printf("4 - суммы половин цифр числа (задание 2, вариант 11)\n");
        printf("5 - равнобедренная трапеция (задание 3, вариант 11)\n");
        printf("0 - выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 1)
            task1_full();
        else if (choice == 2)
            task1_triangle();
        else if (choice == 3)
            task1_variant11();
        else if (choice == 4)
            task2_digits();
        else if (choice == 5)
            task3_trapezoid();

    } while (choice != 0);

    printf("Программа завершена.\n");
    return 0;
}
