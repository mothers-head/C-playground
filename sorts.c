#include <stdio.h>
#include <stdlib.h>

#define NUM_NON_LIST_ELEMS 	 1
#define ERR_NO_ELEMS 		-1
#define ERR_BAD_ELEMS		-2

int getList(int num_elems, char** argv, int* list);

void bubble(int num_elems, int* list);
void merge(int num_elems, int* list);
void print_list(int num_elems, int* list); 

int main(int argc, char* argv[]) {

	if(argc <= NUM_NON_LIST_ELEMS){	
		fprintf(stderr, "error - no elements found\n");
		return ERR_NO_ELEMS;
	}
	
	int num_elems = argc - NUM_NON_LIST_ELEMS;
	int* list = malloc(sizeof(int) * num_elems);
	int err = getList(num_elems, argv, list);
	
	if(err != 0) {
		fprintf(stderr, "error - reading input failed");
		return err;
	}

	printf("%i element(s) succsfully read\n", num_elems);

	print_list(num_elems, list);
	
	bubble(num_elems, list);
	//merge(num_elems, list);	
	print_list(num_elems, list);
}


int getList(int num_elems, char* argv[], int* list) {
	int err = 0;
	for(int i = 0; i < num_elems; i++) {
		err = sscanf(argv[i + NUM_NON_LIST_ELEMS], "%i", &list[i]);
		if(err != 1) {
			fprintf(stderr, "error - problem reading list elements\n");
			return ERR_BAD_ELEMS;
		}
	}
	return 0;
}

void bubble(int num_elems, int* list) {

	for(int i = 0; i < num_elems; i++){
		for(int j = 0; j < num_elems; j++){
			if(list[i] < list[j]) {
				int tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;	
			}
		}
	}
}


void print_list(int num_elems, int* list){

	for(int i = 0; i < num_elems; i++) {
		printf("%i ", list[i]);
	}
	printf("\n");

}





