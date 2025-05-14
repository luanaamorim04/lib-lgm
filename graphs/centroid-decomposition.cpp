vector<int> adj[MAXN];
vector<int> centroid_tree[MAXN];
int is_removed[MAXN];
int subtree_size[MAXN];
int pai[MAXN];

int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) continue;
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) continue;
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

int build_centroid_decomp(int node = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));

	is_removed[centroid] = 1;

	for (int child : adj[centroid]) {
		if (is_removed[child]) continue;
		int child_centroid = build_centroid_decomp(child);
        	centroid_tree[centroid].push_back(child_centroid);
        	centroid_tree[child_centroid].push_back(centroid);
        	pai[child_centroid] = centroid;
	}

    return centroid;
}
