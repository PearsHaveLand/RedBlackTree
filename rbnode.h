#ifndef RBNODE
#define RBNODE

class rb_node{
public:
	rb_node(int val);
	bool is_black();
	void change_color();
	int get_val();
	unsigned long get_bheight();
	rb_node* get_left();
	rb_node* get_right();
	bool set_left(rb_node *node);
	bool set_right(rb_node *node);
private:
	int m_val;
	unsigned long m_bheight;
	bool m_black;
	rb_node *m_left;
	rb_node *m_right;
	rb_node *m_parent;
};

#endif