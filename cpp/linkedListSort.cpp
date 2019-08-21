#include <iostream>
using namespace std;


// 节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v, ListNode* n = NULL) {
        val = v;
        next = n;
    }
};

// 单链表快速排序
class QuickSortValue {
public:
    static void QuickSort(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return;
        QuickSort(pHead, NULL);
    }
private:
    static void QuickSort(ListNode* pHead, ListNode* pTail) {
        if (pHead == pTail || pHead->next == pTail)
            return;
        ListNode* pMid = Partation(pHead, pTail);
        QuickSort(pHead, pMid);
        QuickSort(pMid->next, pTail);
    }
    static ListNode* Partation(ListNode* pHead, ListNode* pTail) {
        if (pHead == pTail || pHead->next == pTail)
            return pHead;
        ListNode* pPivot = pHead; // 基元
        int key = pHead->val;
        for (ListNode* pNode = pHead->next; pNode != pTail; pNode = pNode->next) {
            if (pNode->val < key) {
                pPivot = pPivot->next; // 将比基元小的值，依次交换到前面
                swap(pNode, pPivot);
            }
        }
        swap(pHead, pPivot);
        return pPivot;
    }
    static void swap(ListNode* pA, ListNode* pB) {
        int temp = pA->val; pA->val = pB->val; pB->val = temp;
    }
};

// 单链表归并排序
class MergeSort {
public:
    static ListNode* ListMergeSort(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        // 找到位于中间的节点，快慢指针，快的到结尾，慢的到中点
        while (pFast != NULL && pFast->next == NULL) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        pFast = pSlow;
        pSlow = pSlow->next; // 分割成2段
        pFast->next = NULL;
        pHead = ListMergeSort(pHead);
        pSlow = ListMergeSort(pSlow);
        pHead = merge(pHead, pSlow);
        return pHead;
    };
private:
    static ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) {
            return pHead1 == NULL ? pHead2 : pHead1;
        }
        // 找出合并后的链表头
        ListNode* pHead = NULL;
        if (pHead1->val > pHead2->val) {
            pHead = pHead2;
            pHead2 = pHead2->next;
        } else {
            pHead = pHead1;
            pHead1 = pHead1->next;
        }
        // 将2个链表中值较小的节点依次链接到结果链表中
        ListNode* pHead_orgin = pHead;
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val > pHead2->val) {
                pHead->next = pHead2;
                pHead2 = pHead2->next;
            } else {
                pHead->next = pHead1;
                pHead1 = pHead1->next;
            }
            pHead = pHead->next;
        }
        if (pHead1 == NULL)
            pHead->next = pHead2;
        else
            pHead->next = pHead1;
        return pHead_orgin;
    };
};