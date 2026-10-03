class MyLinkedList {
public:

    class Node{
        public:
        int val;
        Node*next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
    };

    Node* head;
    int size;
    MyLinkedList() {
        head  = NULL;
        size =0;
    }
    
    int get(int index) {
        if(index<0 || index>= size){
            return -1;
        }
        Node* temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head==NULL){
            head = newNode;
            size++;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        Node* newNode  = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        if(index == 0){
            Node* temp= head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        Node* temp = head;
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        size--;
    }
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