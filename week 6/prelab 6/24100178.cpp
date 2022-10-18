#include <iostream>
using namespace std;

class MyMatrix
{
private:
    int **matrix;
    int rows;
    int cols;

public:
    // default constructor
    MyMatrix()
    {
        rows = 0;
        cols = 0;
        matrix = NULL;
    }
    // parameterized constructor
    MyMatrix(int **Array2D, int r, int c)
    {
        // initialise matrix to r and c
        rows = r;
        cols = c;
        // allocate memory for matrix
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        // copy values from Array2D to matrix using pointer notation
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                *(*(matrix + i) + j) = *(*(Array2D + i) + j);
            }
        }
    }
    // copy constructor
    MyMatrix(const MyMatrix &obj)
    {
        // initialise matrix to obj.rows and obj.cols
        rows = obj.rows;
        cols = obj.cols;
        // allocate memory for matrix
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        // copy values from obj.matrix to matrix using pointer notation
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                *(*(matrix + i) + j) = *(*(obj.matrix + i) + j);
            }
        }
    }
    // destructor
    ~MyMatrix()
    {
        // deallocate memory for matrix
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // overloads
    // overload = operator
    MyMatrix &operator=(const MyMatrix &obj)
    {
        // check if the object is being assigned to itself
        if (this != &obj)
        {
            // deallocate memory for matrix
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            // initialise matrix to obj.rows and obj.cols
            rows = obj.rows;
            cols = obj.cols;
            // allocate memory for matrix
            matrix = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = new int[cols];
            }
            // copy values from obj.matrix to matrix using pointer notation
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    *(*(matrix + i) + j) = *(*(obj.matrix + i) + j);
                }
            }
        }
        return *this;
    }

    // overload == operator
    bool operator==(const MyMatrix &obj)
    {
        // check if the object is being compared to itself
        if (this == &obj)
        {
            return true;
        }
        // check if the rows and cols are equal
        if (rows != obj.rows || cols != obj.cols)
        {
            return false;
        }
        // check if the values in the matrix are equal
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (*(*(matrix + i) + j) != *(*(obj.matrix + i) + j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    // overload + operator
    MyMatrix operator+(const MyMatrix &obj)
    {
        // check if the rows and cols are equal
        if (rows != obj.rows || cols != obj.cols)
        {
            string errorMessage =  "Error: The matrices are not the same size";
            __throw_invalid_argument(errorMessage.c_str());
        }
        // create a new matrix to store the sum
        int **sum = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            sum[i] = new int[cols];
        }
        // add the values from the matrices and store them in sum
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                *(*(sum + i) + j) = *(*(matrix + i) + j) + *(*(obj.matrix + i) + j);
            }
        }
        // create a new object to store the sum
        MyMatrix sumObj(sum, rows, cols);
        // deallocate memory for sum
        for (int i = 0; i < rows; i++)
        {
            delete[] sum[i];
        }
        delete[] sum;
        return sumObj;
    }

    // subtraction operator
    MyMatrix operator-(const MyMatrix &obj)
    {
        // check if the rows and cols are equal
        if (rows != obj.rows || cols != obj.cols)
        {
            string errorMessage =  "Error: The matrices are not the same size";
            __throw_invalid_argument(errorMessage.c_str());

        }
        // create a new matrix to store the difference
        int **difference = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            difference[i] = new int[cols];
        }
        // subtract the values from the matrices and store them in difference
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                *(*(difference + i) + j) = *(*(matrix + i) + j) - *(*(obj.matrix + i) + j);
            }
        }
        // create a new object to store the difference
        MyMatrix differenceObj(difference, rows, cols);
        // deallocate memory for difference
        for (int i = 0; i < rows; i++)
        {
            delete[] difference[i];
        }
        delete[] difference;
        return differenceObj;
    }

    // overload * operator
    MyMatrix operator*(const MyMatrix &obj)
    {
        // check if the cols of the first matrix is equal to the rows of the second matrix
        if (cols != obj.rows)
        {
            string errorMessage =  "Error: The matrices are not compatible for multiplication";
            __throw_invalid_argument(errorMessage.c_str());
        }
        // create a new matrix to store the product
        int **product = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            product[i] = new int[obj.cols];
        }
        // multiply the values from the matrices and store them in product
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
            {
                *(*(product + i) + j) = 0;
                for (int k = 0; k < cols; k++)
                {
                    *(*(product + i) + j) += *(*(matrix + i) + k) * *(*(obj.matrix + k) + j);
                }
            }
        }
        // create a new object to store the product
        MyMatrix productObj(product, rows, obj.cols);
        // deallocate memory for product
        for (int i = 0; i < rows; i++)
        {
            delete[] product[i];
        }
        delete[] product;
        return productObj;
    }

    // output operator
    friend ostream& operator<<(ostream &output, const MyMatrix &obj)
    {
        // output the values in the matrix
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
            {
                output << *(*(obj.matrix + i) + j) << " ";
            }
            output << endl;
        }
        return output;
    }

    friend istream& operator>>(istream &input, MyMatrix &obj)
    {
        // input the values in the matrix
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
            {
                input >> *(*(obj.matrix + i) + j);
            }
        }
        return input;
    }
};


int main(){

    MyMatrix m1;


    cin >> m1;

    cout << m1;

    return 0;
}