#include <gtest/gtest.h>
#include <sstream>
#include "set.hpp"

TEST(Test, t1) {
    Sphere s(3.0);
    EXPECT_EQ(std::abs(s.metric() - ((4.0 / 3.0) * 3.14 * std::pow(3.0, 3))) <= 0.0001, true);

    Cube c(2.0);
    EXPECT_EQ(c.metric(), std::pow(2.0, 3));

    Cone cn(3.0, 4.0);
    EXPECT_EQ(std::abs(cn.metric() - ((1.0 / 3.0) * 3.14 * 9.0 * 4.0)) <= 0.0001, true);
}

TEST(Test, t2) {
    Cone cn(3.0, 4.0);
    EXPECT_EQ(cn.slantHeight(), 5.0);
}

TEST(Test, t3) {
    Sphere s(2.5);
    EXPECT_EQ(s.radius(), 2.5);

    Cube c(4.0);
    EXPECT_EQ(c.edge(), 4.0);

    EXPECT_EQ(s.fitsInBox(1000.0), true);
    EXPECT_EQ(c.fitsInBox(1000.0), true);
}

TEST(Test, t4) {
    shape* ptr = new Sphere(5.0);
    Sphere* s_ptr = dynamic_cast<Sphere*>(ptr);
    EXPECT_EQ(s_ptr != nullptr, true);
    if (s_ptr) {
        EXPECT_EQ(s_ptr->radius(), 5.0);
    }
    delete ptr;
}

TEST(Test, t5) {
    shape* ptr = new Cube(3.0);
    Sphere* s_ptr = dynamic_cast<Sphere*>(ptr);
    EXPECT_EQ(s_ptr, nullptr);
    delete ptr;
}

TEST(Test, t6) {
    Set s;
    s.add(new Cube(2.0));
    s.add(new Cube(3.0));
    s.add(new Cube(1.0));

    EXPECT_EQ(s.size(), 3u);

    Cube probe1(2.0);
    Cube probe2(3.0);
    EXPECT_EQ(s.contains(&probe1), true);
    EXPECT_EQ(s.contains(&probe2), true);
}

TEST(Test, t7) {
    Sphere s(4.5);
    std::ostringstream oss;
    oss << s;
    std::string output = oss.str();

    EXPECT_EQ(output.find("Sphere") != std::string::npos, true);
    EXPECT_EQ(output.find("4.5") != std::string::npos, true);
}

TEST(Test, t8) {
    Cube c1(2.0);
    Cube c2(2.0);
    Cube c3(3.0);

    EXPECT_EQ(c1 == c2, true);
    EXPECT_EQ(c1 == c3, false);
}

TEST(Test, t9) {
    Cube c(3.0);
    double val = static_cast<double>(c);
    EXPECT_EQ(val, 27.0);
}

TEST(Test, t10) {
    Set empty_set;
    EXPECT_EQ(empty_set.size(), 0u);
    EXPECT_EQ(empty_set.empty(), true);

    Cube zero_cube(0.0);
    EXPECT_EQ(zero_cube.metric(), 0.0);

    Cube neg_cube(-2.0);
    EXPECT_EQ(neg_cube.metric(), -8.0);
}
