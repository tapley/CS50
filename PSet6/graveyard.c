bool unload(void)
{
    node *previous_node;
    previous_node = root;
    
    int *previous_int;
    previous_int = malloc(sizeof(int)); 
    
    int counter = 0;
    node *unloader; 
     
    while (root != NULL)
    {               
        // actual program
        unloader = find_endnode(root, previous_node, previous_int);
        free(unloader->letter[*previous_int]);
        
        // just for keeping count
        counter++;
        printf("Counter:%i\n", counter);
    };    
    
    return true;
    printf("True");
}

node* find_endnode(node *startnode, node *previous_node, int *previous_int)
{
    int i = 0;
    while (i < 26)
    {
        if (startnode->letter[i] != NULL)
        {
            *previous_int = i;
            previous_node = startnode;
            return find_endnode(startnode->letter[i], previous_node, previous_int);       
        }
        else
        {
            i++;
        };  
    };
    return previous_node;
}
