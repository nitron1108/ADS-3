// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    length++;
  }

  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_val) {
      max_val = num;
    }
  }

  return max_val;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_length = 0;
  unsigned int result_num = lbound;

  for (uint64_t num = lbound; num <= rbound; ++num) {
    unsigned int current_len = collatzLen(num);

    if (current_len > max_length) {
      max_length = current_len;
      result_num = num;
    }
  }

  *maxlen = max_length;
  return result_num;
}
