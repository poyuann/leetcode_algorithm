class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for(auto el: prerequisites) {
            adjlist[el[1]].push_back(el[0]);
        }
        
        vector<bool> discover(numCourses, false), finish(numCourses, false);
        
        vector<int> q;
        for(int i = 0; i < numCourses; i++) 
            if(!finish[i])
                if(cyclic(adjlist, discover, finish, i, q))
                    return {};
        
        reverse(q.begin(), q.end());
        return q;
    }
private:
    bool cyclic(vector<vector<int>>& adjlist, vector<bool>& discover, vector<bool>& finish, int curr_node, vector<int>& q) {
        if (discover[curr_node])
            return true;
        if (finish[curr_node])
            return false;
        discover[curr_node] = true;
        for(auto el: adjlist[curr_node]) {
            if(cyclic(adjlist, discover, finish, el, q))
                return {};
        }
        discover[curr_node] = false; finish[curr_node] = true;
        q.push_back(curr_node);
        return false;
    }
};