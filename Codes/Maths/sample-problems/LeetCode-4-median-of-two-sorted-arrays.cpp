#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  		double median = 0.0;


  		vector<int> mergedList;

  		int size1 = nums1.size();
  		int size2 = nums2.size();

  		int i = 0, j = 0;

  		while( (i < size1) && (j < size2) ) {
  			if(nums1[i] <= nums2[j]) {
  				mergedList.push_back(nums1[i]);
  				i++;
  			} else {
  				mergedList.push_back(nums2[j]);
  				j++;
  			}
  		}

  		while(i < size1) {
			mergedList.push_back(nums1[i]);
			i++;
  		}

  		while(j < size2) {
			mergedList.push_back(nums2[j]);
			j++;
  		}

  		int size = mergedList.size();
  		if( (size & 1) == 1) {
  			median = mergedList[ (size >> 1) ];
  		} else {
  			int mid1 = size / 2;

  			int mid2 = mid1 - 1;

  			median = 1.0 * (mergedList[ mid1 ] + mergedList[ mid2 ]);
  			median = median / 2;
  		}

  		return median;      
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
