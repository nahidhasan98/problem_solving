#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

struct details {
    int start_time, end_time, initial_id;
};

bool operator < ( details a, details b ) {
    if ( a.end_time != b.end_time ) return a.end_time > b.end_time;
    else return true;
}

int n, m, timer = 0, idx = -1, id[10010];
bool visited[10010];
details node[10010];
map<int, vector<int> >path, reverse_path, comp_path;
map<int, vector<int> >::iterator itr;
set<int>indegree;

void first_DFS ( int s ) {
    node[s].start_time = ++timer;
    node[s].initial_id = s;
    visited[s] = true;

    for ( int i = 0; i < path[s].size(); i++ ) {
        int next_node = path[s][i];

        if ( !visited[next_node] ) first_DFS(next_node);
    }

    node[s].end_time = ++timer;
}

void second_DFS ( int s ) {
    id[s] = idx;
    visited[s] = true;

    for ( int i = 0; i < reverse_path[s].size(); i++ ) {
        int next_node = reverse_path[s][i];

        if ( !visited[next_node] ) second_DFS(next_node);
    }
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        timer = 0, idx = -1;
        path.clear(), reverse_path.clear(), comp_path.clear();

        int n, m;
        cin >> n >> m;

        int u, v;
        for ( int i = 0; i < m; i++ ) {
            cin >> u >> v;
            u--, v--;

            path[u].push_back(v);
            reverse_path[v].push_back(u);
        }

        //setting up timer
        memset( visited, false, sizeof(visited) );
        for ( int i = 0; i < n; i++ ) {
            if ( !visited[i] ) first_DFS(i);
        }

        sort( node, node + n );

        //giving component id
        memset( visited, false, sizeof(visited) );
        for ( int i = 0; i < n; i++ ) {
            int curr_node = node[i].initial_id;

            if ( !visited[curr_node] ) {
                ++idx;
                second_DFS(curr_node);
            }
        }

//        for ( int i = 0; i < n; i++ ) {
//            cout << id[i] << endl;
//        }

        //building component graph
        set<int>indegree;
        for ( itr = path.begin(); itr != path.end(); itr++ ) {
            int u = itr->first;
            vector<int>v = itr->second;

            for ( int j = 0; j < v.size(); j++ ) {
                int u_id = id[u];
                int v_id = id[v[j]];

                if ( u_id != v_id ) {
                    comp_path[u_id].push_back(v_id);
                    indegree.insert(v_id);
                }
            }
        }

        cout << "Case " << t << ": " << idx + 1 - indegree.size() << endl;
    }

    return 0;
}
