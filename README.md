# data-structure  
&ensp;这是我对数据结构的练习  
## 顺序表  
### &emsp;1.c是对顺序表的基础操作  
### &emsp;2.c与1的代码基本相同,用malloc把顺序表开辟到了堆内存中  
## 链表   
### &emsp;1.c头插法  
```
void insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> data =e;
    p -> next = L ->next;
    L -> next = p;
}
```

### &emsp;2.c 尾插法
```
Node * get_tail (Node *L)
{
    Node *p = L;
    while(p->next != NULL)
    {
        p = p -> next;
    }
    return p;
}

Node* insertTail(Node *L , ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p ->data =e;
    L -> next = p;
    p ->next =NULL;
    return p;

}
```

### &emsp;3.c 删除数据

```
void deliteList(Node *L , int e)
{
    Node *p = L;
    for(int i = 0 ; i < e-1 ;i++)
    {
        p = p->next;
    }
    Node * temp = (Node *)malloc(sizeof(Node));
    //q指向要删除的节点
    temp = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p ->next = temp->next;//q ->next == p ->next ->next //缺点为不能删除数据，只是不能遍历输出，浪费空间且不安全
    free(temp);
}
```

### &emsp;4.c 清空链表
```
void freelist(Node *L)
{
    Node *p = L ->next;
    Node *q;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L -> next = NULL;
}
```
### &emsp;5.c 利用快慢指针找到倒数第k个节点
```
void findNodeFS(Node* L, int k)
{
    Node* fast = L -> next;
    Node* slow = L -> next;
    for(int i = 0 ; i < k ; i++)
    {
        fast = fast -> next;
    }
    while(fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    printf("倒数第%d个节点值为: %d\n",k , slow -> data);
}

```
### &emsp;6.c 用快慢指针找出单词的相同后缀
```
Node* findIntersectionNode(Node* headA, Node* headB)
{
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    Node* p = headA;
    int lenA = 0;
    int lenB = 0;
    while(p != NULL)
    {
        p = p -> next;
        lenA++;
    }
    p = headB;
    while(p != NULL)
    {
        p = p -> next;
        lenB++;
    }
    Node* fast;
    Node* slow;
    int step;
    if(lenA > lenB)
    {
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }
    else
    {
        step = lenB - lenA;
        fast = headB;
        slow = headA;
    }
    for(int i = 0 ; i < step ; i++)
    {
        fast = fast -> next;
    }
    while(fast != slow)
    {
        fast = fast -> next;
        slow = slow -> next;
    }

    return fast;

}
```
### 7.c &emsp;利用空间换时间，删除绝对值相同的元素
```
void removeNode(Node* L, int n)
{
    Node* p = L;
    int index;//用作数组下标
    int* q = (int*)malloc(sizeof(int)*(n + 1));

    for(int i =  0; i < n+1 ; i++)
    {
        *(q + i) = 0;
        index = i;
    }
    free(q);

    while(p -> next != NULL)
        {
            index = abs( p -> next -> data);
            if(*(q + index)== 0)
            {
                *(q + index) = 1;
                p = p -> next;
            }

            else
            {
                Node* temp = p -> next;
                p -> next = temp -> next;
                free(temp);
            }
        }    

}
```
### &emsp;8.c 反转链表

```
Node* reserveList(Node* head)
{
    Node* first = NULL;
    Node* second = head -> next;
    Node* third;
    while(second != NULL)
    {
        third = second -> next;
        second -> next = first;
        first = second;//first = first -> next
        second = third;//second = second -> next
    }
    Node* hd = initList();
    hd -> next = first;
    return hd;
}
```
### &emsp;9.c 快慢指针法删除中间节点

```
void delMiddleNode(Node* head)
{
    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    } 
    Node* q = slow -> next;
    slow -> next = q -> next;
    free(q);
}
```
### &emsp;10.c 重组链表

```
void reOrderList(Node* head)
{
    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    } 

    Node* first = NULL;
    Node* second = slow -> next;
    slow -> next = NULL;//打断链表
    Node* third = NULL;
    while(second != NULL)
    {
        third = second -> next;
        second -> next = first;
        first = second;
        second = third; 
    }

    Node* p1 = head -> next;
    Node* q1 = first;
    Node* p2 , *q2;
    
    while(p1 != NULL && q1 != NULL)
    {
        p2 = p1 -> next;
        q2 = q1 -> next;

        p1 -> next = q1;
        q1 -> next = p2;

        p1 = p2;
        q1 = q2;
    }

}
```
### &emsp;11.c 判断链表是否有环,且找到环入口
```
Node* findBegin(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
        {
            Node*p = fast;
            int count = 1;
            while(p -> next != slow) 
            {
                count++;
                p = p -> next;
            }
            fast = head;
            slow = head;
            for(int i = 0 ; i <count ; i++)
            {
                fast = fast -> next;
            }
        
            while(fast != slow)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
            return slow;
        }
        
    }
    return NULL;
}
```

### 2024年12月10日更新
&emsp; 增加了栈和队列的代码

### 2024年12月13日更新
&emsp; 增加了二叉树前中后序遍历
ps：可通过运行output的1.exe，看到我所创建的二叉树  

## 如图：![image](/picture/tree.png)

# 代码均出自b站课程https://www.bilibili.com/video/BV1tNpbekEht/?spm_id_from=333.337.search-card.all.click
