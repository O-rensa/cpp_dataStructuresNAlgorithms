#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// helper function(s) declaration
template<typename T>
bool isContained(std::vector<T>& vec, T value);

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
        vector<vector<string>> getPaths(string start, string end, vector<vector<string>> path);
        vector<string>* getShortestPath(string start, string end, vector<string>* path);
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

vector<vector<string>> Graph::getPaths(string start, string end, vector<vector<string>> path = {}) {
    vector<string> visitedPaths;

    for (vector<string> i : path) {
        for (string j : i) {
            visitedPaths.push_back(j);
        }
    }

    visitedPaths.push_back(start);

    if (start == end) {
        path.push_back(vector<string>{start});
        return path;
    }

    if (!(this->isExist(start))) {
        return {};
    }

    vector<vector<string>> paths;
    for (string node : this->graphMap[start]) {
        // cout << !(isContained(visitedPaths, node)) << endl;
        if (!(isContained(visitedPaths, node))) {
            path.push_back(vector<string>{start});
            vector<vector<string>> newPaths = this->getPaths(node, end, path);
            for (vector<string> p : newPaths) {
                paths.push_back(p);
            }
        }
    }


    return paths;
}

vector<string>* Graph::getShortestPath(string start, string end, vector<string>* path = new vector<string>()) {
    path->push_back(start);

    if (start == end) {
        return path;
    }

    if (!(this->isExist(start))) {
        return nullptr;
    }

    vector<string>* shortestPath = nullptr;
    for (string node : this->graphMap[start]) {
        if (!(isContained(*path, start))) {
            vector<string>* sp = this->getShortestPath(node, end, path);
            if (sp != nullptr) {
                if (shortestPath == nullptr || sp->size() < shortestPath->size()) {
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
    for (int i = 0; i < mnRoutes.size(); i++) {
        cout << "Route #" << i + 1 << endl;
        for (string j : mnRoutes[i]) {
            cout << j;
            if (i == mnRoutes[i].size() -1) {
                cout << endl;
            } else {
                cout << "->" << endl;
            }
        }
    }

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