#include <iostream>
using namespace std;
typedef int Status;
/*

1�������ڳ��ȴ���1�ĵ�ѭ��������,����ͷ���Ҳ��ͷָ��.
sΪָ��ĳ������ָ��,�Ա�д�㷨ɾ�����*s��ֱ��ǰ�����.

2����֪�ɵ������ʾ�����Ա���,���������ַ�������Ԫ�أ���:��ĸ,���ֺ������ַ�),
����㷨����������ѭ������ʾ�����Ա�,ʹÿһ������ֻ��ͬһ����ַ�,
������ԭ���еĽ��ռ���Ϊ��������Ŀռ�.(ͷ��������ٿռ�)

3����һ˫����,ÿ������г���prior,data��next����,
��һ����Ƶ����freq,����������ǰ,��ֵ����ʼ��Ϊ��.
ÿ���������Ͻ���һ��LOCATE(L,x)����,Ԫ��ֵΪx�Ľ����freq���ֵ��1,
��ʹ�������н�㱣�ְ�freq�ݼ���˳������,
�Ա�ʹƵ�����ʵĽ�����ǿ�����ͷ.�����������Ҫ���LOCATE�㷨.

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
    cout<<"����Ҫɾ��������:";
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
    cout<<"��������(��#����):";
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
