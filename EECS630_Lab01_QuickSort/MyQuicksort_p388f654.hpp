#ifndef _MY_QUICK_SORT_
#define _MY_QUICK_SORT_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>

const int BOUNDARY_SIZE = 10; // sort directly using insertion sort if the input size is smaller than BOUNRARY_SIZE

// Checks if an array is sorted
// a: input array to be checked
// reverse: if set true, check for descending order; otherwise ascending order
template <typename Comparable>
bool IsSorted( std::vector<Comparable> & a, bool reverse = false)
{
  if(a.size() <= 1) return true;
  bool sorted = true;
  for(size_t i = 0; i < a.size() - 1; ++ i)
  {
    if((a[i] > a[i + 1] && !reverse) || (a[i] < a[i + 1] && reverse))
    {
      sorted = false;
      std::cout << "Out of order: Positions: " << i << " : " << a[i] << "  " << a[i + 1] << std::endl;
      break;
    }
  }
  return sorted;
}

// Prints the array
// a: the array to be printed
template <typename Comparable>
void PrintArray( std::vector<Comparable> & a)
{
  for(size_t i = 0; i < a.size(); ++ i)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return;
}

// The insertion sort algorithm:
// a: the input array
// left and right: the left and end indexes of the range of the elements to be sorted, inclusive
// reverse: if set true, sort in descending order. Default: false
template <typename Comparable>
void InsertionSort(std::vector<Comparable> &a, int left, int right, bool reverse = false) {
    for (int i = left + 1; i <= right; ++i) {
        Comparable key = std::move(a[i]);
        int j = i - 1;

        while (j >= left && ((reverse && a[j] < key) || (!reverse && a[j] > key))) {
            a[j + 1] = std::move(a[j]);
            --j;
        }

        a[j + 1] = std::move(key);
    }
}



// Finds the median among three elements: a[x], a[y], and a[z]
// a: the array
// x, y, z: the three indexes in the array
// returns the index that corresponds to the median of the three
template <typename Comparable>
const size_t ArrayMedian3(std::vector<Comparable> &a, const size_t x, const size_t y, const size_t z) {
    if ((a[x] <= a[y] && a[y] <= a[z]) || (a[z] <= a[y] && a[y] <= a[x]))
        return y;
    else if ((a[y] <= a[x] && a[x] <= a[z]) || (a[z] <= a[x] && a[x] <= a[y]))
        return x;
    else
        return z;
}


// The partition function for the quick sort algorithm
template <typename Comparable>
int partition(std::vector<Comparable> &a, int left, int right, bool reverse = false) {
    // Find the median of three elements and use it as the pivot
    int pivotIndex = ArrayMedian3(a, left, (left + right) / 2, right);
    Comparable pivotValue = a[pivotIndex];

    // Move the pivot to the end of the array
    std::swap(a[pivotIndex], a[right]);

    // Initialize the storeIndex to the leftmost position
    int storeIndex = left;

    // If reverse is true, partition the array such that elements greater than the pivot are on the left
    if (reverse) {
        for (int i = left; i < right; i++) {
            if (a[i] >= pivotValue) {
                std::swap(a[i], a[storeIndex]);
                storeIndex++;
            }
        }
    } else {
        // If reverse is false, partition the array such that elements less than the pivot are on the left
        for (int i = left; i < right; i++) {
            if (a[i] <= pivotValue) {
                std::swap(a[i], a[storeIndex]);
                storeIndex++;
            }
        }
    }

    // Move the pivot to its final place
    std::swap(a[storeIndex], a[right]);

    // Return the index of the pivot
    return storeIndex;
}

// The recursive quick sort function
// a: the array to be sorted
// left and right: the indexes for the range to be sorted, inclusive
// reverse: if set true, sort in descending order; otherwise in ascending order
// The quicksort function that recursively sorts the elements of the array
template <typename Comparable>
void Quicksort(std::vector<Comparable> &a, int left, int right, bool reverse = false) {
    // Base case: if the left index is no longer less than the right index, the array is sorted
    if (left < right) {
        // Partition the array and get the index of the pivot
        int pivotIndex = partition(a, left, right, reverse);

        // Recursively sort the left subarray, which contains elements less than the pivot
        Quicksort(a, left, pivotIndex - 1, reverse);

        // Recursively sort the right subarray, which contains elements greater than the pivot
        Quicksort(a, pivotIndex + 1, right, reverse);
    }
}


// The driver quicksort function
template <typename Comparable>
void Quicksort( std::vector<Comparable> & a, bool reverse = false)
{
  Quicksort( a, 0, a.size( ) - 1, reverse);
}


#endif