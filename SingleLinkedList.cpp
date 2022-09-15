#include <iostream>

template <typename T>
class list {
private:
  struct Node {
    T val;
    Node* next;

    Node(T _val) : val(_val), next(nullptr) {}
  };

  Node* first;
  Node* last;
  
public:
  list() : first(nullptr), last(nullptr) {}

  bool is_empty()
  {
    return first == nullptr;
  }

  void push_front(T _val)
  {
    Node* p = new Node(_val);
    if (is_empty())
    {
      first = p;
      last = p;
      return;
    }
    p->next = first;
    first = p;
  }

  void push_back(T _val)
  {
    Node* p = new Node(_val);
    if (is_empty())
    {
      first = p;
      last = p;
      return;
    }
    last->next = p;
    last = p;
  }

  void print()
  {
    if (is_empty())
      return;
    Node* p = first;
    while (p)
    {
      std::cout << p->val;
      p = p->next;
    }
    std::cout << std::endl;
  }

  Node* find(T _val)
  {
    Node* p = first;
    while (p && p->val != _val)
      p = p->next;
    return (p && p->val == _val) ? p : nullptr;
  }

  void remove_first() {
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
  }

  void remove_last()
  {
    if (is_empty())
      return;
    if (first == last)
    {
      remove_first();
      return;
    }
    Node* p = first;
    while (p->next != last)
      p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
  }

  void remove(T _val)
  {
    if (is_empty())
      return;
    if (first->val == _val)
    {
      remove_first();
      return;
    }
    else if (last->val == _val)
    {
      remove_last();
      return;
    }

    Node* f = first;
    Node* n = first->next;

    while (n && n->val != _val)
    {
      f = f->next;
      n = n->next;
    }

    if (!n)
    {
      std::cout << "Element not found";
      return;
    }

    f->next = n->next;
    delete n;
  }

  Node* operator [](const int index)
  {
    if (is_empty())
      return nullptr;
    Node* p = first;

    for (int i = 0; i < index; i++)
    {
      p = p->next;
      if (!p) return nullptr;
    }

    return p;
  }
};

int main()
{
}
