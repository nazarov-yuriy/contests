#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int t = nums1Size;
        nums1Size = nums2Size;
        nums2Size = t;
        int *p = nums1;
        nums1 = nums2;
        nums2 = p;
    }

    if (nums1Size == 0) {
        return nums2[(nums2Size - 1) / 2] / 2.0 + nums2[nums2Size / 2] / 2.0;
    }
    int l = 0;
    int r = nums1Size;
    while (1) {
        int pos1 = l + (r - l ) / 2;
        int pos2 = (nums1Size + nums2Size) / 2 - pos1;
        int max_l, min_r;
        if (pos1 == 0) {
            max_l = nums2[pos2-1];
        } else if (pos2 == 0) {
            max_l = nums1[pos1-1];
        } else {
            max_l = MAX(nums1[pos1-1], nums2[pos2-1]);
        }
        if (pos1 == nums1Size) {
            min_r = nums2[pos2];
        } else if (pos2 == nums2Size) {
            min_r = nums1[pos1];
        } else {
            min_r = MIN(nums1[pos1], nums2[pos2]);
        }
        if (max_l <= min_r) {
            if ((nums1Size + nums2Size) % 2 == 1) {
                return min_r;
            } else {
                return (max_l + min_r) / 2.0;
            }
        } else {
            if (pos1 && nums1[pos1-1] > min_r) {
                r = pos1 - 1;
            } else {
                l = pos1 + 1;
            }
        }
    }
}