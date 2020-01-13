struct Video {
    int f, e;
    Video(int first, int end): f(first), e(end) {}
    bool operator < (Video v) {
        return (f < v.f) || (f == v.f && e < v.e);
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<Video> Vd;
        for(int i = 0; i < clips.size(); i++) {
            Vd.push_back(Video(clips[i][0], clips[i][1]));
        }
        sort(Vd.begin(), Vd.end());
        
        if(Vd[0].f > 0 || Vd[Vd.size() - 1].e < T) {
            return -1;
        }

        int nc = 0, e = Vd[0].e, tempe, tempi;
        bool ok;
        for(int i = 0; i < Vd.size(); ) {
            if(Vd[i].e >= T) {return nc + 1;}
            if(i < Vd.size() - 1) {
                if(Vd[i + 1].f == Vd[i].f) {
                    e = Vd[i + 1].e;
                    i++;
                    continue;
                }
                ok = false;
                tempe = e;
                for(int j = Vd.size() - 1; j > i; j--) {
                    if(Vd[j].f <= tempe && Vd[j].e > e) {
                        e = Vd[j].e;
                        tempi = j;
                        ok = true;
                    }
                }
                if(!ok) {return -1;}
                else {
                    nc += 1;
                    i = tempi;
                }
            }
        }
        if(e < T) {return -1;}
        return nc + 1;
    }
};
