#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(k*n)+O(n)
// Space Complexity:- O(n-1)
// long double MinimiseTheMaximumDistance(vector<int> &arr, int k){
//     int n=arr.size();
//     vector<int> howMany(n-1, 0);
//     for(int i=1; i<=k; i++){
//         long maximumVal=-1;
//         int maxIndex=-1;
//         for(int j=0; j<arr.size()-1; j++){
//             long double difference=arr[j+1]-arr[j];
//             long double sectionLength=difference/(long double)(howMany[j]+1);
//             if(sectionLength>maximumVal){
//                 maximumVal=sectionLength;
//                 maxIndex=j;
//             }
//         }
//         howMany[maxIndex]++;
//     }
//     long double maxAns=-1;
//     for(int i=0; i<arr.size(); i++){
//         long double difference=arr[i+1]-arr[i];
//         long double sectionLength=difference/(long double)(howMany[i]+1);
//         maxAns=max(maxAns, sectionLength);
//     }
//     return maxAns;
// }

// Time Complexity:- O(nlogn)+O(klogn)
// Space Complexity:- O(n-1)
// long double MinimiseTheMaximumDistance(vector<int> &arr, int k){
//     vector<int> howMany(arr.size()-1, 0);
//     priority_queue<pair<long double, int>> pq;
//     for(int i=0; i<arr.size()-2; i++){
//         pq.push({arr[i+1]-arr[i], i});
//     }
//     for(int i=1; i<=k ;i++){
//         auto top=pq.top();
//         pq.pop();
//         int index=top.second;
//         howMany[index]++;
//         long double difference=arr[index+1]-arr[index];
//         long double sectionLength=difference/(long double)(howMany[index]+1);
//         pq.push({sectionLength, index});
//     }
//     return pq.top().first;
// }

// Time Complexity:- O(nlogn)+O(n)
// Space Complexity:- O(1)
int NumberOfGasStationRequired(long double distance, vector<int> &arr){
	int count=0;
	for(int i=1; i<arr.size(); i++){
		int numberInBetween=(arr[i]-arr[i-1])/distance;
		if(arr[i]-arr[i-1]/distance==numberInBetween+distance){
			numberInBetween++;
		}
		count+=numberInBetween;
	}
	return count;
}
double MinimiseTheMaximumDistance(vector<int> &arr, int k){
	int n=arr.size();
	long double low=0;
	long double high=0;
	for(int i=0; i<n; i++){
		high=max(high, (long double)(arr[i+1]-arr[i]));
	}
	long double difference=1e-6;
	while(high-low>difference){
		long double mid=(low+high)/2.0;
		int count=NumberOfGasStationRequired(mid, arr);
		if(count>k){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	return high;
}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int k=4;
    double ans=MinimiseTheMaximumDistance(arr, k);
    cout<<ans;
    return 0;
}
