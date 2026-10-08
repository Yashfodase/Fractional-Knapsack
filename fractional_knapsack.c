#include <stdio.h>

struct Package
{
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};

struct Package p[20];
int n;
float capacity;

/* 1. Enter Package Details */
void enterDetails()
{
    printf("Enter number of packages: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    for(int i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter value: ");
        scanf("%f", &p[i].value);

        printf("Enter weight: ");
        scanf("%f", &p[i].weight);

        p[i].ratio = 0;
        p[i].fraction = 0;
    }
}

/* 2. Display Package Details */
void displayDetails()
{
    printf("\nPackage\tValue\tWeight\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\n",
               p[i].id,
               p[i].value,
               p[i].weight);
    }
}

/* 3. Calculate Value/Weight Ratio */
void calculateRatio()
{
    for(int i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nValue/Weight Ratios:\n");

    for(int i = 0; i < n; i++)
    {
        printf("Package %d = %.2f\n",
               p[i].id,
               p[i].ratio);
    }
}

/* 4. Sort Packages by Ratio */
void sortPackages()
{
    struct Package temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(p[i].ratio < p[j].ratio)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nPackages sorted by decreasing ratio.\n");

    for(int i = 0; i < n; i++)
    {
        printf("Package %d -> Ratio = %.2f\n",
               p[i].id,
               p[i].ratio);
    }
}

/* 5. Find Maximum Value */
void findMaximum()
{
    float remaining = capacity;
    float maxValue = 0;
    float totalWeight = 0;

    for(int i = 0; i < n; i++)
    {
        p[i].fraction = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(remaining == 0)
            break;

        /* Complete package */
        if(p[i].weight <= remaining)
        {
            p[i].fraction = 1;

            remaining = remaining - p[i].weight;

            totalWeight = totalWeight + p[i].weight;

            maxValue = maxValue + p[i].value;
        }

        /* Fraction of package */
        else
        {
            p[i].fraction = remaining / p[i].weight;

            maxValue = maxValue +
                       p[i].value * p[i].fraction;

            totalWeight = totalWeight + remaining;

            remaining = 0;
        }
    }

    printf("\nTotal Weight Used = %.2f", totalWeight);
    printf("\nMaximum Value = %.2f\n", maxValue);
}

/* 6. Display Selected Packages */
void displaySelected()
{
    printf("\nSelected Packages:\n");

    for(int i = 0; i < n; i++)
    {
        if(p[i].fraction > 0)
        {
            printf("Package %d -> %.2f%% selected\n",
                   p[i].id,
                   p[i].fraction * 100);
        }
    }
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n\n===== FRACTIONAL KNAPSACK =====\n");

        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximum();
                break;

            case 6:
                displaySelected();
                break;

            case 7:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}