#include<stdio.h>
int main()
{
	int i,j,a[3][3],b[3][3], isSymmetric;
	printf("Write the 9 element of matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	/*
     * Find transpose of matrix A
     */
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=a[j][i];
		}
	}


     /* Check whether matrix A is equal to its transpose or not
     */
	isSymmetric = 1;
    for(i=0; i<3 && isSymmetric; i++)
    {
        for(j=0; j<3; j++)
        {
            /* If matrix A is not equal to its transpose */
            if(a[i][j] != b[i][j])
            {
                isSymmetric = 0;
                break;
            }
        }
    }

    if(isSymmetric == 1)
    {
        printf("\nThe given matrix is Symmetric matrix: \n");

        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                printf("%d ", a[i][j]);
            }

            printf("\n");
        }
    }
    else
    {
        printf("\nThe given matrix is not Symmetric matrix.");
    }
    return 0;
}
