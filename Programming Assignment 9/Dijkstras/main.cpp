#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct dijkstra_table
{
    int val[50][50];
    char ptr[50][50];
};
dijkstra_table table;

//initialization of the final table
void initialize(int vertices)
{
    for(int i = 1; i<=vertices ; i++)
    {
        for(int j = 1 ; j<=vertices ; j++)
        {
            table.val[i][j] = 0;
        }
    }
    
    // assign infinity to table values
    int i = 0;
    for(int j = 0; j<=vertices ; j++)
    {
        table.val[i][j] = 999;
    }
    
    int j = 0;
    for(int i =0; i<= vertices; i++)
    {
        table.val[i][j] = 999;
    }
}

// display output table
void display_output(int vertices, char vertice_name[50])
{
    cout << "\nThe output table is : ";
    cout << "\n\n\n";
    for(int i=1 ; i<=vertices ; i++)
    {
        cout << "\t" << vertice_name[i];
    }
    
    for(int i=1; i<=vertices ; i++)
    {
        cout << "\n";
        cout << vertice_name[i] << "\t";
        for(int j=1 ; j<=vertices; j++)
        {
            cout<< table.val[i][j] << "," << table.ptr[i][j] << "\t";
        }
    }
    cout<<"\n";
}

 //print adjacency matrix
void print_matrix(int vertices, char vertice_name[50], int matrix[50][50])
{
    cout<< "\nThe adjacency matrix is : ";
    cout<<"\n";
    for(int i = 1; i <= vertices ; i++)
    {
        cout << "\t" << vertice_name[i];
    }
    for(int i = 1; i<= vertices; i++)
    {
        cout<<"\n";
        cout << vertice_name[i] << "\t";
        for(int j = 1; j<=vertices; j++)
        {
            cout << matrix[i][j]  << "\t";
        }
    }
}


void dijkstras()
{
    int k =0;
    int matrix[50][50];
    char vertice_name[50];
    int vertices=0;
    
    // get user input
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    cout << "Enter the names of vertices starting from the source: ";
    
    for(int i = 1; i<=vertices; i++)
    {
        cin >> vertice_name[i];
    }
    
    for(int i =1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    
    for(int i = 1; i<=vertices ; i++)
    {
        for(int j = 1 ; j<=vertices ; j++)
        {
            if(matrix[j][i] == 0)
            {
                cout<< "Enter the weight of the edge between vertex " << vertice_name[i] << " and vertex " << vertice_name[j];
                cin >> matrix[i][j];
                matrix[j][i] = matrix[i][j];
            }
        }
    }
    
    initialize(vertices);
    print_matrix(vertices, vertice_name, matrix);
    
   // construct the table
    vector<int> sol_list;
    vector<char> sol_label;

    int next_val = 1;
    int prev_val = 0;
    int findmin = 0;
    int minimum = 999;
    int curr_len = 0;
    char sol_char;
    int flagger = 0;
    
    int i = 1;
    k = 1;
    
    sol_list.push_back(0);
    sol_label.push_back(vertice_name[i]);
    
    while(k <= vertices)
    {
        minimum = 999;
        for(int j = 1; j<=vertices; j++)
        {
            // set the first cell of the table as 0
            if (i == 1 && j == 1)
            {
                table.val[k][j] = 0;
                table.ptr[k][j] = vertice_name[i];
            }
            else
            {
                if(find(sol_list.begin(), sol_list.end(), table.val[k-1][j]) != sol_list.end() && find(sol_label.begin(), sol_label.end(), table.ptr[k-1][j]) != sol_label.end())
                {
                    table.val[k][j] = table.val[k-1][j];
                    table.ptr[k][j] = table.ptr[k-1][j];
                    findmin = 0;
                }
                // if path is not shorter
                else if(table.val[k-1][j] < matrix[i][j] + curr_len)
                {
                    table.val[k][j] = table.val[k-1][j];
                    table.ptr[k][j] = table.ptr[k-1][j];
                    findmin = 1;
                }
                // if there exists a shorter path
                else
                {
                    table.val[k][j] = matrix[i][j]+curr_len;
                    table.ptr[k][j] = vertice_name[i];
                    findmin = 1;
                }
                
                if(table.val[k][j] < minimum && findmin == 1)
                {
                    minimum = table.val[k][j];
                    sol_char = table.ptr[k][j];
                    next_val = j;
                    flagger = 1;
                }
            }
        }
        
        if(flagger == 1)
        {
            sol_list.push_back(minimum);        // find the minimum value and add to the list
            curr_len = minimum;
            sol_label.push_back(sol_char);
            prev_val = i;
            i = next_val;
            flagger =0;
            findmin = 0;
        }
        
        k++;
    }
    
    display_output(vertices, vertice_name);
}


int main(int argc, const char * argv[]) {
    
    dijkstras();
    
}
