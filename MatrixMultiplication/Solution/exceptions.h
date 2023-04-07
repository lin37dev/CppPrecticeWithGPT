#include <stdexcept>
#ifndef EXCEPTIONS_MATRIX_MALTIPLACATION_EXCEPTIONS_H
#define EXCEPTIONS_MATRIX_MALTIPLACATION_EXCEPTIONS_H

#endif //EXCEPTIONS_MATRIX_MALTIPLACATION_EXCEPTIONS_H

class FileNotExistException : public std::runtime_error{
public:
    explicit FileNotExistException(const std::string & m) :
    std::runtime_error(m){}
};
class FileOpenException : public std::runtime_error{
public:
    explicit FileOpenException(const std::string & m) :
            std::runtime_error(m){}
};
class DataMatchingException : public std::runtime_error{
public:
    explicit DataMatchingException(const std::string & m) :
            std::runtime_error(m){}
};
class MatrixDimensionException : public std::runtime_error{
public:
    explicit MatrixDimensionException(const std::string & m) :
            std::runtime_error(m){}
};
