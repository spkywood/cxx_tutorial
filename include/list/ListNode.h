
//�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
template <typename T>
struct ListNode {
	T data;				// ����
	ListNode<T> pre;	// ǰ���ڵ�
	ListNode<T> next;	// ��̽ڵ�

	ListNode() {}

	ListNode(T e, ListNode<T> p = NULL, ListNode<T> n = NULL)
		: data(e), pre(p), next(n) {} //Ĭ�Ϲ�����

	// �����ӿ�
	ListNode<T> insertAsPre(T const& e) {
		ListNode<T> x = new ListNode(e, pre, this); //�����½ڵ�
		pre->next = x; 
		pre = x; //������������
		return x; //�����½ڵ��λ��
	}
	//������ǰ�ڵ�֮ǰ�����½ڵ�
	
	ListNode<T> insertAsNext(T const& e) {
		ListNode<T> x = new ListNode(e, this, next); //�����½ڵ�
		next->pre = x; 
		next = x; //������������
		return x; //�����½ڵ��λ��
	}
	//���浱ǰ�ڵ�֮������½ڵ�
};

template <typename T>
ListNode<T>::insertAsPre(T const& e) 