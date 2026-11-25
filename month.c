
#include <stdio.h>

int main()
{
    int year, i, j, days, firstDay;

    int monthDays[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    char *months[] = {"January", "February", "March",
                      "April", "May", "June",
                      "July", "August", "September",
                      "October", "November", "December"};

    printf("Enter year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        monthDays[1] = 29;
    }

    int y = year - 1;

    firstDay = (365 * y + y / 4 - y / 100 + y / 400 + 1) % 7;

    for (i = 0; i < 12; i++)
    {
        printf("\n\n       %s %d\n", months[i], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        days = monthDays[i];

        for (j = 0; j < firstDay; j++)
        {
            printf("    ");
        }

        for (j = 1; j <= days; j++)
        {
            printf("%4d", j);

            if ((firstDay + j) % 7 == 0)
            {
                printf("\n");
            }
        }

        firstDay = (firstDay + days) % 7;
    }

    printf("\n");

    return 0;
}
