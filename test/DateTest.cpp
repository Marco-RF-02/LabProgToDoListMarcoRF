//
// Created by Marco on 09/08/2022.
//

#include "gtest/gtest.h"
#include "../Date.h"


TEST(Date, checkDateTest) {
    Date date;
    ASSERT_FALSE(date.checkDate(1,1,2022));
    ASSERT_FALSE( date.checkDate(31,6,2023));
    ASSERT_TRUE(date.checkDate(2,2,2023));
}

TEST(Date, deparseDateTest) {
    Date dateobj;
    Date date=dateobj.deparseDate("1^1^1111");
    ASSERT_EQ(1,date.getDay());
    ASSERT_EQ(1,date.getMonth());
    ASSERT_EQ(1111,date.getYear());
}
