// Copyright 2019 Alexander Batashev

#include <gtest/gtest.h>
#include <algorithm>

#include "include/set.h"

TEST(SetTest, Can_Add_Item) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.insert(5);

  // Assert
  EXPECT_EQ(*mSet.begin(), 5);
}

TEST(SetTest, Added_Items_Are_Unique) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.insert(5);
  mSet.insert(5);
  mSet.insert(5);

  // Assert
  EXPECT_EQ(mSet.size(), 1);
  EXPECT_EQ(*mSet.begin(), 5);
}

TEST(SetTest, Added_Items_Are_Sorted) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.insert(3);
  mSet.insert(2);
  mSet.insert(1);

  // Assert
  EXPECT_TRUE(std::is_sorted(mSet.begin(), mSet.end()));
}

TEST(SetTest, Can_Remove_Items) {
  // Arrange
  Set<int> mSet;

  mSet.insert(3);
  mSet.insert(2);
  mSet.insert(1);

  // Act
  mSet.remove(2);

  // Assert
  for (const auto &it : mSet) {
    EXPECT_NE(it, 2);
  }
}

TEST(SetTest, Can_Copy) {
  // Arrange
  Set<int> mSet1;
  Set<int> mSet2;

  mSet1.insert(5);

  // Act & assert
  ASSERT_NO_THROW(mSet2 = mSet1);
  EXPECT_EQ(*mSet2.begin(), 5);
}

TEST(SetTest, Can_Move) {
  // Arrange
  Set<int> mSet1;
  Set<int> mSet2;

  mSet1.insert(5);

  // Act & assert
  ASSERT_NO_THROW(mSet2 = std::move(mSet1));
  EXPECT_EQ(*mSet2.begin(), 5);
  EXPECT_EQ(mSet1.size(), 0);
}
