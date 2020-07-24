#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <vector>

#include "quicksort.hpp"

using VectorsPair = std::pair<std::vector<int>, std::vector<int>>;

struct QuickSortVectorTestFixture : public ::testing::TestWithParam<VectorsPair> {};

TEST_P(QuickSortVectorTestFixture, GivenAnInputVectorWhenVectorIsSortedThenItIsEqualToExpected) {
    // GIVEN
    auto [input, expected] = GetParam();
    // WHEN
    quickSort(input);
    // THEN
    ASSERT_EQ(input, expected);
}

INSTANTIATE_TEST_SUITE_P(PositiveVector,
                         QuickSortVectorTestFixture,
                         ::testing::Values(VectorsPair{{3, 2, 1}, {1, 2, 3}},
                                           VectorsPair{{1, 2, 3}, {1, 2, 3}},
                                           VectorsPair{{2, 1, 3}, {1, 2, 3}},
                                           VectorsPair{{3, 1, 2}, {1, 2, 3}},
                                           VectorsPair{{}, {}},
                                           VectorsPair{{1}, {1}}));

INSTANTIATE_TEST_SUITE_P(NegativeVectors,
                         QuickSortVectorTestFixture,
                         ::testing::Values(VectorsPair{{-3, -2, -1}, {-3, -2, -1}},
                                           VectorsPair{{-1, -2, -3}, {-3, -2, -1}},
                                           VectorsPair{{-2, -1, -3}, {-3, -2, -1}},
                                           VectorsPair{{-3, -1, -2}, {-3, -2, -1}},
                                           VectorsPair{{-1}, {-1}}));

INSTANTIATE_TEST_SUITE_P(LongVectors,
                         QuickSortVectorTestFixture,
                         ::testing::Values(VectorsPair{{7, 4, 3, 9, 1, 3, 12, 19, 2, 25, 17, 99, 5}, {1, 2, 3, 3, 4, 5, 7, 9, 12, 17, 19, 25, 99}},
                                           VectorsPair{{19, 7, 25, 4, 3, 99, 9, 1, 3, 12, 5, 2, 17}, {1, 2, 3, 3, 4, 5, 7, 9, 12, 17, 19, 25, 99}}));
                                           
//vectors with repetitions
//extremal numbres in vector(high/low on beginning, ending or middle)

//vectors with doubles
//vector with strings
//vector with chars
