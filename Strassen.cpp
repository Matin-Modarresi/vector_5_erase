#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

const int N = 9;     //Define the size of the Matrix
  
template<typename T>
void Strassen(int n, T A[][N], T B[][N], T C[][N]); 

void Matrix_creat(int , int , int [][N]);

template<typename T>
void Matrix_Multiply(T A[][N], T B[][N], T C[][N]);

template<typename T>
void input(int n, T p[][N]);

template<typename T>
void output(int n, T C[][N]);

int main() {

    int A[N][N],B[N][N],C[N][N];    
    cout << "\n\n\n";

    for(int i=0; i<N; i++) {
       for(int j=0; j<N; j++) {
          A[i][j] = 0;
          B[i][j] = 0; 
		  C[i][j] = 0;  
       }        
    }
    
    Matrix_creat(1,20,A);
    Matrix_creat(1,20,B);
   
    output(N,A);
    cout << "\n\n";
    output(N,B);
     cout << "\n\n";
     Strassen(N, A, B, C);
    

    output(N, C);
    
    system("pause");
    return 0;
}


void Matrix_creat(int a, int b, int m[][N])
{
	for(int i=0 ; i<N ; i++)
	 for(int j=0 ; j<N ; j++)
	 {
	 	m[i][j] = rand()%(b-a+1)+a;
	 }
}

/**The Input Function of Matrix*/
template<typename T>
void input(int n, T p[][N]) {
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cin>>p[i][j];
        }        
     }
}


template<typename T>
void output(int n, T C[][N]) {
     for(int i=0; i<n; i++) {
     	
        for(int j=0; j<n; j++) {
           cout << setw(5)  <<C[i][j];        
        }  
		
		cout << endl;      
     }     
}

/**Matrix Multiplication as the normal algorithm*/
template<typename T>
void Matrix_Multiply(T A[][N], T B[][N], T C[][N]) {  //Calculating A*B->C
     for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {      
           for(int t=0; t<2; t++) {
              C[i][j] += A[i][t]*B[t][j];        
           }  
        }        
     }
}

/**Matrix Addition*/
template <typename T>
void Matrix_Add(int n, T X[][N], T Y[][N], T Z[][N]) {
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           Z[i][j] = X[i][j] + Y[i][j];        
        }        
     }     
}

/**Matrix Subtraction*/
template <typename T>
void Matrix_Sub(int n, T X[][N], T Y[][N], T Z[][N]) {
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           Z[i][j] = X[i][j] - Y[i][j];        
        }        
     }     
}


template <typename T> 
void Strassen(int n, T A[][N], T B[][N], T C[][N]) {
     T A11[N][N], A12[N][N], A21[N][N], A22[N][N];
     T B11[N][N], B12[N][N], B21[N][N], B22[N][N];     
     T C11[N][N], C12[N][N], C21[N][N], C22[N][N];
     T M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
     T AA[N][N], BB[N][N];
     
     for(int i=0 ; i<N ; i++)
      for(int j=0 ; j<N ; j++)
      {
      	A11[i][j] = 0, A12[i][j] = 0, A21[i][j] = 0, A22[i][j] = 0;
      	B11[i][j] = 0, B12[i][j] = 0 , B21[i][j] = 0, B22[i][j] = 0;  
      	C11[i][j] = 0, C12[i][j] = 0 , C21[i][j] = 0, C22[i][j] = 0;
      	M1[i][j]=0, M2[i][j]=0, M3[i][j]=0, M4[i][j]=0, M5[i][j]=0, M6[i][j]=0, M7[i][j]=0;
      	AA[i][j]=0 , BB[i][j]=0;
	  }
     if(n <= 2) {  //2-order
        Matrix_Multiply(A, B, C);
		cout << "\n\n n<=2 " << n << "\n\n"; 
		output(n,C);    
		cout << '\n';
                } 
	 
	 else {
            int k = 1;
           	if(n%2==0)
           	  k=0;
    
          for(int i=0; i<n/2+k; i++) {
           for(int j=0; j<n/2+k; j++) {
			   
              A11[i][j] = A[i][j];
			  B11[i][j] = B[i][j];
			  
			  if(j+n/2+k < n ){
			  A12[i][j] = A[i][j+n/2+k];
			  B12[i][j] = B[i][j+n/2+k];
		      }
		      if(i+n/2+k < n)
		      {
			  A21[i][j] = A[i+n/2+k][j];
			  B21[i][j] = B[i+n/2+k][j];
		      }
			  if(j+n/2+k < n && i+n/2+k <n){
			  
              A22[i][j] = A[i+n/2+k][j+n/2+k];
              B22[i][j] = B[i+n/2+k][j+n/2+k]; 
		       }
		
              
		 }
                  
        }  
        
        
        cout << setw(25) << left << "A11 : " << setw(25) << left << "A12 : " ;
        cout << setw(25) << left << "A21 : " << setw(25) << left << "A22 : " ;
        
        cout << "\n";
        
        for(int i = 0 ; i<n ; i++)
        {
        	
        	 
        	 for(int j=0 ; j<n ; j++)
        	 {
			 if(j==n-1)
        	  cout << left << setw(10) << A11[i][j];
        	  
        	  else
        	  cout << left << setw(3) << A11[i][j] ;
        	 }
             
        	 
        	  for(int j=0 ; j<n ; j++)
        	  {
        	  if(j==n-1)
        	  cout << left << setw(10) << A12[i][j];
        	  
        	  else 
			  cout << left << setw(3) <<  A12[i][j] ;
              }
        	  
        	  for(int j=0 ; j<n ; j++) 
        	  {  
			  if(j==n-1)
        	  cout << left << setw(10) << A21[i][j];
        	  
			  else 
        	  cout <<left << setw(3) <<  A21[i][j];
        	 }
        	
        	  for(int j=0 ; j<N ; j++)
        	  {
			  if(j==n-1)
        	  cout << left << setw(10) <<  A22[i][j];
        	  
        	  else 
        	  cout << left << setw(3) << A22[i][j];
              }
        	  cout << endl;
		}
        
        cout << "\n\n";
        
        cout << setw(25) << left << "B11 : " << setw(25) << left << "B12 : " ;
        cout << setw(25) << left << "B21 : " << setw(25) << left << "B22 : " ;
        cout << "\n";
         for(int i = 0 ; i<n ; i++)
        {
        	
        	 
        	 for(int j=0 ; j<n ; j++)
        	 {
			 if(j==n-1)
        	  cout << left << setw(10) << B11[i][j];
        	  
        	  else
        	  cout << left << setw(3) << B11[i][j] ;
        	 }
             
        	 
        	  for(int j=0 ; j<n ; j++)
        	  {
        	  if(j==n-1)
        	  cout << left << setw(10) << B12[i][j];
        	  
        	  else 
			  cout << left << setw(3) <<  B12[i][j] ;
              }
        	  
        	  for(int j=0 ; j<n ; j++) 
        	  {  
			  if(j==n-1)
        	  cout << left << setw(10) << B21[i][j];
        	  
			  else 
        	  cout <<left << setw(3) <<  B21[i][j];
        	 }
        	
        	  for(int j=0 ; j<n ; j++)
        	  {
			  if(j==n-1)
        	  cout << left << setw(10) <<  B22[i][j];
        	  
        	  else 
        	  cout << left << setw(3) << B22[i][j];
              }
        	  cout << endl;
		}
        
        cout << "\n";
        
		
       //Calculate M1 = (A0 + A3) × (B0 + B3)
        cout << "\n\nM1 = (A0 + A3) * (B0 + B3) \n\n";
        Matrix_Add(n, A11, A22, AA);
        Matrix_Add(n, B11, B22, BB);
        
         output(n,AA);
         cout << "\n\n";
         output(n,BB);
        Strassen(n/2+k, AA, BB, M1);
        
       // cout << "\n\n-------------------------------------------------------------------------------\n\n";
        
        //Calculate M2 = (A2 + A3) × B0
        cout << "\n\nM2 = (A2 + A3) * B0\n\n";
        Matrix_Add(n, A21, A22, AA);
        output(n,AA);
        cout << "\n\n";
        Strassen(n/2+k, AA, B11, M2);
        
        //Calculate M3 = A0 × (B1 - B3)
        cout << "\n\nM3 = A0 * (B1 - B3)\n\n";
        Matrix_Sub(n, B12, B22, BB);
        output(n,BB);
        cout << "\n\n";
        Strassen(n/2+k, A11, BB, M3);
        
        //Calculate M4 = A3 × (B2 - B0)
        cout << "\n\nM4 = A3 * (B2 - B0)\n\n";
        Matrix_Sub(n, B21, B11, BB);
        output(n,BB);
        cout << "\n\n";
        Strassen(n/2+k, A22, BB, M4);
        
        //Calculate M5 = (A0 + A1) × B3
        cout << "\n\n M5 = (A0 + A1) * B3\n\n";
        Matrix_Add(n, A11, A12, AA);
        output(n,AA);
        cout << "\n\n";
        Strassen(n/2+k, AA, B22, M5);
        
        //Calculate M6 = (A2 - A0) × (B0 + B1)
        cout << "\n\nM6 = (A2 - A0) * (B0 + B1)\n\n";
        Matrix_Sub(n, A21, A11, AA);
        output(n,AA);
        cout << "\n\n";
        Matrix_Add(n, B11, B12, BB);
        output(n,BB);
        cout << "\n\n";
        Strassen(n/2+k, AA, BB, M6);
        
        //Calculate M7 = (A1 - A3) × (B2 + B3)
        cout << "\n\nM7 = (A1 - A3) * (B2 + B3)\n\n";
        Matrix_Sub(n, A12, A22, AA);
        output(n,AA);
        cout << "\n\n";
        Matrix_Add(n, B21, B22, BB);
        output(n,BB);
        cout << "\n\n";
        Strassen(n/2+k, AA, BB, M7);
        
        //Calculate C0 = M1 + M4 - M5 + M7
        Matrix_Add(n, M1, M4, AA);
        Matrix_Sub(n, M7, M5, BB);
        Matrix_Add(n, AA, BB, C11);
        
        cout << "C0 :\n\n";
        output(n,C11);
        cout << "\n\n";
        
        //Calculate C1 = M3 + M5
        Matrix_Add(n, M3, M5, C12);
         cout << "C1 : \n\n";
		 output(n,C12);
		 cout << "\n\n";       
		 
		  
        //Calculate C2 = M2 + M4
        Matrix_Add(n, M2, M4, C21);
        cout << "C2 : \n\n";
        output(n,C21);
        cout << "\n\n";
        
        
        //Calculate C3 = M1 - M2 + M3 + M6
        Matrix_Sub(n, M1, M2, AA);
        Matrix_Add(n, M3, M6, BB);
        Matrix_Add(n, AA, BB, C22);
         cout << "C3 :\n\n";
         output(n,C22);
         cout << "\n\n";
        //Set the result to C[][N]
        
         for(int i=0; i<n/2 + k; i++) {
           for(int j=0; j<n/2 + k; j++) {
           	
              C[i][j] = C11[i][j];
              if(i+n/2+k < n && j+n/2+k)
              C[i+n/2+k][j+n/2+k] = C22[i][j];
			  if(j+n/2+k < n)   
              C[i][j+n/2+k] = C12[i][j];
              if(i+n/2+k < n)
		      C[i+n/2+k][j] = C21[i][j];
		     
		     
              
             
	      } 
        }  
        
        output(n,C);
        cout << "\n\n";
     }
}
