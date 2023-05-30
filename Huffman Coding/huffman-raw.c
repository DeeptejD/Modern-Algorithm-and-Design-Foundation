#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

struct node
{
    int freq;
    char c;
    struct node *next, *left, *right;
};

struct node *start = NULL;

greatest = 0; // this holds the greatest freq

void addatend(char c[], int f[], int n)
{
    for (int i = 0; i < n; i++)
    {

        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->c = c[i], start->freq = f[i], start->next = NULL, start->left = NULL, start->right = NULL;
        }
        else
        {
            struct node *ptr = start;

            while (ptr->next != NULL)
                ptr = ptr->next;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->c = c[i], temp->freq = f[i];
            temp->next = NULL;
            temp->left = temp->right = NULL;
            ptr->next = temp;
        }
    }
}
void showlist()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("(%c, %d), ", ptr->c, ptr->freq);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *delfront()
{
    // printf("Entered delete front\n");
    struct node *temp = start;
    start = start->next;
    return temp;
}

void addafterliketerms(struct node *temp)
{
    // check if there is only one
    if (start == NULL)
        start = temp;
    else if (start->next == NULL) // only one term
    {
        // printf("only one node\n");
        if (temp->freq < start->freq)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            temp->next = start->next;
            start->next = temp;
        }
    }
    else
    {
        // printf("more than one node\n");
        // more than one node
        int found = 0;
        struct node *at;
        struct node *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->freq == temp->freq)
            {
                // printf("node found\n");
                found = 1;
                at = ptr;
                break;
            }
            ptr = ptr->next;
        }
        ptr = start;
        if (found)
        {
            // printf("entered the found condition\n");
            struct node *ptr = at;
            while (ptr->next->freq == temp->freq && ptr->next != NULL)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
        else
        {
            ptr = start;
            // printf("node not found\n");
            // while (ptr != NULL)
            // {
            //     if (ptr->next->freq < temp->freq)
            //         ptr = ptr->next;
            // }
            // if (ptr == NULL)
            // {
            //     printf("reached the end\n");
            //     ptr = start;
            //     while (ptr->next != NULL)
            //         ptr = ptr->next;
            //     temp->next = ptr->next;
            //     ptr->next = temp;
            // }
            // else
            // {
            //     printf("not at the end\n");
            //     temp->next = ptr->next;
            //     ptr->next = temp;
            // }
            // greatest condition
            // while (ptr->next != NULL)
            //     ptr = ptr->next;
            // if (temp->freq > ptr->freq)
            // {
            //     printf("incoming node is greater than the last node\n");
            //     temp->next = ptr->next;
            //     ptr->next = temp;
            // }
            // ptr = start;
            // while (ptr->next != NULL)
            // {
            while (ptr->next->freq <= temp->freq && ptr != NULL)
                ptr = ptr->next;
            // }
            // if (ptr->next == NULL)
            // {
            //     if (temp->freq > ptr->freq)
            //     {
            //         temp->next = ptr->next;
            //         ptr->next = temp;
            //     }
            //     else
            //     {
            //         ptr = start;
            //         while (ptr->next->next != NULL)
            //             ptr = ptr->next;
            //         temp->next = ptr->next;
            //         ptr->next = temp;
            //     }
            // }
            // else
            // {
            if (ptr != NULL)
            {
                // printf("ptr is not null\n");
                temp->next = ptr->next;
                ptr->next = temp;
            }
            else
            {
                // printf("ptr is null\n");
                ptr = start;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
            // }
        }
    }
}

void ins_end(struct node *temp)
{
    if (start == NULL)
    {
        // printf("Entered start==NULL in ins_end func\n");
        // start = NULL;
        temp->next = NULL;
        start = temp;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void huffman()
{
    if (start == NULL)
        return;

    while (start->next != NULL)
    {
        // printf("start next is not null\n");
        struct node *a = delfront();
        // printf("returned a = (%c, %d)", a->c, a->freq);
        struct node *b = delfront();
        // printf("\nreturned b = (%c, %d)\n", b->c, b->freq);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        // temp->i = (struct item *)malloc(sizeof(struct item));
        temp->c = '#', temp->freq = a->freq + b->freq;
        temp->left = a, temp->right = b, temp->next = NULL;
        if (temp->freq >= greatest)
        {
            greatest = temp->freq;
            ins_end(temp);
            // showlist();
        }
        else
            addafterliketerms(temp);
        showlist();
        printf("\n");
    }
}

void printcodes(struct node *root, int path[], int stringlen)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        for (int i = 0; i < stringlen; i++)
            printf("%d", path[i]);
        printf("\t%c\n", root->c);
    }

    // left tree
    path[stringlen] = 0;
    printcodes(root->left, path, stringlen + 1);

    // right tree
    path[stringlen] = 1;
    printcodes(root->right, path, stringlen + 1);
}

void findgreatest()
{
    struct node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    greatest = ptr->freq;
}

int main(int argc, char const *argv[])
{
    char arr[] = {'g', 'n', 'h', 'r', 'c', 'a', 'd', 'p', 's', 't', 'o'};
    int freq[] = {1, 1, 1, 1, 1, 1, 2, 2, 4, 5, 7};
    // char arr[] = {'o', 'd', 'y', 't', 'h', 'i', 's', 'a', ' '};
    // int freq[] = {1, 1, 1, 2, 2, 2, 2, 2, 4};
    printf("%d\n", strlen(arr));
    addatend(arr, freq, strlen(arr) - 1);
    showlist();
    findgreatest();
    huffman();
    int path[N];
    printf("Huffman Codes\n");
    printcodes(start, path, 0);

    return 0;
}