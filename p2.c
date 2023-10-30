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

int main(int argc, char** argv){
        InitData();
        int numel,from,row,vect;
	printf("Nombre d'elements: ");
        scanf("%d", &numel);
	printf("Posició Vector d'inici: ");
        scanf("%d", &from);
	printf("Quina fila: ");
	scanf("%d", &row);
	printf("Quin vecotor? ");
        scanf("%d", &vect);

	float alfa;
	printf("Multiplicació: ");
        scanf("%e", &alfa);

	float* vector[3] = {V1, V2, V3};
	float* vectres;

//	PrintVect(vector[vect-1], from, numel );
//	printf("\n");
//	PrintRow(Mat, row, from, numel);
	//printf("\n");
	MultEscalar(vector[vect-1], vectres, alfa);
	printf("\n");
		
	return 0;
}
