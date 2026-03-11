// Copyright 2022 UNN-CS
#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <gtest/gtest.h>

const double EPSILON = 1e-10;

TEST(CircleTest, DefaultConstructor) {
  Circle c;
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, ConstructorWithRadius) {
  Circle c;
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(5.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 5.0, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 25.0, c.getArea());
}

TEST(CircleTest, ConstructorWithZeroRadius) {
  Circle c;
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, ConstructorWithNegativeRadiusThrows) {
  Circle c;
  EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusPositive) {
  Circle c;
  c.setRadius(7.5);
  EXPECT_DOUBLE_EQ(7.5, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 7.5, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 56.25, c.getArea());
}

TEST(CircleTest, SetRadiusZero) {
  Circle c;
  c.setRadius(10.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetRadiusNegativeThrows) {
  Circle c;
  EXPECT_THROW(c.setRadius(-3.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusTwice) {
  Circle c;
  c.setRadius(2.0);
  EXPECT_DOUBLE_EQ(2.0, c.getRadius());

  c.setRadius(8.0);
  EXPECT_DOUBLE_EQ(8.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 8.0, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 64.0, c.getArea());
}

TEST(CircleTest, SetFerencePositive) {
  Circle c;
  double ference = 20.0;
  c.setFerence(ference);
  double expectedRadius = ference / (2.0 * M_PI);
  EXPECT_DOUBLE_EQ(expectedRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(ference, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * expectedRadius * expectedRadius, c.getArea());
}

TEST(CircleTest, SetFerenceZero) {
  Circle c;
  c.setRadius(10.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetFerenceNegativeThrows) {
  Circle c;
  EXPECT_THROW(c.setFerence(-15.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceTwice) {
  Circle c;
  c.setFerence(2.0 * M_PI * 3.0);
  EXPECT_NEAR(3.0, c.getRadius(), EPSILON);

  c.setFerence(2.0 * M_PI * 7.0);
  EXPECT_NEAR(7.0, c.getRadius(), EPSILON);
  EXPECT_NEAR(M_PI * 49.0, c.getArea(), EPSILON);
}

TEST(CircleTest, SetAreaPositive) {
  Circle c;
  double area = 50.0;
  c.setArea(area);
  double expectedRadius = std::sqrt(area / M_PI);
  EXPECT_DOUBLE_EQ(expectedRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * expectedRadius, c.getFerence());
  EXPECT_DOUBLE_EQ(area, c.getArea());
}

TEST(CircleTest, SetAreaZero) {
  Circle c;
  c.setRadius(10.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetAreaNegativeThrows) {
  Circle c;
  EXPECT_THROW(c.setArea(-25.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaTwice) {
  Circle c;
  c.setArea(M_PI * 16.0);
  EXPECT_NEAR(4.0, c.getRadius(), EPSILON);

  c.setArea(M_PI * 36.0);
  EXPECT_NEAR(6.0, c.getRadius(), EPSILON);
  EXPECT_NEAR(2.0 * M_PI * 6.0, c.getFerence(), EPSILON);
}

TEST(CircleTest, GetMethodsReturnCorrectValues) {
  Circle c;
  c.setRadius(4.0);
  EXPECT_DOUBLE_EQ(4.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 4.0, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 16.0, c.getArea());
}

TEST(CircleTest, GetMethodsConstCorrectness) {
  Circle c;
  c.setRadius(5.0);
  const Circle &constC = c;
  EXPECT_DOUBLE_EQ(5.0, constC.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 5.0, constC.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 25.0, constC.getArea());
}

TEST(CircleTest, SetRadiusAfterSetFerence) {
  Circle c;
  c.setFerence(2.0 * M_PI * 10.0);
  EXPECT_NEAR(10.0, c.getRadius(), EPSILON);

  c.setRadius(15.0);
  EXPECT_DOUBLE_EQ(15.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2.0 * M_PI * 15.0, c.getFerence());
  EXPECT_DOUBLE_EQ(M_PI * 225.0, c.getArea());
}

TEST(CircleTest, SetAreaAfterSetRadius) {
  Circle c;
  c.setRadius(6.0);
  EXPECT_DOUBLE_EQ(6.0, c.getRadius());

  c.setArea(M_PI * 100.0);
  EXPECT_NEAR(10.0, c.getRadius(), EPSILON);
  EXPECT_NEAR(2.0 * M_PI * 10.0, c.getFerence(), EPSILON);
}

TEST(Task1Test, GapCalculation) {
  double gap = task1();
  EXPECT_NEAR(0.1591549430918953, gap, 1e-10);
}

TEST(Task1Test, GapPositive) {
  double gap = task1();
  EXPECT_GT(gap, 0.0);
}

TEST(Task1Test, GapNotZero) {
  double gap = task1();
  EXPECT_NE(gap, 0.0);
}

TEST(Task1Test, GapLessThanOne) {
  double gap = task1();
  EXPECT_LT(gap, 1.0);
}

TEST(Task1Test, GapIndependentOfRadius) {
  Circle earth;
  earth.setRadius(1000.0);
  double ropeLength = earth.getFerence();
  double newRopeLength = ropeLength + 1.0;
  Circle newCircle;
  newCircle.setFerence(newRopeLength);
  double customGap = newCircle.getRadius() - 1000.0;

  double gap = task1();
  EXPECT_NEAR(gap, customGap, 1e-10);
}

TEST(Task2Test, TotalCostPositive) {
  double totalCost = task2();
  EXPECT_GT(totalCost, 0.0);
}

TEST(Task2Test, ConcreteCostCalculation) {
  double expectedPathArea = M_PI * 7.0;
  double expectedConcreteCost = expectedPathArea * 1000.0;

  double expectedFenceLength = 2.0 * M_PI * 4.0;
  double expectedFenceCost = expectedFenceLength * 2000.0;

  double expectedTotal = expectedConcreteCost + expectedFenceCost;
  double actualTotal = task2();

  EXPECT_NEAR(expectedTotal, actualTotal, 1e-6);
}

TEST(Task2Test, ConcreteCostNotZero) {
  Circle pool;
  pool.setRadius(3.0);
  Circle poolWithPath;
  poolWithPath.setRadius(4.0);
  double pathArea = poolWithPath.getArea() - pool.getArea();
  double concreteCost = pathArea * 1000.0;
  EXPECT_GT(concreteCost, 0.0);
}

TEST(Task2Test, FenceCostNotZero) {
  Circle poolWithPath;
  poolWithPath.setRadius(4.0);
  double fenceCost = poolWithPath.getFerence() * 2000.0;
  EXPECT_GT(fenceCost, 0.0);
}

TEST(Task2Test, FenceCostGreaterThanConcreteCost) {
  double totalCost = task2();

  Circle pool;
  pool.setRadius(3.0);
  Circle poolWithPath;
  poolWithPath.setRadius(4.0);
  double pathArea = poolWithPath.getArea() - pool.getArea();
  double concreteCost = pathArea * 1000.0;
  double fenceCost = poolWithPath.getFerence() * 2000.0;

  EXPECT_GT(fenceCost, concreteCost);
  EXPECT_NEAR(totalCost, concreteCost + fenceCost, 1e-10);
}