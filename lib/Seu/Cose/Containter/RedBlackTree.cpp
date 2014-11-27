/**
/**
 *红黑树，满足以下性质，即只有满足以下全部性质的树，我们才称之为红黑树：
1）每个结点要么是红的，要么是黑的。
2）根结点是黑的。
3）每个叶结点（叶结点即指树尾端NIL指针或NULL结点）是黑的。
4）如果一个结点是红的，那么它的俩个儿子都是黑的。
5）对于任一结点而言，其到叶结点树尾端NIL指针的每一条路径都包含相同数目的黑结点。
应用：
红黑树的应用比较广泛，主要是用它来存储有序的数据，它的时间复杂度是O(lgn)，效率非常之高。
例如，Java集合中的TreeSet和TreeMap，C++ STL中的set、map，以及Linux虚拟内存的管理，都是通过红黑树去实现的。
 */
enum RBTColor{BLACK,RED};
template<class T>
class RBTNode
{
	T data;
	T key;
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;
	RBTColor color;
	RBTNode(T value,RBTColor c,RBTNode* p,RBTNode* l,RBTNode* r):
	key(value),color(c),left(l),parent(p),right(r)
	{}
}RBTreeNode;

#ifndef RBTREE
#define RBTREE
template<class T>
class RBTree
{
	private:
		RBTreeNode<T>* mRoot;//根节点
		
	public:
		RBTree();
		RBTree(const RBTree&);
		RBTree(const RBTreeNode& _head);
		//插入一个树节点
		void insertNode(const RBTreeNode&);
		//删除一个树节点
		RBTreeNode& deleteNode();
		~RBTree();
		//前序遍历
		void preOrder();
		//中序遍历
		void inOrder();
		//后序遍历
		void postOrder();

		//递归实现查找“红黑树”中键值为key的节点
		RBTNode<T>* search(T key);
		//非递归实现查找“红黑树”中键值为key的节点
		RBTNode<T>* iterativeSearch(T key);

		T minimum();
		T maximum();
		//查找T节点的后继节点
		RBTNode<T>* successor(RBTNode<T>* x);
		//查找x节点的前驱节点
		RBTNode<T>* predecessor(RBTNode<T>* x);
		//删除节点
		void remove(T key);
		//插入节点
		void insert(T key);
		//销毁红黑树
		void destroy();
		//打印红黑树
		void print();
	private:
		void preOrder(RBTNode<T>* tree)const;
		void inOrder(RBTNode<T>* tree)const;
		void postOrder(RBTNode<T>* tree)const;

		RBTNode<T>* search(RBTNode<T> * x,T key)const;
		RBTNode<T>* iterativeSearch(RBTNode<T> * x,T key)const;
		//查找最小节点：返回tree为根节点的红黑树的最小节点
		RBTNode<T>* minimum(RBTNode<T> * x);
		//查找最大节点：返回tree为根节点的红黑树的最大节点
		RBTNode<T>* maximum(RBTNode<T> * x);

		//左旋
		void leftRotate(RBTNode<T>* &root,RBTNode<T>* x);
		//右旋
		void  rightRotate(RBTNode<T>* &root,RBTNode<T>* x);
		//插入函数
		void insert(RBTNode<T>* &root,RBTNode<T>* x);
		//插入修正函数
		void insertFixUp(RBTNode<T>* &root,RBTNode<T>* node);
		//销毁红黑树
		void destroy(RBTNode<T>* &tree,T key,int direction);

	/*	RBTNode<T>* parent(RBTNode<T>* x)
		{
			return x->parent;
		}&*/

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color==RED)
#define rb_is_black(r) ((r)->color==BLACK)
#define rb_set_black(r) do{(r)->color=RED;}while(0)
#define rb_set_black(r) do{(r)->color=RED;}while(0)
#define rb_set_parent(r) do{(r)->color=BLACK;}while(0)
#define rb_set_color(r,c) do{(r)->color=(c);}while(0)
};
#endif
RBTree::RBTree()
{
	
}
void RBTree::adjusted()
{
	
}
void insertNode(const RBTreeNode& node)
{
	
}