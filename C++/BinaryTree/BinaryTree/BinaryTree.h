#pragma once
#include <iostream>
#include<queue>
#include<stack>
using namespace std;
#include<assert.h>

#if 0
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& x)
		:_left(NULL)
		, _right(NULL)
		, _data(x)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(T* a, size_t n, const T& invalid)
	{
		size_t index = 0;
		_root = CreateTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& t);//�������캯��
	BinaryTree<T>& operator = (const BinaryTree<T>& t);
	~BinaryTree()//��������(�������)
	{
		Destroy(_root);
	}
	void Destroy(Node* root)//��Ա����
	{
		if (root == NULL)
		{
			return;
		}
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

	void PrevOrderNonR()//�ǵݹ鷽ʽǰ�����
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.pop();
			s.pop();

			//������ķ�ʽ����������
			cur = top->_right;


		}
	}
	void InOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node*top = s.pop();
			s.pop;
			cout << top->_data << " ";
			//������������ѭ�������⣩
			cur = top->_right;
		}
	}
	void PostOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);//ѹջ cur
				cur = cur->_left;
			}
			Node* top = s.pop();
			if (top->_right == NULL)//������pop������������δ����
			{
				cout << top->_data << " ";
			}
			cur = top->_right;
		}
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
	//void LevelOrder();//��α���
	void LevelOrder()
	{
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (!q.empty())
		{
			Node* front = q.front();
			cout << front->_data << " ";
			if (front->_left)
			{
				q.push(front->_left);
			}
			if (front->_right)
			{
				q.push(front->_right);
			}
			q.pop();
		}
		cout << endl;
	}

	//size_t Size();//�������
	size_t Size()
	{
		return _Size(_root);
		cout << endl;
	}
	//size_t LeafSize();//Ҷ�ӽ�����
	size_t LeafSize()
	{
		return _LeafSize(_root);
		cout << endl;
	}
	//size_t GetKLevel(size_t k);//ĳ�������
	/*
	size_t GetKLevel(size_t k)
	{
		assert(k > 0);
	}
	*/
	//size_t Depth();//����������
	size_t Depth()
	{
		return _Depth(_root);
	}
	//Node* Find(const T& x);//��һ�����Ƿ��������
	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}


protected:

	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == x)
		{
			return root;
		}
		Node* ret = _Find(root->_left, x);
		if (ret)
		{
			return ret;
		}
		return _Find(root->_right, x);
	}
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_PrevOrder(root->_left);
		cout << root->_data << " ";
		_PrevOrder(root->_right);
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	size_t _Size(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return _Size(root->_left) + _Size(root->_right);
	}
	size_t _LeafSize(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			return 1;
		}
		return _LeafSize(root->_left) + _LeafSize(root->_right);
	}
	size_t _GetLevel(Node* root, size_t k)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (k == 1)
		{
			return 1;
		}
		return _GetLevel(root->_left, k - 1) + _GetLevel(root->_right, k - 1);
	}
	size_t _Depth(Node *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			return 1;
		}
		size_t left = _Depth(root->_left);
		size_t right = _Depth(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	Node* CreateTree(T* a, size_t n, const T& invalid, size_t& index)
	{
		//ǰ����������
		Node* root = NULL;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = CreateTree(a, n, invalid, ++index);
			root->_right = CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
protected:
	Node* _root;
};

#endif
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};
//ǰ�����������
void preorder(TreeNode* root)
{
	if (root != nullptr)
	{
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
//�������������
void inorder(TreeNode* root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}
//��������������
void postorder(TreeNode* root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}
//�������������
//������������
//��������С���
//���������
//������������
//��������ķǵݹ�
void inorder(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* pCur = root;
	while (pCur != nullptr || !s.empty())
	{
		while(pCur != nullptr)
		{
			s.push(pCur);
			pCur = pCur->left;
		}
		TreeNode* top = s.top();
		cout << top->data;
		s.pop();
		pCur = pCur->right;
	}
	cout << endl;
}