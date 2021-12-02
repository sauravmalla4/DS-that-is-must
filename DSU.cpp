class DSU{
        vector<int> parent;
        vector<int> rank;
        public:
        DSU(int n):parent(n),rank(n){
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }
        int Find(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=Find(parent[u]);
        }
        void Union(int u,int v){
            u=Find(u);
            v=Find(v);
            if(u!=v){
                if(rank[u]<rank[v]){
                    swap(u,v);
                }
                parent[v]=u;
                if(rank[u]==rank[v]){
                    rank[u]++;
                }
            }
        }
};
