
//列表节点模板类（以双向链表形式实现）
template <typename T>
struct ListNode {
	T data;				// 数据
	ListNode<T> pre;	// 前驱节点
	ListNode<T> next;	// 后继节点

	ListNode() {}

	ListNode(T e, ListNode<T> p = NULL, ListNode<T> n = NULL)
		: data(e), pre(p), next(n) {} //默认构造器

	// 操作接口
	ListNode<T> insertAsPre(T const& e) {
		ListNode<T> x = new ListNode(e, pre, this); //创建新节点
		pre->next = x; 
		pre = x; //设置正向链接
		return x; //返回新节点的位置
	}
	//紧靠当前节点之前插入新节点
	
	ListNode<T> insertAsNext(T const& e) {
		ListNode<T> x = new ListNode(e, this, next); //创建新节点
		next->pre = x; 
		next = x; //设置逆向链接
		return x; //返回新节点的位置
	}
	//紧随当前节点之后插入新节点
};

template <typename T>
ListNode<T>::insertAsPre(T const& e) 