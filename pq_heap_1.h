struct heap
{
	int data;
	int priority;
};
typedef struct heap heap_t;

typedef struct delete_Min_struct
{
	int* n;
	heap_t* heap;
}delete_Min_struct;

typedef struct insert_struct{
	heap_t* heap; 
	heap_t ele; 
	int* n;
}insert_struct;

typedef struct  display_struct
{
	heap_t* heap;
	int n;
}display_struct;

// void insert(heap_t*, heap_t, int*);
void* insert(void *);
void swap(heap_t*, heap_t*);
void heapify(heap_t*, int);
// void delete_Min(heap_t*, int*);
void* delete_Min(void*);
// void display(heap_t*, int);
void* display(void*);
