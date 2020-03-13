/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* head;     //父节点
        Node* tmp;      //下一层最左的孩子
        Node* son;      //要处理的这一层，新建一个辅助节点hd
        Node  hd = Node();
        head = root;
        if(!head) return root;
        while(head) {  //直到最后一层，但是判断到了最后一层要停止（没有子孩子了）
            //保存下一层起始点
            tmp = head->left ? head->left : head->right;   
            while(!tmp && head->next) {
                //tmp为空，head->next非空，继续找非空的子节点
                head = head->next;
                tmp = head->left ? head->left : head->right;   
            }
            if(!tmp) break; //没有非空的子孩子了
            son = &hd;
            while(head) {
                if(head->left) {
                    son->next = head->left;
                    son = son->next;
                }
                if(head->right) {
                    son->next = head->right;
                    son = son->next;
                }
                head = head->next;
            }
            head = tmp;
        }
        return root;
    }
};
