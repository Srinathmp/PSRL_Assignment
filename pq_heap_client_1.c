#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	3
#include"pq_heap_1.h"

int main()
{
	int ch;
	int num;
	printf("Enter the number of elements\n");
	scanf("%d", &num);
	heap_t* queue = (heap_t*)malloc(sizeof(heap_t) * num);
	heap_t ele;
	int n = 0;
	int key;
	display_struct *disp = (display_struct*)malloc(sizeof(display_struct));
	

	delete_Min_struct *delete = (delete_Min_struct*)malloc(sizeof(delete_Min_struct));
	

	
	

	while(1)
	{	
		printf("1. Insert\n");
		printf("2. Delete minimum\n");	
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("5. Search for priority of element\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	
					printf("Enter the data and priority\n");	
					scanf("%d%d", &(ele.data), &(ele.priority));
					insert_struct *element = (insert_struct*)malloc(sizeof(insert_struct));
					element->heap = queue;
					element->n = &n;
					element->ele = ele;
					insert((void*)element);//queue, ele, &n);
					break;

			case 2: printf("Deleting min element\n");
					delete->heap = queue;
					delete->n = &n;
					delete_Min((void*)delete);//queue, &n);
					break;

			case 3: printf("The priority queue:\n");
					disp->heap = queue;
					disp->n = n;
					display((void*)disp);//queue, n);
					break;
			case 4: printf("Thank You!");
					return 0;
			case 5: printf("Enter the element whose priority you need\n");
					scanf("%d",&key);
					search_struct *search_key = (search_struct*)malloc(sizeof(search_struct));
					search_key->heap = queue;
					search_key->n = n;
					search_key->key = key;
					search((void*)search_key);
		}
	}
}
