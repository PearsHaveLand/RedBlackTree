#include "redblacktree.h"
rb_tree::rb_tree(){
	m_size = 0;
	m_height = 0;
	m_root = NULL;
	m_vals = NULL;
}

rb_tree::~rb_tree(){
	del_tree(m_root);
	clear_vals();
}

rb_tree::rb_tree(const rb_tree& other){}

/*
Checks if tree is empty
Returns true if empty
	false if not
*/
bool rb_tree::empty(){
	return (m_size > 0) ? true : false;
}

//Bootstraps
unsigned long rb_tree::get_height(){
	return get_height(m_root);
}

bool rb_tree::push(int val){
	bool pushed;
	if(m_root){
		pushed = push(val, m_root);
	}
	else{
		m_root = new rb_node(val);
		pushed = true;
	}
	if(pushed){
		set_height();
		m_size++;
	}
	return pushed;
}
bool rb_tree::pop(int val){ return pop(val, m_root); }
bool rb_tree::find(int val){ return find(val, m_root); }

bool rb_tree::preorder(){
	bool exists = (init_vals()) ? true : false;
	if(exists && m_root){
		preorder(m_root, 1);
		print_vals();
	}
	else{
		cout << "error, unable to allocate tree buffer\n";
	}
	return exists;
}

int rb_tree::get_min(){ return get_min(m_root); }
int rb_tree::get_max(){ return get_max(m_root); }

/*
get_height
Returns the height of the current node's subtree
*/
unsigned long rb_tree::get_height(rb_node *root){
	unsigned long l_height = 0, r_height = 0;

	if(root){
		//If children exist, get their height
		if(root->get_left()){
			l_height = get_height(root->get_left());
		}
		if(root->get_right()){
			r_height = get_height(root->get_right());
		}
		//Return greatest height
		if(l_height > r_height){
			return l_height + 1;
		}
		else{
			return r_height + 1;
		}
	}
	else{
		return 0;
	}
}

void rb_tree::set_height(){
	m_height = get_height();
}

/*
push
Returns whether or not val was successfully added to root's subtree
returns true if added
	false if not
*/
bool rb_tree::push(int val, rb_node *root){
	bool pushed = false;
	rb_node *temp;

	//If value is less than root val
	if(val < root->get_val()){
		if(root->get_left()){
			//If root has left child, try pushing to left subtree
			pushed = push(val, root->get_left());
		}
		else{
			temp = new rb_node(val);
			root->set_left(temp);
			pushed = true;
		}
	}
	//If value is greater than root val
	else if(val > root->get_val()){
		if(root->get_right()){
			//If root has right subtree, push to that subtree
			pushed = push(val, root->get_right());
		}
		else{
			temp = new rb_node(val);
			root->set_right(temp);
			pushed = true;
		}
	}
	//Will return false if equal
	return pushed;
}

bool rb_tree::pop(int val, rb_node *root){return false;}
bool rb_tree::find(int val, rb_node *root){return false;}

void rb_tree::preorder(rb_node *root, unsigned long index){
	m_vals[index] = root->get_val();
	cout << "index*2 = " << index*2 << endl;
	if(root->get_left())
		preorder(root->get_left(), index*2);
	else if (m_vals_size > index*2){
		m_vals[index*2] = -1;
	}
	if(root->get_right())
		preorder(root->get_right(), (index*2) + 1);
	else if (m_vals_size > (index*2) + 1)
		m_vals[(index*2) + 1] = -1;
}

int rb_tree::get_min(rb_node *root){return 0;}
int rb_tree::get_max(rb_node *root){return 0;}
void rb_tree::rebalance(rb_node *root){}
void rb_tree::del_tree(rb_node *root){
	if(root){
		del_tree(root->get_left());
		del_tree(root->get_right());
		delete root;
		root = NULL;
	}
}

void rb_tree::clear_vals(){
	if(m_vals){
		delete [] m_vals;
	}
}

bool rb_tree::init_vals(){
	bool exists;
	//cout << "height: " << m_height << endl;
	//cout << m_root << endl;
	clear_vals();
	m_vals_size = pow(m_height) + 1;
	cout << "arr_size = " << m_vals_size << endl;
	m_vals = new int[m_vals_size];
	exists = (m_vals) ? true : false;
	for(unsigned long i = 0; i < m_vals_size; i++){
		m_vals[i] = -1;
	}
	return exists;
}

void rb_tree::print_vals(){
	for(unsigned long i = 1; i < m_vals_size; i++){
		cout << m_vals[i] << ' ';
	}
	cout << endl;
}

//rb_tree& rb_tree::operator=(const rb_tree& other){}
