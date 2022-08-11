//
// Created by Marco on 09/08/2022.
//

#include "gtest/gtest.h"
#include "../Date.h"


TEST(Date, checkDateTest) {
    Date date;
    ASSERT_EQ(false,date.checkDate(1,1,2022));
    ASSERT_EQ(true, date.checkDate(23,8,2023));
}

TEST(Date, deparseDateTest) {
    Date dateobj;
    Date date=dateobj.deparseDate("1^1^1111");
    ASSERT_EQ(1,date.getDay());
    ASSERT_EQ(1,date.getMonth());
    ASSERT_EQ(1111,date.getYear());
}
