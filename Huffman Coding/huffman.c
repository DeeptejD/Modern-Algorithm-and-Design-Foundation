#include <stdio.h>
#include <stdlib.h>
#define N 50
#define sint(x) scanf("%d", &x)

// we will use a minheap to make sure that the node with the least frequency is always at the top
struct minheapnode
{
    char item;
    int freq;
    struct minheapnode *left, *right;
};

struct minheap
{
    int size, cap;
    struct minheapnode **array; // nodes in the minheap are stored as an array
};

// make a new node
struct minheapnode *newnode(char item, int freq)
{
    struct minheapnode *temp = (struct minheapnode *)malloc(sizeof(struct minheapnode));
    temp->left = temp->right = NULL;
    temp->item = item, temp->freq = freq;

    return temp;
}

// make minheap
struct minheap *createminh(int cap)
{
    struct minheap *minh = (struct minheap *)malloc(sizeof(struct minheap));
    minh->size = 0, minh->cap = cap; // size = 0 because init no nodes, cap = max nodes heap can hold

    minh->array = (struct minheapnode **)malloc(minh->cap * sizeof(struct minheapnode *)); // allocates enough size to the array to hold all the minheap nodes

    return minh;
}

void _swap(struct minheapnode **a, struct minheapnode **b)
{
    struct minheapnode *temp = *a;
    *a = *b;
    *b = temp;
}

// heapify: maintains the minheap property
void heapify(struct minheap *minh, int current_index)
{
    int smallest = current_index, left = 2 * current_index + 1, right = 2 * current_index + 2;

    if (left < minh->size && minh->array[left]->freq < minh->array[smallest]->freq)
        smallest = left;

    if (right < minh->size && minh->array[right]->freq < minh->array[smallest]->freq)
        smallest = right;

    if (smallest != current_index)
    {
        _swap(&minh->array[smallest], &minh->array[current_index]);
        heapify(minh, smallest);
    }
}

int checksize(struct minheap *minh)
{
    return (minh->size == 1);
}

struct minheapnode *getminnode(struct minheap *minh)
{
    struct minheapnode *temp = minh->array[0];
    minh->array[0] = minh->array[minh->size - 1];
    --minh->size;

    heapify(minh, 0);

    return temp;
}

void insert(struct minheap *minh, struct minheapnode *minnode)
{
    ++minh->size;
    int i = minh->size - 1;
    while (i && minnode->freq < minh->array[(i - 1) / 2]->freq)
    {
        minh->array[i] = minh->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minh->array[i] = minnode;
}

// arranges the array elements to form a valid minheap
void buildminheap(struct minheap *minh)
{
    int n = minh->size - 1;

    // (n-1)/2 is the index of the last non leaf node since the heap is represented as an array
    for (int i = (n - 1) / 2; i >= 0; --i)
        heapify(minh, i);
}

int isleaf(struct minheapnode *root)
{
    return (!(root->left) && !(root->right));
}

struct minheap *createandbuild(char item[], int freq[], int size)
{
    struct minheap *minh = createminh(size);

    for (int i = 0; i < size; ++i)
        minh->array[i] = newnode(item[i], freq[i]);

    minh->size = size;
    buildminheap(minh);

    return minh;
}

struct minheapnode *buildhuffman(char item[], int freq[], int size)
{
    struct minheapnode *left, *right, *top;
    struct minheap *minh = createandbuild(item, freq, size);

    while (!checksize(minh))
    {
        left = getminnode(minh);
        right = getminnode(minh);

        top = newnode('$', left->freq + right->freq);

        top->left = left, top->right = right;

        insert(minh, top);
    }
    return getminnode(minh);
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void huffcodes(struct minheapnode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        huffcodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        huffcodes(root->right, arr, top + 1);
    }
    if (isleaf(root))
    {
        printf("%c\t", root->item);
        show(arr, top);
    }
}

void huffman(char item[], int freq[], int size)
{
    struct minheapnode *root = buildhuffman(item, freq, size);
    int arr[N], top = 0;
    huffcodes(root, arr, top);
}

int main(int argc, char const *argv[])
{
    char arr[] = {'d', 'o', 'g', 's', 'n', 't', 'p', 'h', 'r', 'c', 'a'};
    int freq[] = {2, 7, 1, 4, 1, 5, 2, 1, 1, 1, 1};
    // char arr[] = {'A', 'B', 'C', 'D'};
    // int freq[] = {5, 1, 6, 3};
    // char arr[] = {'t', 'h', 'i', 's', 'a', 'o', 'd', 'y', '-'};
    // int freq[] = {2, 2, 2, 2, 1, 1, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Huffman Codes\n");
    huffman(arr, freq, size);
    return 0;
}
