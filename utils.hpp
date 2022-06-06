#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>

int getRandomNumber(const unsigned int& min, const unsigned int& max);
bool tests(const unsigned int& min, const unsigned int& max,
  const size_t& amountOfElements, const size_t& amountOfTests);
void testsStatus(bool tests, std::ostream& out = std::cout);
void notDescendingQuickSort(std::vector< unsigned int >& arr, const long int& low, const long int& high);
void swap(unsigned int* a, unsigned int* b);
long int partition(std::vector< unsigned int >& arr, const long int& low, const long int& high);

#endif
