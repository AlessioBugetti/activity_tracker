//
// Created by alessio on 28/05/19.
//

#include "gtest/gtest.h"

#include "../Date.h"

TEST(Date, DateConstructor) {
    Date d(2018, Months::Gennaio, 1);
    ASSERT_EQ(1, d.getDay());
    ASSERT_EQ(Months::Gennaio, d.getMonth());
    ASSERT_EQ(2018, d.getYear());
}

TEST(Date, InvalidDate) {
    ASSERT_THROW(Date d(2018, Months::Ottobre, 35),std::domain_error);
}

TEST(Date, InvalidDateFeb) {
    ASSERT_THROW(Date d(2018, Months::Febbraio, 30),std::domain_error);
}

TEST(Date, InvalidDateApr) {
    ASSERT_THROW(Date d(2018, Months::Aprile, 31),std::domain_error);
}

TEST(Date, ModifyDateDay) {
    Date d(2018, Months::Gennaio, 1);
    d.setDay(25);
    ASSERT_EQ(25, d.getDay());
    ASSERT_EQ(Months::Gennaio, d.getMonth());
    ASSERT_EQ(2018, d.getYear());
}

TEST(Date, ModifyDateMonth) {
    Date d(2018, Months::Gennaio, 1);
    d.setMonth(Months::Aprile);
    ASSERT_EQ(1, d.getDay());
    ASSERT_EQ(Months::Aprile, d.getMonth());
    ASSERT_EQ(2018, d.getYear());
}

TEST(Date, ModifyDateYear) {
    Date d(2018, Months::Gennaio, 1);
    d.setYear(2019);
    ASSERT_EQ(1, d.getDay());
    ASSERT_EQ(Months::Gennaio, d.getMonth());
    ASSERT_EQ(2019, d.getYear());
}