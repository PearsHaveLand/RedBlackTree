#ifndef REDBLACKTREE
#define REDBLACKTREE

#include "rbnode.h"
#include "pow.h"

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
	bool preorder();
	int get_min();
	int get_max();
	rb_tree& operator=(const rb_tree& other);
private:
	unsigned long get_height(rb_node *root);
	void set_height();
	bool push(int val, rb_node *root);
	bool pop(int val, rb_node *root);
	bool find(int val, rb_node *root);
	void preorder(rb_node *root, unsigned long index);
	int get_min(rb_node *root);
	int get_max(rb_node *root);
	void rebalance(rb_node *root);
	void del_tree(rb_node *root);
	void clear_vals();
	bool init_vals();
	void print_vals();
	unsigned long m_size;
	unsigned long m_height;
	rb_node *m_root;
	int *m_vals;
	unsigned long m_vals_size;
};

#endif
