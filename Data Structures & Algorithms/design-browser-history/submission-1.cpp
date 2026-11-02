class ListNode1 {
public:
    string val;
    ListNode1* next = nullptr;
    ListNode1* prev = nullptr;
    ListNode1(string x): val(x) {}
};

class BrowserHistory {
    ListNode1* top;
public:
    BrowserHistory(string homepage) {
        top = new ListNode1(homepage);
    }
    
    void visit(string url) {
        ListNode1* visitNode = new ListNode1(url);
        top->next = visitNode;
        visitNode->prev = top;
        top = visitNode;
    }
    
    string back(int steps) {
        int i = steps;
        while (i && top->prev) {
            top = top->prev;
            i--;
        }
        return top->val;
    }
    
    string forward(int steps) {
        int i = 0;
        while (i < steps && top->next) {
            top = top->next;
            i++;
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