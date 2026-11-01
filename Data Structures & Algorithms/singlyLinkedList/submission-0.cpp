class ListNode {
public:
    int val_;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    ListNode(int val) {
        val_ = val;
    }
};

class LinkedList {
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (i < index && curr) {
            curr = curr->next;
            i++;
        }
        return curr == nullptr ? -1: curr->val_;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        newNode->prev = head;
        if (head->next != nullptr) {
            head->next->prev = newNode;
        } else {
            tail = newNode;
        }
        head->next = newNode;
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (i < index && curr) {
            curr = curr->next;
            i++;
        }
        if (curr == nullptr) return false;
        if (curr == tail) {
            tail = curr->prev;
        }
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        curr->prev->next = curr->next;
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        ListNode* curr = head->next;
        while (curr) {
            values.push_back(curr->val_);
            curr = curr->next;
        }
        return values;
    }
};
