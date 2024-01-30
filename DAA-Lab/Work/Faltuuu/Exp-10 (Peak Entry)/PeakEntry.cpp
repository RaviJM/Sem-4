/*
The solution is achieved using concept of binary searching throughout the array,
which is done using recursion

We take the middle element of the array, and check if it is the peak element we're trying to find
[The peak element has the following PROPERTY: Value of elements right before and after the peak element,
will have lesser value than the peak element.
This is a unique property for the peak element.]

If we find it, we return its value, otherwise,
we recursively call the function accordingly to the right or left half of the array.
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int findPeakEntry(vector <int> v, int low, int high){
    int mid = (low+high)/2;

    //if we have yet not reached the peak, and are on the left of the peak(where values are rising)
    if (v[mid] > v[mid-1] && v[mid] < v[mid+1]){
        return findPeakEntry(v,mid+1,high);
    }

    //if we have gone to the right side of the peak (where values are falling)
    else if (v[mid] < v[mid-1] && v[mid] > v[mid+1]){
        return findPeakEntry(v,low,high-1);
    }

    //we found the peak element, who follows the above mentioned property
    else{
        return v[mid];
    }
}

int main(){
    vector <int> v;
    v = {3,2,1};
    int n = v.size();

    int peakEntry = findPeakEntry(v,0,n-1);
    cout<<"The Peak Entry of the array is: "<<peakEntry;

    return 0;
}