#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
NODE create(NODE root)
{
	int i, n, item;
	NODE temp, prev, cur;
	printf("Enter the number of nodes\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		temp = (NODE)malloc(sizeof(struct node));
		printf("\nEnter thr node value\n");
		scanf("\t%d", &item);
		temp->info = item;
		temp->llink = NULL;
		temp->rlink = NULL;
		if (root == NULL)
		{
			root = temp;
		}
		else
		{
			cur = root;
			prev = NULL;
			while (cur != NULL)
			{
				prev = cur;
				if (item < cur->info)
					cur = cur->llink;
				else
					cur = cur->rlink;
			}
			if(item < prev->info)
				prev->llink = temp;
			else
				prev-> rlink = temp;
		}
	}
	return root;
}
void inorder(NODE root) //R always after L
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->llink);
		printf("\t%d\t", root->info);
		inorder(root->rlink);
	}
}
void preorder(NODE root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("\t%d\t", root->info);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
void postorder(NODE root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("\t%d\t", root->info);
	}
	return;
}
NODE search(NODE root)
{
	NODE cur;
	int key;
	if (root == NULL)
	{
		printf("tree is empty\n");
		return root;
	}
	else
	{
		printf("enter the key element\n");
		scanf("%d", &key);
		cur = root;
		while (cur != NULL)
		{
			if (key == cur->info)
				break;
			if (key < cur->info)
				cur = cur->llink;
			else
				cur = cur->rlink;
		}
		if (cur == NULL)
		{
			printf("key not found\n");
		}
		else
		{
			printf("%d key found\n", key);
		}
	}
	return root;
}
NODE delete_item(NODE root)
{
	int key;
	NODE cur, prev, suc, q;
	if (root == NULL)
	{
		printf("Tree empty\n");
		return root;
	}
	prev = NULL;
	cur = root;
	printf("Enter the element to be deleted");
	scanf("%d", &key);
	while (cur != NULL)
	{
		if (key == cur->info)
			break;
		prev = cur;
		if (key < cur->info)
			cur = cur->llink;
		else
			cur = cur->rlink;
	}
	if (cur == NULL)
	{
		printf("Key not found\n");
		return root;
	}

	//Search operation ends here.

	else
	{
		if (cur->llink == NULL)
		{
			q = cur->rlink;
		}
		else if (cur->rlink == NULL)
		{
			q = cur->llink;
		}
		else
		{
			suc = cur->rlink;
			while (suc->llink != NULL)
			{
				suc = suc->llink;
			}
			q = cur->rlink;
		}
		if (prev == NULL)
			return q;
		//Why oh Why??
		if (cur == prev->llink)
		{
			prev->llink = q;
		}
		else
		{
			prev->rlink = q;
		}
		free(cur);
	}
	return root;
}
int main()
{
	int ch;
	NODE root = NULL;
	printf("binary search tree\n");
	while (1)
	{
		printf("1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n 5.Search\n6.Delete\n7.EXIT[0]\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			//root = create(root);
			break;
		case 2:
			printf("inorder traversal\n");
			if (root == NULL)
				printf("tree empty\n");
			else
				postorder(root);
			break;
		case 3:
			printf("preorder traversal\n");
			if (root == NULL)
				printf("tree empty\n");
			else
				preorder(root);
			break;
		case 4:
			printf("postorder traversal\n");
			if (root == NULL)
				printf("tree empty\n");
			else
				postorder(root);
			break;
		case 5:
			root = search(root);
			break;
		case 6:
			root = delete_item(root);
			break;
		case 7:
			exit(0);
		default:
			printf("invalid choice\n");
		}
	}
	return 0;
}
