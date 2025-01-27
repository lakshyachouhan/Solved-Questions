class Node{
    public:
    int key ,val ;
    Node* next ;
    Node* prev ;

    Node(int k,int v){
        this -> key = k ;
        this -> val = v ;
        this -> next = NULL ;
        this -> prev = NULL ;
    }
};

class LRUCache {
public:
    unordered_map<int,Node* > mp ; // {key,Node*}
    Node* head, *tail ;
    int capacity ;
    LRUCache(int capacity) {
        this -> capacity = capacity ;
        this -> head = new Node(-1,-1);
        this -> tail = new Node(-1,-1);
        head -> next = tail ;
        tail -> prev = head ;
    }

    void deleteNode(Node *temp){
        Node *prevNode = temp -> prev ;
        Node* nextNode = temp -> next ;

        prevNode -> next = nextNode ;
        nextNode -> prev = prevNode ;
    }

    void insertAtFront(Node *temp){
        
        Node * currFront = head -> next ;
        temp -> next = currFront ;
        currFront -> prev = temp ;
        head -> next = temp ;
        temp -> prev = head ;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end())  return -1;
        else{
            Node* curr = mp[key];
            int ans = curr->val ;
            deleteNode(curr);
            insertAtFront(curr);
            return ans ;
        }
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            curr->val = value ;
            deleteNode(curr);
            insertAtFront(curr);
        }

        else{
            if(mp.size() == capacity){
                Node* lastNode = tail->prev;
                mp.erase(lastNode->key);
                deleteNode(lastNode);
            }

            Node* curr = new Node(key,value);
            mp[key] = curr ;
            insertAtFront(curr);
        }
    }
};
