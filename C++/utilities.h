#ifndef LDPC_TEST_OPT_UTILITIES_H
#define LDPC_TEST_OPT_UTILITIES_H

#include <cstdint>
#include <climits>

/**
 * Source: https://stackoverflow.com/a/776523
 */
static inline uint32_t rotl32 (uint32_t n, unsigned int c)
{
  const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);  // assumes width is a power of 2.

  // assert ( (c<=mask) &&"rotate by type width or more");
  c &= mask;
  return (n<<c) | (n>>( (-c)&mask ));
}

/**
 * Source: https://stackoverflow.com/a/776523
 */
static inline uint32_t rotr32 (uint32_t n, unsigned int c)
{
  const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);

  // assert ( (c<=mask) &&"rotate by type width or more");
  c &= mask;
  return (n>>c) | (n<<( (-c)&mask ));
}

template<class T, size_t N>
void printarr(std::array<T, N> arr) {
    for (unsigned int j = 0; j < N; j++) {
        std::cout << std::hex << arr[j] << " ";
    }
}

#endif //LDPC_TEST_OPT_UTILITIES_H
