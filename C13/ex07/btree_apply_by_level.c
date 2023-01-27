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

typedef struct s_temp
{
    int level;
    int level_i;
    int *is_first;
    void (*applyf)(void *item, int current_level, int is_first_elem);
} t_temp

void btree_apply_at_level(t_btree *root, t_temp self)
{
    if (!root)
        return;
    if (!self.level_i)
    {
        self.applyf(root->item, self.level, *self.if_first);
        if (*self.is_first)
            *self.is_first = 0;
    }
    else if (self.level_i > 0)
    {
        self.level_i--;
        self.applyf(root->left, self);
        self.apply(root->right, self);
    }
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
    int level;
    int is_first;
    int count;
    t_temp self;

    level = 0;
    count = btree_level_count(root);
    while (level < count)
    [
        is_first = 1;
        self.applyf = applyf;
        self.level = level;
        self.level_i = level;
        self.is_first = &is_first;
        btree_apply_at_level(root, self);
        level++;
    ]
}