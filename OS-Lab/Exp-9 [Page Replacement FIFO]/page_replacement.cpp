#include <bits/stdc++.h>

using namespace std;

int main(){
    int pageFrames, entries;
    cout<<"Enter number of page frames: ";
    cin>>pageFrames;
    cout<<"Enter total number of entries: ";
    cin>>entries;

    int arr[entries];
    int arr2[pageFrames];
    for (int i=0;i<entries;i++){
        cout<<"Enter entry-"<<(i+1)<<": ";
        cin>>arr[i];
    }
    
    int currentCountOfElements = 0;
    int miss = 0;
    int pointer = 0;

    for (int i=0;i<entries;i++){
        int element = arr[i];
        int flag = 1;
        for (int j=0;j<currentCountOfElements;j++){
            if (arr2[j] == element){
                flag=0;
                break;
            }
        }

        //if element does not already exist in arr2
        if (flag==1){
            if (currentCountOfElements < pageFrames){
                currentCountOfElements++;
            }
            miss++;

            //add element in arr2
            arr2[pointer] = element;

            //update the pointer
            pointer++;
            pointer = pointer%pageFrames;
        }
        // cout<<"CurrentCountOfElements: "<<currentCountOfElements<<", Pointer: "<<pointer;
        // cout<<"\n";
    }

    
    cout<<"\nQueue state at the end:";
    for (int i=0;i<pageFrames;i++){
        cout<<arr2[i]<<" ";
    }

    cout<<"\nHits: "<<(entries-miss)<<endl;
    cout<<"Misses: "<<miss<<endl;

    double hitRatio = double(entries-miss)/double(entries);
    double missRatio = double(miss)/double(entries);
    cout<<"Hit ratio: "<<hitRatio<<endl;
    cout<<"Miss ratio: "<<missRatio<<endl;

    return 0;
}