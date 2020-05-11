#ifndef LYFXML
#define LYFXML 1

struct downNode
{
	struct downNode *next;
	struct xmlTreeNode *down;
};

struct attribute
{
	struct attribute *next;
	char date[64];            //节点里的数据用数组还是字符串？？？
};

struct xmlTreeNode
{
	struct downNode *downNodeList;
	struct attribute *attributeList;
	struct xmlTreeNode *up;
	char date[256];
};

#include "xmlControl.cpp"
#include "xmlRead.cpp"
#include "xmlWrite.cpp"

#endif

