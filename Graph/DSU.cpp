DSU -> https://www.youtube.com/watch?v=qHZxfNKUMXw
DSU vs DFS -> https://www.youtube.com/watch?v=pNSZT8WyAdM


public class DisjointSetUnion {
    int[] p,rank,setSize;
    public DisjointSetUnion(int N) {
        p=new int[N];
        rank=new int[N];
        setSize=new int[N];
        for(int i=0;i<N;i++) {
            p[i]=i;
            setSize[i]=1;
        }
    }
    public int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
    public boolean isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    public void union(int i,int j) {
        if (isSameSet(i, j)) return;
        int x=findSet(i),y=findSet(j);
        if(rank[x]>rank[y]) {
            p[y] = x; setSize[x] += setSize[y];
        } else {
            p[x] = y; setSize[y] += setSize[x];
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    public int sizeOfSet(int i) { return setSize[findSet(i)]; }
}
