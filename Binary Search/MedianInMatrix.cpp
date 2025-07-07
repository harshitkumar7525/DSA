#include<bits/stdc++.h>
using namespace std;
int upper(vector<int>& row, int val){ // returns the index of the first element greater than val
    /*
    if we get the index of the first element greater than val, 
    then all elements to the left of this index are less than or equal to val.
    */
      int i=0;
      int j=row.size()-1;
      while(i<=j){
          int mid = i+(j-i)/2;
          if(row[mid]<=val){
              i=mid+1;
          } else {
              j=mid-1;
          }
      }
      return i;
  }
  int helper(vector<vector<int>> &mat,int mid){ // returns the count of elements less than or equal to mid
    /*
    This function counts the number of elements in the matrix that are less than or equal to mid.
    It does this by iterating through each row and using binary search to find the count of elements
    that are less than or equal to mid in that row.
    */
      int n = mat.size();
      int count = 0;
      for(int i=0;i<n;i++){
          count+=upper(mat[i],mid);
      }
      return count;
  }
    int median(vector<vector<int>> &mat) {
        int n = mat.size(); // number of rows
        int m = mat[0].size(); // number of columns
        int req = (m*n)/2; // required count of elements to find the median
        if((m*n)%2==0) req++; // if the total number of elements is even, we need to consider the next element as well
        int low=INT_MAX,high=INT_MIN; 
        // finding the minimum and maximum elements in the matrix
        // low will be the minimum element and high will be the maximum element
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
        }
        for(int i=0;i<n;i++){
            high=max(high,mat[i].back());
        }
        while(low<=high){
            /*
            We perform binary search on the range [low, high] to find the median.
            Kyuki hamara answer hamesha low se high ke beech mein hoga.
            We calculate the mid value and count the number of elements less than or equal to mid.
            */
            int mid = low + (high - low)/2;
            int smallerEquals = helper(mat,mid);
            if(smallerEquals <= req){ // agar mid se chhote ya barabar elements ki count required se kam hai
                // iska matlab median mid se bada hoga
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return low;
    }
int main(){
    // Input: 2D matrix
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 7, 8}
    };

    int med = median(matrix);
    cout << "Median: " << med << endl;
    // Output: Median of the matrix
    // Expected output: 5
    return 0;
}