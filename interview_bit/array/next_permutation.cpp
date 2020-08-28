/* https://www.interviewbit.com/problems/next-permutation/ */
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void rev(vector<int>& s, int l, int r) { 
    while (l < r) 
        swap(s[l++], s[r--]); 
} 

int bsearch(vector<int>& s, int l, int r, int key) { 
    int index = -1; 
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
        if (s[mid] <= key) 
            r = mid - 1; 
        else { 
            l = mid + 1; 
            if (index == -1 || s[index] >= s[mid]) 
                index = mid; 
        } 
    } 
    return index; 
}

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size();
    bool notposs = false;
    int i = n - 2; 
    while (i >= 0 && A[i] >= A[i + 1]) 
        --i; 
    if (i < 0) 
        notposs = true; 
    else { 
        int index = bsearch(A, i + 1, n - 1, A[i]); 
        swap(A[i], A[index]); 
        rev(A, i + 1, n - 1); 
    } 
    if(notposs)
        sort(A.begin(), A.end());
    
    return A;
}
