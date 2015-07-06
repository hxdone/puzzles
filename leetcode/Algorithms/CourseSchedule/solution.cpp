// topological sort by hxdone

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree;
        vector<vector<int>> end_nodes_list;
        for (int i = 0; i < numCourses; ++i) {
            indegree.push_back(0);
            end_nodes_list.push_back(vector<int>());
        }
        for (int i = 0; i < prerequisites.size(); ++i) {
            ++indegree[prerequisites[i].first];
            end_nodes_list[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> sorted_nodes;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                sorted_nodes.push_back(i);
        int start = 0;
        while (start < sorted_nodes.size()) {
            int len = end_nodes_list[sorted_nodes[start]].size();
            for (int i = 0; i < len; ++i) {
                int node = end_nodes_list[sorted_nodes[start]][i];
                if (--indegree[node] == 0)
                    sorted_nodes.push_back(node);
            }
            ++start;
        }
        return sorted_nodes.size() == numCourses;
    }
};
