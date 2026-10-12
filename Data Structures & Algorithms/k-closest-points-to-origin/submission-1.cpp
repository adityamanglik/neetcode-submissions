class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        // store all points and distances in map
        map<vector<int>, int> dist;
        map<int, int> counter;
        for(int i = 0; i < points.size(); ++i){
            int value = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            dist[points[i]] = value;
            if(counter.find(value) != counter.end())
                counter[value] += 1;
            else
                counter[value] = 1;
        }
        // add distances and counts to another map --> avoids multimap
        // second map would be sorted by value
        // return k by iterating from end
        for(auto i = counter.begin(); i != counter.end(); ++i)
        {   // return all points with the same distance iter->first
            for(auto j = dist.begin(); j != dist.end(); ++j)
                if(j->second == i->first and k > 0 and i->second > 0)
                {   ans.push_back(j->first);
                    k -= 1;
                    i->second -= 1;
                }
        }
        return ans;
    }
};
