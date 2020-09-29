#include <iostream>
using namespace std;

struct node{
    int n;
    node *next;
    
};

bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head, node *&last, int n);
void insert(node *&head, node *&last, int n);
void remove(node *&head, node *&last);
void showLIst(node *current);


bool isEmpty(node *head){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
char menu(){
    char choice;
    cout<<"Menu\n";
    cout<<"1. Add and Item.\n";
    cout<<"2. remove.\n";
    cout<<"3. show list.\n";
    cout<<"4. exit.\n";
    cin >> choice;
    return choice;
}
void insertAsFirstElement(node *&head, node *&last, int n){
    node *temp = new node;
    temp->n = n;
    temp->next = NULL;
    head = temp;
    last = temp;
    
    
}
void insert(node *&head, node *&last, int n){
    if(isEmpty(head)){
        insertAsFirstElement(head, last, n);
    }
    else{
        node *temp = new node;
        temp->n = n;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void remove(node *&head, node *&last){
    if(isEmpty(head)){
        cout<<"The list is empty"<<endl;
    }
    else if(head == last){
        delete head;
        head == NULL;
        last == NULL;
    }
    else{
        node *temp = head;
        head = head -> next;
        delete temp;
        
    }
}
void showList(node *current){
    if(isEmpty(current)){
        cout<<"The list is empty"<<endl;
        
    }
    else{
        cout<<"The list contains: \n";
        while(current != NULL){
            cout<< current ->n <<endl;
            current = current ->next;
        }
    }
}


int main(int argc, const char * argv[]) {
    node *head = NULL;
    node *last = NULL;
    char choice;
    int n;
    do{
        choice =menu();
        switch(choice){
            case'1': cout<<"please enter a number: ";
                cin >> n;
                insert(head, last, n);
                break;
            case'2':
                remove(head, last);
                break;
            case'3':
                showList(head);
                break;
            default:
                cout<<"system exit"<<endl;
                
                
        }
    }while(choice != 4);
    {
        
    }
    cout<<"Hello"<<endl;
    return 0;
}
