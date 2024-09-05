/*
 * @Author: xinao_seven_
 * @Date: 2022-04-05 18:37:45
 * @LastEditTime: 2024-03-24 15:56:01
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\Listnode.cpp
 * 
 */
#include<bits/stdc++.h>
//实现链表功能
class MyLinkedList {
public:
    struct mylist{//定义链表的结构体
        int val;
        mylist* next;
        mylist(int val):val(val),next(nullptr){}

    };
    int size;//链表长度
    mylist* nul = nullptr;//虚拟头节点
    MyLinkedList() {//链表初始化
        nul = new mylist(-1);
        size=0;
    }
    
    int get(int index) {//获取链表在index的值
        if(index<0||index>size-1){
            return -1;
        }
        mylist* cur = nul->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {//头插法
        mylist* newlist = new mylist(val);
        newlist->next = nul->next;
        nul->next = newlist;
        
        size++;
    }
    
    void addAtTail(int val) {//尾插法
        mylist* newlist = new mylist(val);
        mylist* cur = nul;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = newlist;
        size++;
    }
    
    void addAtIndex(int index, int val) {//指定索引前插入
        if(index==size){
            addAtTail(val);
        }else if(index<0){
            addAtHead(val);
        }else if(index>size){
            return;
        }else{
            mylist* newlist = new mylist(val);
            mylist* cur = nul;
            while(index--){
                cur = cur->next;
            }
            newlist ->next = cur->next;
            cur->next = newlist;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {//删除节点
        if(index>=0&&index<size){
            mylist* cur =  nul;
            while(index--){
                cur = cur->next;
            }
            mylist* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            size--;
        }
    }
    void print(){
        mylist* cur = nul->next;
        while(cur){
            std::cout<<cur->val<<" ";
            cur = cur->next;
        }
        std::cout<<std::endl;
    }
    int Getlistsize(){
        return size;
    }
    
};

int main()
{
    int n = 1;
    std::vector<std::vector<int>> res(n,std::vector<int>(n,0));
    return 0;
}