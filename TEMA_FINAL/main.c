#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "competition.h"

int n;

static inline char *get_string(char sep, FILE *f)
{
    char ch = 0;

    char *s = calloc(16, sizeof(char));
    int size = 0, capacity = 16;

    for (;;)
    {
        fscanf(f, "%c", &ch);
        if (ch == sep)
            break;

        if ((++size) > capacity)
            capacity <<= 1, s = realloc(s, capacity * sizeof(char));

        s[(size - 1)] = ch;
    }

    if ((++size) > capacity)
        capacity <<= 1, s = realloc(s, capacity * sizeof(char));

    for (int x = (size - 1); x < capacity; ++x)
        s[x] = 0;

    return s;
}

static inline bool IsPowerOfTwo (int X)
{
    return ((X & (X - 1)) == 0);
}

int main(int argc, char *argv[])
{
    FILE *c_file = fopen(argv[1], "r");
    FILE *d_file = fopen(argv[2], "r");
    FILE *e_file = fopen(argv[3], "w");

    int task_1 = 0, task_2 = 0, task_3 = 0, task_4 = 0, task_5 = 0;
    fscanf(c_file, "%d", &task_1);
    fscanf(c_file, "%d", &task_2);
    fscanf(c_file, "%d", &task_3);
    fscanf(c_file, "%d", &task_4);
    fscanf(c_file, "%d", &task_5);

    fscanf(d_file, "%d", &n);

    competition *comp = competition_create();
    comp->n = n;

    for (int i = 1; i <= n; ++i)
    {
        team *t = team_create();
        t->next = comp->first, comp->first = t;

        fscanf(d_file, "%d", &(t->n));

        char ch = 0;
        fscanf(d_file, "%c", &ch);

        t->name = get_string('\n', d_file);

        for (int j = 1; j <= (t->n); ++j)
        {
            node *now = calloc(1, sizeof(node));
            now->next = t->first, t->first = now;

            now->X.firstName = get_string(' ', d_file), now->X.secondName = get_string(' ', d_file);
            fscanf(d_file, "%d", &(now->X.points));

            t->sum += (now->X.points);
        }

        t->avg = (long double)t->sum / (long double)t->n;

        fscanf(d_file, "%c", &ch);
    }

    if (task_2)
    {
        while(!IsPowerOfTwo(comp->n))
            Remove_Min(comp);
    }

    if (task_1)
    {
        team *i = comp->first;

        for (; i; i = i->next)
            fprintf(e_file, "%s\n", i->name);
    }

    competition_destroy(comp);

    fclose(c_file), fclose(d_file), fclose(e_file);

    return 0;
}
