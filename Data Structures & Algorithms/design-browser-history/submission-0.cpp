class ListNode1 {
public:
    string val;
    ListNode1* next = nullptr;
    ListNode1* prev = nullptr;
    ListNode1(string x): val(x) {}
};

class BrowserHistory {
    ListNode1* head;
    ListNode1* tail;
    ListNode1* top;
public:
    BrowserHistory(string homepage) {
        head = new ListNode1(homepage);
        tail = head;
        top = tail;
    }
    
    void visit(string url) {
        ListNode1* visitNode = new ListNode1(url);
        top->next = visitNode;
        visitNode->prev = top;
        tail = visitNode;
        top = visitNode;
    }
    
    string back(int steps) {
        int i = steps;
        while (i && top) {
            top = top->prev;
            i--;
        }
        if (!top) {
            top = head;
            return head->val;
        }
        return top->val;
    }
    
    string forward(int steps) {
        int i = 0;
        while (i < steps && top) {
            top = top->next;
            i++;
        }
        if (!top) {
            top = tail;
            return tail->val;
        }
        return top->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */