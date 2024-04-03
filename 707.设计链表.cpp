/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {}
    };
    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    // 获取到第index个节点数值， 如果index是非法数值，直接返回01，
    // index从0开始，第0个节点就是头结点
    int get(int index) {
        if(index > (_size-1) || index < 0) return -1;
        LinkedNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    // 在链表的最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    // 在第index个节点之前插入一个新节点，例如index = 0 , 那么新插入的节点为链表的新头结点
    // 如果index等于链表的长度， 这说明是新插入的节点为链表的尾节点
    // 如果index 大于链表的长度，则返回空
    // 如果index 小于0， 则在头部插入节点
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    // 删除第index个节点，如果index大于等于链表的长度，直接return,注意index从0开始
    void deleteAtIndex(int index) {
        if(index>=_size || index < 0) return;
        LinkedNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size--;
        
    }

    void printLinkedList(){
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout<< endl;
        
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

