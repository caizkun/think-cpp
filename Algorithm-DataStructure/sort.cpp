// summary for sort

// sort is often used in combination with algorithms such as binary search, two pointers

// complexity:
    O(n^2)      selection sort
                insertion sort
                bubble sort

    O(nlog(n))  merge sort
                quick sort
                heapsort

// Must be able to customize a comparator
// 1. write a customized compare function
bool compare(int &a, int &b) {
    return (a > b);     // reverse order
}
sort(data.begin(), data.end(), compare);

// 2. more conveniently, use a lambda function
sort(data.begin(), data.end(), [] (pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);     // sort by the second element of pairs
});





// >>> quicksort: O(nlogn) <<<
void quicksort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int pos = partition(nums, l, r);
    quicksort(nums, l, pos - 1);
    quicksort(nums, pos + 1, r);
    return;
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


// Mergesort: O(nlogn)
void mergesort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergesort(nums, l, mid);
    mergesort(nums, mid + 1, r);
    merge(nums, l, mid, r);
    return;
}

// merge
void merge(vector<int> &nums, int l, int mid, int r) {
    vector<int> copied(nums.begin() + l, nums.begin() + (mid + 1));
    
    int pos = 0;
    int i = 0, j = mid + 1;
    while (i < copied.size() && j <= r) {
        if (copied[i] <= nums[j]) {
            nums[pos++] = copied[i++];
        } else {
            nums[pos++] = nums[j++];
        }
    }
    
    while (i < copied.size()) {
        nums[pos++] = copied[i++];
    }
    while (j <= r) {
        nums[pos++] = nums[j++];
    }
    
    return;
}



