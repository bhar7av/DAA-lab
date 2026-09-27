//priority queue and adjacency list 
#include<stdio.h>
#include<stdlib.h>

struct edge{
    int vertex;
    int weight;
    struct edge *next;
};

struct node{
    int vertex;
    int key;
};

struct Minheap{
    struct node heap;
    int size;
};

void swap(struct node *a , struct node *b){
    struct node temp = *a;
    *a = *b;
    *b = temp;

}

