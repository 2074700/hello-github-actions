extern void xmlNodeInit(struct xmlTreeNode *nownode)
{
	nownode = (struct xmlTreeNode *)malloc(sizeof(struct xmlTreeNode));
	nownode->up = NULL;
	nownode->attributeList = NULL;
	nownode->downNodeList = NULL;
}

extern void xmlNodeCreat(struct xmlTreeNode *nownode,const int side,const char date[])
{
	struct downNode *just;
	just = nownode->downNodeList;
	nownode->downNodeList = (struct downNode *)malloc(sizeof(struct downNode));
	(nownode->downNodeList)->next = just;
	(nownode->downNodeList)->down = (struct xmlTreeNode *)malloc(sizeof(struct xmlTreeNode));
	just = nownode;
	nownode = (nownode->downNodeList)->down;
	nownode->up  = just;
	nownode->attributeList = NULL;
	nownode->downNodeList = NULL;
	int i = 0;
	do
	{
		nownode->date[i] = date[i];
		++i;
	} while (date[i] != '\0');
}

extern void xmlAttributeCreat(struct xmlTreeNode *nownode,const char date[])
{
	struct attribute *just;
	just = nownode->attributeList;
	nownode->attributeList = (struct attribute *)malloc(sizeof(struct attribute));
	(nownode->attributeList)->next = just;
	int i = 0;
	do
	{
		(nownode->attributeList)->date[i] = date[i];
		++i;
	} while (date[i] != '\0');
}

extern struct attribute *xmlAttributeFind(const struct *nownode,const char date[])
{
	struct attribute *now,*just;
	for ( now = nownode->attributeList; ; now = now->next)
	{
		if (just = findString(now->date,date) != NULL)
		{
			return just;
		}
	}
	return NULL;
}
