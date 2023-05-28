#include <stdio.h>

// Structure to represent an item
struct Item
{
    int weight;
    int value;
};

// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using branch and bound
int knapsackBranchAndBound(int capacity, struct Item items[], int n)
{
    // Sort items based on value per unit weight (value/weight) in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double valuePerUnitWeight1 = (double)items[j].value / items[j].weight;
            double valuePerUnitWeight2 = (double)items[j + 1].value / items[j + 1].weight;
            if (valuePerUnitWeight1 < valuePerUnitWeight2)
            {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Initialize variables
    int currentWeight = 0;
    int currentValue = 0;
    int bestValue = 0;
    int include[n];
    int bestInclude[n];

    // Function to calculate the upper bound (best possible value) of a node
    double calculateUpperBound(int level, int weight, int value)
    {
        double upperBound = value;
        int remainingWeight = capacity - weight;
        int i = level;
        while (i < n && items[i].weight <= remainingWeight)
        {
            remainingWeight -= items[i].weight;
            upperBound += items[i].value;
            i++;
        }
        if (i < n)
            upperBound += (double)remainingWeight * items[i].value / items[i].weight;
        return upperBound;
    }

    // Recursive function to perform branch and bound
    void branchAndBound(int level, int weight, int value)
    {
        if (weight <= capacity && value > bestValue)
        {
            bestValue = value;
            for (int i = 0; i < level; i++)
                bestInclude[i] = include[i];
        }

        if (calculateUpperBound(level, weight, value) <= bestValue)
            return;

        if (level >= n)
            return;

        include[level] = 1;
        branchAndBound(level + 1, weight + items[level].weight, value + items[level].value);
        include[level] = 0;
        branchAndBound(level + 1, weight, value);
    }

    // Start branch and bound
    branchAndBound(0, 0, 0);

    // Print the items included in the knapsack
    printf("Items included in the knapsack:\n");
    for (int i = 0; i < n; i++)
    {
        if (bestInclude[i] == 1)
            printf("Item %d (Weight: %d, Value: %d)\n", i + 1, items[i].weight, items[i].value);
    }

    // Return the best value
    return bestValue;
}

int main()
{
    // Example usage
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    int numItems = sizeof(items) / sizeof(items[0]);

    int maxValue = knapsackBranchAndBound(capacity, items, numItems);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}