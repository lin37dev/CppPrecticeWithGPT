Write a program that performs matrix multiplication between two matrices. The program should read data for the matrices from files. Implement exception handling to handle various possible error situations, and use the noexcept keyword to mark functions that do not throw exceptions.

Possible error situations include:

- File does not exist or cannot be opened.
- Data format error in the file, such as incomplete or invalid matrix data.
- Incompatible dimensions of the two matrices, making multiplication impossible.
- 
To accomplish this, follow these steps:

- Create a Matrix class, which includes a constructor that reads matrix data from a file. Use try and catch blocks to catch any exceptions that may occur during file operations.
- Write a MatrixMultiplication function that accepts two Matrix objects as arguments and returns the result matrix. In this function, handle the possible error of incompatible matrix dimensions, and use the noexcept keyword to indicate that this function does not throw exceptions.
- In the main function, call the Matrix constructor and the MatrixMultiplication function, and use try and catch blocks to catch any possible exceptions. Output appropriate error messages based on the caught exception type.
- If all operations are successful, output the result matrix.

Note: In actual code implementation, create custom exception classes to represent different types of errors.
