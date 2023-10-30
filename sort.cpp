/**
 * Version 0.0.1
 *
 * This sorting algorithm is not optimized with prefix sums
 */

#include <iostream>
#include <vector>

void sort(std::vector<int> &arr)
{
    int min = arr[0], max = arr[0];

    for (int i : arr)
    {
        min = std::min(min, i);
        max = std::max(max, i);
    }

    std::vector<int> sorting(max - min + 1);

    for (int i : arr)
        ++sorting[i - min];

    // used tell which location in the arr to write.
    int counter = 0;
    for (int i = 0; i < sorting.size(); ++i)
    {
        for (int j = 0; j < sorting[i]; ++j)
        {
            arr[counter] = i + min;
            counter++;
        }
    }
}

void printArr(std::vector<int> &arr)
{
    std::cout << "{";
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[arr.size() - 1] << "}";
}

int main()
{
    std::vector<int> test = {5, 2, 8, 1, 9, 3};
    sort(test);
    // {1, 2, 3, 5, 8, 9}
    printArr(test);

    return 0;
}