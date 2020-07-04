#include<stdio.h>
#include"pq_heap_1.h"

void* delete_Min(void* delete_Min_struct_object)//heap_t* heap, int* n)
{
	delete_Min_struct *delete_Min_object = (delete_Min_struct*)delete_Min_struct_object;
	// heap_t *heap = delete_Min_object->heap;
	// int *n = delete_Min_object->n;
	if(*delete_Min_object->n == 0){
		printf("Queue is empty!\n");
		return 0;
	}
	delete_Min_object->heap[0] = delete_Min_object->heap[*delete_Min_object->n - 1];
	(*delete_Min_object->n)--;
	heapify(delete_Min_object->heap, *delete_Min_object->n);
}

void swap(heap_t* i, heap_t* j)
{
	heap_t temp = *i;
	*i = *j;
	*j = temp;
}

void heapify(heap_t* heap, int n)
{
	int i;
	int j;
	i = 0;
	j = 2 * i + 1;
	int flag = 0;

	while(j <= n && !flag)
	{
		if((j + 1) < n && heap[j + 1]. priority < heap[j]. priority)
		{
			++j;
		}
		if(heap[i].priority > heap[j].priority)
		{
			swap(&heap[i], &heap[j]);
			//heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			flag = 1;
		}
	}
} 

void* insert(void *insert_struct_object)//heap_t* heap, heap_t ele, int* n)
{
	insert_struct *insert_object = (insert_struct*)insert_struct_object;
	// heap_t* heap = insert_object->heap; 
	// heap_t ele = insert_object->ele; 
	// int* n = insert_object->n;


	int i, j;
	i = *insert_object->n;
	insert_object->heap[i] = insert_object->ele;
	(*insert_object->n)++;
	j = (i - 1) / 2; //find parent and store in j

	while((i > 0) && insert_object->heap[j].priority > insert_object->heap[i].priority)
	{
		swap(&insert_object->heap[i], &insert_object->heap[j]);
		//heap[i] = heap[j];
		i = j;
		j = (i - 1)/2; //update parent
	}
}

void* display(void *display_struct_object)//heap_t* heap, int n)
{
	display_struct *display_object = (display_struct*)display_struct_object;
	// heap_t* heap = display_object->heap;
	int n = display_object->n;
	heapSort(display_object->heap,n);
	for(int i = 0; i < n; ++i)
	{
		printf("element = %d priority = %d\n", display_object->heap[i].data, display_object->heap[i].priority);
	}
	printf("\n");
}

void my_heapify(heap_t* heap, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && heap[l].priority > heap[largest].priority) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && heap[r].priority > heap[largest].priority) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&heap[i], &heap[largest]); 
  
        // Recursively heapify the affected sub-tree 
        my_heapify(heap, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(heap_t* heap, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        my_heapify(heap, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(&heap[0], &heap[i]); 
  
        // call max heapify on the reduced heap 
        my_heapify(heap, i, 0); 
    } 
} 

void* search(void *search_struct_object)//heap_t* heap, int n,int key)
{	
	int found = 0;

	search_struct *search_object = (search_struct*)search_struct_object;
	// printf("value of n =%d\n",search_object->n);
	// printf("the key =%d\n", search_object->key);
	for(int i = 0; i < search_object->n; ++i)
	{
		// printf("%d\n",search_object->heap[i].data);
		if(search_object->heap[i].data == search_object->key){
			found =1;
			printf("priority of %d is %d\n",search_object->heap[i].data,search_object->heap[i].priority);
		}
	}
	if (found == 0)
	{
		printf("element does not exist in queue\n");
	}
}