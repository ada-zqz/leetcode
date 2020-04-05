class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int r2 = radius * radius;
        if(x_center <= x2 && x_center >= x1 && y_center <= y2 + radius && y_center >= y1 - radius) return true;
        if(x_center <= x2 + radius && x_center >= x1 - radius && y_center <= y2 && y_center >= y1) return true;
        if(dist(x_center, y_center, x2, y2) <= r2 || dist(x_center, y_center, x1, y1) <= r2 || 
           dist(x_center, y_center, x1, y2) <= r2 ||dist(x_center, y_center, x2, y1) <= r2) return true;
        return false;
    }
    int dist(int xc, int yc, int xs, int ys) {
        return (xc - xs) * (xc - xs) + (yc - ys) * (yc - ys);
    }
};
