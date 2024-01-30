#include <stdio.h>
static int n;
void standard_matrix_mul(int arr1[n][n] , int arr2[n][n], int result_arr[n][n], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            result_arr[i][j]=0;
            for (int k=0;k<n;k++){
                result_arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void display(int arr[n][n], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter size (n) of matrices: ");
    scanf("%d",&n);
    int arr1[n][n];
    int arr2[n][n];

    printf("Enter elements of Matrix-1:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("Enter element [%d][%d]: ",(i+1),(j+1));
            int temp;
            scanf("%d",&temp);
            arr1[i][j] = temp;
        }
    }

    printf("\nEnter elements of Matrix-2:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("Enter element [%d][%d]: ",(i+1),(j+1));
            int temp;
            scanf("%d",&temp);
            arr2[i][j] = temp;
        }
    }

    printf("\nMatrix-1:\n");
    display(arr1,n);

    printf("\nMatrix-2:\n");
    display(arr2,n);

    int resultArr[n][n];
    standard_matrix_mul(arr1,arr2,resultArr,n);

    printf("\nResultant Matrix:\n");
    display(resultArr,n);
}