#include "MyCircularLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
     cout << "\t========== Driver Code ========== " << endl
          << endl;

     MyCircularLinkedList<int> cll;

     cout << endl
          << "\tINSERTIONS" << endl;

     cout << "Alternating between insertAtTail and insertFirstNode." << endl;
     cll.insertAtTail(10);
     cll.insertFirstNode(9);
     cll.insertAtTail(11);
     cll.insertFirstNode(8);
     cll.print();

     cout << endl
          << endl
          << "\tDELETIONS" << endl;
     cout << endl
          << "deletion of first: " << cll.deleteFirstNode() << endl;
     cll.print();
     cout << endl
          << "deletion at tail: " << cll.deleteFromTail() << endl;
     cll.print();
     cll.insertAtTail(69);
     cll.insertFirstNode(420);
     cout << endl
          << "After new insertions: " << endl;
     cll.print();
     cout << endl
          << "delete value 10(deleting a value somewhere between head and tail): "
          << cll.deleteAValue(10) << endl;
     cll.print();
     cout << endl
          << "delete value 69(deleting value at tail): " << cll.deleteAValue(69)
          << endl;
     cll.print();
     cout << endl
          << "delete value 420(deleeting value at head): " << cll.deleteAValue(420)
          << endl;
     cll.print();
     cout << endl
          << "delete non-existing value: " << cll.deleteAValue(360) << endl;
     cll.print();
     cout << endl
          << "delete value 9(empty out the list, testing circular tail case): "
          << cll.deleteAValue(9) << endl;

     cout << endl
          << endl
          << "\tSEARCHING" << endl;

     cll.insertAtTail(100);
     cout << endl
          << "After new insertions: " << endl;
     cll.print();

     cout << endl
          << "search value(for circular tail); " << cll.search(100) << endl;
     cout << endl
          << "search value 100 position(for circular tail case); "
          << cll.searchPositionOfValue(100);

     cll.insertAtTail(101);
     cll.insertFirstNode(99);
     cout << endl
          << "After new insertions: " << endl;
     cll.print();

     cout << endl
          << "search value 101 position(at tail); "
          << cll.searchPositionOfValue(101);
     cout << endl
          << "search value 100 position(somewhere between head and tail); "
          << cll.searchPositionOfValue(100);
     cout << endl
          << "search value 99 position(at head); "
          << cll.searchPositionOfValue(99);

     cout << endl
          << endl
          << "\tSORTING" << endl;

     for (int i = -5; i <= 5; i++)
     {
          if (i % 2 == 0)
          {
               cll.insertFirstNode(i);
          }
          else
          {
               cll.insertAtTail(i);
          }
     }
     cout << endl
          << "After new insertions: " << endl;
     cll.print();

     cout << endl
          << "After ascending sort: " << endl;
     cll.sortCircularListInAscendingOrder();
     cll.print();

     cout << endl
          << "After descending sort(LL will be reversed): " << endl;
     cll.sortCircularListInDescendingOrder();
     cll.print();

          cout << endl
          << endl
          << "\tDESTROYING" << endl;
	  cll.destroyCircularLinkedList();
	  cll.print();

     cout <<endl<<endl<< "\t========== END DRIVER CODE ========== " << endl
          << endl;
     return 0;
}
