#include "redblacktree.h"

int main(){
	rb_tree mytree;
	cout << mytree.push(1) << endl;
	cout << mytree.push(2) << endl;
	cout << mytree.push(3) << endl;
	cout << mytree.push(4) << endl;
	mytree.preorder();
	return 0;
}
