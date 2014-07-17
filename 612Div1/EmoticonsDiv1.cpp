#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
typedef pair<pair<int,int>,int> node_t;
typedef pair<int,int> state_t;

class EmoticonsDiv1 {
public:
	int printSmiles(int smiles) {
        node_t s = make_pair(make_pair(1, 0), 0);
        set<state_t> visited;
        queue<node_t> open;
        open.push(s);
        visited.insert(s.first);
        while(!open.empty()){
            node_t head = open.front();
            open.pop();
            int msg = head.first.first;
            int clip = head.first.second;
            int level = head.second;
            if(msg == smiles)
                return level;
            
            node_t n[3];
            n[0] = make_pair(make_pair(msg, msg), level+1);
            n[1] = make_pair(make_pair(msg+clip, clip), level+1);
            n[2] = make_pair(make_pair(msg-1, clip), level+1);
            for(int i=0;i<3;i++){
                if(n[i].first.first>=0 && !visited.count(n[i].first))
                    open.push(n[i]),visited.insert(n[i].first);
            }
        }
        
        return -1;
    }
};
