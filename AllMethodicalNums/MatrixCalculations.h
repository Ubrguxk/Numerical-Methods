#pragma once
#ifndef MATRIXCALCULATIONS_H
#define MATRIXCALCULATIONS_H

#include <string>

float** addMatrix(float** tab1, float** tab2, int sizeTab);
float** TopTriangleMatrix(float** Tab, int sizeTab);
float** BottomTriangleMatrix(float** Tab, int sizeTab);
float** DiagonalMatrix(float** Tab, int sizeTab);
#endif