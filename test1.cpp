#include "redblacktree.h"

int main(){
	rb_tree mytree;
	mytree.push(6);
	mytree.push(3);
	mytree.push(7);
	mytree.push(9);
	mytree.push(8);
	mytree.push(2);
	mytree.push(1);
	mytree.push(4);
	mytree.push(5);

	if(mytree.push(5)){
		cout << "that shouldn't have worked\n";
	}
	mytree.preorder();
	return 0;
}
