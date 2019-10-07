#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM 10000

int urand();
void getNums(int* nums);
int compar(const void *a, const void *b);
void bubble(int* nums, int len);

int main(char* args[])
{
    struct timeval tv1, tv2, tv3, tv4;
    struct timezone tz;
    int i;
    int nums[NUM];
    int nums2[NUM];
    getNums(nums);
    for (i = 0; i < NUM; ++i)
    {
        nums2[i]=nums[i];
    }

    printf("nums: %d\n", NUM);
    gettimeofday(&tv1, &tz);
    qsort(nums, NUM, sizeof(int), compar);
    gettimeofday(&tv2, &tz);
    printf("qsort: %ldus\n", (tv2.tv_usec-tv1.tv_usec));

    gettimeofday(&tv3, &tz);
    bubble(nums2, NUM);
    gettimeofday(&tv4, &tz);
    printf("bubble: %ldus\n", (tv4.tv_usec-tv3.tv_usec));
    return 0;
}

int urand()
{
    srand((int)time(0)+rand());
    return rand() % 101 + 1;
}

void getNums(int* nums)
{
    int i;
    int r;
    for (i = 0; i < NUM; ++i)
    {
        nums[i] = urand();
    }
}

int compar(const void *a, const void *b)
{
    int *aa = (int * ) a, *bb = (int * ) b;
    if(*aa>*bb)return 1;
    if(*aa==*bb)return 0;
    if(*aa<*bb)return -1;
}

void bubble(int* nums, int len)
{
    int i, j, temp;
    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < len-i-1; ++j)
        {
            if (nums[j]>nums[j+1])
            {
                temp=nums[j+1];
                nums[j+1]=nums[j];
                nums[j]=temp;
            }
        }
    }
}