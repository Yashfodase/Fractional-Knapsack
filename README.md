# Smart Delivery Planning – Fractional Knapsack

## Project Description

This project implements the Fractional Knapsack problem using the Greedy Algorithm.

The program calculates the Value/Weight ratio of each package and sorts the packages in decreasing order of their ratio. It selects complete packages whenever possible and selects a fraction of a package when the complete package cannot fit in the vehicle.

The program finally displays the selected packages, total weight used, and maximum value obtained.

## Objectives

- Understand the Greedy Algorithm.
- Calculate the Value/Weight ratio of each package.
- Sort packages according to their ratio.
- Select complete packages whenever possible.
- Select a fraction of a package when required.
- Find the maximum value.
- Understand time complexity.

## Algorithm

1. Enter the number of packages.
2. Enter the value and weight of each package.
3. Enter the vehicle capacity.
4. Calculate the Value/Weight ratio for every package.
5. Sort the packages in decreasing order of ratio.
6. Select the package with the highest ratio first.
7. If the complete package fits, select it completely.
8. If it does not fit, select the required fraction of the package.
9. Calculate the total value and total weight.
10. Display the selected packages and maximum value.

## Sample Input

| Package | Value | Weight |
|--------|------:|-------:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

**Vehicle Capacity:** 15

## Value/Weight Ratio

| Package | Ratio |
|--------|------:|
| 1 | 8 |
| 2 | 3 |
| 3 | 10 |
| 4 | 5 |

### Sorted Order

1. Package 3 → Ratio 10
2. Package 1 → Ratio 8
3. Package 4 → Ratio 5
4. Package 2 → Ratio 3

## Result

- Package 3 → 100% selected
- Package 1 → 100% selected
- Package 4 → 100% selected
- Package 2 → 10% selected

**Total Weight Used:** 15

**Maximum Value:** 113

## Time Complexity

The program uses sorting to arrange packages according to their Value/Weight ratio.

**Time Complexity: O(n²)**

## Space Complexity

**Space Complexity: O(n)**

## Technology Used

- Programming Language: C
- Algorithm: Greedy Algorithm
- Problem: Fractional Knapsack
- IDE: Visual Studio Code

## Project Structure

```text
Fractional-Knapsack/
│
├── fractional_knapsack.c
├── README.md
└── screenshots/
    ├── package-details.png
    ├── ratio.png
    ├── sorted.png
    ├── maximum-value.png
    └── selected-packages.png

