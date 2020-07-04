a.out : pq_heap_client_1.o pq_heap_server_1.o
	gcc pq_heap_client_1.o pq_heap_server_1.o

pq_heap_client.o : pq_heap_client_1.c pq_heap_1.h
		gcc -c pq_heap_client_1.c

pq_heap_server.o : pq_heap_server_1.c pq_heap_1.h
		gcc -c pq_heap_server_1.c
