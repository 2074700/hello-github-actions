#ifndef LYFTREE
#define LYFTREE 1

struct node
{
	struct node *left;
	struct node*right;
	struct node *up;
	int date;
};

extern struct node *book;

extern void initTree(struct node *nownode)
{
	nownode = (struct node *)malloc(sizeof(struct node));
	nownode->left = NULL;
	nownode->right = NULL;
	nownode->up = NULL;
	book = NULL;
}

extern int creat(struct node *nownode,const short int side,const int date)
{
	struct node *just;
	just = nownode;
	if (side == left)
	{
		nownode->left = (struct node *)malloc(sizeof(struct node));
		nownode = nownode->left;
	}
	else if (side == right)
	{
		nownode->right = (struct node *)malloc(sizeof(struct node));
		nownode = nownode->right;
	}
	else
	{
		return LYFFALSE;
	}
	nownode->up = just;
	nownode->right = NULL;
	nownode->right = NULL;
	nownode->date = date;
	nownode = just;
	return LYFTRUE;
}

extern void _findnode_(struct node *nownode,const int aimDate)
{
	if (book != NULL)
	{
		return;
	}
	if (nownode->date == aimDate)
	{
		book = nownode;
		return;
	}
	_findnode_(nownode->left,aimDate);
	_findnode_(nownode->right,aimDate);
}

extern int findNode(struct node *nownode,const int aimDate)
{
	struct node *just;
	just = nownode;
	for ( ; just->up != NULL; just = just->up) ;
	book = NULL;
	_findnode_(just,aimDate);
	if (book == NULL)
	{
		return LYFFALSE;
	}
	else
	{
		return LYFTRUE;
	}
}

extern int move(struct node *nownode,const int aimDate)
{
	_findnode_(nownode,aimDate);
	if (book == NULL)
	{
		return LYFFALSE;
	}
	else
	{
		nownode = book;
		return LYFTRUE;
	}
}

#endif
