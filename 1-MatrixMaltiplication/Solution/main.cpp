#include <iostream>
#include "exceptions.h"
#include <fstream>
#include <sstream>
class Matrix;
class Dim{
public:
    Dim(int c, int r) : column(c), row(r){}
    Dim(std::ifstream & file){
        column = 0;
        row = 0;
        std::string line;
        bool first_row = true;
        while(getline(file,line)){
            ++row;
            std::istringstream rs(line);
            int number = 0;
            if(first_row){
                while(rs >> number) {
                    ++column;
                }
                first_row = false;
            }
        }
        file.clear();
        file.seekg(0, std::ios::beg);
        std::cout << "The matrix is " << column << ", "
        << row << ". " << std::endl;
    }
    explicit Dim(Matrix *);
    unsigned column_is()const{
        return column;
    }
    unsigned row_is()const{
        return row;
    }
    void display_dim(){
        std::cout << "The column is: " << column <<
        " and, the row is: " << row << std::endl;
    }
    ~Dim() = default;
private:
    unsigned column;
    unsigned row;
};

class Matrix{
public:
    Matrix() = default;
    Matrix(const Dim & d) :
    COL(d.column_is()), ROW(d.row_is()), matrix(new int*) {
        for(int i = 0; i < ROW; ++i){
            matrix[i] = new int[COL];
        }
    }
    Matrix(const Dim &, std::ifstream &);
    unsigned int get_m_col()const{
        return COL;
    }
    unsigned int get_m_row()const{
        return ROW;
    }
    int * * get_ptr()const{
        return matrix;
    }
    void display_matrix(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                std::cout << this->get_ptr()[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    ~Matrix() {
        for (int i = 0; i < ROW; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
private:
    unsigned int COL;
    unsigned int ROW;
    int * * matrix;
};
Dim::Dim(Matrix * m){
    column = m->get_m_col();
    row = m->get_m_row();
}
bool multipliable(const Matrix & m1, const Matrix & m2){
    return m1.get_m_col() == m2.get_m_row();
}
Dim multiplied_dim(const Matrix & m1, const Matrix & m2){
    if(multipliable(m1, m2)) return Dim(m1.get_m_row(), m2.get_m_col());
    else throw MatrixDimensionException("These two matrices can not perform multiplication.");
}
int get_number(const Matrix & m1, const Matrix & m2, const int cc, const int rr){
    int result = 0;
    Dim temp = multiplied_dim(m1, m2);
    if(cc < temp.column_is() && rr < temp.row_is()){
        for(int i = 0; i < m1.get_m_col(); ++i){
            result = (m1.get_ptr()[cc][i]) * (m2.get_ptr()[i][rr]) + result;
        }
    }
    return result;
}
Matrix operator*(const Matrix & m1, const Matrix & m2) noexcept{
    Dim new_dim = multiplied_dim(m1, m2);
    Matrix new_matrix = Matrix(new_dim);
    for(int i = 0; i < new_matrix.get_m_row(); ++i){
        for(int j = 0; j < new_matrix.get_m_col(); ++j){
            new_matrix.get_ptr()[i][j] = get_number(m1, m2, j, i);
        }
    }
    return new_matrix;
}
bool operator!=(const Dim & n, const Dim & m) {
    return n.row_is() != m.row_is() || n.column_is() != m.column_is();
}
Matrix::Matrix(const Dim & dim, std::ifstream & fs) :
COL(dim.column_is()), ROW(dim.row_is()), matrix(new int*[ROW]){
    if(fs){
        if(Dim(this) != Dim(fs))
            throw DataMatchingException("The file data do not fit.");
        else{
            std::string line1;
            int idx_row = 0;
            while(getline(fs, line1)){
                int idx_col = 0;
                int number = 0;
                std::istringstream r(line1);
                matrix[idx_row] = new int(COL);
                while(r >> number){
                    matrix[idx_row][idx_col] = number;
//                    std::cout << matrix[idx_row][idx_col] << " ";
                    ++idx_col;
                }
                ++idx_row;
            }
            fs.close();
        }
    }else throw FileNotExistException("The file can not be opened.");
}
int main() {
    std::ifstream in_file_1
    ("matrix-1");
    std::ifstream in_file_2
    ("matrix-2");
    try {
        Matrix one = Matrix(Dim(7, 7), in_file_1);
        one.display_matrix();
        Matrix two = Matrix(Dim(7, 7), in_file_2);
        two.display_matrix();
        std::cout << std::endl;
        (one * two).display_matrix();
    }catch(const DataMatchingException & e){
        std::cerr << "Error: " << e.what() << std::endl;
    }catch(const FileNotExistException & e){
        std::cerr << "Error: " << e.what() << std::endl;
    }catch(const MatrixDimensionException & e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
