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
		printf("%f",mat[row][i]);

	}
}

int main(int argc, char** argv){
        InitData();
        int numel,from,row;
	printf("Nombre d'elements: ");
        scanf("%d", &numel);
	printf("Posició Vector d'inici: ");
        scanf("%d", &from);
	printf("Quina fila: ");
	scanf("%d", &row);
        int vect;
	printf("Quin vecotor? ");
        scanf("%d", &vect);

	//float* vector[3] = {V1, V2, V3};

	PrintVect(V1, from, numel );
	
	//PrintRow( float mat[row][i], int row, int from, int numel);
		
	return 0;
}
