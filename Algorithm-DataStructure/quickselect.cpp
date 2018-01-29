// summary for quickselect


// quicksort: O(nlogn)
void quicksort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int pos = partition(nums, l, r);
    quicksort(nums, l, pos - 1);
    quicksort(nums, pos + 1, r);
    return;
}


// quickselect is the algorithm to find the k-th smallest / (n+1-k) largest number in an unsorted array of size n
// time complexity: O(n)
int quickselect(vector<int> &nums, int l, int r, int k) {
    while (l < r) {
        int pos = partition(nums, l, r);
        if (pos + 1 == k) {
            break;
        } else if (pos + 1 < k) {
            l = pos + 1;
        } else {
            r = pos - 1;
        }
    }
    
    return nums[k - 1];
}


// partition
int partition(vector<int> &nums, int l, int r) {
    int left = l, right = r;
    int pivot = nums[left];     // use left point as pivot
    
    while (left < right) {
        while (left < right && nums[right] >= pivot) {  // use > to insert at the last position when duplicated
            --right;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot) {   // use < to insert at the first index when duplicated
            ++left;
        }
        nums[right] = nums[left];
    }
    
    nums[left] = pivot;
    return left;
}


