#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertHampathToSat {
    int numVertices;
    vector<Edge> edges;
    vector<vector<int>> clauses;
    vector<vector<int>> adj;

    ConvertHampathToSat(int n, int m) :
        numVertices(n),
        edges(m),
        adj(numVertices)
    {

    }

    int varNum(int i, int j){
        return numVertices * i + j;
    }

    void exactlyOneOf(const vector<int>& l){
        clauses.push_back(l);
        for(int i = 0; i < l.size(); i ++){
            for(int j = i + 1; j < l.size(); j ++){
                clauses.push_back({- l[i], - l[j]});
            }
        }
    }

    void prepare(){
        for(Edge& e: edges){
            adj[e.from].push_back(e.to);
            adj[e.to].push_back(e.from);
        }


        for(int i = 0; i < numVertices; i ++){
            vector<int> tmp;
            for(int pos = 1; pos <= numVertices; pos ++){
                tmp.push_back(varNum(i, pos));
            }
            exactlyOneOf(tmp);
        }
        for(int pos = 1; pos <= numVertices; pos ++){
            vector<int> tmp;
            for(int i = 0; i < numVertices; i ++){
                tmp.push_back(varNum(i, pos));
            }
            exactlyOneOf(tmp);
        }
        for(int pos = 1; pos < numVertices; pos ++){
            for(int u = 0; u < numVertices; u ++){
                vector<int> tmp;
                tmp.push_back(-varNum(u, pos));
                for(int v: adj[u]){
                    tmp.push_back(varNum(v, pos + 1));
                }
                clauses.push_back(tmp);
            }
        }
    }

    void printEquisatisfiableSatFormula() {
        prepare();
        cout << clauses.size() << " " <<  numVertices * numVertices << "\n";
        for(vector<int>& vt: clauses){
            for(int i: vt) cout << i << " ";
            cout << 0 << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertHampathToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
        converter.edges[i].from --;
        converter.edges[i].to --;
    }

    converter.printEquisatisfiableSatFormula();

    return 0;
}
