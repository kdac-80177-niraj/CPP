#include<iostream>
using namespace std;

class Matrix{
    private:
        int m;
        int n;
        int **p;
        
    public:
        Matrix(int m,int n):m(m),n(n){
            p = new int *[m];
            for(int i = 0 ; i < m ; i++){
                p[i] = new int[n];
            }
        }

        Matrix(): m(0),n(0),p(nullptr){

        }

        void accept(){
            cout<<"Enter matrix elements: "<<endl;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0; j<n;j++){
                    cout<<"Enter elements at row "<< i+1 <<" and column " << j+1 << " : ";
                    cin>>p[i][j];
                }
            }

        }
        void print(){
            cout<<"Matrix: "<<endl;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    cout<<p[i][j];
                }
                cout<<endl;
            }
        }

        void add(Matrix *mat1,Matrix *mat2){
            
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    this->p[i][j] = mat1->p[i][j] + mat2->p[i][j];
                }
            }
            
        }
        void substract(Matrix *mat1,Matrix *mat2){
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    this->p[i][j] = mat1->p[i][j] - mat2->p[i][j];
                }
            }

        }
        void multiply(Matrix &mat1,Matrix &mat2){
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    p[i][j] = 0;
                    for(int k = 0 ; k < m ; k++){
                        p[i][j] += mat1.p[i][k]*mat2.p[k][j];
                    }
                }
            }
        }
        void transpose(Matrix* mat1){
            for(int i = 0 ; i < m ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    this->p[j][i] = mat1->p[i][j];
                }
            }
        }

        
        ~ Matrix(){
            for(int i = 0 ; i < m ; i++){
                    delete[] p[i];
                }
                delete[] p;
        }
};

int main(){
    int m,n;
    cout<<"Enter rows for 1st matrix: ";
    cin>>m;
    cout<<"Enter columns for 1st matrix: ";
    cin>>n;

    Matrix mat1(m,n);
    mat1.accept();

    cout<<"Enter rows for 2nd matrix: ";
    cin>>m;
    cout<<"Enter columns for 2nd matrix: ";
    cin>>n;

    Matrix mat2(m,n);
    mat2.accept();

    cout<<"First Matrix: "<<endl;
    mat1.print();

    cout<<"Second Matrix: "<<endl;
    mat2.print();

    Matrix mat3(m,n);
    mat3.add(&mat1,&mat2);
    cout<<"result of addition: "<<endl;
    mat3.print();

    mat3.substract(&mat1,&mat2);
    cout<<"Result of substraction is: "<<endl;
    mat3.print();

    mat3.multiply(mat1,mat2);
    cout<<"Result of multiplication is: "<<endl;
    mat3.print();

    mat3.transpose(&mat1);
    cout<<"Result of transpose is: "<<endl;
    mat3.print();

    mat3.transpose(&mat2);
    cout<<"Result of transpose is: "<<endl;
    mat3.print();


    


    return 0;
}