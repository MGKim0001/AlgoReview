// 나이순 정렬
// stable sort - 안정 정렬 - 문제
// 들어온 순서대로 나이순으로 정렬한다
// 안정 정렬은 삽입 정렬, 버블 정렬, 병합 정렬이 있다
// 삽입 정렬을 사용해서 풀었을 때는 시간 초과가 떴다
// stable_sort() 라이브러리를 사용해서 풀었다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Member {
    int age;
    char name[101];
    int join;
};

void insertionSortMems(Member mems[], int size)
{
  int i, j;
  for(i = 0; i < size; i++)
  {
    Member key = mems[i];
    j = i-1;
    for(; j >= 0 && key.age < mems[j].age; j--)
    {
      swap(mems[j], mems[j+1]);
    }
    mems[j+1] = key;
  }
}

bool compare(Member m1, Member m2)
{
  if(m1.age < m2.age)
  {
    return true;
  }
  else if(m1.age == m2.age)
  {
    return m1.join < m2.join;
  }
  else
  {
    return false;
  }
}

bool cmp(Member m1, Member m2)
{
  return m1.age < m2.age;
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<Member> members(n);

  int i;
  for(i = 0; i < n; i++)
  {
    int age;
    string name;
    //cin >> members[i].age >> members[i].name;
    scanf("%d %s", &members[i].age, members[i].name);
    members[i].join = i;
  }

  //insertionSortMems(members, n);
  sort(members.begin(), members.end(), compare);
  //stable_sort(members.begin(), members.end(), cmp);

  for(i = 0; i < n; i++)
  {
    //cout << members[i].age << " " << members[i].name << endl;
    printf("%d %s\n", members[i].age, members[i].name);
  }

  return 0;
}
