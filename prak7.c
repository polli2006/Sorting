#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* n=число элементов для сортировки*/
#define n 10000
extern unsigned long long timestamp(void);
extern int cmp1(double a, double b);
extern void change (double *a, double *b);
extern int cm, sw;
/*сортировка пузырьком*/
void bubblesort ( double * a )
{
    int i, j,k;
    for(j = 1; j < n; ++j)
        for(i = n - 1; i >= j; --i)
        {
           
            if ((k=cmp1((a[i - 1]), (a[i]))))
            {
                    change(&(a[i - 1]), &(a[i]));
                   

            }
        }
}
/*Быстрая сортировка*/
void quicksort(double* a, int first, int last)
{
    int i = first, j = last;
    double x = a[(last+first) / 2];

    while (i<j) {
        while (cmp1(x,a[i])) {i++; }
        while (cmp1(a[j],x)) {j--; }

        if(i <= j) {
            change(&a[i], &a[j]);
       
            i++;
            j--;
        }
    }
    if (i < last)
        quicksort(a, i, last);
    if (first < j)
        quicksort(a, first,j);
}
/*Рандомное заполение элементов массива*/
void randomize(double *a)
{
    int i;
    for (i=0; i<n; i++)
    {
        a[i] = rand()*rand()*rand()*rand()*rand();
        double c=rand();
        if (c) a[i]=a[i]/((double)c);
    }
}
int main(void)
{
    int i;
    double *a = (double *) malloc(n * sizeof(double));
    double *b = (double *) malloc(n * sizeof(double));
    srand(time(NULL));
    randomize(a);
    for (i = 0; i < n; ++i)
        b[i] = a[i];
    unsigned long long tq0 = timestamp();

	cm=0;
	sw=0;
    quicksort(a, 0, n - 1);
    unsigned long long tq1 = timestamp();

    unsigned long long timeq = tq1 - tq0;
    printf("QUICKSORT\n\nn=%d\n\ncmp=%d swp=%d\ntime=%llu\n\n",n,  cm, sw, timeq);

    unsigned long long tb0 = timestamp();

	cm=0;
	sw=0;
    bubblesort(b); 
    unsigned long long tb1 = timestamp();

    unsigned long long timeb = tb1 - tb0;
    printf("BUBBLESORT\n\nn=%d\ncmp=%d swp=%d\ntime=%llu\n",n, cm, sw, timeb);
    
    /*Вывод отсортированных массивов, для проверки*/   

   /* for (i=0;i<n;++i)
        printf("%lf ",a[i]);
    printf("\n");

    for (i=0;i<n;++i)
       printf("%lf ",b[i]); */
    free(a);
    free(b);
    return 0;
}
