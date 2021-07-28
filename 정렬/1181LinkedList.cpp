// 단어 정렬하기
// 단어가 입력되면 배열에서 맞는 위치를 찾아가는 방법을 사용한다
// 단어의 순서 계산법은 길이 -> 알파벳 대조 순서로 한다
// 연결리스트를 통해 구현해 봤다
// 결과 - 시간초과

#include <iostream>
#define MAXIMUM 20001

using namespace std;

struct Node
{
  public:
     string data;
     Node* next = nullptr;
};

void printList(Node* h)
{
  Node* curr = h;
  while(curr->next != nullptr)
  {
    printf("%s\n", curr->data);
    //cout << curr->data << endl;
    curr = curr->next;
  }
}

// curr == newNode return 2
// curr > newNode return 1
// curr < newNode return 0
int compareString(string s1, string s2)
{
    if(s1.length() > s2.length())
    {
      return 1;
    }
    else if (s1.length() < s2.length())
    {
      return 0;
    }

    for(int i = 0; i < s1.length(); i++)
    {
      int c1 = s1.at(i) - '\0';
      int c2 = s2.at(i) - '\0';

      if(c1 > c2)
      {
        return 1;
      }
      else if(c1 < c2)
      {
        return 0;
      }
    }

    return 2;
}

void insertList(Node* h, Node* newNode)
{
  Node* curr = h;
  Node* prev;

  while(curr->next != nullptr)
  {
    if(compareString(curr->data, newNode->data) == 1)
    {
      prev->next = newNode;
      newNode->next = curr;
      return;
    }

    prev = curr;
    curr = curr->next;
  }

  prev->next = newNode;
  newNode->next = curr;
}

int checkDup(Node* h, Node* newNode)
{
  Node* curr = h;

  while(curr->next != nullptr)
  {
    if(compareString(curr->data, newNode->data) == 2)
    {
      return 1;
    }
    curr = curr->next;
  }

  return 0;
}

int main()
{
  int i, n;
  Node* head = nullptr;

  cin >> n;

  for(i = 0; i < n; i++)
  {
    string e;
    cin >> e;

    Node* node = new Node();
    node->data = e;

    if(head == nullptr)
    {
      Node* empty = new Node();
      empty->data = "";

      head = node;
      head->next = empty;
    }
    else
    {
      int dup = checkDup(head, node);

      if(!dup)
      {
        // compare to head first
        if(compareString(head->data, node->data))
        {
          node->next = head;
          head = node;
        }
        else
        {
          insertList(head, node);
        }
      }
    }
  }

  printList(head);
  return 0;
}
