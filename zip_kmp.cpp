int KMPStrMatching(string T, string P, int *N, int start) {
    int j = 0;                          //模式P的下标
    int i = start;                      //母串T的下标
    int plen = P.length();
    int tlen = T.length();
    if(tlen - start < plen) return -1;
    while(j < plen && i < tlen) {
        if(j == -1 || T[i] == P[j]) {
            i++; j++;   
        }
        else j = N[j];
    }
    if(j >= plen) return (i - plen);
    else return -1;
}

int findNext(string P) {
    int j, k;
    int m = P.length();
    // assert(m > 0);          //若m = 0，退出
    int *next = new int[m];
    // assert(next != 0);      //若开辟存储区域失败，退出
    next[0] = -1;
    j = 0; k = -1;
    while(j < m - 1) {
        while(k >= 0 && P[k] != P[j])
            k = next[k];
        j++; k++;
        if(P[k] == P[j])
            next[j] = next[k];
        else next[j] = k;
    }
    return next;
}
