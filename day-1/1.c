#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common.h"

const char path[] = "day-1/input.txt";

const int starting_number = 50;
const int dial_max = 100;

const int show_dialing = 0;

int main()
{
    FILE *fptr;

    fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        printf("Unable to read file.\n");
        return 0;
    }

    char buff[10];

    int pointing_number = starting_number;
    int times_hit_zero = 0;

    while (fgets(buff, sizeof(buff), fptr) != NULL)
    {
        int dir;
        switch (buff[0])
        {
        case 'L':
            dir = -1;
            break;
        case 'R':
            dir = 1;
        default:
            break;
        }

        // I don't know what I'm doing.
        size_t len = strlen(buff);
        char num_str[len + 1];
        size_t j = 0;
        for (size_t i = 1; i <= sizeof(buff); ++i)
        {
            num_str[j++] = buff[i];
        }

        // Parsed number
        int num = atoi(num_str);

        if (show_dialing == 1)
        {
            printf("Dial: %d -> turn %d -> ", pointing_number, num * dir);
        }

        pointing_number = (((pointing_number + num * dir) % dial_max) + dial_max) % dial_max;

        if (show_dialing == 1)
        {
            printf("%d\n", pointing_number);
        }
        if (pointing_number == 0)
        {
            times_hit_zero++;
        }
    }
    fclose(fptr);

    if(show_dialing == 1) {
        printf("---\n");
    }

    printf("Times hit zero: %d", times_hit_zero);

    printf("\n");
    return 0;
}