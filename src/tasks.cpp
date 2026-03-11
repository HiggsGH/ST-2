// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double task1() {
  double earthRadius = 63781.0;

  Circle earth;
  earth.setRadius(earthRadius);

  double ropeLength = earth.getFerence();

  double newRopeLength = ropeLength + 1.0;

  Circle newCircle;
  newCircle.setFerence(newRopeLength);

  double newRadius = newCircle.getRadius();

  double gap = newRadius - earthRadius;

  return gap;
}

double task2() {
  double poolRadius = 3.0;

  double pathWidth = 1.0;

  double outerRadius = poolRadius + pathWidth;

  Circle pool;
  pool.setRadius(poolRadius);

  Circle poolWithPath;
  poolWithPath.setRadius(outerRadius);

  double pathArea = poolWithPath.getArea() - pool.getArea();

  double concreteCost = pathArea * 1000.0;

  double fenceLength = poolWithPath.getFerence();

  double fenceCost = fenceLength * 2000.0;

  return concreteCost + fenceCost;
}