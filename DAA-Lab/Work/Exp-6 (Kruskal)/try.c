#include <stdio.h>


typedef struct Edges{
    int start,end,weight;
}Edges;



typedef struct Graph{
    //number of vertices
    int v;
    //number of edges
    int e;
    //set of edges
    Edges Edges[];
}Graph;





typedef struct subset{
    int parent;
}subset;




typedef struct size_of_each_subset{
    int size;
}size_of_each_subset;




//function to find parent of a node
int find(struct subset subset[], int x){
    
    if ((subset[x].parent) != x){
        return (find(subset, subset[x].parent));
    }
    return x;
}




void unionSets(int u, int v, struct subset s[], struct size_of_each_subset r[]){
    

    if ((r[u].size) > (r[v].size)){
        s[v].parent = u;
        r[u].size += r[v].size;
    }

    else if ((r[u].size) < (r[v].size)){
        s[u].parent = v;
        r[v].size += r[u].size;
    }
    
    else{
        s[v].parent = u;
        r[u].size += r[v].size;
    }
}




void sort(struct Graph *g, int no_of_edges){

    int startArr[(no_of_edges)];
    int endArr[(no_of_edges)];
    int weightArr[(no_of_edges)];

    
    for (int i=1;i<no_of_edges;i++){
        startArr[i] = g->Edges[i].start;
        endArr[i] = g->Edges[i].end;
        weightArr[i] = g->Edges[i].weight;
    }


    for (int i=1;i<no_of_edges;i++){
        int smallest = weightArr[i];
        int index = i;
        for (int j=i;j<no_of_edges;j++){
            if (weightArr[j] < smallest){
                smallest = weightArr[j];
                index = j;
            }
        }
        
        

        //moddify the arrays (swap values)
        int temp = startArr[i];
        startArr[i] = startArr[index];
        startArr[index] = temp;

        temp = endArr[i];
        endArr[i] = endArr[index];
        endArr[index] = temp;

        temp = weightArr[i];
        weightArr[i] = weightArr[index];
        weightArr[index] = temp;

    }

    //modify the graph
    int counter = 1;
    for (int i=1;i<no_of_edges;i++){
        g->Edges[counter].start = startArr[i];
        g->Edges[counter].end = endArr[i];
        g->Edges[counter].weight = weightArr[i];
        counter++;
    }
}




int kruskalAlgo(struct Graph *g, int no_of_edges, struct subset s[], struct size_of_each_subset r[]){
    int minCost = 0;
    
    ///sort the graph
    sort(g, no_of_edges);



    printf("\nThe edges in MST are:\n");

    for (int i=1;i<=(g->e);i++){
        
        int v1 = g->Edges[i].start;
        int v1_parent = find(s, v1);
        
        int v2 = g->Edges[i].end;
        int v2_parent = find(s, v2);

        int wt = g->Edges[i].weight;

        // If the parents are different that
		// means they are in different sets so
		// union them

        if (v1_parent != v2_parent){
            //union them
            unionSets(v1_parent, v2_parent, s, r);
            minCost+=wt;
            printf("%d--%d: %d\n",g->Edges[i].start, g->Edges[i].end, g->Edges[i].weight);
        }
    }

    return minCost;
}




int main(){
    Graph g;
    g.e=5;
    g.v=4;

    int no_of_vertices = 5; //same as (g.v)+1
    int no_of_edges = 6; //same as (g.e)+1

    subset s[5];
    size_of_each_subset r[5];

    for (int a=1;a<no_of_vertices;a++){
        s[a].parent = a;
    }

    for (int b=1;b<no_of_vertices;b++){
        r[b].size = 1;
    }

    g.Edges[1].start = 1;
    g.Edges[1].end = 2;
    g.Edges[1].weight = 10;

    g.Edges[2].start = 2;
    g.Edges[2].end = 4;
    g.Edges[2].weight = 15;

    g.Edges[3].start = 3;
    g.Edges[3].end = 4;
    g.Edges[3].weight = 4;

    g.Edges[4].start = 1;
    g.Edges[4].end = 3;
    g.Edges[4].weight = 6;

    g.Edges[5].start = 1;
    g.Edges[5].end = 4;
    g.Edges[5].weight = 5;








    int minCost = kruskalAlgo(&g, no_of_edges, s, r);
    printf("\nMinimum cost of MST is: %d",minCost);
    

    return 0;
}