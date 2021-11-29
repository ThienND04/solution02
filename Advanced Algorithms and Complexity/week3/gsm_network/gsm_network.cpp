#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertGSMNetworkProblemToSat {
    const int numColor = 3;
    int numVertices;
    vector<Edge> edges;
    vector<vector<int>> clauses;
    vector<int> tmp;

    ConvertGSMNetworkProblemToSat(int n, int m) :
        numVertices(n),
        edges(m)
    {  }

    int varnum(int i, int color){
        return (i - 1) * numColor + color;
    }

    void exactlyOneOf(int i){
        for(int k = 1; k <= numColor; k ++){
            tmp[k - 1] = varnum(i, k);
        }
        clauses.push_back(tmp);
        for(int j = 0; j < numColor; j ++){
            for(int t = j + 1; t < numColor; t ++){
                clauses.push_back({-tmp[j], -tmp[t]});
            }
        }
    }

    void calc(){    
        tmp.resize(numColor);
        for(int i = 1; i <= numVertices; i ++){
            exactlyOneOf(i);
        }
        for(Edge& e: edges){
            for(int k = 1; k <= numColor; k ++){
                clauses.push_back({- varnum(e.from, k), - varnum(e.to, k)});
            }
        }
    }

    void printEquisatisfiableSatFormula() {
        cout << clauses.size() << " " << numVertices * 3 << "\n";
        for(vector<int>& vt: clauses){
            for(int element: vt){
                cout << element << " ";
            }
            cout << "0\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertGSMNetworkProblemToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
    }

    converter.calc();
    converter.printEquisatisfiableSatFormula();

    return 0;
}
