class tnode{
	int val;
	tnode left;
	tnode right;
}

class tree{
	public static void main(String[] args){
		tnode root = new tnode();
		root.val = 1;
		root.left = null;
		root.right = null;
		System.out.println(root.val);
	}
	int maxdepth(tnode root){
		if(null == root)
			return 0;
		return Math.max(maxdepth(root.left),maxdepth(root.right))+1;
	}
	
	}