struct TrieNode{
    int child[AlphaSize];
    bool end = false;

    TrieNode(){
        fill(child, child + AlphaSize, -1);
    }
};

vector<TrieNode> trie(1);

// adiciona strings na Trie
void add_string(string const& s){
    // vértice atual
    int v=0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c] == -1){
            trie[v].child[c] = trie.size();
            // adiciona o novo vértice/nó
            trie.emplace_back();
        }
        v = trie[v].child[c];
    }
    trie[v].end = true;
}

bool search(string const& s){
    int v=0;
    for(auto ch:s){
        int c = ch - 'a';
        if(trie[v].child[c]==-1) return false;
        v = trie[v].child[c];
    }

    if(trie[v].end==true) return true;
    return false;
}

bool search_prefix(string const& s){
    int v=0;
    for(auto ch:s){
        int c = ch - 'a';
        if(trie[v].child[c]==-1) return false;
        v = trie[v].child[c];
    }

    return true;
}
