class SparseVector {
public:
    vector<int> v;
    
    SparseVector(vector<int> &nums) {
        v = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(int i=0; i<v.size(); i++)   ans+= vec.v[i]*v[i];
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);