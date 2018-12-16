#include "rbnode.h"

rb_node::rb_node(int val){
	m_val = val;
	m_bheight = 1;
	m_black = false;
	m_left = NULL;
	m_right = NULL;
	m_parent = NULL;
}
bool rb_node::is_black(){
	return m_black;
}
void rb_node::change_color(){
	m_black = !m_black;
}
int rb_node::get_val(){
	return m_val;
}
unsigned long rb_node::get_bheight(){
	return m_bheight;
}
rb_node* rb_node::get_left(){
	return m_left;
}
rb_node* rb_node::get_right(){
	return m_right;
}
bool rb_node::set_left(rb_node *node){
	m_left = node;
}
bool rb_node::set_right(rb_node *node){
	m_right = node;
}
