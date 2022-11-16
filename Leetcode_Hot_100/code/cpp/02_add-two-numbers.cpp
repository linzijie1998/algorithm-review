struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* addNode(ListNode* iter, int value)
    {
        ListNode* node = new(ListNode);
        node->val = value;
        node->next = nullptr;
        if (iter != nullptr)
            iter->next = node;
        return node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = l1->val, b = l2->val;
        int value = (a + b) % 10;
        int offset = (a + b) / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = addNode(nullptr, value);
        ListNode* iter = head;

        while(!(l1 == nullptr && l2 == nullptr))
        {
            a = 0;
            if (l1 != nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            }
            b = 0;
            if (l2 != nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }
            value = (a + b + offset) % 10;
            offset = (a + b + offset) / 10;
            iter = addNode(iter, value);
        }
        if (offset)
            iter = addNode(iter, offset);
        return head;
    }
};