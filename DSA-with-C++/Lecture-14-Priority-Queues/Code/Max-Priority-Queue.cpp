// Implement the class for Max Priority Queue which includes following functions -
// 1. getSize -
// Return the size of priority queue i.e. number of elements present in the priority queue.
// 2. isEmpty -
// Check if priority queue is empty or not. Return true or false accordingly.
// 3. insert -
// Given an element, insert that element in the priority queue at the correct position.
// 4. getMax -
// Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
// 5. removeMax -
// Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
// Note : main function is given for your reference which we are using internally to test the class.


#include <iostream>
using namespace std;

#include<vector>
#include<climits>
class PriorityQueue {
    // Declare the data members here
    vector<int> v;

   public:
    PriorityQueue() {
        // Implement the constructor here
        
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        v.push_back(element);
        int currentIndx = v.size() - 1;
        while(currentIndx > 0){
            int parentIndx = (currentIndx - 1) / 2;
            if(v[parentIndx] < v[currentIndx])
                swap(v[parentIndx], v[currentIndx]);
            else
                break;
            currentIndx = parentIndx;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(v.size() == 0)
            return INT_MIN;
        return v[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(v.size() == 0)
            return INT_MIN;
        int ans = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();
        int parentIndx = 0;
        int maxIndx;
        while(parentIndx < v.size()){
            int lChildIndx = 2 * parentIndx + 1;
            int rChildIndx = 2 * parentIndx + 2;
            if(rChildIndx < v.size()){
                if(v[rChildIndx] > v[lChildIndx])
                    maxIndx = rChildIndx;
                else
                    maxIndx = lChildIndx;
            } else
                break;
            
            if(v[parentIndx] < v[maxIndx])
                swap(v[parentIndx], v[maxIndx]);
            else
                break;
            
            parentIndx = maxIndx;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return v.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        if(v.size())
            return false;
        else
            return true;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}