#ifndef LISTS_H
#define LISTS_H

template<class T>
class List{
	public:
		List();
		~List();

		struct node{
			T data;
			node* next;
		};
		node* hnode, * lastnode;
		virtual int Size();
		
		virtual void AddFirst(T _data);
		virtual void AddLast(T _data);
		virtual void RemoveData(node* _node);
		virtual void RemoveData(int _n);
		virtual void RemoveData(T _data);
		virtual void RemoveDataAll(T _data);
		virtual bool IsData(T _data);
		virtual T GetFirst();
		virtual T GetLast();
		virtual T GetData(unsigned int _n);

		virtual node* GetNode(unsigned int _n);
		virtual void Clear();
};

template <class T>
List<T>::List(){
	hnode = nullptr;
	lastnode = nullptr;
}

template <class T>
List<T>::~List(){
	Clear();
}

template <class T>
int List<T>::Size(){
	int i = 0;
	node* tempnode = hnode;
	while(tempnode){
		i++;
		tempnode = tempnode->next;
	}
	return i;
}

template <class T>
void List<T>::AddFirst(T _data){
	node* tempnode = new node;
	tempnode->data = _data;
	tempnode->next = hnode;
	hnode = tempnode;
	if(!lastnode){
		lastnode = tempnode;
	}
}

template <class T>
void List<T>::AddLast(T _data){
	node* tempnode = new node;
	tempnode->data = _data;
	tempnode->next = nullptr;
	if(lastnode){
		lastnode->next = tempnode;
	}else{
		hnode = tempnode;
	}
	lastnode = tempnode;
}

template <class T>
void List<T>::RemoveData(node* _node){
	if(_node == hnode){
		if(!_node->next)
			lastnode = nullptr;
		hnode = _node->next;
		delete _node;
		return;
	}
	node* tempnode = hnode;
	while(tempnode->next != _node){
		tempnode = tempnode->next;
	}
	if(!_node->next)
		lastnode = tempnode;
	tempnode->next = _node->next;
	delete _node;
}

template <class T>
void List<T>::RemoveData(int _n){
	node* tempnode = hnode;
	for(int i = 1; i < _n; i++){
		tempnode = tempnode->next;
	}
	RemoveData(tempnode);
}

template <class T>
void List<T>::RemoveData(T _data){
	node* tempnode = hnode;
	while(tempnode){
		if(tempnode->data == _data){
			RemoveData(tempnode);
			return;
		}
		tempnode = tempnode->next;
	}
}

template <class T>
void List<T>::RemoveDataAll(T _data){
	node* tempnode = hnode;
	while(tempnode){
		if(tempnode->data == _data){
			RemoveData(tempnode);
		}
		tempnode = tempnode->next;
	}
}

template <class T>
bool List<T>::IsData(T _data){
	node* tempnode = hnode;
	while(tempnode){
		if(tempnode->data == _data){
			return true;
		}
		tempnode = tempnode->next;
	}
	return false;
}

template <class T>
T List<T>::GetFirst(){
	return hnode->data;
}

template <class T>
T List<T>::GetLast(){
	return lastnode->data;
}

template <class T>
T List<T>::GetData(unsigned int _n){
	return GetNode(_n)->data;
}

template <class T>
class List<T>::node* List<T>::GetNode(unsigned int _n){
	node* tempnode = hnode;
	if(_n)
		_n--;
	while(_n){
		_n--;
		tempnode = tempnode->next;
	}
	return tempnode;
}

template <class T>
void List<T>::Clear(){
	node* tempnode = hnode;
	node* prev;
	while(tempnode){
		prev = tempnode;
		tempnode = tempnode->next;
		delete prev;
	}
	hnode = nullptr;
	lastnode = nullptr;
}

#endif
