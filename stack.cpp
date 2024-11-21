#include<iostream>
#include<string>
using namespace std;
struct node{
char data;
node*next;

node(char val){
    data=val;
    next=NULL;
}
};
struct stack{
void push(node*&top,char val){
    node*temp=top;
    node*n=new node(val);
    if(top==NULL){
        top=n;
        return;
    }
    n->next=top;
    top=n;
}
char pop(node*&top){
    
    node*topop=top;
    char d=topop->data;
    top=top->next;
    delete topop;
    return d;
    
}
bool isempty(node*&top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
char peek(node*&top){
    if(top==NULL){
        cout<<"stack is empty";
        return '\0';
    }
    node*temp=top;
    return temp->data;
}
void display(node*top){
node*temp=top;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;

}
};
void balanced(string s,node*&top){
    int n=s.size();
    stack st;
    string m=s;
    bool ans=true;
    for(int i=0;i<n;i++){
        if(m[i]=='(' || m[i]=='[' || m[i]=='{'){
            st.push(top,m[i]);
        }
        else if(m[i]==')' || m[i]==']' || m[i]=='}'){
            if (st.isempty(top)){
                ans = false; 
                break;
            }
            char o=st.peek(top);
            if( (m[i]==']' &&o=='[' ) || (m[i]==')' && o=='(') || (m[i]=='}' && o=='{'))
            {
                st.pop(top);
            }
            else{
                ans=false;
                break;
            }
        }
    }
    if (!ans) {
        cout<<"invalid parenthesis" << endl;
    } 
    else {
        cout<<"valid parenthesis" <<endl; 
    }
}

int precision(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='-' || c=='+'){
        return 1;
    }
    else{
        return 0;
    }
}
void infix_postfix(node*& top,string s){
    string output="";
    stack st;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i]) || isdigit(s[i])){
            output+=s[i];
        }
        else if(s[i]=='('){
           st.push(top,s[i]);
        }
       
        else if(s[i]==')'){
            while(st.peek(top)!='('){
                output+=st.peek(top);
                st.pop(top);
            }
            st.pop(top);
        }
        else{
        while(!st.isempty(top) && precision(s[i])<=precision(st.peek(top)))
        {
            char topp=st.peek(top);
            output+=topp;
            st.pop(top);
        }
        st.push(top,s[i]);
        }
    }
    while(!st.isempty(top)){
        output+=st.peek(top);
        st.pop(top);
    }
    cout<<output;
}

void solution(string s){
    node*head=NULL;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
               int num=(s[i]-'0');
         
        push(head,num);
        }
        else{
               if(head==NULL){
                return;
            }
            int b=pop(head);
            if(head==NULL){
                return;
            }
            int a=pop(head);
            cout<<"b"<<b<<"a"<<a<<endl;
            int ans;
            if(s[i]=='+')
            {
                 ans=a+b;
               push(head,ans);
            }
            else if(s[i]=='-')
                 { ans=a-b;
                     push(head,ans);
                 }
           
           
            else if(s[i]=='*'){
                 ans=a*b;
                  push(head,ans);
            }
            else if(s[i]=='/'){
                 ans=a/b;
                 push(head,ans);
                 
            }
            else if(s[i]=='^'){
                ans=pow(a,b);
                 push(head,ans);
            }
         
           
        }
    }
    cout<<"answer is "<<pop(head);
}

int main(){
    node*top=NULL;
    int op;
    do {
        cout<<"1)Lab Task 1: Write an application using Stack that checks whether the entered string of brackets is balanced, e.g.
[{( )}] is Balanced while {[( )] } is not Balanced because the priority of the parenthesis is not maintained. "<<endl;
cout<<"2)Lab Task 2: Use dynamic stack, implement Infix to Postfix conversion algorithm, and test it for various inputs."<<endl;
cout<<"3)Lab Task 3:For a given postfix expression, use dynamic stack to evaluate a numerical result for given values of variables."<<endl;
cout<<"4)Exit"<<endl;
cin>>op;
if (op==1){
    string s;
    node*top=NULL;
    cout<<"Enter the string of brackets: ";
    getline(cin,s);
    balanced(s,top);

}else if(op==2){
    string s;
    node*top=NULL;
    cout<<"Enter the infix expression: Donot enter the expression with spaces ";
    getline(cin,s);
    infix_to_postfix(s,top);

}
else if (op==3){
    string s;
    node*top=NULL;
    cout<<"Enter the postfix expression: Donot enter the expression with spaces ";
    getline(cin,s);
}
    else{
        cout<<"Invalid choice"<<endl;
        exit(0);
    }
    
    }while(i>=1 && i<=4);

}