// please include std::vector, std::pair, std::string
/*
  Author : haruki291sa
  written on 2023-03-23(yyyy-mm-dd)
  Maximum size of trie is 1e6. Please be careful when using it.
  Search(s) : if string s in the trie, return true. otherwise return false;
  Insert(s) : inserts string s into the trie.
  _size : size of trie
*/
#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
struct TRIE{
    vector<pair<int,int> >vp[1000003];
    int _size=1;
    void __True_Insert(int i,int n,string &S){
        int len=S.size();
        bool flag=true;
        for(int j=0;j<(int)vp[i].size();j++){
            int nxt=vp[i][j].first,w=vp[i][j].second;
            if(S[n]==w){
                __True_Insert(nxt,n+1,S);
                flag=false;
                break;
            }
        }
        if(flag){
            int k=i;
            for(int j=n;j<len;j++){
                vp[k].push_back({++_size,S[j]});
                k=_size;
            }
        }
    }
    bool __True_Search(int i,int n,string &S){
        if(n==(int)S.size())return true;
        for(int j=0;j<(int)vp[i].size();j++){
            int nxt=vp[i][j].first,w=vp[i][j].second;
            if(S[n]==w)return __True_Search(nxt,n+1,S);
        }
        return false;
    }
    void Insert(string &S){
        __True_Insert(1,0,S);
    }
    bool Search(string &S){
        return __True_Search(1,0,S);
    }
};


#endif // TRIE_H_INCLUDED
