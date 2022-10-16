#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc != 2)
		return 0;
	
	const int N = atoi(argv[1]);
	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]); 
	int j, keep;
	for (int i = 1; i < N; i++)
	{
		keep = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < keep)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = keep;
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	return 0;
}
	
