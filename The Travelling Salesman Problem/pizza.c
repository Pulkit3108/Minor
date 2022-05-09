#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define min 9999
int number_of_cities, cost = 0, count = 0;
static int visited[15];

int **input_matrix;
char **arr;
/* This input() function will take the distance matrix as input via the user, for doing so it is taking the number of nodes that our salesman needs to visit. */
int **input()
{
    printf("\n*********************************************************************************************************\n");
    printf("-----------------------------------PIZZA DELIVERY OPTIMAL PATH FINDER------------------------------------\n");
    printf("*********************************************************************************************************\n");
    printf("\nEnter The Number OF Locations : ");
    scanf("%d", &number_of_cities);

    // Dynamic allocation is used to take the input.
    input_matrix = (int **)malloc(number_of_cities * sizeof(int *));
    arr = (char **)malloc(number_of_cities * sizeof(char *));
    for (int i = 0; i < number_of_cities; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
    }
    printf("Enter The Name of The Locations : ");
    for (int i = 0; i < number_of_cities; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int k = 0; k < number_of_cities; k++)
    {
        input_matrix[k] = (int *)malloc(number_of_cities * sizeof(int));
    }

    for (int i = 0; i < number_of_cities; i++)
    {
        for (int j = 0; j < number_of_cities; j++)
        {
            if (i == j)
            {
                *(*(input_matrix + i) + j) = 0;
            }
            else
            {
                printf("Enter The Distance Between Location %s and %s : ", arr[i], arr[j]);
                scanf("%d", &*(*(input_matrix + i) + j));
            }
        }
    }
    return input_matrix;
}
// next_min() function gets the next node selected and sends it to the mincost() function.
int next_min(int city)
{
    int min_cost = min;
    int next_city = 0;
    for (int i = 0; i < number_of_cities; i++)
    {
        if ((input_matrix[i][city] != 0) && (visited[i] != 1))
        {
            if (input_matrix[city][i] < min_cost)
            {
                //+ input_matrix[i][0];
                min_cost = input_matrix[city][i];
                next_city = i;
            }
        }
    }
    return next_city;
}
/* This is the significant part of the code, as you can see recursion is used here, the mincost() function takes the help of next_min() function to calculate the path. */
void mincost(int root_city)
{
    int next_city = 0;
    visited[root_city] = 1;
    printf("%s ---> ", arr[root_city]);
    next_city = next_min(root_city);
    if (next_city < number_of_cities && count < number_of_cities - 1)
    {
        count += 1;
        mincost(next_city);
    }
}
/* Driver code, the main() function calls input() function and all the other major functions. */
int main()
{
    int c;
    int **input_matrix1;
    int root;
    printf("\nEnter 0 To Perform Input/Output Manually\n");
    printf("Enter 1 To Perform Input/Output Using File Handling\n");
    printf("Enter Your Choice : ");
    scanf("%d", &c);
    if (c == 1)
    {
        char finame[20];
        char foname[20];
        printf("Enter The Name Of The Input File : ");
        scanf("%s", finame);
        printf("Enter The Name Of The Output File : ");
        scanf("%s", foname);
        FILE *f;
        f = freopen(finame, "r", stdin);
        f = freopen(foname, "w+", stdout);
        input_matrix1 = input();
        printf("\n\n\nDistance Matrix :\n\n");
        for (int i = 0; i < number_of_cities; i++)
        {
            printf("[ ");
            for (int j = 0; j < number_of_cities; j++)
            {
                printf("%d", input_matrix1[i][j]);
                if (j == number_of_cities - 1)
                {
                    printf(" ]");
                    printf("\n");
                    continue;
                }
                printf("\t");
            }
        }

        while (1)
        {
            for (int i = 0; i < number_of_cities; i++)
            {
                // The source will also be the end point.
                printf("\nPress %d TO Select Starting Location As : %s", (i), arr[i]);
            }
            printf("\n");
            scanf("\n%d", &root);
            // To check if the valid input is given.
            if (root > (number_of_cities - 1))
            {
                printf("You Have Entered The Wrong Choice!!\n");
                printf("Please Try Again!!\n");
                continue;
            }
            else
            {
                printf("\nThe Best Path For Pizza Delivery :\n");
                mincost(root);
                printf("%s\n", arr[root]);
                printf("\n");
                printf("*********************************************************************************************************\n");
                break;
            }
        }
        fclose(f);
    }
    else if (c == 0)
    {
        input_matrix1 = input();
        printf("\nDistance Matrix :\n\n");
        // input for the distance b/w any two nodes.
        for (int i = 0; i < number_of_cities; i++)
        {
            printf("[ ");
            for (int j = 0; j < number_of_cities; j++)
            {
                printf("%d", input_matrix1[i][j]);
                if (j == number_of_cities - 1)
                {
                    printf(" ]");
                    printf("\n");
                    continue;
                }
                printf("\t");
            }
        }

        while (1)
        {
            for (int i = 0; i < number_of_cities; i++)
            {
                printf("\nPress %d TO Select Starting Location As : %s", (i), arr[i]);
            }
            printf("\nEnter Your Choice : ");
            scanf("%d", &root);
            if (root > (number_of_cities - 1))
            {
                printf("You Have Entered The Wrong Choice!!\n");
                printf("Please Try Again!!\n");
                continue;
            }
            else
            {
                printf("\nThe Best Path For Pizza Delivery :\n");
                mincost(root);
                printf("%s\n", arr[root]);
                printf("\n");
                printf("*********************************************************************************************************\n\n");
                break;
            }
        }
    }
    return 0;
}
