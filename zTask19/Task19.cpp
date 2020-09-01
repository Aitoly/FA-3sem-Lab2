#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>


int* array_copy(int arr_size, int& res_size, const int* arr)
{
    int* res = (int*)malloc(sizeof(int));
    if (res == NULL)
    {
        return NULL;
    }

    res_size = 1;
    int i_in_res = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (i == 0)
        {
            res[i_in_res] = *arr;
            ++i_in_res;
        }
        else
        {
            int j;
            for (j = 0; j < res_size; ++j)
            {
                if (*arr == res[j])
                    break;
            }

            if (j == res_size)
            {
                ++res_size;
                res = (int*)realloc(res, res_size * sizeof(int));
                res[i_in_res] = *arr;
                ++i_in_res;
            }

            ++arr;
        }
    }

    return res;
}

int main()
{
    int res_size = 0;

    int arr[8] = { 1, 2, 3, 4, 5, 5, 6, 6 };
    int* ptr = array_copy(8, res_size, arr);

    for (int i = 0; i < res_size; ++i)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}
