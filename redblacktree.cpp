#include "redblacktree.h"
rb_tree::rb_tree(){}
rb_tree::~rb_tree(){}
rb_tree::rb_tree(const rb_tree& other){}
bool rb_tree::empty(){
	return (m_size > 0) ? true : false;
}

//Bootstraps
unsigned long rb_tree::get_height(){
	if(!empty()){
		return get_height(m_root);
	}
	else{
		return 0;
	}
}
bool rb_tree::push(int val){
	if(empty()){
		m_root = new rb_node(val);
		return true;
	}
	else{
		return push(val, m_root); 
	}
}
bool rb_tree::pop(int val){ return pop(val, m_root); }
bool rb_tree::find(int val){ return find(val, m_root); }
void rb_tree::preorder(){ preorder(m_root); }
int rb_tree::get_min(){ return get_min(m_root); }
int rb_tree::get_max(){ return get_max(m_root); }

unsigned long rb_tree::get_height(rb_node *root){
	unsigned long l_height = 0, r_height = 0;
	
	//If children exist, get their height
	if(root->get_left()){
		l_height = get_height(root->get_left());
	}
	if(root->get_right()){
		r_height = get_height(root->get_right());
	}
	
	//Return greatest height
	if(l_height > r_height){
		return l_height;
	}
	else{
		return r_height;
	}
}

bool rb_tree::push(int val, rb_node *root){
	bool pushed = false;
	rb_node *temp;
	
	//If value is less than root val
	if(val < root->get_val()){
		
		//If root has left child, try pushing to left subtree
		if(root->get_left()){
			pushed = push(val, root->get_left());
		}
		
		//If no left child, point left child to temp
		else{
			pushed = true;
			temp = new rb_node(val);
			root->set_left(temp);
		}
	}
	
	//If value is greater than root val
	else if(val > root->get_val()){
		
		//If root has right subtree, push to that subtree
		if(root->get_right()){
			pushed = push(val, root->get_right());
		}
		
		//If no left child, point right child to temp
		else{
			pushed = true;
			temp = new rb_node(val);
			root->set_right(temp);
		}
	}
	
	//Will return false if equal
	return pushed;
}
/*
bool rb_tree::pop(int val, rb_node *root){}
bool rb_tree::find(int val, rb_node *root){}
*/
void rb_tree::preorder(rb_node *root){
}
/*
int rb_tree::get_min(rb_node *root){}
int rb_tree::get_max(rb_node *root){}
void rb_tree::rebalance(rb_node *root){}
void rb_tree::del_tree(rb_node *root){}
rb_tree& rb_tree::operator=(const rb_tree& other){}
*/