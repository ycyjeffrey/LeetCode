#define pdi pair<double, int>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdi> pq;
        for (int i = 0; i < classes.size(); i++) {
            double pass = classes[i][0], total = classes[i][1];
            double inc = (pass + 1) / (total + 1) - pass / total;
            pq.push({inc, i});
        }
        while (extraStudents > 0) {
            pdi root = pq.top();
            pq.pop();
            classes[root.second][0]++;
            classes[root.second][1]++;
            double pass = classes[root.second][0], total = classes[root.second][1];
            double inc = (pass + 1) / (total + 1) - pass / total;
            pq.push({inc, root.second});
            extraStudents--;
        }
        double ret = 0;
        for (auto& cl : classes)
            ret += (double)cl[0] / (double)cl[1];
        ret /= classes.size();
        return ret;
    }
};