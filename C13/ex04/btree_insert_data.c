#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *elem;

    elem = (t_btree *)malloc(sizeof(t_btree));
    elem->right = NULL;
    elem->left = NULL;
    elem->item = item;
    return (elem);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    if (!*root)
        *root = btree_create_node(item);
    else if (cmpf(item, data->item) < 0)
    {
        if ((*root)->left)
            btree_insert_data(&((*root)->left), item, cmpf);
        else
            (*root->left) = btree_create_node(item);
    }
    else
    {
        if ((*root)->right)
            btree_insert_data(&((*root)->right), item, cmpf);
        else
            (*root)->right = btree_create_node(item);
    }
}