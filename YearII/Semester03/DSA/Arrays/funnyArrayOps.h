int a[100], n, val, i, pos;

void create() {
printf("\nEnter the size of the array elements:\t");
scanf("%d", &n);
printf("\nEnter the elements for the array:\n");
for (i = 0; i < n; i++)
	{
			scanf("%d", &a[i]);
}
	printf("The array looks like this.\n");
for (i = 0; i < n; i++)
{
	printf("\n%d", a[i]);
}
}

	void display() {
for (i = 0; i < n; i++)
{
	printf("\n%d", a[i]);
}
}

	void insert() {
printf("\nEnter the position for the new element:\t");
scanf("%d", &pos);
printf("\nEnter the element to be inserted :\t");
scanf("%d", &val);
for (i = n - 1; i >= pos; i--)
	{
			a[i + 1] = a[i];
}
	a[pos] = val;
n = n + 1;
}

	void delete () {
printf("\nEnter the position of the element to be deleted:\t");
scanf("%d", &pos);
val = a[pos]; //just to display deleted element.
for (i = pos; i < n - 1; i++)
	{
			a[i] = a[i + 1];
}
	n = n - 1;
printf("\nThe deleted element is %d", val);
}
