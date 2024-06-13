//Extremely simple vector and matrix classes by Janusz Malinowski. 
#include <stdio.h>
#pragma once

/**
 * @class Vector
 * @brief Simple 3-dimensional vector class.
 */
class Vector
{
 public:
 double data[3];

 /**
 * @brief Default constructor for Vector.
 *
 * Initializes vector components to zero.
 */
 Vector();


 /**
 * @brief Print the components of the vector.
 *
 * Prints the components of the vector in the format "(x, y, z)".
 */
 void Print(void);


 /**
 * @brief Set the components of the vector.
 *
 * @param d1 Value for the x component.
 * @param d2 Value for the y component.
 */
 void Set(double d1,double d2);


 /**
 * @brief Get the x component of the vector.
 *
 * @return double X component of the vector.
 */
 double GetX();


 /**
 * @brief Get the y component of the vector.
 *
 * @return double Y component of the vector.
 */
 double GetY();
};

class Matrix
{
 public:
 double data[3][3];


 /**
 * @brief Default constructor for Matrix.
 *
 * Initializes matrix elements to zero.
 */
 Matrix();


 /**
 * @brief Print the elements of the matrix.
 *
 * Prints the elements of the matrix in a 3x3 grid.
 */
 void Print(void);


 /**
 * @brief Multiply two matrices.
 *
 * @param m Matrix to multiply with.
 * @return Matrix Resulting matrix from the multiplication.
 */
 Matrix operator*(const Matrix);


 /**
 * @brief Multiply a matrix with a vector.
 *
 * @param m Matrix to multiply with.
 * @param v Vector to multiply with.
 * @return Vector Resulting vector from the multiplication.
 */
 friend Vector operator*(const Matrix,const Vector);
};

