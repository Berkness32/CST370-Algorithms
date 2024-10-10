// Title: Homework 3-2
// Abstract: Graph data
// Name: Aaron Berkness
// Date: 9/17/24

#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int edges = 0;
    int vertices = 0;
    int startingVertex;
    
    while (edges < 1) {
        cin >> vertices;
        cin >> edges;
    }
    int nums[edges][4]; //  | Starting vertex - End vertex - cost - visited?  |
    stack<int> visited;
    stack<int> visitedIndices;
    visited.push(-1);
    visitedIndices.push(-1);
    
    int fullRouteTotalValues = edges - vertices;
    int fullRouteTotalValues2 = vertices + 1;
    int fullRoute[fullRouteTotalValues][fullRouteTotalValues2];
    int fullRouteCount = 0;
    
    for (int i = 0; i < edges; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
        nums[i][3] = 0;
    }
    
    cin >> startingVertex;  // --------------------------------------- Important
    
    visited.push(startingVertex);
    
    int loopCount = 0; // Used for tracking loops
    int stopCount = 0; // How many stops have been made - use to figure out when to copy to fullRoute

    while (nums[loopCount][0] != startingVertex) {
        loopCount++;
    }
    visitedIndices.push(loopCount);
    fullRoute[fullRouteCount][stopCount] = startingVertex;
    
    int visitCount = edges; // How many have been marked as visited - use for fullRoute copies
    int runningTotal = nums[loopCount][2]; // Running total of the scores summed up
    
    // ----------------------- Testing to see if we have visited everything ---------------------------
    while (visitCount != 0 && visited.top() != -1) {
        int nextStop = nums[visitedIndices.top()][1]; // Next position that will be visited.
        loopCount = 0;
        bool nextStopFound = false;
        
        
        // -------------------- Main while loop -------------------------------------------------------
        while (!nextStopFound) {
            
            if (nums[loopCount][0] == nextStop && nums[loopCount][3] != 1 && nums[visitedIndices.top()][0] != nums[loopCount][1]) {
                
                // End the while loop
                nextStopFound = true;
                
                // Mark as visited
                visited.push(nums[loopCount][0]);
                visitedIndices.push(loopCount);
                fullRoute[fullRouteCount][stopCount] = nums[loopCount][0];
                nums[loopCount][3] = 1;
                
                // Update the counts
                stopCount++;
                visitCount--;
                runningTotal += nums[loopCount][2];
                
            }
            
            loopCount++;
            
            // Make sure while loop does not run forever
            if (loopCount >= edges) {
                
                if (visited.top() == startingVertex) {
                    visitCount = edges;
                    runningTotal = 0;
                    

                    visited.pop();
                    visitedIndices.pop();
                    
                    for (int i = 0; i < edges; i++) {
                        if (nums[i][0] != startingVertex) {
                            nums[i][3] = 0;
                        } else if (nums[i][0] == startingVertex && nums[i][3] != 1 && visited.top() == -1) {
                            // Push the new starting vertex value
                            visited.push(nums[i][0]);
                            visitedIndices.push(i);
                            
                            fullRoute[fullRouteCount][stopCount] = nums[i][0];
                            nums[i][3] = 1;
                            
                            // Update the counts
                            stopCount++;
                            visitCount--;
                            runningTotal += nums[loopCount][2];
                            
                        } else {
                            visitCount--;
                        }
                    }
                    break;
                } else {
                    if (visited.top() == -1) {
                        break;
                    }
                    
                    // Next stop not found so we pop from the stack
                    visited.pop();
                    runningTotal -= nums[visitedIndices.top()][2];
                    visitedIndices.pop();
                    
                    fullRoute[fullRouteCount][stopCount] = -1;
                    stopCount--;
                    
                    
                    break;
                }
            }
            
            
        }
        
        // Check to see if we have a full route
        if (stopCount == vertices) {
            int newRouteCount = fullRouteCount + 1;
            
            // Copy over the current route to a new one
            for (int i = 0; i < stopCount; i++) {
                fullRoute[newRouteCount][i] = fullRoute[fullRouteCount][i];
            }
            
            fullRoute[fullRouteCount][vertices] = runningTotal;
            stopCount--;
            fullRouteCount++;
            runningTotal -= nums[visitedIndices.top()][2];

            // Next stop not found so we pop from the stack
            visited.pop();
            visitedIndices.pop();
            
        }
        
    }
    
    
    if (visited.top() == -1) {
        cout << "Path:" << endl;
        cout << "Cost:" << -1
    } else {
        
        int least = fullRoute[0][vertices];
        int index = 0;
        for (int x = 0; x < fullRouteCount; x++) {
            if (fullRoute[x][vertices] < least && fullRoute[x][vertices-1] != -1) {
                least = fullRoute[x][vertices];
                index = x;
            }
        }
        
        if (fullRoute[index][vertices-1] == -1) {
            
            cout << "Path:" << endl;
            cout << "Cost:" << -1
        } else {
            cout << "Path:";
            for (int i = 0; i < vertices; i++) {
                cout << fullRoute[index][i] << " ";
                
            }
            
            cout << "\n";
            cout << "Cost: " << fullRoute[index][vertices] << endl;
        }
    }
}
    
