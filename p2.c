#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 512
float Mat[N][N]; 
float MatDD[N][N]; 
float V1[N]; 
float V2[N]; 
float V3[N]; 
float V4[N];

void InitData(){
int i,j;
srand(4422543);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}

void PrintVect( float vect[N], int from, int numel ){
        int i;
        for(i=from; i < from + numel; i++){
                printf("%f ", vect[i]);

        }
}

void PrintRow( float mat[N][N], int row, int from, int numel ){
	int i;
	for(i=from; i < from+numel; i++){
		printf("%f", mat[row][i]);

	}
}

void MultEscalar( float vect[N], float vectres[N], float alfa ){
        int i;
        for(i=0; i < N; i++){
		vectres[i] = vect[i] * alfa;
                printf("%f", vectres[i]);
        }
}

float Scalar( float vect1[N], float vect2[N] ){
        int i;
	float res;
	res = 0;
        for(i=0; i < N; i++){
		res += vect1[i] * vect2[i];
	}
	printf("%f", res);
	return res;
}

float Magnitude( float vect[N] ) {
        int i;
        float res,x;
        res = 0;
        for(i=0; i < N; i++){
                res += vect[i]*vect[i];
        }
	x = sqrt(res);
        printf("%f", x);
        return x;
}

int Ortogonal( float vect1[N], float vect2[N] ){
        int i;
        float res;
        res = 0;
        for(i=0; i < N; i++){
                res += vect1[i] * vect2[i];
        }
        if(res == 0){
		printf("Vect1 i Vect2 són ortogonals");
		return 1;
	}else{
		printf("Vect1 i Vect2 no són ortogonals");
		return 0;
	}
}

void Projection( float vect1[N], float vect2[N], float vectres[N] ){
        int i;
        float producte,res,numero,x;
        producte = 0;
        for(i=0; i < N; i++){
                producte += vect1[i]*vect2[i];
        }
	for(i=0; i < N; i++){
                res += vect2[i]*vect2[i];
        }
	x = sqrt(res);
	numero = producte / x;
        int j;
        for(j=0; j < N; j++){
                vectres[j] = vect2[j] * numero;
		printf("%f",vectres[j]);
        }
}

float Infininorm( float M[N][N] ){
	int i,j;
	float maxim,suma;
	maxim = 0;
	for(i=0; i<N; i++){
		suma=0;
		for(j=0;j<N;j++){
			suma += fabs(M[i][j]);
		}
	if(suma>maxim){
		maxim = suma;
		}
	}
	printf("%f",maxim);
	return maxim;
}

float Onenorm( float M[N][N] ){
        int i,j;
        float maxim,suma;
        maxim = 0;
        for(i=0; i<N; i++){
                suma=0;
                for(j=0;j<N;j++){
                        suma += fabs(M[j][i]);
                }
        if(suma>maxim){
                maxim = suma;
                }
        }
        printf("%f",maxim);
        return maxim;
}

float NormFrobenius( float M[N][N] ) {
	int i,j;
	float x,suma;
	suma = 0;
    	for(i = 0; i < N; i++) {
        	for(j = 0; j < N; j++) {
            	suma += M[i][j] * M[i][j];
        	}
    	}
    	x = sqrt(suma);
    	printf("%f",x);
    	return x;
}

int DiagonalDom( float M[N][N] ) {
    	int i, j;
    	for(i = 0; i < N; i++) {
        	float suma = 0;
        	for(j = 0; j < N; j++) {
            	if(i != j) {
                	suma += fabs(M[i][j]);
            	}	
        	}
        	if(fabs(M[i][i]) < suma) {
            		return 0; 
        	}
    		}
		return 1;
}

int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
	float x[N], res;
	if(!DiagonalDom(M)){
		return 0;
 	}	
	for (unsigned k = 0; k < iter; k++) {
		for (int i = 0; i < N; i++) {
			x[i] = vect[i];
			for (int j = 0; j < N; j++) {
				if (i != j) {
					x[i] -= M[i][j] * vect[j];
				}
			}	
			x[i] /= M[i][i];
			vectres[i]=x[i];	
		}	
	}
	return 1;
} 

int main(int argc, char** argv){
        InitData();
        int numel,from,row,vect,vect2,mat,iteracio;
	printf("Nombre d'elements: ");
        scanf("%d", &numel);
	printf("Posició Vector d'inici: ");
        scanf("%d", &from);
	printf("Quina fila: ");
	scanf("%d", &row);
	printf("Primer Vector: ");
        scanf("%d", &vect);
	printf("Segon Vector: ");
	scanf("%d",&vect2);
	printf("Quina matriu? (Mat = 1, MatDD = 2) ");
	scanf("%d", &mat);
	printf("Iteracions que vols: ");
	scanf("%d", &iteracio);


	float alfa;
	printf("Multiplicació: ");
        scanf("%f", &alfa);

	float* vector[3] = {V1, V2, V3};
	float* vectres;
	
	float(*M)[512];
	if(mat==1){
		M = Mat;
	}else if(mat==2){
		M = MatDD;
	}

//	printf("\n");
//	PrintVect(vector[vect-1], from, numel );
//	printf("\n");
//	PrintRow(M, row, from, numel);
//	printf("\n");
//	MultEscalar(vector[vect-1], V1 , alfa);
//	printf("\n");
//	Scalar(vector[vect-1],vector[vect2-1]);
//	printf("\n");
//	Magnitude(vector[vect-1]);
//	printf("\n");
//	Ortogonal(vector[vect-1],vector[vect2-1]);
//	printf("\n");
//	Projection(vector[vect-1],vector[vect2-1],V1);
//	printf("\n");
//	Infininorm(M);
//	printf("\n");
//	Onenorm(M);
//	printf("\n");
//	NormFrobenius(M);
//	printf("\n");
//	DiagonalDom(M);
//	if(DiagonalDom == 0){
//		printf("La diagonal no és dominant");
//	}
//	else{
//		printf("La diagonal és dominant");
//	}
//	printf("\n");
	Jacobi(M, vector[vect-1],V4,iteracio);
	if(Jacobi){
		PrintVect(V4,0,10);
	}
	printf("\n");



}
