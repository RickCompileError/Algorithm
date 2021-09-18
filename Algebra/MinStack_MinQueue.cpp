// These data structure is used to find min value in subarray
#include <bits/stdc++.h>

using namespace std;

class MinStack{
private:
    stack<pair<int,int>> s;
public:
    int getMin(){
        return s.top().second;
    }
    void add(int n){
        int new_min = s.empty()?n:min(n,s.top().second);
        s.push({n,new_min});
    }
    void remove(){
        s.pop();
    }
};

class MinQueue1{
private:
    deque<int> q;
public:
    int getMin(){
        return q.front();
    }
    void add(int n){
        while (!q.empty() && q.back()>n) q.pop_back();
        q.push_back(n);
    }
// this remove method is used by specified value
    void remove(int v){
        if (!q.empty() && q.front()==v) q.pop_front();
    }
};

class MinQueue2{
private:
    deque<pair<int,int>> q;
    int accu_added = 0;
    int accu_remove = 0;
public:
    int getMin(){
        return q.front().first;
    }
    void add(int n){
        while (!q.empty() && q.back().first>n) q.pop_back();
        q.push_back({n,accu_added});
        accu_added++;
    }
// this remove method is used by comfirming if removed index equal to current index
    void remove(){
        if (!q.empty() && q.front().second==accu_remove) q.pop_front();
        accu_remove++;
    }
};

// This data structure can find minimum value in O(1)
// by using two minstack to simulate minqueue
class MinQueue3{
private:
    stack<pair<int,int>> s1, s2;
public:
    int getMin(){
        if (s1.empty() || s2.empty())
            return s1.empty()?s2.top().second:s1.top().second;
        else
            return min(s1.top().second, s2.top().second);
    }
    void add(int n){
        int new_min = s1.empty()?n:min(s1.top().second,n);
        s1.push({n,new_min});
    }
// Push all value from s1 to s2, we can get a reverse
// bottom-top stack.
// Besides this, the min value also has new range
    void remove(){
        if (s2.empty()){
            while (!s1.empty()){
                int value = s1.top().first;
                s1.pop();
                int new_min = s2.empty()?value:min(s2.top().second,value);
                s2.push({value,new_min});
            }
        }
        s2.pop();
    }
};

int input[]{1,7,2,5,3,4,9,0};

void f1(){
    MinStack ms;
    for (int i=0;i<8;i++) ms.add(input[i]);
    for (int i=0;i<8;i++){
        cout <<ms.getMin() <<' ';
        ms.remove();
    }
    cout <<endl;
}

void f2(int interval){
    MinQueue1 mq;
    int i=0;
    while (i<interval) mq.add(input[i++]);
    for (;i<8;i++){
        cout <<mq.getMin() <<' ';
        mq.remove(input[i-interval]);
        mq.add(input[i]);
    }
    cout <<mq.getMin() <<endl;
}

void f3(int interval){
    MinQueue2 mq;
    int i=0;
    while (i<interval) mq.add(input[i++]);
    for (;i<8;i++){
        cout <<mq.getMin() <<' ';
        mq.remove();
        mq.add(input[i]);
    }
    cout <<mq.getMin() <<endl;
}

void f4(int interval){
    MinQueue3 mq;
    int i=0;
    while (i<interval) mq.add(input[i++]);
    for (;i<8;i++){
        cout <<mq.getMin() <<' ';
        mq.remove();
        mq.add(input[i]);
    }
    cout <<mq.getMin() <<endl;
}

int main(){
    f1();
    f2(2);
    f3(3);
    f4(4);
}