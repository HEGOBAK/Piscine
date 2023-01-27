#include "ft_btree.h"

int btree_level_count(t_btree *root)
{
    int height_l;
    int height_r;

    if (!root)
        return (0);
    height_l = btree_level_count(root->left);
    height_r = btree_level_count(root->right);
    if (height_l > height_r)
        return (height_l + 1);
    else
        return (height_r + 1);
}