struct segtree {
	struct node {
		node *left,*right;
		int data,lazy;
		int id;
		int l,r;
		node(int a,int b) {
			left=NULL,right=NULL;
			data=lazy=0;
			l=a,r=b;
		}
		update(int v) {
			data+=(r-l+1)*v;
			lazy+=v;
		}
		extend() {
			int m=(l+r)/2;
			left=new node(l,m);
			right=new node(m+1,r);
		}
		propagate() {
			left->update(lazy);
			right->update(lazy);
			lazy=0;
		}
		
	};
	node *root;
	segtree(int l,int r) {
		root=new node(l,r);
	}
	void update(node *now,int l,int r,int v)
	{
		if(r<now->l || now->r<l) return;
		if(l<=now->l && now->r<=r) {
			now->update(v);
			return;
		}
		if(now->left==NULL) now->extend();
		now->propagate();
		update(now->left,l,r,v);
		update(now->right,l,r,v);
		now->data=now->left->data+now->right->data;
	}
	void update(int l,int r,int v) {
		update(root,l,r,v);
	}
	int query(node *now,int l,int r)
	{
		if(now->l>r || now->r<l) return 0;
		if(l<=now->l && now->r<=r) {
			return now->data;
		}
		if(now->left==NULL) now->extend();
		now->propagate();
		return query(now->left,l,r)+query(now->right,l,r);
	}
	int query(int l,int r) {
		return query(root,l,r);
	}
};
