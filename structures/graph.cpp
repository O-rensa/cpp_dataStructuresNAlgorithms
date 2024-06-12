#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// helper function(s) prototype
template<typename T>
bool isContained(vector<T>& vec, T value);

void showPaths(vector<vector<string>>& vectors);

void showPath(vector<string> vector);

// class(es)
class Graph {
    private:
        map<string, vector<string>> graphMap;
    public:
        // constructor(s)
        explicit Graph(vector<pair<string, string>> input) {
            for (pair<string, string> i : input) {
                if (this->graphMap[i.first].size() == 0) {
                    this->graphMap[i.first] = vector<string>{i.second};
                } else {
                    this->graphMap[i.first].push_back(i.second);
                }
            }
        }
        // destructor;
        ~Graph(){}

        // method(s) declaration
        bool isExist(string start);
        vector<vector<string>> getPaths(string start, string end, vector<string> path);
        vector<string> getShortestPath(string start, string end, vector<string> path);
};

// class method(s) definition
bool Graph::isExist(string start) {
    for (auto item : this->graphMap) {
        if (item.first == start) {
            return true;
        }
    }

    return false;
}

vector<vector<string>> Graph::getPaths(string start, string end, vector<string> path = {}) {
    path.push_back(start);

    vector<vector<string>> paths;

    if (start == end) {
        paths.push_back(path);
        return paths;
    }

    if (!(this->isExist(start))) {
        return paths;
    }

    for (string node : this->graphMap[start]) {
        // cout << !(isContained(visitedPaths, node)) << endl;
        if (!(isContained(path, node))) {
            vector<vector<string>> newPaths = this->getPaths(node, end, path);
            for (vector<string> p : newPaths) {
                paths.push_back(p);
            }
        }
    }

    return paths;
}

vector<string> Graph::getShortestPath(string start, string end, vector<string> path = {}) {
    path.push_back(start);

    if (start == end) {
        return path;
    }

    if (!(this->isExist(start))) {
        return {};
    }

    vector<string> shortestPath = {};
    for (string node : this->graphMap[start]) {
        if (!(isContained(path, node))) {
            vector<string> sp = this->getShortestPath(node, end, path);
            if (sp.size()) {
                if (shortestPath.size() == 0 || sp.size() < shortestPath.size()) {
                    shortestPath = sp;
                }
            }
        }
    }
    
    return shortestPath;
}

int main() {

    vector<pair<string, string>> routes = {
        pair<string, string>("Mumbai", "Paris"),
        pair<string, string>("Mumbai", "Dubai"),
        pair<string, string>("Paris", "Dubai"),
        pair<string, string>("Paris", "New York"),
        pair<string, string>("Dubai", "New York"),
        pair<string, string>("New York", "Toronto"),
    };

    Graph routeGraph = Graph(routes);

    string start = "Mumbai";
    string end = "New York";

    cout << "All paths between: " << start << " and " << end << endl;
    auto mnRoutes = routeGraph.getPaths(start, end);

    showPaths(mnRoutes);

    cout << endl << "The shortest path between: " << start << " and " << end << endl;

    vector<string> shortestPath = routeGraph.getShortestPath(start, end);

    showPath(shortestPath);

    return 0;
}

template<typename T>
bool isContained(vector<T>& vec, T value) {
    for (T itr : vec) {
        if (itr == value) {
            return true;
        }
    }
    return false;
}

__attribute__((always_inline)) inline
void showPaths(vector<vector<string>>& vectors){
    for (int i = 0; i < vectors.size(); i++) {
        cout << endl << "Route #" << i + 1 << endl;
        for (int j = 0; vectors[i].size() > j; j++) {
            cout << vectors[i][j];
            if (j == vectors[i].size() -1) {
                cout << endl;
            } else {
                cout << " -> ";
            }
        }
    }
}

__attribute__((always_inline)) inline
void showPath(vector<string> vector){
    for (int i = 0; vector.size() > i; i++) {
        cout << vector[i];
        if (i == vector.size() -1) {
            cout << endl;
        } else {
            cout << " -> ";
        }
    }
}