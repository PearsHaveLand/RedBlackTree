#ifndef REDBLACKTREE
#define REDBLACKTREE

class rb_tree{
public:
	rb_tree();
	~rb_tree();
	rb_tree(const rb_tree& other);
	bool empty();
	bool get_height();
	bool push(int val);
	bool pop(int val);
	bool find(int val);
	void preorder();
	int get_lowest();
	int get_highest();
	void rebalance(rb_node *root);
	void del_tree(rb_node *root);
	rb_tree& rb_tree::operator=(const rb_tree& other);
private:
	unsigned long m_size;
	unsigned long m_height;
	rb_node *m_root;
};
	
#endif