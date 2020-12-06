//Depth First Traversal of Graph

void dfs(int** edges, int n, int startvertex, bool* visited){

    cout<< startvertex <<endl;
    visited[startvertex] = true;
    for(int i=0; i<n; i++)
    {
        if(i== startvertex){
            continue;
        }
        if (edges[startvertex][i] == 1)
        {
            if(visited[i]){
                continue;
            }
            dfs(edges,n, i, visited);
        }
    }
}

int main(){
    int n;
    int e;
    cin>> n >> e;
    int** edges = new int*[n];
    for(int i=0; i<=n; i++)
    {
         edges[i] = new int[n];
         for(int j=0; j<n; j++)
         {
             edges[i][j] = 0;
         }
    }
    for(int i=0; i<e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited= new bool [n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    cout << "DFS" <<endl;
    dfs(edges, n, 0, visited);
   
    delete [] visited;
    for(int i=0; i<n;  i++){
        delete [] edges[i];
    }
    delete [] edges;
}