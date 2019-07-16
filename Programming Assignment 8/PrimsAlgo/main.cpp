#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node
{
    int key;
    int src;
    int color;
};
Node node[50];


// print the minimum spanning tree
void print_prims(int vertices, char vertice_names[50], int  matrix[50][50])
{
    int i = 0;
    while(i<vertices)
    {
        printf("\nWeight of edge %c to %c is %d \n" , vertice_names[node[i].src], vertice_names[i], matrix[i][node[i].src]);
        i++;
    }
}

void prims()
{
    int  matrix[50][50];
    char vertice_names[50];
    vector<int> priority_queue;
    int vertices;
    int infinity = 999;
    
    
    // take user inputs
    cout << "\nEnter the number of vertices";
    cin >> vertices;
    
    cout << "Enter vertices from source vertex: ";
    for(int i=0; i<vertices ; i++)
    {
        cin >> vertice_names[i];
    }
    
    for(int i=0; i<vertices ; i++)
    {
        for(int j= 0; j<vertices; j++)
        {
            matrix[i][j] = infinity;
        }
    }
    
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            if(matrix[j][i] == infinity)
            {
                cout<< "Enter the weight of the edge between vertex " << vertice_names[i] << " and vertex " << vertice_names[j];
                cin >> matrix[i][j];
                matrix[j][i] = matrix[i][j];
            }
        }
    }
    
    // Initialize and set color as 0 for red and 1 for blue
    int i =0;
    while(i<vertices)
    {
        node[i].key = infinity;
        node[i].color = 0;
        i++;
    }
    
    node[0].key = 0;
    node[0].src = -1;
    
    for(int i=0; i<vertices; i++)
    {
        priority_queue.push_back(node[i].key);
    }
    
    sort(priority_queue.begin(),priority_queue.end());      // storing elements of queue in sorted order
    
    int u, y, index;
    
    int j = 0;
    while(j<vertices-1)
    {
        u = priority_queue.front();
        priority_queue.erase(priority_queue.begin());          // find minimum value
        y=0;
        
        // obtain corresponding vertex once key is removed from the queue
        while(y<vertices)
        {
            if(node[y].key == u)
            {
                index = y;
                break;
            }
            else
            {
                y++;
            }
        }
        node[i].color =1;
    
        for(int i=0; i<vertices; i++)
        {
            if(matrix[u][i] && node[i].color == 0 && matrix[u][i] < node[i].key)
            {
                node[i].key = matrix[u][i];
                priority_queue.pop_back();
                priority_queue.push_back(node[i].key);
                sort(priority_queue.begin(), priority_queue.end());
                node[i].src = u;
            }
        }
        j++;
    }
    
    print_prims(vertices, vertice_names, matrix);
}

int main(int argc, const char * argv[]) {

    prims();
    
}





