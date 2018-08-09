/* HASHING - LINEAR AND QUADRATIC PROBING */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int tsize;
int **hash;

int hasht(int key)
{
	int i;
	i = key%tsize;
	return i;
}

//-------LINEAR PROBING-------
int rehashl(int key)
{
	int temp = hasht(key);
	while (hash[temp][1] != 0 && hash[temp][1] != -1)
		temp = (temp + 1) % tsize;
	return temp;
}

//-------QUADRATIC PROBING-------
int rehashq(int key)
{
	int j = 1;
	int temp = hasht(key);
	while (hash[temp][1] != 0 && hash[temp][1] != -1)
	{
		temp = (temp + (j*j)) % tsize;
		j++;
	}
	return temp;
}

int rehashr(int key)
{
	int temp = hasht(key);
	srand(0);
	while (hash[temp][1] != 0 && hash[temp][1] != -1)
	{
		temp = (temp + rand()) % tsize;
		printf("while temp is %d\n", temp);
	}
	return temp;
}

void deleteHash(int key)
{
	int temp = hasht(key);
	srand(0);
	while (hash[temp][0] != key)
	{
		temp = (temp + rand()) % tsize;
		printf("while temp is %d\n", temp);
	}
	hash[temp][1] = -1;
}

int main()
{
	int arr[20];
	int temp;
	int n;//the number of elements
	scanf("%d %d", &n, &tsize);
	hash = (int**)malloc(sizeof(int*)*tsize);
	for (int i = 0; i < tsize; i++)
		hash[i] = (int*)malloc(3 * sizeof(int));//已知第二维的二维数组动态分配
	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);//scan the numbers
	for (int i = 0; i<tsize; i++)
	{
		hash[i][0] = -1;
		hash[i][1] = 0;//0 is empty, 1 is occupied, -1 is deleted
	}
	for (int i = 0; i<n; i++)
	{
		temp = rehashr(arr[i]);
		printf("final temp is %d\n", temp);
		hash[temp][0] = arr[i];
		hash[temp][1] = 1;
	}//add the number to hash tableSize
	deleteHash(5);
	for (int i = 0; i < tsize; i++)
		printf("\n Element at position %d: %d %d", i, hash[i][0], hash[i][1]);
	return 0;
}
