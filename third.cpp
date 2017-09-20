#include <iostream>
using namespace std;
typedef int Status;
/*

1、假设在长度大于1的单循环链表中,既无头结点也无头指针.
s为指向某个结点的指针,试编写算法删除结点*s的直接前驱结点.

2、已知由单链表表示的线性表中,含有三类字符的数据元素（如:字母,数字和其它字符),
设计算法构造三个以循环链表示的线性表,使每一个表中只含同一类的字符,
且利用原表中的结点空间作为这三个表的空间.(头结点可以另辟空间)

3、有一双链表,每个结点中除有prior,data和next域外,
有一访问频度域freq,在链表被启用前,其值均初始化为零.
每当在链表上进行一次LOCATE(L,x)运算,元素值为x的结点中freq域的值增1,
并使此链表中结点保持按freq递减的顺序排列,
以便使频繁访问的结点总是靠近表头.设计满足上述要求的LOCATE算法.

*/
int length=0;
typedef struct ElemType
{
    int num;
}ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
Status Default(LinkList &L)
{
    L=new LNode();
    L->next=NULL;
    return 0;
}
Status InitNum(LinkList L,int num)
{
    LinkList head=L                                                                                                                                                                                                                                                                                                                                                               ;
    LinkList temp;
    Default(temp);
    if(L->next==NULL)
    {
        L->data.num=num;
        L->next=head;
        return 0;
    }
    while(L->next!=head)
        L=L->next;
    temp->data.num=num;
    temp->next=head;
    L->next=temp;
    length++;
        cout<<&L<<"^^^^"<<&head<<endl;
    return 0;
}
Status Find(LinkList L,int num)
{
    int i=0;
    while(L->data.num!=num)
    {
        L=L->next;
        i++;
    }
    return i;
}
Status Delete(LinkList L)
{
    LinkList temp=L,head=L;
    int loca,num,j=0;
    cout<<"输入要删除的数字:";
    cin>>num;
    loca=Find(L,num);
    if(loca==0)
        loca=length;
    while(j!=loca-1)
    {
        head=head->next;
        j++;
    }
    L=head;
    head=temp;
    cout<<L->data.num<<"**"<<head->data.num;
    return 0;
}
Status Input(LinkList L)
{
    LinkList temp=L;
    char ch='*';
    int t;
    cout<<"输入数字(以#结束):";
    while(ch!='#')
    {
        cin>>ch;
        t=ch-'0';
        InitNum(L,t);
    }
    return 0;
}
Status Output(LinkList L)
{
    LinkList head=L;
    while(L->next!=head)
    {
        cout<<L->data.num<<" ";
        L=L->next;
    }
    cout<<endl;
    cout<<"length="<<length<<endl;
    return 0;
}
int main()
{
    LinkList L;
    Default(L);
    Input(L);
    Output(L);
    while(1)
        Delete(L);
    return 0;
}
