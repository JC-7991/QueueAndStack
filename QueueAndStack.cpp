#include <iostream>
#include <stack>
#include <queue>

class Solution{
  
    std::stack<char> myStack;
    std::queue<char> myQueue;
    
    public:
        void pushCharacter(char ch){
            myStack.push(ch);
        }
        void enqueueCharacter(char ch){
            myQueue.push(ch);
        }
        char popCharacter(){
           char top = myStack.top();
           myStack.pop();
           return top; 
        }
        char dequeueCharacter(){
           char front = myQueue.front();
           myQueue.pop();
           return front; 
        }

};

int main(){

    std::string s;
    getline(std::cin, s);

    Solution obj;
  
    for(int i = 0; i < s.length(); i++){
      obj.pushCharacter(s[i]);
      obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;

    for(int i = 0; i < s.length() / 2; i++){

      if(obj.popCharacter() != obj.dequeueCharacter()){
        isPalindrome = false;
        break;
      }

    }
    
    if(isPalindrome){
      std::cout << "The word, " << s << ", is a palindrome.";
    }
    else{
      std::cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;

}