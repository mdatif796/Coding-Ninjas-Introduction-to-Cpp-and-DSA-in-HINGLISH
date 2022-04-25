// Implement the function RemoveMin for the min priority queue class.
// For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
// Note : main function is given for your reference which we are using internally to test the code.


#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

    public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while(parentIndex < pq.size()){
            int lChildIndex = 2 * parentIndex + 1;
            int rChildIndex = 2 * parentIndex + 2;
            int minIndex;
            if(lChildIndex < pq.size() && rChildIndex < pq.size()){
                if(pq[lChildIndex] < pq[rChildIndex])
                    minIndex = lChildIndex;
                else  
                    minIndex = rChildIndex;
            } else
                break;                                                                                                                  


            if(pq[parentIndex] > pq[minIndex]){                                                                     
                swap(pq[parentIndex], pq[minIndex]);                                                                                    
            } else                                                                                                                          
                break;                                                                                                                  

            parentIndex = minIndex;                                                                                                         
        }                                                                                                                                       
        return ans; 
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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