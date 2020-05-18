class Solution {
public:
    // 两点之间距离的平方
    int dis2(vector<int>& v1, vector<int>& v2) {
        return (v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]);
    }
    // 在圆里
    bool incirc(vector<int>& v, vector<double>& ct, int& r2) {
        if(pow(ct[0] - (double)v[0], 2) + pow(ct[1] - (double)v[1], 2) <= (double)r2) return true;
        return false;
    }
    // 圆心位置
    vector<vector<double>> center(vector<int>& v1, vector<int>& v2, int& r2, int& dis) {
        //两个圆心
        vector<vector<double>> ct(2, vector<double>(2));
        //两个点中点到圆心之间的距离
        double dc = pow((double)r2 - (double)dis / 4, 0.5);
        //两点中点坐标
        vector<double> mid(2);
        mid[0] = (double)(v1[0] + v2[0]) / 2;
        mid[1] = (double)(v1[1] + v2[1]) / 2;
        double tantheta, costheta, sintheta;
        if(v1[1] != v2[1]) {
            tantheta = (double)(v2[0] - v1[0]) / (v1[1] - v2[1]);  //k1*k2=-1
            if(tantheta >= 0) {
                costheta = 1. / pow(tantheta * tantheta + 1., 0.5);
                sintheta = tantheta * costheta;
            }
            else {
                costheta = -1. / pow(tantheta * tantheta + 1., 0.5); //<0
                sintheta = tantheta * costheta;                      //>0
            }
        }
        else {
            sintheta = 1;
            costheta = 0;
        }
        ct[0][0] = mid[0] - dc * costheta;
        ct[0][1] = mid[1] - dc * sintheta;
        ct[1][0] = mid[0] + dc * costheta;
        ct[1][1] = mid[1] + dc * sintheta;
        return ct;
    }
    int numPoints(vector<vector<int>>& points, int r) {
        // 给定两点，dis<2r，那么过这两个点的圆有2个，计算园内的点
        int n = points.size();
        int res = 1;
        int r2 = r * r;
        int dm = 4 * r2;  // 直径^2
        vector<vector<double>> ct(2, vector<double>(2));   // 两个圆心(x, y)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dis = dis2(points[i], points[j]);
                if(dis > dm) continue;
                ct = center(points[i], points[j], r2, dis);
                int now1 = 2, now2 = 2;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    if(incirc(points[k], ct[0], r2)) now1++;
                    if(incirc(points[k], ct[1], r2)) now2++;
                }
                res = max(max(res, now1), now2);
            }
        }
        return res;
    }
};
