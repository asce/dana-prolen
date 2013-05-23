typedef struct node_def {
  int number; 
  struct node_def *next;
} node;

// Start Pointer

node* startPtr; 


node *search (node* start, int value) {

  node* cur;

  for (cur = start; cur != NULL; cur = cur->next) {

    if (cur->number == value) return cur;

  }

  return NULL; 

}
node* mallocNode (){
  node * n;
  if ((n = malloc(sizeof(node))) == NULL) {

    printf("Can not allocate node\n");

    exit(1);

  }else{
  
    n->next=NULL;
    return n;
  
  }
}

void showNodes (node* start) {
  node* cur;
  for (cur = start; cur != NULL; cur = cur->next) {

    printf(" %i ",cur->number);

  }
  printf("\n");
}


void freeNode (node* start) {

  node* prevptr = NULL;
  node *node2bfree = NULL;
  node2bfree = start;

  while(node2bfree != NULL) {
    prevptr = node2bfree;
    node2bfree = node2bfree->next;
    printf("Free %i\n",prevptr->number);
    free (prevptr);
  }

}



node *addNode (node* start, int value) {

  node* prevptr = NULL;

  node* ptr = NULL;

  node* node2badd, cur;
 
  // Check where to insert 
  for (ptr = start; ptr != NULL; ptr = ptr->next) {
    prevptr = ptr;
  }

  // Create new node
  if ((node2badd = malloc(sizeof(node))) == NULL) {

    perror ("Can not allocate node\n");

    exit(1);

  } 

  node2badd->number = value;

  node2badd->next = NULL;

  // Add Node to the list

  if (prevptr == NULL) {

    // Start of List or empty list
    start = node2badd;

    node2badd->next = ptr; 

  } else {

    node2badd->next = ptr;

    prevptr->next = node2badd;

  }

  return start;

}
int elems_number(node* l1){

  node *actual_node = l1;
  int count = 0;
  while(actual_node != NULL) {
    actual_node = actual_node->next;
    count++;
  }
  return count;
}
int isEqualNodeList(node* l1,node* l2){
  int distintas=0;
  node* actual_l1=l1;
  node* actual_l2=l2;
  if(actual_l1==NULL && actual_l2==NULL){
    printf("WARNING: Se están comparando listas vacías\n");
    return 1;
  }else if(actual_l1==actual_l2){
    printf("WARNING: Ambas listas tienen la misma dir. de memoria\n");
    return 1;
  }else if(elems_number(l1)!=elems_number(l2)){
    return 0;
  }else{//Mismo numero de elementos
    while(actual_l1->next!=NULL){
      if(actual_l1->number!=actual_l2->number){
	return 0;
      }
      actual_l1=actual_l1->next;
      actual_l2=actual_l2->next;
    }
  }
  return 1;
}

int checkEqualNodeList(node* l1,node*l2){
  int equal = isEqualNodeList(l1,l2);
  if(equal == 0){
    printf("Las listas son distintas\n");
    showNodes(l1);
    showNodes(l2);
  }
  return equal;
  
}
