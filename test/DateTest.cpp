//
// Created by Marco on 09/08/2022.
//

#include "gtest/gtest.h"
#include "../Date.h"


TEST(Date, checkDateTest) {
    Date date;
    ASSERT_EQ(false,date.checkDate(1,1,2022));
    ASSERT_EQ(true, date.checkDate(9,8,2022));
}

