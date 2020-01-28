struct trie {
	struct node {
		node *next[26][2];
		int words=0;
		node() {
			for(int i=0;i<26;i++) next[i][0]=next[i][1]=NULL;
		}
	};
	node *root=NULL;
	trie() {
		root=new node();
	}
	pair<int,int> get(char x)
	{
		if('a'<=x&&x<='z') return {x-'a',0};
		return {x-'A',1};
	}
	void insert(string x)
	{
		int n=x.size();
		node *now=root;
		for(int i=0;i<n;i++) {
			pair<int,int> id=get(x[i]);
			if(now->next[id.first][id.second]==NULL)
				now->next[id.first][id.second]=new node();
			now=now->next[id.first][id.second];
		}
		now->words++;
	}
	int search(string x) {
		int n=x.size();
		node *now=root;
		for(int i=0;i<n;i++)
		{
			pair<int,int> id=get(x[i]);
			if(now->next[id.first][id.second]==NULL) return 0;
			else now=now->next[id.first][id.second];
		}
		return now->words;
	}
	void del(node *x) {
		for(int i=0;i<26;i++)
		{
			if(x->next[i][0]) del(x->next[i][0]);
			if(x->next[i][1]) del(x->next[i][1]);
		}
		delete(x);
	}
	void del() {
		del(root);
	}
};
