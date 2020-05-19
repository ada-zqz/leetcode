class Solution {
public:
    // const double PI = atan(1.0)*4;  // M_PI
    // 给pair<double, int>排序，记录扫描的最大点数
    struct cmp {
        bool operator()(pair<double, int>& a1, pair<double, int>& a2) {
            if(a1.first != a2.first) return a1.first < a2.first;
            return a1.second > a2.second;  //可以在圆线上，先进来，下一个才考虑出去
        }
    };
    // 两点之间距离
    double dist(vector<int>& v1, vector<int>& v2) {
        return sqrt((double)pow(v1[0] - v2[0], 2) + pow(v1[1] - v2[1], 2));
    }
    // 进入圆的角1和角2
    vector<double> findangle(vector<int>& a, vector<int>& b, double& delta) {
        double angleB = atan2(b[1] - a[1], b[0] - a[0]);  // [-pi, pi]
        double angle1 = angleB - delta;
        double angle2 = angleB + delta;
        return vector<double> {angle1, angle2};
    }
    int numPoints(vector<vector<int>>& points, int r) {
        // 给定一个点A(x1, y1)，以直径2r扫描（顶点记为C），点B(x2, y2)进入圆的角度angle1，出圆的角度angle2
        // 时间复杂度O(n^2 lgn) lgn是排序的需要
        // delta = ∠BAC = arccos(d/2r)
        // AB与x轴的夹角angle = arctan((y2-y1)/(x2-x1))  函数atan2(y2-y1, x2-x1)不用额外判断x2=x1的情况
        // 而且atan(y/x)只能返回一个角度值[-pi/2,pi/2]，因此确定点的角度很复杂，要判断在哪个象限，不易于处理旋转的问题
        int r2 = 2 * r;  //直径
        int res = 1;
        vector<pair<double, int>> angles;  // 进入(出去)的角度，1(-1)
        for(auto a: points) {
            angles.clear();
            for(auto b: points) {
                double d = dist(a, b);
                if((a[0] == b[0] && a[1] == b[1]) || d > r2) continue;
                double delta = acos(d / r2);  // 一定小于pi/2
                vector<double> angle = findangle(a, b, delta);
                angles.push_back({angle[0], 1});  // 进入的角度
                angles.push_back({angle[1], -1}); // 出去的角度
            }
            sort(angles.begin(), angles.end(), cmp());
            int val = 1;
            for(auto p: angles) {
                val += p.second;
                res = max(res, val);
            }
        }
        return res;
    }
};
