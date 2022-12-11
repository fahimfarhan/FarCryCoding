#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {

  int n1 = nums1Size; // nums1.size();
  int n2 = nums2Size; // nums2.size();

  int n = n1 + n2;

  int mid = 0;
  if ((n & 1) == 1) {
    mid = n >> 1;
  } else {
    mid = (n - 1) >> 1;
  }

  int mid_plus_one = mid + 1;

  int k = 0;
  int m1, m2;
  int i = 0, j = 0;

  while ((i < n1) && (j < n2)) {
    if (nums1[i] <= nums2[j]) {
      // choose nums1[i]
      if (k == mid) {
        m1 = nums1[i];
      } else if (k == mid_plus_one) {
        m2 = nums1[i];
      }
      i++;
    } else {
      // choose nums2[j]
      if (k == mid) {
        m1 = nums2[j];
      } else if (k == mid_plus_one) {
        m2 = nums2[j];
      }
      j++;
    }
    k++;
  }

  while (i < n1) {
    if (k == mid) {
      m1 = nums1[i];
    } else if (k == mid_plus_one) {
      m2 = nums1[i];
    }
    i++;
    k++;
  }

  while (j < n2) {
    // choose nums2[j]
    if (k == mid) {
      m1 = nums2[j];
    } else if (k == mid_plus_one) {
      m2 = nums2[j];
    }
    j++;
    k++;
  }

  double median = 0;

  if ((n & 1) == 1) {
    median = m1;
  } else {
    median = (0.0 + m1 + m2) * 0.5;
  }

  return median;
}

int main(int argc, char *argv[]) { return 0; }
