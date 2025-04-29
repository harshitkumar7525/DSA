# Sliding Window 
## General code structure
### Fixed Size
    // k is the window size here
    int i=0,j=0;
    while(j<n){
        window size = j-i+1;
        //calcuation
        if(size<k){ 
            j++;
        } else if (size==k){
            // use your previous calcuation to get results
            // i ko increase krne se pehle uski calculations hatao
            i++;
            j++
        }
    }

### Variable size window
    // k is the condition here
    int i = 0, j = 0;
    while (j < n) {
        // Do calculations or include arr[j] in current window

        if (condition is NOT satisfied) {
            // Expand window
            j++;
        } 
        else if (condition IS satisfied) {
            // Possibly update answer
            // Start shrinking window until condition becomes false
            while (condition is satisfied) {
                // Update answer if needed
                // Shrink window from the left
                // Remove arr[i] from calculation
                i++;
            }
            // After shrinking, move forward
            j++;
        }
    }
    return answer;

    