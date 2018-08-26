#include <iostream>
using namespace std;

template <typename T> struct Node{
  T data;
  Node<T> *pNext;
};

template <typename T> class List{
  Node<T> *head, *end;
public:
  List() { head = NULL; end = NULL;}
  void CreateNode(T info);
  void Display();
  void Insert(int pos, T info);
  void Delete(int pos);
  void RemoveDuplicates();
};

template<typename T> void List<T>::CreateNode(T info){
  Node<T> *tmp = new Node<T>;
  tmp->data = info;
  tmp->pNext = NULL;
  if(!head) {
    head = tmp;
    end = tmp;
    tmp = NULL;
  } else {
    end->pNext = tmp;
    end = tmp;
  }
}

template <typename T> void List<T>::Display(){
  Node<T> *tmp = new Node<T>;
  tmp = head;
  while(tmp){
    cout << tmp->data << "\t";
    tmp = tmp->pNext;
  }
  cout << endl;
}

template <typename T> void List<T>::Insert(int pos, T info){
  Node<T> *prev = new Node<T>;
  Node<T> *cur = new Node<T>;
  Node<T> * tmp = new Node<T>;
  cur = head;
  for(int i = 1; i < pos; i++){
    prev = cur;
    cur = cur->pNext;
  }
  tmp->data = info;
  prev->pNext = tmp;
  tmp->pNext = cur;
}

template <typename T> void List<T>::Delete(int pos){
  Node<T> *cur = new Node<T>;
  Node<T> *prev = new Node<T>;
  cur = head;
  for(int i = 1; i < pos; i++){
    prev = cur;
    cur = cur->pNext;
  }
  prev->pNext = cur->pNext;
}

template <typename T> void List<T>::RemoveDuplicates(){
  int pos;
  Node<T> *tmp = new Node<T>;
  Node<T> *flag = new Node<T>;
  tmp = head;
  while(tmp){
    flag = head;
    pos = 0;
    while(flag){
        if(tmp->data == flag->data && tmp != flag) this->Delete(pos);
        pos++;
        flag = flag->pNext;
    }
    tmp = tmp->pNext;
  }
}


int main(){
  List<int> list;
  for(int i = 0; i < 5; i++){
    list.CreateNode(i);
  }
  list.CreateNode(4);
  list.Display();
  list.Insert(2, 120);
  list.Display();
  list.Delete(3);
  list.Display();
  list.RemoveDuplicates();
  list.Display();
  return 0;
}
