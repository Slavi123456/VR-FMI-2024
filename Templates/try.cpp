#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void freeList(ListNode *head)
{
    if (!head || !head->next)
    {
        delete head;
        return;
    }
    return freeList(head->next);
}
void print(ListNode *head)
{
    if (!head)
    {
        std::cout << "nullptr " << std::endl;
        return;
    }
    std::cout << head->val << "-> ";
    return print(head->next);
}

ListNode *copyList(ListNode *head)
{
    if (!head || !head->next)
    {
        return new ListNode(head->val, head->next);
    }
    ListNode *newList = copyList(head->next);
    ListNode *newNode = new ListNode(head->val, newList);
    return newNode;
}
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *revList = copyList(head);
        revList = reverseList(head);

        ListNode *dummy = new ListNode(head->val, head->next);
        
        while (revList->next != nullptr && dummy->next != nullptr)
        {
            if (revList->val != dummy->val)
                return false;
            revList = revList->next;
            dummy = dummy->next;
        }
        delete dummy;
        return true;
    }
};

int main()
{
    Solution sol;
    ListNode *list1 = new ListNode(1, new ListNode(2, nullptr));
    print(list1);
    std::cout << std::boolalpha << sol.isPalindrome(list1) << std::endl;
    freeList(list1);
    return 0;
}