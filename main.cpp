//
#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeLinker.h"

using namespace std;

template<class T>
T getInput(){
    T n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<endl;
    return n;
}

void printMenu(){
    cout<<"1. Insert."<<endl;
    cout<<"2. Delete."<<endl;
    cout<<"3. Preorder Traversal."<<endl;
    cout<<"4. Inorder Traversal."<<endl;
    cout<<"5. Postorder Traversal."<<endl;
    cout<<"6. Display."<<endl;
    cout<<"7. Mirror."<<endl;
    cout<<"8. Quit."<<endl;
    cout<<"9. Assignment 3 Task 2 - Node with Minimum Value."<<endl;
    cout<<"10. Assignment 3 Task 3 - Is tree height balanced."<<endl;
}

template<class T>
bool bstMenuActions(BinaryTree<T>& bst, int choice){
    if(choice==0){
        printMenu();
    }
    else if(choice==1){
        bst.insert(getInput<int>());
    }
    else if(choice==2){
        bst.deletenode(getInput<int>());
    }
    else if(choice==3){
        bst.preorder();
        cout<<endl;
    }
    else if(choice==4){
        bst.inorder();
        cout<<endl;
    }
    else if(choice==5){
        bst.postorder();
        cout<<endl;
    }
    else if(choice==6){
        bst.inorder();
        cout<<endl;
    }
    else if(choice==7){
        bst.mirror();
    }
    else if(choice==8){
        return false;
    }
    else if(choice==9){
        cout<<"Minimum Value: "<<bst.min()<<endl;
    }
    else if(choice==10){
        if(bst.balanced()){
            cout<<"Balanced."<<endl;
        }
        else{
            cout<<"Unbalanced."<<endl;
        }
    }
    return true;
}

int main() {
    bool continuation=true;

    /* Creating the BST given in Assignment 3 Question File */
    cout<<endl<<"Creating the BST given in Assignment 3 Question File."<<endl;

    BinaryTree<int> bst;

    const int size=14;
    int nums[size] = {60, 70, 80, 75, 77, 50, 53, 57, 30, 35, 40, 48, 45, 32};

    for(int num : nums){
        bst.insert(num);
    }

    //the test run
    printMenu();
    cout<<endl;

    while(continuation){
        cout<<"Enter Choice(0 to print menu again.)."<<endl;
        continuation=bstMenuActions(bst, getInput<int>());
    }
    return 0;
}
