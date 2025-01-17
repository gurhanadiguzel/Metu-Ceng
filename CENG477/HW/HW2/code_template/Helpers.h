#ifndef __HELPERS_H__
#define __HELPERS_H__
#define ABS(a) ((a) > 0 ? (a) : -1 * (a))
#define EPSILON 0.000000001

#include <cmath>
#include <iostream>

#include "Color.h"
#include "Matrix4.h"
#include "Vec3.h"
#include "Vec4.h"

/*
 * Calculate cross product of vec3 a, vec3 b and return resulting vec3.
 */
Vec3 crossProductVec3(Vec3 a, Vec3 b);

/*
 * Calculate dot product of vec3 a, vec3 b and return resulting value.
 */
double dotProductVec3(Vec3 a, Vec3 b);

/*
 * Find length (|v|) of vec3 v.
 */
double magnitudeOfVec3(Vec3 v);

/*
 * Normalize the vec3 to make it unit vec3.
 */
Vec3 normalizeVec3(Vec3 v);

/*
 * Return -v (inverse of vec3 v)
 */
Vec3 inverseVec3(Vec3 v);

/*
 * Add vec3 a to vec3 b and return resulting vec3 (a+b).
 */
Vec3 addVec3(Vec3 a, Vec3 b);

Vec4 addVec4(Vec4 a, Vec4 b);

Vec4 addVec4WithVec3(Vec4 a, Vec3 b);

Color addColor(Color a, Color b);

/*
 * Subtract vec3 b from vec3 a and return resulting vec3 (a-b).
 */
Vec3 subtractVec3(Vec3 a, Vec3 b);

Vec4 subtractVec4(Vec4 a, Vec4 b);

Color subtractColor(Color a, Color b);

/*
 * Multiply each element of vec3 with scalar.
 */
Vec3 multiplyVec3WithScalar(Vec3 v, double c);

Vec4 multiplyVec4WithScalar(Vec4 v, double c);

Color multiplyColorWithScalar(Color v, double c);

Vec3 divideVec3WithScalar(Vec3 v, double c);

Vec4 divideVec4WithScalar(Vec4 v, double c);

Color divideColorWithScalar(Color v, double c);

/*
 * Prints elements in a vec3. Can be used for debugging purposes.
 */
void printVec3(Vec3 v);

void printVec4(Vec4 v);

void printMatrix(Matrix4 matrix);

/*
 * Check whether vec3 a and vec3 b are equal.
 * In case of equality, returns 1.
 * Otherwise, returns 0.
 */
int areEqualVec3(Vec3 a, Vec3 b);
/*
 * Returns an identity matrix (values on the diagonal are 1, others are 0).
 */
Matrix4 getIdentityMatrix();

/*
 * Multiply matrices m1 (Matrix4) and m2 (Matrix4) and return the result matrix r (Matrix4).
 */
Matrix4 multiplyMatrixWithMatrix(Matrix4 m1, Matrix4 m2);

/*
 * Multiply matrix m (Matrix4) with vector v (vec4) and store the result in vector r (vec4).
 */
Vec4 multiplyMatrixWithVec4(Matrix4 m, Vec4 v);

#endif