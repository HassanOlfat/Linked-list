#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class node{
int data;
node *next;
node *pre;
friend class list;
};
class list{
node *head;
public:
list();
list(int n);
void print();
int addf(int n);
int addl(int n);
int insert(int n,int k);
int rf();
int rl();
int del(int n);
};
//******************************************************************************
list::list(){
head=0;
}
//******************************************************************************
list::list(int n){
node *t;
t=new node();
t->data=n;
t->next=0;
t->pre=0;
head=t;
}
//******************************************************************************
int list::addf(int n){
node *t;
t=new node();
t->data=n;
if(head==0)
  {
  head=t;
  t->next=0;
  t->pre=0;
  return n;
  }else{
t->next=head;
head->pre=t;
head=t;
t->pre=0;
}
}
//******************************************************************************
int list::addl(int n){
node *p;
p=head;
node *t;
t=new node();
t->data=n;
if(head==0)
  {
  head=t;
  t->next=0;
  t->pre=0;
  return n;
  }else{

       while(p->next!=0)
            {
            p=p->next;
            }
       t->pre=p;
       p->next=t;
       t->next=0;
       return n;
      }
}
//******************************************************************************
int list::rf(){
node *p,*q;
p=head;
if(p->next==0)
 {
  int n=p->data;
  delete p;
  head=0;
  return n;
 }
if(head->next!=0)
  {
  p=head;
  q=p->next;
  int n=p->data;
  delete p;
  q->pre=0;
  head=q;
  return n;
  }
}
//******************************************************************************
int list::rl(){
node *p,*q;
p=head;
if(p->next==0)
 {
  int n=p->data;
  delete p;
  head=0;
  return n;
 }
 if(head->next!=0)
  {
   node *q;
   p=head->next;
   q=head;
   while(p->next!=0)
        {
         p=p->next;
         q=q->next;
        }
   int n=p->data;
   delete p;
   q->next=0;
   return n;
  }
}
//******************************************************************************
int list::del(int n){
if(head==0) return 0;
node *p,*q;
   int i=1;
   node *o;
   p=head->next;
   q=head;
   while(i<n-1)
       {
        p=p->next;
        q=q->next;
        i++;
       }
   int m=p->data;
   q->next=p->next;
   o=p->next;
   o->pre=q;
   delete p;
   return m;
  }

//*****************************************************************************
void list::print(){
node *t=head;
while(t->next!=0)
     {
      cout<<t->data;
      t=t->next;
     }
cout<<t->data;
}
//******************************************************************************
int list::insert(int n,int k){
if(head==0)
addf();
int i=1;
node *p=head;
while(p->next!=0)
     {
      p=p->next;
      i++;
     }
if(i==k)
addl();
int i=1;
node *t;
t=new node();
t->data=n;
node *p,*q;
p=head->next;
q=head;
while(i<k)
    {
     p=p->next;
     q=q->next;
     i++;
    }

}
//******************************************************************************
void main(){
list a;
a.addf(10);
a.addl(20);
a.addl(30);
a.addl(40);
a.del(2);
a.print();
getch();
}