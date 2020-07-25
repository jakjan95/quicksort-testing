#include <gtest/gtest.h>
#include <vector>

#include "quicksort.hpp"

using VectorsPair = std::pair<std::vector<int>, std::vector<int>>;

struct QuickSortVectorTestFixture : public ::testing::TestWithParam<VectorsPair> {};

TEST_P(QuickSortVectorTestFixture, IntigerInputVectorAfterSortingShouldBeEqualToExpected) {
    auto [input, expected] = GetParam();
    quickSort(input);
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
                                           VectorsPair{{15, 38, 69, 73, 61, 60, 48, 65, 16, 9,
                                                        70, 46, 55, 41, 67, 56, 100, 8, 14, 12,
                                                        64, 98, 6, 24, 4, 19, 71, 74, 90, 82,
                                                        94, 28, 7, 25, 47, 87, 92, 2, 34, 13,
                                                        43, 26, 80, 51, 66, 91, 31, 77, 32, 93,
                                                        62, 42, 36, 30, 59, 79, 96, 95, 23, 68,
                                                        27, 86, 39, 99, 45, 50, 40, 37, 97, 83,
                                                        89, 57, 3, 44, 85, 18, 17, 49, 22, 84,
                                                        21, 20, 58, 88, 53, 11, 52, 75, 72, 78,
                                                        54, 81, 10, 33, 5, 35, 63, 76, 29, 1},
                                                       {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
                                                        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                                        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
                                                        56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
                                                        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
                                                        86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100}},
                                           VectorsPair{{19, 7, 25, 4, 3, 99, 9, 1, 3, 12, 5, 2, 17}, {1, 2, 3, 3, 4, 5, 7, 9, 12, 17, 19, 25, 99}}));

INSTANTIATE_TEST_SUITE_P(OutliersVectors,
                         QuickSortVectorTestFixture,
                         ::testing::Values(VectorsPair{{99, 0, 0, 0, 0, 0, 0, 0, 97}, {0, 0, 0, 0, 0, 0, 0, 97, 99}},
                                           VectorsPair{{1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7}},
                                           VectorsPair{{1, 1, 1, 1, 0, 0, 0, -99}, {-99, 0, 0, 0, 1, 1, 1, 1}},
                                           VectorsPair{{99, 99, 99, -50, -25, 5, 9, 0}, {-50, -25, 0, 5, 9, 99, 99, 99}}));

using DoubleVectorsPair = std::pair<std::vector<double>, std::vector<double>>;

struct QuickSortDoubleVectorTestFixture : public ::testing::TestWithParam<DoubleVectorsPair> {};

TEST_P(QuickSortDoubleVectorTestFixture, DoubleInputVectorAfterSortingShouldBeEqualToExpected) {
    auto [input, expected] = GetParam();
    quickSort(input);
    ASSERT_EQ(input, expected);
}

INSTANTIATE_TEST_SUITE_P(PositiveDoubleVector,
                         QuickSortDoubleVectorTestFixture,
                         ::testing::Values(DoubleVectorsPair{{3.3, 2.2, 1.1}, {1.1, 2.2, 3.3}},
                                           DoubleVectorsPair{{1.1, 2.2, 3.3}, {1.1, 2.2, 3.3}},
                                           DoubleVectorsPair{{2.2, 1.1, 3.3}, {1.1, 2.2, 3.3}},
                                           DoubleVectorsPair{{3.3, 1.1, 2.2}, {1.1, 2.2, 3.3}},
                                           DoubleVectorsPair{{}, {}},
                                           DoubleVectorsPair{{1.1}, {1.1}}));

INSTANTIATE_TEST_SUITE_P(NegativeDoubleVectors,
                         QuickSortDoubleVectorTestFixture,
                         ::testing::Values(DoubleVectorsPair{{-3.3, -2.2, -1.1}, {-3.3, -2.2, -1.1}},
                                           DoubleVectorsPair{{-1.1, -2.2, -3.3}, {-3.3, -2.2, -1.1}},
                                           DoubleVectorsPair{{-2.2, -1.1, -3.3}, {-3.3, -2.2, -1.1}},
                                           DoubleVectorsPair{{-3.3, -1.1, -2.2}, {-3.3, -2.2, -1.1}},
                                           DoubleVectorsPair{{-1.1}, {-1.1}}));

TEST(StringVectorSorting, GivenStringVectorShouldBeEqualToExpectedAfterSorting) {
    std::vector<std::string> input{"niqcur", "mogssc", "ulxymo", "qyqcrh", "wnzduz", "uenryd"};
    std::vector<std::string> expected{"mogssc", "niqcur", "qyqcrh", "uenryd", "ulxymo", "wnzduz"};

    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(StringVectorSorting, GivenReverseSortedStringVectorShouldBeEqualToExpectedAfterSorting) {
    std::vector<std::string> input{"wnzduz", "ulxymo", "uenryd", "qyqcrh", "niqcur", "mogssc"};
    std::vector<std::string> expected{"mogssc", "niqcur", "qyqcrh", "uenryd", "ulxymo", "wnzduz"};

    quickSort(input);
    ASSERT_EQ(input, expected);
}
