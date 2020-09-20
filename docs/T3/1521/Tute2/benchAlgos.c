// NOTE: This uses obsidian a benchmarking library and unit testing library I wrote
// https://braedonwooding.github.io/Obsidian/#/

#include "cbench.h"
#include "obsidian.h"
#include <string.h>

#include <limits.h> // char_bit
#include <assert.h>

#include <string.h>

typedef unsigned long long Word;
#define SIZEOF_BITS(T) (sizeof(T) * CHAR_BIT)

Word reverseBits_1(Word word) {
    Word ret = 0;
    for (unsigned int bit = 0; bit < SIZEOF_BITS(Word); bit++) {
      Word mask = 1u << ((SIZEOF_BITS(Word) - 1) - bit);
      ret |= !!(word & mask) << bit;
    }

    return ret;
}

Word reverseBits_2(Word word) {
    Word ret = 0;
    for (unsigned int bit = 0; bit < SIZEOF_BITS(Word); bit++) {
      Word mask = 1u << ((SIZEOF_BITS(Word) - 1) - bit);

      if (word & mask) {
        ret &= 1u << bit;
      }
    }

    return ret;
}

Word reverseBits_3(Word word) {
    Word ret = 0;
    int max = SIZEOF_BITS(Word) - 1;

    for (; word != 0; word >>= 1) {
      ret |= word & 1;
      ret <<= 1;
      max--;
    }

    return ret << max;
}

Word reverseBits_4(Word word) {
  Word ret = 0;             // Reversed bit-string
  Word left = 1;            // Left moving mask
  Word right = ~(-1u >> 1); // Right moving mask

  for (; right != 0; left <<= 1, right >>= 1) {
    if (word & left) {
      ret |= right;
    }
  }

  return ret;
}

Word reverseBits_5(Word word) {
  Word ret = 0;                          // Reversed bit-string
  Word left = 1;                         // Left moving mask
  Word right = ~(-1u >> 1); // Right moving mask

  for (; right != 0; left <<= 1, right >>= 1) {
    // ret |= -!!(word & left) & right;
    ret |= !!(word & left) * right;
  }

  return ret;
}

Word reverseBits_6(Word word) {
  Word ret = 0;                             // Reversed bit-string
  Word shift = (__builtin_ffs(word) - 1);
  Word left = 1 << shift;                   // Left moving mask
  Word right = ~(-1u >> 1) >> shift;        // Right moving mask

  for (; right != 0; left <<= 1, right >>= 1) {
    if (word & left) {
      ret |= right;
    }
  }

  return ret;
}

// #define LHS 0x01234567
// #define RHS 0xe6a2c48000000000ull
#define LHS 20015997779968
#define RHS 0xe6a2c480000

#define ITERATIONS 2
#define ITERATIONS_INNER 10000000

int main(int argc, char *argv[]) {
    OBS_SETUP("Benchmarks", argc, argv);
    OBS_BENCHMARK("Reverse Bits copy bits 1 by 1 no branch", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_1(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_BENCHMARK("Reverse Bits copy bits 1 by 1 branch", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_2(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_BENCHMARK("Reverse Bits shift word down and move bits", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_3(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_BENCHMARK("Reverse Bits two cursors branch", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_4(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_BENCHMARK("Reverse Bits two cursors no branch!", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_5(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_BENCHMARK("Reverse Bits two cursors no branch + skip 0's", ITERATIONS, {
        volatile Word w1 = LHS;
        volatile Word w2 = 0;
        for (int i = 0; i < ITERATIONS_INNER; i++) {
            w2 = reverseBits_6(w1);
        }
        obs_test_eq(Word, w2, RHS);
    })

    OBS_REPORT;
    return tests_failed;
}
