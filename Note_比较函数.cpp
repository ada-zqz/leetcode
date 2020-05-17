// 自定义字符串大小的排序，不稳定排序
vector<string> st;
sort(st.begin(), st.end(), [](string &a, string &b){return a.size() < b.size();});

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

