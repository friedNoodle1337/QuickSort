#include <algorithm>

#include "utils.hpp"

int getRandomNumber(const unsigned int& min, const unsigned int& max)
{
  static const double fraction = 1.0 / (static_cast< double >(RAND_MAX) + 1.0);
  return static_cast< unsigned int >(rand() * fraction * (max - min + 1) + min);
}

bool tests(const unsigned int& min, const unsigned int& max, const size_t& amountOfElements, const size_t& amountOfTests)
{
  for (size_t i = 0; i < amountOfTests; ++i)
  {
    std::vector< unsigned int > testArr(amountOfElements);
    std::vector< unsigned int > compareArr(amountOfElements);

    for (size_t j = 0; j < amountOfElements; ++j)
    {
      unsigned int element = getRandomNumber(min, max);
      testArr[j] = element;
      compareArr[j] = element;
    }

    notDescendingQuickSort(testArr, 0, static_cast<int>(amountOfElements) - 1);
    std::sort(compareArr.begin(), compareArr.end());

    for (size_t j = 0; j < amountOfElements; ++j)
    {
      if (testArr[j] != compareArr[j])
      {
        return false;
      }
    }
  }

  return true;
}

void testsStatus(bool tests, std::ostream& out)
{
  if (tests == true)
  {
    out << "All tests are completed successfully!\n";
  }
  else
  {
    out << "Tests are failed!\n";
  }
}

void notDescendingQuickSort(std::vector< unsigned int >& arr, const long int& low, const long int& high)
{
  if (low < high)
  {
    long int pivot = partition(arr, low, high);
    notDescendingQuickSort(arr, low, pivot - 1);
    notDescendingQuickSort(arr, pivot + 1, high);
  }
}

void swap(unsigned int* a, unsigned int* b)
{
  unsigned int temp = *a;
  *a = *b;
  *b = temp;
}

long int partition(std::vector< unsigned int >& arr, const long int& low, const long int& high)
{
  // select the rightmost element as pivot
  unsigned int pivot = arr[high];

  // pointer for greater element
  long int i = low - 1;

  // traverse each element of the array
  // compare them with the pivot
  for (long int j = low; j < high; ++j)
  {
    if (arr[j] <= pivot)
    {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      ++i;

      // swap element at i with element at j
      swap(&arr[i], &arr[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(&arr[i + 1], &arr[high]);

  // return the partition point
  return i + 1;
}
