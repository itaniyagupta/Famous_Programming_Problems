//Breadth First Traveral of Graph

void BFS(int** edges, int n, int startvertex){

    queue<int> pendingVertices;
    bool* visited= new bool [n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    pendingVertices.push(startvertex);
    visited[startvertex] = true;

    while(!pendingVertices.empty()){

        int currvertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currvertex << endl;
        for(int i=0; i<n; i++)
        {   if(i == currvertex){
             continue;
            }
            if(edges[currvertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
    for(int i=0; i<n;  i++){
        delete [] edges[i];
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

    cout<< "BFS" << endl;
    BFS(edges, n, 0);

    delete [] visited;
    for(int i=0; i<n;  i++){
        delete [] edges[i];
    }
    delete [] edges;
}
