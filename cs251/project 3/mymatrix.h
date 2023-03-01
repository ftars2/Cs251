//@filename mymatrix.h
///@author FrankTarshis
///@date Febuary 28th, 2023
/*mymatrix.h*/
//
//
//
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

//
// mymatrix
//
// The mymatrix class provides a matrix (2D array) abstraction.
// The size can grow dynamically in both directions (rows and
// cols).  Also, rows can be "jagged" --- i.e. rows can have
// different column sizes, and thus the matrix is not necessarily
// rectangular.  All elements are initialized to the default value
// for the given type T.  Example:
//
//   mymatrix<int>  M;  // 4x4 matrix, initialized to 0
//
//   M(0, 0) = 123;
//   M(1, 1) = 456;
//   M(2, 2) = 789;
//   M(3, 3) = -99;
//
//   M.growcols(1, 8);  // increase # of cols in row 1 to 8
//
//   for (int r = 0; r < M.numrows(); ++r)
//   {
//      for (int c = 0; c < M.numcols(r); ++c)
//         cout << M(r, c) << " ";
//      cout << endl;
//   }
//
// Output:
//   123 0 0 0
//   0 456 0 0 0 0 0 0
//   0 0 789 0
//   0 0 0 -99
//

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename T>
class mymatrix
{
private:
  struct ROW
  {
    T *Cols;     // dynamic array of column elements
    int NumCols; // total # of columns (0..NumCols-1)
  };

  ROW *Rows;   // dynamic array of ROWs
  int NumRows; // total # of rows (0..NumRows-1)
///@brief adds a row to a matrix up to a c # of columns
///@param r number of rows to add
///@param c number of columns each new row goes up to
  void addrows(int r, int c)
  {
    if (r <= NumRows)
    {
      // No need to add rows
      return;
    }

    // Allocate new array of ROW structures
    ROW *newRows = new ROW[r];

    // Copy existing rows into new array
    for (int i = 0; i < NumRows; i++)
    {
      newRows[i] = Rows[i];
    }

    // Allocate memory for new rows and columns
    for (int i = NumRows; i < r; i++)
    {
      newRows[i].Cols = new T[c];
      newRows[i].NumCols = c;
      for (int j = 0; j < c; j++)
      {
        newRows[i].Cols[j] = T(); // default-initialize the elements
      }
    }
    Rows = newRows;
    NumRows = r;
  }


  /// @brief multiplies 2 values from a matrix
  /// @param val1 value from first matrix
  /// @param val2 value from second matrix
  /// @return returns the product
  int matrixmult(int val1, int val2)
  {
    int val = val1 * val2;

    return val;
  }

public:
  ///
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 matrix.  All
  // elements are initialized to the default value of T.
  //
  
  mymatrix()
  {
    Rows = new ROW[4]; // an array with 4 ROW structs:
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[4]; // an array with 4 elements of type T:
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{}; // default value for type T:
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a matrix with R rows,
  // where each row has C columns. All elements are initialized to
  // the default value of T.
  ///@param R # of rows
  ///@param C # of columns
  mymatrix(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::constructor: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::constructor: # of cols");

    Rows = new ROW[R]; // an array with R ROW structs:
    NumRows = R;

    // initialize each row to have C columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[C]; // an array with C elements of type T:
      Rows[r].NumCols = C;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{}; // default value for type T:
      }
    }
  }

  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a matrix that contains a
  // copy of an existing matrix.  Example: this occurs when passing
  // mymatrix as a parameter by value
  //
  //   void somefunction(mymatrix<int> M2)  <--- M2 is a copy:
  //   { ... }
  //
  ///@param other reference to matrix
  mymatrix(const mymatrix<T> &other)
  {
    // copy the number of rows from the other matrix
    NumRows = other.NumRows;

    // allocate memory for the rows
    Rows = new ROW[NumRows];

    // copy each row from the other matrix
    for (int r = 0; r < NumRows; ++r)
    {
      // copy the number of columns for this row
      Rows[r].NumCols = other.Rows[r].NumCols;

      // allocate memory for the columns in this row
      Rows[r].Cols = new T[Rows[r].NumCols];

      // copy the elements in this row
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = other.Rows[r].Cols[c];
      }
    }
  }

  //
  // numrows
  //
  // Returns the # of rows in the matrix.  The indices for these rows
  // are 0..numrows-1.
  ///@return returns the number of rows 
  int numrows() const
  {

    return NumRows;
  }

  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  Note that the # of columns can be different
  // row-by-row since "jagged" rows are supported --- matrices are not
  // necessarily rectangular.
  ///@param r row specified
  int numcols(int r) const
  {
    if (r < 0 || r >= NumRows) // if r is not a valid number throw error
      throw out_of_range("mymatrix::numcols: row index out of range");

    return Rows[r].NumCols;

    //
    // TODO not
    //
  }

  //
  // growcols
  //
  /// @brief the # of columns in row r to at least C.  If row r contains
  /// fewer than C columns, then columns are added; the existing elements
  /// are retained and new locations are initialized to the default value
  /// for T.  If row r has C or more columns, then all existing columns
  /// are retained -- we never reduce the # of columns.
  ///
  /// Jagged rows are supported, i.e. different rows may have different
  /// column capacities -- matrices are not necessarily rectangular.
  ///@param r row specified
  ///@param c new # of columns in row specified
  void growcols(int r, int C)
  {
    // if either r or c are invalid values throw error
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::growcols: row");
    if (C < 1)
      throw invalid_argument("mymatrix::growcols: columns");

    // if the current number of columns of this row is larger then the specifed amount, dont edit the row
    if (C <= Rows[r].NumCols)
      return;
    // creates a new matrix with the new amount of columns in r row
    mymatrix<T> newMatrix(*this);
    newMatrix.Rows[r].NumCols = C;
    newMatrix.Rows[r].Cols = new T[C];

    for (int i = 0; i < newMatrix.NumRows; ++i)
    {
      if (i != r) // Copy rows other than row r
      {
        for (int j = 0; j < newMatrix.Rows[i].NumCols; ++j)
          newMatrix.Rows[i].Cols[j] = Rows[i].Cols[j];
      }
      else // Copy row r and add new columns
      {
        for (int j = 0; j < Rows[r].NumCols; ++j)
          newMatrix.Rows[r].Cols[j] = Rows[r].Cols[j];
        for (int j = Rows[r].NumCols; j < C; ++j)
          newMatrix.Rows[r].Cols[j] = T(); // Default-initialize new elements
      }
    }

    // Replace the old matrix with the new one
    *this = newMatrix;
  }

  //
  // grow
  //
  // Grows the size of the matrix so that it contains at least R rows,
  // and every row contains at least C columns.
  //
  // If the matrix contains fewer than R rows, then rows are added
  // to the matrix; each new row will have C columns initialized to
  // the default value of T.  If R <= numrows(), then all existing
  // rows are retained -- we never reduce the # of rows.
  //
  // If any row contains fewer than C columns, then columns are added
  // to increase the # of columns to C; existing values are retained
  // and additional columns are initialized to the default value of T.
  // If C <= numcols(r) for any row r, then all existing columns are
  // retained -- we never reduce the # of columns.
  ///@param R minimum number of rows to be grown to
  ///@param C minimum # of columns to be grown to
  void grow(int R, int C)
  {
    
    if (R < 1)
      throw invalid_argument("mymatrix::grow: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::grow: # of cols");
    addrows(R, C);
    for (int i = 0; i < NumRows; i++)
    {
      if (Rows[i].NumCols < C)
        growcols(i, C);
    }

    return;
  }


  //
  // size
  //
  // Returns the total # of elements in the matrix.
  //
  ///@return returns number of elements in matrix
  int size() const
  {
    int count = 0;
    for (int i = 0; i < NumRows; i++)
    {
      for (int j = 0; j < Rows[i].NumCols; j++)
      {
        count++;
      }
    }
    return count;
  }

  //
  // at
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M.at(r, c) = ...
  //    cout << M.at(r, c) << endl;
  //
  T &at(int r, int c) const
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::at: row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::at: col");



    //    T temp = {};  // we need to return something, so a temp for now:

    return Rows[r].Cols[c];
  }

  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M(r, c) = ...
  //    cout << M(r, c) << endl;
  //
  T &operator()(int r, int c) const
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::(): row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::(): col");


    //    T temp = {};  // we need to return something, so a temp for now:

    return Rows[r].Cols[c];
  }

  //
  // scalar multiplication
  //
  // Multiplies every element of this matrix by the given scalar value,
  // producing a new matrix that is returned.  "This" matrix is not
  // changed.
  //
  // Example:  M2 = M1 * 2;
  //
  mymatrix<T> operator*(T scalar)
  {
    //multiplies each value of the matrix with the scalar and stores it in the result matrix
    mymatrix<T> result(*this);
    for (int i = 0; i < NumRows; i++)
    {
      for (int j = 0; j < Rows[i].NumCols; j++)
      {
        result.Rows[i].Cols[j] *= scalar;
      }
    }

    //
    // TODO
    //

    return result;
  }

  //
  // matrix multiplication
  //
  // Performs matrix multiplication M1 * M2, where M1 is "this" matrix and
  // M2 is the "other" matrix.  This produces a new matrix, which is returned.
  // "This" matrix is not changed, and neither is the "other" matrix.
  //
  // Example:  M3 = M1 * M2;
  //
  // NOTE: M1 and M2 must be rectangular, if not an exception is thrown.  In
  // addition, the sizes of M1 and M2 must be compatible in the following sense:
  // M1 must be of size RxN and M2 must be of size NxC.  In this case, matrix
  // multiplication can be performed, and the resulting matrix is of size RxC.
  //
  mymatrix<T> operator*(const mymatrix<T> &other)
  {
    //rect other/temp determines if the matrix is rectangular
    bool rectother = false;
    bool recttemp = false;
    //first is used to determine if its the first iteration of the loop
    bool first = true;
    //holds the first row's# of columns 
    int colnum = 0;
    mymatrix<T> temp(*this);
    for (int i = 0; i < temp.NumRows; i++)
    {
      if (first)
      {
        first = false;
        colnum = temp.Rows[0].NumCols;
        continue;
      }
      if (colnum != temp.Rows[i].NumCols)//if the first rows # of columns doesnt match with the rest
      {

        throw runtime_error("mymatrix::*: this not rectangular");
      }
      else
      {
        recttemp = true;
      }
    }
    first = true;
    colnum = 0;
    for (int i = 0; i < other.NumRows; i++)
    {
      if (first)
      {
        first = false;
        colnum = other.Rows[0].NumCols;
        continue;
      }
      if (colnum != other.Rows[i].NumCols)//if the first rows # of columns doesnt match with the rest
      {
        throw runtime_error("mymatrix::*: other not rectangular");
      }
      else
      {
        rectother = true;
      }
    }
    if (rectother && recttemp)//if both matracies are rectangular
    {
      if (other.NumRows != temp.Rows[0].NumCols)//if they are not compatable for multiplication
      {
        throw runtime_error("mymatrix::*: size mismatch");
      }
    }
    //holds other matrix current index
    int othercol = 0;
    int otherrow = 0;

//holds temp matrix current index
    int tempcol = 0;
    int temprow = 0;

    T val = 0;
    //holds result matrix current index
    int rescol = 0;
    int resrow = 0;
    //both tr and oc count how many temp row's and other columns are remaining, respectively
    int tr = temp.NumRows;
    int oc = other.Rows[0].NumCols;

    int cout1 = 0;
    int cout2 = 0;
    mymatrix<T> result(temp.NumRows, other.Rows[0].NumCols);
    while (true)
    {

      while (true)
      {
        val += matrixmult(temp.Rows[temprow].Cols[tempcol], other.Rows[otherrow].Cols[othercol]);
        ++tempcol;
        ++otherrow;
        //if a entire row has been read,move others column over and multiply again
        if (tempcol == temp.Rows[0].NumCols)
        {
          result(resrow, rescol) = val;
          val = 0;
          ++rescol;
          ++othercol;
          tempcol = 0;
          otherrow = 0;
          ++cout1;
        }
        //if other has been fully multiplied, check if temp has a second row and if so continue
        if (cout1 == oc)
        {
          ++cout2;
          cout1 = 0;
          ++temprow;
          tempcol = 0;
          othercol = 0;
          otherrow = 0;
          ++resrow;
          rescol = 0;
        }
        if (cout2 == tr)
          return result;
      }
    }
  }

  //
  // both matrices must be rectangular for this to work:
  //

  //
  // TODO
  //
  // if (this matrix is not rectangular)
  //   throw runtime_error("mymatrix::*: this not rectangular");
  //
  // if (other matrix is not rectangular)
  //   throw runtime_error("mymatrix::*: other not rectangular");

  //
  // Okay, both matrices are rectangular.  Can we multiply?  Only
  // if M1 is R1xN and M2 is NxC2.  This yields a result that is
  // R1xC2.
  //
  // Example: 3x4 * 4x2 => 3x2
  //

  //
  // TODO
  //
  // if (this matrix's # of columns != other matrix's # of rows)
  //   throw runtime_error("mymatrix::*: size mismatch");

  //
  // Okay, we can multiply:
  //

  //
  // TODO
  //

  //
  // _output
  //
  // Outputs the contents of the matrix; for debugging purposes.
  //
  void _output()
  {
    for (int r = 0; r < this->NumRows; ++r)
    {
      for (int c = 0; c < this->Rows[r].NumCols; ++c)
      {
        cout << this->Rows[r].Cols[c] << " ";
      }
      cout << endl;
    }
  }
};
