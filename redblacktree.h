#ifndef REDBLACKTREE
#define REDBLACKTREE

#include "rbnode.h"

class rb_tree{
public:
	rb_tree();
	~rb_tree();
	rb_tree(const rb_tree& other);
	bool empty();
	unsigned long get_height();
	bool push(int val);
	bool pop(int val);
	bool find(int val);
	void preorder();
	int get_min();
	int get_max();
	rb_tree& operator=(const rb_tree& other);
private:
	unsigned long get_height(rb_node *root);
	bool push(int val, rb_node *root);
	bool pop(int val, rb_node *root);
	bool find(int val, rb_node *root);
	void preorder(rb_node *root);
	int get_min(rb_node *root);
	int get_max(rb_node *root);
	void rebalance(rb_node *root);
	void del_tree(rb_node *root);
	unsigned long m_size;
	unsigned long m_height;
	rb_node *m_root;
};
	
#endif