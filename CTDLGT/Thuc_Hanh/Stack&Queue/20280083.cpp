#include <iostream>
using namespace std;

struct NODE{ 
    int Key; 
    NODE *pNext; 
}; 
NODE* CreateNode(int Data) 
{ 
    NODE* pNode; 
    pNode = new NODE; 
    if (pNode == NULL) 
        return NULL; 
    pNode->Key = Data; 
    pNode->pNext = NULL; 
    return pNode; 
} 
bool AddHead(NODE* &pHead, int Data) 
{ 
    NODE *pNode; 
    pNode = CreateNode(Data); 
    if (pNode == NULL) 
    return false; 
    if (pHead == NULL) 
    pHead = pNode; 
    else { 
        pNode->pNext = pHead; 
        pHead = pNode;
    }
    return true;
} 

NODE* AddTail(NODE* &pHead, int data)
{
    NODE* temp = CreateNode(data);
    NODE* pCurr = pHead;
    if (pCurr == nullptr)
        pCurr->pNext = temp;
    else {
        while (pCurr->pNext != nullptr)
            pCurr = pCurr->pNext;
        pCurr->pNext = temp;
    } 
    return temp;       
}

NODE* RemoveHead(NODE* &pHead) 
{ 
    if(pHead == NULL) 
        return NULL; 
    NODE* pResult = pHead; 
    pHead = pHead->pNext; 
    return pResult; 
} 

NODE* RemoveTail(NODE* &pHead) 
{ 
    NODE *pNode; 
    if(pHead == NULL) //<1>
    { 
        return NULL; 
    } 
    else if(pHead->pNext == NULL) //<2>
    { 
        pNode = pHead; 
        pHead = NULL; 
        return pNode; 
    } 

    pNode = pHead; 
    while(pNode->pNext->pNext != NULL) //<3>
    { 
        pNode = pNode->pNext; 
    } 

    NODE* pResult = pNode->pNext; 
    pNode->pNext = NULL; 
    return pResult; 
} 
//-------STACK : 
//----PUSH tương ứng AddHead 
//----POP tương ứng RemoveHead 
bool PushStack(NODE* &pStack, int Data) 
{ 
    return AddHead(pStack, Data); 
} 
NODE* PopStack(NODE* &pStack) 
{ 
    return RemoveHead(pStack); 
} 
//--------QUEUE : 
//----ENQUEUE tương ứng AddHead 
//----DEQUEUE tương ứng RemoveTail 
bool EnQueue(NODE* &pQueue, int Data) 
{ 
    return AddHead(pQueue, Data); 
} 

NODE* DeQueue(NODE* &pQueue) 
{ 
    return RemoveTail(pQueue); 
} 

bool EnQueue_Tail(NODE* &pQueue, int data)
{
    return AddTail(pQueue, data);
}




int main() 
{ 
    NODE* pStack = NULL; 
    NODE* pQueue = NULL; 
    // int n = 10; 
    // while(n!=0) 
    // { 
    //     PushStack(pStack, n); 
    //     EnQueue(pQueue, n); 
    //     n--; 
    // } 
    // NODE* pNode = DeQueue(pQueue); 
    // if(pNode != NULL) //<4>
    //     printf("\nGia tri phan tu (Queue) : %d\n", pNode->Key); 
    // else 
    //     printf("\nNULL\n"); 
    // NODE* pNode2 = PopStack(pStack); 
    // if(pNode2 != NULL) 
    //     printf("\nGia tri phan tu (Stack) : %d\n", pNode2->Key); 
    // else 
    //     printf("\nNULL\n");
    // int temp = 0;
    // cin >> temp;
    // PushStack(pStack, temp); 
    // cin >> temp;
    // PushStack(pStack, temp); 
    // cin >> temp;
    // PushStack(pStack, temp); 
    // for (int i = 0; i < 4; i++)
    // {
    //     NODE* t = PopStack(pStack);
    //     if (t != nullptr)
    //         cout << t->Key << "\t";
    //     else
    //         cout << "STACK RONG, KHONG LAY DUOC PHAN TU\n";
    // }
    int tem = 0;
    cin >> tem;
    EnQueue(pQueue, tem);
    cin >> tem;
    EnQueue(pQueue, tem);
    cin >> tem;
    EnQueue(pQueue, tem);
    

    EnQueue_Tail(pQueue, 100);
    for (int i = 0; i < 4; i++)
    {
        NODE* t = DeQueue(pQueue);
        if (t != nullptr)
            cout << t->Key << "\t";
        else
            cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU\n";
    }
    cout << endl;
    int n = 0;
    cout << "Input n = ";
    cin >> n;
    while (n != 0) {
        PushStack(pStack, n%2);
        n = n / 2;
    }
    NODE* pCur = pStack;
    while (pCur != nullptr)
    {
        cout << pCur->Key;
        pCur = pCur->pNext;
    }
    return 0;
}
