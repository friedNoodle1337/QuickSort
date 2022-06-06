#include <ctime>

#include "utils.hpp"

int main()
{
  srand(static_cast< unsigned int >(time(0)));

  try
  {
    std::cout << "Tests with small range: \n";
    unsigned int min = 0;
    unsigned int max = 5000;
    std::size_t amountOfElements = 10000;
    std::size_t amountOfTests = 100;
    testsStatus(tests(min, max, amountOfElements, amountOfTests));

    std::cout << "\nTests with medium range: \n";
    max = 25000;
    amountOfElements = 50000;
    testsStatus(tests(min, max, amountOfElements, amountOfTests));

    std::cout << "\nTests with large range: \n";
    max = 50000;
    amountOfElements = 100000;
    testsStatus(tests(min, max, amountOfElements, amountOfTests));
  }
  catch (const std::exception& exc)
  {
    std::cerr << exc.what() << "\n";
  }

  return 0;
}
