// 自定义字符串大小的排序，不稳定排序
vector<string> st;
sort(st.begin(), st.end(), [](string &a, string &b){return a.size() < b.size();});

// 比较类，应用加()
struct cmp{
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
        // 字符串长度小的在前面，长度相同的保持原来list中的相对位置
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
        return a.second < b.second;
    }
};
vector<pair<string, int>> st; // 字符串，原来的相对位置
sort(st.begin(), st.end(), cmp());  //cmp加()

// 外部比较函数，这里static必须加
static bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
    return a.second < b.second;
}
vector<pair<string, int>> st; // 字符串，原来的相对位置
sort(st.begin(), st.end(), cmp);  //不用加()

//------------------------
vector<int>& A;
// 自定义比较的函数，并且利用引用减少调用时间
// 比较 (Compare) 形参的定义，使得若其第一参数在弱序中先于其第二参数则返回 true 。(a, b) a<b为true返回a
// 但因为 priority_queue 首先输出最大元素，故“先来”的元素实际上最后输出。即队列头含有按照 比较 (Compare) 所施加弱序的“最后”元素。
auto cmp = [&A](vector<int>& a, vector<int>& b) {
    //A[a[0]]/A[a[1]] - A[b[0]]/A[b[1]]
    return A[a[0]] * A[b[1]] > A[a[1]] * A[b[0]];
    // 返回true，a>b，priority_queue 输出b（要求从小到大输出）
};  // 需要分号结尾
priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

//-------------------------
// http://www.cplusplus.com/reference/set/multiset/multiset/
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};
multiset<int,classcomp> fifth;                // class as Compare

bool fncomp (int lhs, int rhs) {return lhs<rhs;}
bool(*fn_pt)(int,int) = fncomp;
multiset<int,bool(*)(int,int)> sixth (fn_pt); // function pointer as Compare
